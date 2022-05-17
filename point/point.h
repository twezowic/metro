#ifndef POINT_H
#define POINT_H


class point
{

public:
    int x;
    int y;
    int id;
    point(int x1=0,int y1=0,int id1=0);
    int getid()
    {return id;}
};

#endif // POINT_H
