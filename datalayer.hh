//****************************************************************************************
//Author: Hanyu Zhang, Xiaotian Zhang, Runji Hu
//Discription: this file Define a logic layer of playground for robots to run 
//****************************************************************************************
#ifndef DATALAYER_HH
#define DATALAYER_HH

#include "Robot.hh"
#include <math.h>

//The class Datalayer makes a logic layer to record robots` locations, radiuses, alert area.
//It is also used for checking collision between robots. 

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

    void clearData();       //clear everything on datalayer

    void loadData();        //paint and robot boundaries on the datalayer
};

#endif // DATALAYER_HH

