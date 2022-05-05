#pragma once
#include <string>
#include <iostream>
#include <vector>


typedef double Tonnes;
typedef double Litres;

class Wagon
{
private:
	Tonnes weigth;
	int id;
public:
	Wagon(int idd, Tonnes weigthh);
	int getID() const { return id; };
	Tonnes getWeigth() const { return weigth; };
	virtual ~Wagon() {};
};

class GoodsWagon : public Wagon
{
private:
	std::string goods_name;
public:
	GoodsWagon(int idd, Tonnes weigthh, std::string goods_namee);
	std::string getGoodsName() { return goods_name; };
	virtual ~GoodsWagon() {};
};

class Cistern : public GoodsWagon
{
private:
	Litres capacity;
	Litres used_cap;
public:
	Cistern(int idd, std::string goods_namee, Tonnes weigth , Litres capacityy, Litres used_capp);
	double getFilledPerc() const;
	virtual ~Cistern() {};
};

class SolidMatWagon : public GoodsWagon
{
private:
	Tonnes capacity;
	Tonnes used_cap;
public:
	SolidMatWagon(int idd, std::string goods_namee, Tonnes weigthh, Tonnes capacityy, Tonnes used_capp);
	double getFilledPerc() const;
	virtual ~SolidMatWagon() {};
};

class LivestockWagon : public GoodsWagon
{
private:
	int livestock_cap;
	int cur_livestock;
public:
	LivestockWagon(int idd, std::string goods_namee, Tonnes weigthh, int livestock_capp, int cur_livestockk);
	double getFilledPerc() const;
	virtual ~LivestockWagon() {};
};


class PassenegerWagon : public Wagon
{
private:
	std::vector<bool> places_vec;
public:
	PassenegerWagon(int idd, Tonnes weigthh, int max_passenegers);
	int findNumberOfFreePlaces();
	int getNumberOfPlaces();
	virtual ~PassenegerWagon() {};
	void bookAPlace(int place) noexcept;
};