//***********************************************************************************
//Author: Hanyu Zhang
//Discription: This file define the details in user interface
//***********************************************************************************

#include "robotgui.h"
#include "ui_robotgui.h"
#include <QtWidgets>

extern Datalayer myLayer;
extern vector<Robot *> robotList;

RobotGui::RobotGui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RobotGui)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(update()));                             //if timeout then run paintevent();
    timer->start(100);                                                                 //set time as 100ms

    setWindowTitle(tr("Robot Simulator"));                                             //define the title of the window
    QSize mySize(myLayer.getLength()+200,myLayer.getWidth()+100);                      //define the size of the window
    this->resize(mySize);
    ui->pushButton->setGeometry(myLayer.getLength()/2-120,myLayer.getWidth()+40,80,20);
    ui->pushButton_2->setGeometry(myLayer.getLength()/2+40,myLayer.getWidth()+40,80,20); //layout widgets
    ui->label->setGeometry(myLayer.getLength()+5,5,70,20);
    ui->label1->setGeometry(myLayer.getLength()+5,30,70,20);
    ui->label2->setGeometry(myLayer.getLength()+5,55,70,20);
    ui->label3->setGeometry(myLayer.getLength()+5,80,70,20);
    ui->label4->setGeometry(myLayer.getLength()+5,105,70,20);
    ui->label5->setGeometry(myLayer.getLength()+5,130,70,20);
    ui->label6->setGeometry(myLayer.getLength()+5,155,70,20);
    ui->lineEdit->setGeometry(myLayer.getLength()+80,5,70,20);
    ui->lineEdit_1->setGeometry(myLayer.getLength()+80,30,70,20);
    ui->lineEdit_2->setGeometry(myLayer.getLength()+80,55,70,20);
    ui->lineEdit_3->setGeometry(myLayer.getLength()+80,80,70,20);
    ui->lineEdit_4->setGeometry(myLayer.getLength()+80,105,70,20);
    ui->lineEdit_5->setGeometry(myLayer.getLength()+80,130,70,20);
    ui->lineEdit_6->setGeometry(myLayer.getLength()+80,155,70,20);
    ui->label_2->setGeometry(myLayer.getLength()+5,200,52,20);
    ui->lineEdit_7->setGeometry(myLayer.getLength()+80,200,50,20);
    ui->label_3->setGeometry(myLayer.getLength()+5,225,52,20);
    ui->label_4->setGeometry(myLayer.getLength()+80,225,120,20);
    ui->label_5->setGeometry(myLayer.getLength()+5,250,52,20);
    ui->label_6->setGeometry(myLayer.getLength()+80,250,70,20);
    ui->label_7->setGeometry(myLayer.getLength()+5,275,52,20);
    ui->label_8->setGeometry(myLayer.getLength()+80,275,70,20);
}

RobotGui::~RobotGui()
{
    delete ui;
}

void RobotGui::paintEvent(QPaintEvent *e){                                               //painting;
    QPainter painter(this);
    QPainter painter2(this);
    painter.setRenderHint(QPainter::Antialiasing);                                       //antialiasing
    QColor robotC(127,0,127);
    QColor boundC(127,127,0);
    QColor AlertC(0,127,127);
    myLayer.loadData();                                                                  //load data to datalayer and check collision;
    myLayer.clearData();                                                                 //clear datalayer;
    painter.setPen(boundC);
    painter.drawLine(0,0,myLayer.getLength(),0);
    painter.drawLine(0,0,0,myLayer.getWidth());
    painter.drawLine(myLayer.getLength(),0,myLayer.getLength(),myLayer.getWidth());
    painter.drawLine(0,myLayer.getWidth(),myLayer.getLength(),myLayer.getWidth());
    for(int i=0; i<robotList.size();i++){
        QPoint myCenter(robotList[i]->getX(),robotList[i]->getY());
        painter2.setPen(AlertC);
        painter2.save();
        painter2.drawEllipse(myCenter,robotList[i]->getAlert(),robotList[i]->getAlert());
        painter.setPen(Qt::NoPen);
        painter.setBrush(robotC);
        painter.save();
        painter.drawEllipse(myCenter,robotList[i]->getRadius(),robotList[i]->getRadius());
        robotList[i]->go();                                                               //robot move;
    }

}

void RobotGui::on_pushButton_clicked()                                                    //push button "New Robot" then add a new robot.
{
    bool c=1;
    QString Speed = ui->lineEdit_1->text();
    double speed=Speed.toDouble(&c);
    QString X = ui->lineEdit_2->text();
    double x = X.toDouble(&c);
    QString Y = ui->lineEdit_3->text();
    double y = Y.toDouble(&c);
    QString Theta = ui->lineEdit_4->text();
    double theta = Theta.toDouble(&c);
    QString Radius = ui->lineEdit_5->text();
    double radius = Radius.toDouble(&c);
    QString Alert = ui->lineEdit_6->text();
    double alert = Alert.toDouble(&c);
    QString ID = ui->lineEdit->text();
    int id = ID.toInt(&c,10);
    Robot* newRobot = new Robot(speed, x, y, theta, radius, alert, id);
    robotList.push_back(newRobot);
}

void RobotGui::on_pushButton_2_clicked()
{
    bool c=1;
    QString ID = ui->lineEdit->text();
    unsigned int id = ID.toInt(&c,10);
    if(id>=robotList.size()) return;
    QString location='('+QString::number(robotList[id]->getX(),'g',6)+','+QString::number(robotList[id]->getY(),'g',6)+')';
    ui->label_4->setText(location);
    QString speed=QString::number(robotList[id]->getSpeed(),'g',6);
    ui->label_6->setText(speed);
    QString degree=QString::number(robotList[id]->getTheta(),'g',6);
    ui->label_8->setText(degree);
}
