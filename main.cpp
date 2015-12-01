//***********************************************************************************
//author: Hanyu Zhang
//Discription:Main function of robotsimulator
//***********************************************************************************

#include "robotgui.h"
#include <QApplication>

vector<Robot*> robotList;

int Robot::count_robots = 0;

Datalayer myLayer(400,400);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RobotGui w;                                            //create GUI
//  Robot* test=new Robot(1.0,300.0,300.0,45,10,10,0);
//  robotList.push_back(test);
    w.show();                                              //Show the GUI

    return a.exec();                                       //Run!
}
