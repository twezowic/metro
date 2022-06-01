#include "Display.h"
string Display::drawConnection(int x1, int y1, int x2, int y2)
{
	x1 *= size;
	y1 *= size;
	x2 *= size;
	y2 *= size;
	return "<line x1=\"" + to_string(x1) + "\" y1=\"" + to_string(y1) + "\" x2=\"" + to_string(x2) + "\" y2=\"" + to_string(y2) + "\" style=\"stroke:rgb(0, 0, 0);stroke-width:2\" />";
}
string Display::drawStation(int x, int y, int index)
{
	x *= size;
	y *= size;
	return "<circle onmouseover=mouseOver(\"station" + to_string(index) + "\") onmouseout=mouseOut() cx=\"" + to_string(x) + "\" cy=\"" + to_string(y) + "\" r=\"6\" stroke=\"black\" stroke-width=\"3\" fill=\"red\" />";
}

string Display::drawTrain(int lastStationx, int lastStationy, int nextStationx, int nextStationy, double distance, double actualDistance, int index)
{
	double distancePercentage = actualDistance / distance;
	int newX, newY;

	if (lastStationx - nextStationx != 0)
	{
		int lineEquationX = (lastStationy - nextStationy) / (lastStationx - nextStationx);
		int lineEquationY = lastStationy - ((lastStationy - nextStationy) / (lastStationx - nextStationx)) * lastStationx;

		newX = abs(lastStationx - nextStationx) * distancePercentage + lastStationx;
		newY = lineEquationX * newX + lineEquationY;
	}
	else
	{
		newX = lastStationx;
		newY = abs(lastStationy - nextStationy) * distancePercentage + lastStationy;

	}
	newX *= size;
	newY *= size;
	return "<circle onmouseover=mouseOver(\"train" + to_string(index) + "\") onmouseout=mouseOut() cx=\"" + to_string(newX) + "\" cy=\"" + to_string(newY) + "\" r=\"4\" fill=\"blue\" />";
}
string Display::addScripts()
{
	return R""""(<div id="field" style="position:absolute; left:1000px; top:10px"></div>
<script>
function mouseOver(text) {
  document.getElementById("field").innerHTML = document.getElementById(text).innerHTML;
}
function mouseOut() {
  document.getElementById("field").innerHTML = "";
}
</script>)"""";
}

string Display::addStationInfo(int index, string name, int peopleNumber)
{
	string result;
	result += "<div id=\"station" + to_string(index) + "\" style=\"display:none\">\n";
	result += "<strong>Station name: </strong>" + name + "\n";
	result += "<br> <strong>Number of people on station: </strong>" + to_string(peopleNumber) + '\n';
	result += "</div>\n";
	return result;
}

string Display::addTrainInfo(int index, string name, int maxCapacity, int peopleNumber)
{
	string result;
	result += "<div id=\"train" + to_string(index) + "\" style=\"display:none\">\n";
	result += "<strong>Train name: </strong>" + name + "\n";
	result += "<br> <strong>Train capacity: </strong>" + to_string(peopleNumber) + '/' + to_string(maxCapacity) + '\n';
	result += "</div>\n";
	return result;
}


void Display::create_map(MetroApp metroapp)
{
	string result, informations;
	result += "<svg  version = \"1.1\" xmlns = \"http://www.w3.org/2000/svg\" width=\"1000\" height=\"1000\">\n";
	//connections
	for (int i = 0; i < metroapp.getConnections().size(); i++)
	{
		int x1, y1, x2, y2;
		x1 = metroapp.getStation(metroapp.getConnections()[i].getstation1id())->x;
		y1 = metroapp.getStation(metroapp.getConnections()[i].getstation1id())->y;
		x2 = metroapp.getStation(metroapp.getConnections()[i].getstation2id())->x;
		y2 = metroapp.getStation(metroapp.getConnections()[i].getstation2id())->y;
		result += drawConnection(x1, y1, x2, y2) + '\n';
	}
	// stations
	for (int i = 0; i < metroapp.getCoordinator().getStations().size(); i++)
	{
		int x, y;
		x = metroapp.getCoordinator().getStations()[i].x;
		y = metroapp.getCoordinator().getStations()[i].y;
		result += drawStation(x, y, i) + '\n';
		informations += addStationInfo(i, metroapp.getCoordinator().getStations()[i].getName(), metroapp.getCoordinator().getStations()[i].getWaitingList().size());
	}
	// trains
	for (int i = 0; i < metroapp.getTrains().size(); i++)
	{
		int lastStationx = 20, lastStationy = 20, nextStationx = 1, nextStationy = 1;
		double distance = 2, actualDistance = 1;
		result += drawTrain(lastStationx, lastStationy, nextStationx, nextStationy, distance, actualDistance, i) + '\n';
		informations += addTrainInfo(i, "A", 300, 100);
	}
	result += "</svg>\n";
	result += informations + addScripts();
	fstream file("../station.html", ios::out);
	file << result;
	file.close();
}