#ifndef TIMETABLE_H
#define TIMETABLE_H
#include"../train/train.h"
#include <queue>
class timetable
{
    queue<pair<train*, int>> my_timetable;
public:
    timetable();
    void add_timetable(train& trainname, int time);
    string nextTrain(int time);
};

#endif // TIMETABLE_H
