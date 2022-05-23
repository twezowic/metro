#include "CoordinatorLib.h"
	// CoordinatorLib.cpp : Defines the functions for the static library.

	Coordinator::Coordinator() {}

void Coordinator::setStations(vector<Station> stations)
{
		this->station_vec = stations;
}

void Coordinator::setTime(time starting_time) {
	cur_time = starting_time;
}

void Coordinator::increaseTime(time& simulation_time)
{ // as of right now, this means - increasing the time by one minute
	++cur_time;
	++simulation_time;
	if (cur_time == 1440)
		cur_time = 0;
}

void Coordinator::HandleStations() //@TODO when a passeneger gets to the end of his route
{
	for (auto stat_ite = station_vec.begin(); stat_ite != station_vec.end(); ++stat_ite)
	{
		std::vector<Train*> trains_on_station;
		if ((*stat_ite).hasTrains())
			trains_on_station = (*stat_ite).getNextTrains(cur_time);
		else
			trains_on_station = {};
		std::vector<Person*> waiting_list_after_operations;
		std::vector<Person*> waiting_list = (*stat_ite).getWaitingList();
		for (auto train_ite = trains_on_station.begin(); train_ite != trains_on_station.end(); ++train_ite)
		{
			std::vector<Person*> new_person_in_train_vec;
			for (auto person_ite = (*train_ite)->getPeopleVec().begin(); person_ite != (*train_ite)->getPeopleVec().end(); ++person_ite)
			{
				if ((*person_ite)->getNextStop() == &(*stat_ite))
				{
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
				(*waiting_person_ite); //remove person function should go here
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
		std::pair<std::vector<Train*>, time> train_time_pair = station.nexttrain(time_offset);
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
