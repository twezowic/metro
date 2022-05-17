#include "CoordinatorLib.h"
// CoordinatorLib.cpp : Defines the functions for the static library.

Coordinator::Coordinator(size_t starting_time): cur_time(starting_time) {}

void Coordinator::HandleStations()
{
	for (auto stat_ite = station_ptr_vec.begin(); stat_ite != station_ptr_vec.end(); ++stat_ite)
	{
		std::vector<Person*> waiting_list_after_operations;
		std::vector<Train*> trains_on_station = (*stat_ite)->getCurrentTrains(cur_time);
		std::vector<Person*> waiting_list = (*stat_ite)->getWaitingList();
		for (auto train_ite = trains_on_station.begin(); train_ite != trains_on_station.end(); ++train_ite)
		{
			std::vector<Person*> new_person_in_train_vec;
			for (auto person_ite = (*train_ite).getPeopleVec().begin(); person_ite != (*train_ite).getPeopleVec().end(); ++person_ite)
			{
				if ((*person_ite).getNextStop == (*stat_ite))
				{
					waiting_list.push_back((*person_ite));
				}
				else
					new_person_in_train_vec.push_back((*person_ite));
			}
			(*train_ite).setPeopleVec(new_person_in_train_vec);
		}
		std::vector<Train*> next_trains_on_station = findNextTrains();
		for (auto waiting_person_ite = waiting_list.begin(); waiting_person_ite != waiting_list.end(); ++waiting_person_ite)
		{
			// pytanie, try do tego nie zadziała w c++?
			Train train_to_append = findBestTrain((*waiting_person_ite).getRoute(), next_trains_on_station);
			if (train_to_append)
				train_to_append.AssignPerson(*waiting_person_ite); //co jeśli nie będzie właściwego pociągu
			else
				waiting_list_after_operations.push_back(*waiting_person_ite);
		}
		(*stat_ite)->SetWaitingList(waiting_list_after_operations);
	}

}
std::vector<Train*> Coordinator::findNextTrains(TimeTable timetable)
{
	size_t time_offset = cur_time;
	for (int i = 0; i != NUMBER_OF_TRAINS; ++i)
	{
		std::pair<Train*, size_t> train_time_pair = timetable.nextTrain(time_offset); //@TODO
		time_offset = train_time_pair.second + 1;

	}

}
Train Coordinator::findBestTrain(Dikstra_result full_route, std::vector<Train*> next_trains)
{
	for (int i = 0; i != NUMBER_OF_TRAINS; ++i)
	{
		try
		{
			// mój aktualny pomysł - znaleźć najlepszy pociąg jako funkcja dwóch zmiennych - czas_do_pociągu * stała_1 + procent_stacji_jakie_przejedzie * stała_2
			// najmniejszy czas jest najlepszy
			timetable.getNextTrain(cur_time); //@TODO
			//compareTrainA
		}
		catch (...)
		{
			break;
		}
	}
}
