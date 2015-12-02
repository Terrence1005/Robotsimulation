//****************************************************************************************
//Author: Hanyu Zhang,Xian Zhang, Runji Hu
//Discription: Define class Robot
//****************************************************************************************


#ifndef ROBOT_HH
#define ROBOT_HH
#include <vector>

using namespace std;

//The class Robot can store basic parameters of a robot such as speed, direction, location, etc.
//And it defines some funtions which can prevent robots from collision. 

class Robot;

//The structure Telecom will record the information of other robots which come into the alert 
//area of this robot and caculate the distance between this robot to them. 

struct Telecom {
    int    number;
    Robot *pointer;
    double distance;
};

class Robot{
private:
    int ID;                                                          //The ID of each robot
    double speed;                                                    //robot moving speed;
    double coordinate_x;
    double coordinate_y;                                             //location in the coordinate x,y;
    double theta;                                                    //set north as degree 0;
    double robotsize_radius;                                         //set robot as a circle;
    double alert;                                                    //set the alert area;
    vector<Telecom> communication;                                   //A vector to record Telecom structure;
    vector<double> trace;                                            //A vector to record new directions of this robot; 
    static int count_robots;                                         //How many robots in this place;
public:
    Robot(double ,double ,double ,double ,double ,double, int);

    ~Robot();

    double getSpeed() const;

    void change_speed(int);

    double getX() const;

    double getY() const;

    void change_location(double ,double);                         //change the robot location;

    double getTheta() const;                                      //get the robot direction

    void change_theta(double);                                    //change the robot direction

    int getCount() const;                                         //count the robot numbers

    double getRadius() const;                                     //let the robot get a test of blocks range in the radius r

    double getAlert() const;

    int getID() const;

    void capture(int);                                            //capture information from near object;

    void add_trace(Robot* ,Robot*);

    void add_trace_bound(Robot*, int);

    void go();
};

#endif // ROBOT_HH

