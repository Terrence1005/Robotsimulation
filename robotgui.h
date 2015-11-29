#ifndef ROBOTGUI_H
#define ROBOTGUI_H
#include "datalayer.hh"
#include <QDialog>
#include <QtGui>
#include <QtCore>
#include <QWidget>

namespace Ui {
class RobotGui;
}

class RobotGui : public QDialog
{
    Q_OBJECT

public:
    explicit RobotGui(QWidget *parent = 0);
    ~RobotGui();

private:
    Ui::RobotGui *ui;
protected:
    void paintEvent(QPaintEvent *);
private slots:
    void on_pushButton_clicked();
};

#endif // ROBOTGUI_H
