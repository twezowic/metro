#include"../train/train.h"
#include <queue>
class timetable
{
    queue<pair<train*, time>> my_timetable;
public:
    timetable();
    void add_timetable(train& trainname, time time);
    pair<train*,time> nextTrain(time time);
};

