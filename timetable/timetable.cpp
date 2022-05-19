#include "timetable.h"

timetable::timetable()
{   train v(0,"widmo",0,0);
    pair<train*, int> c(&v, 2400);
    pair<train*, int> d(&v, 00);
    my_timetable.push(c);
    my_timetable.push(d);
}
void  timetable::add_timetable(train& trainname, int time)
{
    if (my_timetable.front().second == 2400)
    {
        train v(0,"widmo",0,0);
        pair<train*, int> c(&v, 2400);
        pair<train*, int> d(&v, 00);
        my_timetable.pop();
        my_timetable.push(c);
        my_timetable.pop();
        my_timetable.push(d);
    }

    while (!(my_timetable.back().second < time and my_timetable.front().second>time))
    {

        pair<train*, int> element = my_timetable.front();
        my_timetable.pop();
        my_timetable.push(element);
        if (my_timetable.front().second == 00)
        {
            train v(0,"widmo",0,0);
                pair<train*, int> c(&v, 2400);
                pair<train*, int> d(&v, 00);

            my_timetable.pop();
            my_timetable.push(d);
        }

    }
    pair<train*, int> to_push(&trainname, time);
    my_timetable.push(to_push);
}
string timetable::nextTrain(int time)
{
    if (my_timetable.front().second == 2400)
    {
        train v(0,"widmo",0,0);
            pair<train*, int> c(&v, 2400);
            pair<train*, int> d(&v, 00);
        my_timetable.pop();
        my_timetable.push(c);
        my_timetable.pop();
        my_timetable.push(d);
    }

    while (!(my_timetable.back().second < time and my_timetable.front().second>time))
    {

        pair<train*, int> element = my_timetable.front();
        my_timetable.pop();
        my_timetable.push(element);
        if (my_timetable.front().second == 00)
        {
            train v(0,"widmo",0,0);
                pair<train*, int> c(&v, 2400);
                pair<train*, int> d(&v, 00);
            my_timetable.pop();
            my_timetable.push(d);
        }

    }

    return my_timetable.front().first->toString() + " " + to_string(my_timetable.front().second);
}
