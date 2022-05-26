#pragma once
#include <vector>
#include "../station/trainstation.h"


//#include "../person/people.h"
//#include"../train/train.h"

typedef train Train;
typedef timetable TimeTable;

static int NUMBER_OF_TRAINS = 10; // number of trains coordinator will look through when trying to find a person a train

class Coordinator
{
private:
	std::vector<Station> station_vec;
	time cur_time; // time in minutes


	// returns the best train, as well as next stop for the passeneger
	std::pair<Train*, Station*> findBestTrain(Station& cur_stat, std::vector<Station*> full_route, std::vector<Train*> next_trains);
	std::vector<Train*> findNextTrains(Station& station);
	// returns the percentage of stations shared by both vectors in order, as well as the last common station
	std::pair<double, Station*> CompareRoutes(Station& start_stat, std::vector<Station*> person_route, std::vector<Station*> train_route); 
public:
	Coordinator();
	void setStations(vector<Station> stations);
	void setTime(time starting_time);
	void increaseTime(time& simulation_time);
	void HandleStations();
	bool isTheTrainOnStation(Train* the_train, std::vector<Train*> trains_on_stat);
	void addStation(Station new_stat);

	// functions below might be useful to refactorise the code
	void AddPersonToTrain(Person& person, Train& train);
	void HandleTrainOnStation(std::vector<Person*> waiting_people, Train& Train, Station& station); // appends waiting people list, removes people from train
	void AddWaitingPeopleToTrains(std::vector<Person*> waiting_people, std::vector<Train*> trains_on_station);
	std::vector<Train*> GetTrainsOnStation(Station& stat);
};
