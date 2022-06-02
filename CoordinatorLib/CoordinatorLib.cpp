#include "CoordinatorLib.h"
	// CoordinatorLib.cpp : Defines the functions for the static library.

	Coordinator::Coordinator() {}

void Coordinator::setStations(vector<Station> stations)
{
		this->station_vec = stations;
}

void Coordinator::fillTimetable(std::vector<std::pair<Train, Train>>& train_pairs_vec)
{
	for (auto train_ite = train_pairs_vec.begin(); train_ite != train_pairs_vec.end(); ++train_ite)
	{
		Train* cur_train = &(*train_ite).first;
		min_time temp_time = cur_time;
		int loop_num = 0;
		bool reached_midnight = false;
		do
		{

			reached_midnight = assignTrainRoute(cur_train, temp_time);
			if (loop_num % 2 == 0)
				cur_train = &(*train_ite).second;
			else
				cur_train = &(*train_ite).first;
			++loop_num;
		} while (!reached_midnight);

	}
	for (auto stat_ite = station_vec.begin(); stat_ite != station_vec.end(); ++stat_ite)
	{
		(*stat_ite).hasTrains(cur_time); // resets the timetable time to the beginning of simulation
	}
}

bool Coordinator::assignTrainRoute(Train* cur_train, min_time& temp_time)
{
	Station* cur_station = cur_train->getRoute()[0];
	bool reached_end_of_route = false;
	int i = 0;
	while(!reached_end_of_route)
	{

		Station* cur_station = cur_train->getRoute()[i];
		Station* next_station = cur_train->getRoute()[i+1];

		cur_station->add_timetable(*cur_train, temp_time);

		temp_time += cur_station->getConnectionTime(next_station);
		
		if (next_station == cur_train->getRoute().back())
		{
			next_station->add_timetable(*cur_train, temp_time%1440);
			temp_time += 1; // 10 is the time of stop at the end of the route of train
			if (temp_time > 24 * 60)
				return true;

			reached_end_of_route = true;
		}
		if (temp_time > 24 * 60)
		{
			temp_time = temp_time % 1440;
			moveTrainToStartingStation(i+1, temp_time, cur_train);
			return true;
		}
		++i;
		} 
	return false;
}

void Coordinator::moveTrainToStartingStation(int cur_stat_num, min_time temp_time, Train* cur_train)
{
	Station* cur_station = cur_train->getRoute()[0];
	bool reached_end_of_route = false;
	int i = cur_stat_num;
	while (!reached_end_of_route)
	{

		Station* cur_station = cur_train->getRoute()[i];
		Station* next_station = cur_train->getRoute()[i + 1];

		cur_station->add_timetable(*cur_train, temp_time);

		temp_time += cur_station->getConnectionTime(next_station);

		if (next_station == cur_train->getRoute().back())
		{
			next_station->add_timetable(*cur_train, temp_time);
			reached_end_of_route = true;
		}
		++i;
	}
}

void Coordinator::setTime(min_time starting_time) {
	cur_time = starting_time;
}

void Coordinator::increaseTime(min_time& simulation_time, min_time metro_start_time)
{ // as of right now, this means - increasing the time by one minute
	++cur_time;
	++simulation_time;
	if (cur_time == 1440)
	{
		cur_time = 1;
		simulation_time += 1;
	}
}

void Coordinator::HandleStations(int& people_in_metro) //@TODO when a passeneger gets to the end of his route
{
	if (cur_time == 1200)
		int ha = people_in_metro;
	for (auto stat_ite = station_vec.begin(); stat_ite != station_vec.end(); ++stat_ite)
	{
		std::vector<Train*> trains_on_station;
		if ((*stat_ite).hasTrains(cur_time))
			trains_on_station = (*stat_ite).getNextTrains(cur_time);
		else
			trains_on_station = {};
		std::vector<Person*> waiting_list_after_operations;
		std::vector<Person*> waiting_list = (*stat_ite).getWaitingList();
		for (auto train_ite = trains_on_station.begin(); train_ite != trains_on_station.end(); ++train_ite)
		{
			(*train_ite)->newstop();
			std::vector<Person*> new_person_in_train_vec;
			std::vector<Person*> cur_people_in_train = (*train_ite)->getPeopleVec();
    		for (auto person_ite = cur_people_in_train.begin(); person_ite != cur_people_in_train.end(); ++person_ite)
			{
				if ((*person_ite)->getNextStop() == &(*stat_ite))
				{
					if ((*person_ite)->getLastStop() == &(*stat_ite))
					{
						--people_in_metro;
						// here the person should be destroyed, if it was dynamically generated
					}
					else
						waiting_list.push_back((*person_ite));
				}
				else
					new_person_in_train_vec.push_back((*person_ite));
			}
			(*train_ite)->setpeople(new_person_in_train_vec);
		}
		std::vector<Train*> next_trains_on_station = findNextTrains(*stat_ite);
		for (auto waiting_person_ite = waiting_list.begin(); waiting_person_ite != waiting_list.end(); ++waiting_person_ite)
		{
			std::pair<Train*, Station*> train_to_append_pair = findBestTrain((*stat_ite), (*waiting_person_ite)->getRoute(), next_trains_on_station);
			if (train_to_append_pair.first)
			{
				if (isTheTrainOnStation(train_to_append_pair.first, trains_on_station) && train_to_append_pair.first->hasFreeSpace())
				{
					train_to_append_pair.first->AddPerson(*waiting_person_ite);
					(*waiting_person_ite)->setNextStop(train_to_append_pair.second);
				}
				else
					waiting_list_after_operations.push_back(*waiting_person_ite);
			}
			else
				--people_in_metro;
				//(*waiting_person_ite); //remove person function should go here
		}
		(*stat_ite).setwaiting(waiting_list_after_operations);
	}

}
bool Coordinator::isTheTrainOnStation(Train* the_train, std::vector<Train*> trains_on_stat)
{
	if (find(trains_on_stat.begin(), trains_on_stat.end(), the_train) == trains_on_stat.end())
		return false;
	else
		return true;
}
void Coordinator::addStation(Station new_stat)
{
	station_vec.push_back(new_stat);
}
std::vector<Train*> Coordinator::findNextTrains(Station& station)
{
	std::vector<Train*> train_vec;
	size_t time_offset = cur_time;
	int i = 0;
	do 
	{
		std::pair<std::vector<Train*>, min_time> train_time_pair = station.nexttrain(time_offset);
		time_offset = train_time_pair.second + 1;

		train_vec.insert(train_vec.end(), train_time_pair.first.begin(), train_time_pair.first.end());
		i += train_time_pair.first.size();
	} while (i < NUMBER_OF_TRAINS);
	return train_vec;
}

std::pair<double, Station*> Coordinator::CompareRoutes(Station& start_stat, std::vector<Station*> person_route, std::vector<Station*> train_route)
{
	auto per_route_ite = person_route.begin();
	auto train_route_ite = train_route.begin();
	double mutual_stations = -1; // because the loop below will always add at least one
	double stations_left = 0;
	Station* last_mutual_station;
	while ((*per_route_ite) != &start_stat) // move person iterator to current station
		++per_route_ite;

	while ((*train_route_ite) != &start_stat) // move train iterator to current station
		++train_route_ite;

	do // count the number of stations both vectors share
	{
		++mutual_stations;
		last_mutual_station = (*per_route_ite);
		++train_route_ite;
		++per_route_ite;
		
		if (per_route_ite == person_route.end()) // this means this train covers every station left for passeneger
			return std::pair<double, Station*>(100, last_mutual_station);
	
		if (train_route_ite == train_route.end()) // this means the train reached it's end
			break;
		//return std::pair<double, Station*>(100, last_mutual_station);
	
	} while ((*per_route_ite) == (*train_route_ite));

	while (per_route_ite != person_route.end()) // count how many stations till the last are left
	{
		++per_route_ite;
		++stations_left;
	}
	return std::pair<double, Station*>(100 * mutual_stations / (mutual_stations + stations_left), last_mutual_station);
}

std::pair<Train*, Station*> Coordinator::findBestTrain(Station& cur_stat, std::vector<Station*> person_route, std::vector<Train*> next_trains)
{
	Train* train_to_assign = nullptr;
	Station* next_stop = nullptr;
	double cur_match = 0; // is a percentage value - 100 means 100% matched
	for (auto train_ite = next_trains.begin(); train_ite != next_trains.end(); ++train_ite)
	{
		{
			std::pair<double, Station*> data_pair = CompareRoutes(cur_stat, person_route, (*train_ite)->getRoute());
			if (data_pair.first > cur_match)
			{
				cur_match = data_pair.first;
				next_stop = data_pair.second;
				train_to_assign = *train_ite;
			}
		}
	}
	return std::pair<Train*, Station*>(train_to_assign, next_stop);
}
Station* Coordinator::getStation(int id)
{
	for (int i = 0; i < station_vec.size(); i++)
	{
		if (station_vec[i].getid() == id)
		{
			return &station_vec[i];
		}

	}
}


int Coordinator::getpozition(int id)
{
	for (int i = 0; i < station_vec.size(); i++)
	{
		if (station_vec[i].getid() == id)
		{
			return i;
		}

	}
	return -1;
}


vector<Station*> Coordinator::dijkstra(int start, int second)
{
	vector<pair<int, int>> distan;
	while (distan.size() > 0)
	{
		distan.pop_back();
	}
	for (int i = 0; i < station_vec.size(); i++)
	{
		if (station_vec[i].getid() != start)
		{
			distan.push_back(pair<int, int>(station_vec[i].getid(), 999999));
		}
		else
		{
			distan.push_back(pair<int, int>(station_vec[i].getid(), 0));
		}
	}
	priority_queue<pair<int, int>> tovisit;
	tovisit.push(pair<int, int>(-0, start));
	while (tovisit.size() != 0)
	{
		pair<int, int> present = tovisit.top();
		int presentpozition = getpozition(present.second);
		for (int i = 0; i < station_vec[presentpozition].vec().size(); i++)
		{
			int koszt = (station_vec[presentpozition].vec()[i])->distance(present.second);

			int disttous = distan[presentpozition].second;
			int distancetosec;
			if (getpozition((station_vec[presentpozition].vec()[i])->getstation2id()) != presentpozition)
			{
				 distancetosec = distan[getpozition((station_vec[presentpozition].vec()[i])->getstation2id())].second;
			}
			else
			{
				 distancetosec = distan[getpozition((station_vec[presentpozition].vec()[i])->getstation1id())].second;

			}
			if (disttous + koszt < distancetosec)
			{   //(stations[presentpozition]->vec()[i])->distance(presentpozition)odleg�os� obecnegopo�
				if (getpozition((station_vec[presentpozition].vec()[i])->getstation2id()) != presentpozition)
				{
					distan[getpozition((station_vec[presentpozition].vec()[i])->getstation2id())].second = (station_vec[presentpozition].vec()[i])->distance(present.second) + distan[presentpozition].second;
					distan[getpozition((station_vec[presentpozition].vec()[i])->getstation2id())].first = presentpozition;

					tovisit.push(pair<int, int>(-distan[getpozition((station_vec[presentpozition].vec()[i])->getstation2id())].second, station_vec[presentpozition].vec()[i]->getstation2id()));

				}
				else
				{
					distan[getpozition((station_vec[presentpozition].vec()[i])->getstation1id())].second = (station_vec[presentpozition].vec()[i])->distance(present.second) + distan[presentpozition].second;
					distan[getpozition((station_vec[presentpozition].vec()[i])->getstation1id())].first = presentpozition;

					tovisit.push(pair<int, int>(-distan[getpozition((station_vec[presentpozition].vec()[i])->getstation1id())].second, station_vec[presentpozition].vec()[i]->getstation1id()));


				}
				}
		}
		tovisit.pop();
	}
	vector<Station*> trasa;
	int poz = getpozition(second);
	while (poz != getpozition(start))
	{
		trasa.push_back(&station_vec[poz]);
		poz = distan[poz].first;
	}

	trasa.push_back(&station_vec[poz]);
	return trasa;//vector stacji

}