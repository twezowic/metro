#pragma once
#include <vector>

typedef int Station;
typedef int Person;
typedef int Train;

typedef int Dikstra_result;

class Coordinator
{
private:
	std::vector<Station*> station_ptr_vec; // vector of pointers
	Dikstra_result findRoute(Person& const person); // uses dikstra algorithm

public:
	void AddRoute(Person& person); // (is used in app class for every person at the beginning) adds the dikstra_result from findRoute to person
	std::vector<Train*> GetTrainsOnStation(Station& stat);
	void AddWaitingPeopleToTrains(std::vector<Person*> waiting_people, std::vector<Train*> trains_on_station);
	std::vector<Station*> getStationsVect() const; // should be used by app, next step will be using the method getTrainsOnStation() 
	void AddPersonToTrain(Person& person, Train& train);
	void HandleTrainOnStation(std::vector<Person*> waiting_people, Train& Train, Station& station); // appends waiting people list, removes people from train
};
