#ifndef _ROBOT_HH_
#define _ROBOT_HH_
#include <iostream>
class Robot{
private:
    double speed;//robot moving speed;
    int coordinate_x;
    int coordinate_y;//location in the coordinate x,y;
    double theta;//set north as degree 0;
    double robotsize_radius;//set robot as a circle;
public:
    static int count_robots;
    Robot(double s,int x,int y,double th,double r);
    ~Robot();
    void robot_move(int& x,int& y,double& s,double& th);
    //move the robot at that speed in that direction;
    double getSpeed() const {return speed;}
    double change_speed(double s);
    int getX(){return coordinate_x;}
    int getY(){return coordinate_y;}
    void change_location(int& x,int& y);
    //change the robot location;
    double getTheta() const {return theta;}
    //get the robot direction
    double change_theta(double th);
    //change the robot direction
    int getCount() const {return count_robots;}
    //count the robot numbers
    double robot_test_range(double r);
    //let the robot get a test of blocks range in the radius r

};
#endif
