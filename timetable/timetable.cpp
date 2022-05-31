#include "timetable.h"

timetable::timetable()
{   train v(0,"widmo",0);
    pair<train*, min_time> c(&v, 2400);
    pair<train*, min_time> d(&v, 00);
    my_timetable.push(c);
    my_timetable.push(d);
}
void  timetable::add_timetable(train& trainname, min_time time1)
{
    if (my_timetable.front().second == 2400)
    {
        train v(0,"widmo",0);
        pair<train*, min_time> c(&v, 2400);
        pair<train*, min_time> d(&v, 00);
        my_timetable.pop();
        my_timetable.push(c);
        my_timetable.pop();
        my_timetable.push(d);
    }

    while (!(my_timetable.back().second <= time1 && my_timetable.front().second>=time1))
    {

        pair<train*, min_time> element = my_timetable.front();
        my_timetable.pop();
        my_timetable.push(element);
        if (my_timetable.front().second == 00)
        {
            train v(0,"widmo",0);
                pair<train*, min_time> c(&v, 2400);
                pair<train*, min_time> d(&v, 00);

            my_timetable.pop();
            my_timetable.push(d);
        }

    }
    pair<train*, min_time> to_push(&trainname, time1);
    my_timetable.push(to_push);
}
pair<vector<train*>, min_time>  timetable::nextTrain(min_time time1)
{
    if (my_timetable.front().second == 2400)
    {
        train v(0, "widmo", 0);
        pair<train*, min_time> c(&v, 2400);
        pair<train*, min_time> d(&v, 00);
        my_timetable.pop();
        my_timetable.push(c);
        my_timetable.pop();
        my_timetable.push(d);
    }

    while (!(my_timetable.back().second < time1 and my_timetable.front().second>time1))
    {

        pair<train*, min_time> element = my_timetable.front();
        my_timetable.pop();
        my_timetable.push(element);
        if (my_timetable.front().second == 00)
        {
            train v(0, "widmo", 0);
            pair<train*, min_time> c(&v, 2400);
            pair<train*, min_time> d(&v, 00);
            my_timetable.pop();
            my_timetable.push(d);
        }

    }
    vector<train*> answer = {};
    answer.push_back(my_timetable.front().first);
    while (!(my_timetable.back().second > time1))
    {

        pair<train*, min_time> element = my_timetable.front();
        my_timetable.pop();
        my_timetable.push(element);
        if (my_timetable.front().second == 00)
        {
            train v(0, "widmo", 0);
            pair<train*, min_time> c(&v, 2400);
            pair<train*, min_time> d(&v, 00);
            my_timetable.pop();
            my_timetable.push(d);
        }
        answer.push_back(my_timetable.front().first);
    }

    return pair<vector<train*>, min_time>(answer, my_timetable.front().second);
}
