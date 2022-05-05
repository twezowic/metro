#include "CppUnitTest.h"
#include"../metro_route/Route.h"
#include"../metro_route/Station.h"
#include"../metro_display/Display.h"
#include"../metro_display/Display_text.h"
#include"../metro_display/Display_gui.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace metrotests
{
	TEST_CLASS(stationTests)
	{
	public:
		
		TEST_METHOD(ConstructorParameterless)
		{
			Station s;
			Assert::IsTrue(s.getName() == "unknown");
			Assert::AreEqual(1, s.getCoordinate().x);
			Assert::AreEqual(1, s.getCoordinate().y);
		}
		TEST_METHOD(ConstructorWithParameter)
		{
			Station s("Warsaw", 5, 7);
			Assert::IsTrue(s.getName() == "Warsaw");
			Assert::AreEqual(5, s.getCoordinate().x);
			Assert::AreEqual(7, s.getCoordinate().y);
		}
		TEST_METHOD(setName)
		{
			Station s;
			s.setName("Berlin");
			Assert::IsTrue(s.getName() == "Berlin");
		}
		TEST_METHOD(setX)
		{
			Station s;
			s.setX(9);
			Assert::AreEqual(9, s.getCoordinate().x);
		}
		TEST_METHOD(setY)
		{
			Station s;
			s.setY(9);
			Assert::AreEqual(9, s.getCoordinate().y);
		}
		TEST_METHOD(outputInput)
		{
			Station a("Warsaw", 1, 7);
			stringstream stream;
			stream << a;
			Station b;
			stream >> b;
			Assert::IsTrue(a.getName() == b.getName());
			Assert::AreEqual(a.getCoordinate().x, b.getCoordinate().x);
			Assert::AreEqual(a.getCoordinate().y, b.getCoordinate().y);
		}
	};
	TEST_CLASS(route_tests)
	{
	public:
		TEST_METHOD(ConstructorParameterless)
		{
			Route r;
			Assert::IsTrue(r.getStations().size() == 0);
		}
		TEST_METHOD(ConstructorWithParameter)
		{
			Station station("Warsaw", 5, 7);
			vector<Station> stations = {station};
			Route r(stations);
			Assert::IsTrue(r[0].getName() == "Warsaw");
			Assert::AreEqual(5, r[0].getCoordinate().x);
			Assert::AreEqual(7, r[0].getCoordinate().y);
		}
		TEST_METHOD(getCoordinates)
		{
			Station station1("Warsaw", 5, 7);
			Station station2("Berlin", 10, 17);
			vector<Station> stations = {station1, station2};
			Route r(stations);
			vector<Coordinate> coordinates = r.getCoordinates();
			Assert::AreEqual(5, coordinates[0].x);
			Assert::AreEqual(7, coordinates[0].y);
			Assert::AreEqual(10, coordinates[1].x);
			Assert::AreEqual(17, coordinates[1].y);
		}
		TEST_METHOD(operatorPlusStation)
		{
			Station station("Warsaw", 5, 7);
			Route r;
			r += station;
			Assert::IsTrue(r[0].getName() == "Warsaw");
			Assert::AreEqual(5, r[0].getCoordinate().x);
			Assert::AreEqual(7, r[0].getCoordinate().y);
		}
		TEST_METHOD(operatorMinusString)
		{
			Station station1("Warsaw", 5, 7);
			Station station2("Berlin", 10, 17);
			vector<Station> stations = { station1, station2 };
			Route r(stations);
			r -= "Warsaw";
			Assert::IsTrue(r[0].getName() == "Berlin");
			Assert::AreEqual(10, r[0].getCoordinate().x);
			Assert::AreEqual(17, r[0].getCoordinate().y);
		}
		TEST_METHOD(outputInput)
		{
			vector<Station> col = { Station("Warsaw", 5, 7),  Station("Berlin", 10, 17) };
			Route a(col);
			stringstream stream;
			stream << a;
			Route b;
			stream >> b;
			Assert::IsTrue(b[0].getName() == "Warsaw");
			Assert::AreEqual(5, b[0].getCoordinate().x);
			Assert::AreEqual(7, b[0].getCoordinate().y);
			Assert::IsTrue(b[1].getName() == "Berlin");
			Assert::AreEqual(10, b[1].getCoordinate().x);
			Assert::AreEqual(17, b[1].getCoordinate().y);
		}
	};
	TEST_CLASS(display_text_test)
	{
	public:
		TEST_METHOD(ConstructorParameterless)
		{
			Display_text d;
			Assert::AreEqual(25, d.getWidht());
			Assert::AreEqual(25, d.getHeight());
		}
		TEST_METHOD(ConstructorWithParameter)
		{
			vector<Station> col = { Station("Warsaw", 5, 7) };
			Route route(col);
			User user;
			Display_text d(50, 12, route, user);
			Assert::AreEqual(50, d.getWidht());
			Assert::AreEqual(12, d.getHeight());
			Assert::IsTrue(d.getRoute()[0].getName() == "Warsaw");
			Assert::AreEqual(5, d.getRoute()[0].getCoordinate().x);
			Assert::AreEqual(7, d.getRoute()[0].getCoordinate().y);
		}
	};
	TEST_CLASS(display_gui_tests)
	{
	public:
		TEST_METHOD(ConstructorParameterless)
		{
			Display_gui d;
			Assert::IsTrue(d.getRoute().getStations().size() == 0);
		}
		TEST_METHOD(ConstructorWithParameter)
		{
			vector<Station> col = { Station("Warsaw", 5, 7) };
			Route route(col);
			User user;
			Display_gui d(route, user);
			Assert::IsTrue(d.getRoute()[0].getName() == "Warsaw");
			Assert::AreEqual(5, d.getRoute()[0].getCoordinate().x);
			Assert::AreEqual(7, d.getRoute()[0].getCoordinate().y);
		}
	};
}
	