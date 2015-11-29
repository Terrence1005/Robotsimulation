#ifndef DATALAYER_HH
#define DATALAYER_HH

#include "robot.hh"
#include <math.h>

class Datalayer{
private:
    int length;
    int width;
    int **layer;
public:
    Datalayer(int ,int);

    ~Datalayer();

    void changeLen(int);

    void changeWid(int);

    int getLength() const;

    int getWidth() const;

    void clearData();

    void loadData();        //paint robot on the datalayer
};

#endif // DATALAYER_HH

