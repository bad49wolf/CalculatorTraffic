#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

#include <QWidget>
#include <QApplication>
#include<QKeyEvent>
#include <QLCDNumber>
class QRadioButton;

class TrafficLight: public QWidget{
  Q_OBJECT

public:

  TrafficLight(QWidget * parent = nullptr);
  void timerEvent(QTimerEvent *e) override;
  void keyPressEvent(QKeyEvent *event) override;


protected:
     void createWidgets();
     void placeWidgets();
     void setIt(int &h, int &m, int &s,int &xs,int hi);

private:

  QRadioButton * redlight;
  QRadioButton * yellowlight;
  QRadioButton * greenlight;
  int i=0;
  int xd=0;
  QLCDNumber *LCDs;
  QLCDNumber *LCDm;
  QLCDNumber *LCDh;
  QLCDNumber *LCDxs;
  int hi=0;
  int s=0;
  int m=0;
  int xs=0;
  int h=0;

};


#endif
