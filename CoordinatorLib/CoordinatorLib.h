#pragma once
#include <vector>
#include "../station/trainstation.h"
//#include "../person/people.h"
//#include"../train/train.h"

typedef station Station;
typedef people Person;
typedef train Train;
typedef timetable TimeTable;

typedef int Dikstra_result;

static int NUMBER_OF_TRAINS = 10; // number of trains coordinator will look through when trying to find a person a train

class Coordinator
{
private:
	std::vector<Station*> station_ptr_vec; // vector of pointers
	Dikstra_result findRoute(Person& const person); // uses dikstra algorithm
	Train findBestTrain(Dikstra_result full_route, std::vector<Train*> next_trains);
	std::vector<Train*> findNextTrains(TimeTable timetable);
	size_t cur_time;
public:
	Coordinator(size_t staring_time);
	void AddRoute(Person& person); // (is used in app class for every person at the beginning) adds the dikstra_result from findRoute to person
	std::vector<Train*> GetTrainsOnStation(Station& stat);
	void AddWaitingPeopleToTrains(std::vector<Person*> waiting_people, std::vector<Train*> trains_on_station);
	std::vector<Station*> getStationsVect() const; // should be used by app, next step will be using the method getTrainsOnStation() 
	void AddPersonToTrain(Person& person, Train& train);
	void HandleTrainOnStation(std::vector<Person*> waiting_people, Train& Train, Station& station); // appends waiting people list, removes people from train
	void HandleStations();

};
