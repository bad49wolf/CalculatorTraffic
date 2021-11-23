#include "trafficlight.h"
#include <QWidget>
#include <QLayout>
#include <QRadioButton>

TrafficLight::TrafficLight(QWidget * parent): QWidget(parent){

    //Creatign the widgets
    createWidgets();

    //place Widgets
    placeWidgets();
    startTimer(10);
}

void TrafficLight::createWidgets()
{

  redlight = new QRadioButton;
  redlight->setEnabled(false);
  redlight->toggle();
  redlight->setStyleSheet("QRadioButton::indicator:checked { background-color: red;}");

  yellowlight = new QRadioButton;
  yellowlight->setEnabled(false);
  yellowlight->setStyleSheet("QRadioButton::indicator:checked { background-color: yellow;}");

  greenlight = new QRadioButton;
  greenlight->setEnabled(false);
  greenlight->setStyleSheet("QRadioButton::indicator:checked { background-color: green;}");
  LCDs = new QLCDNumber();
   LCDm = new QLCDNumber();
    LCDh = new QLCDNumber();
    LCDxs = new QLCDNumber();


}


void TrafficLight::placeWidgets()
{

  // Placing the widgets
  auto layout = new QVBoxLayout;
  auto layout1 = new QHBoxLayout;
  layout->addWidget(redlight);

  layout->addWidget(yellowlight);
  layout->addWidget(greenlight);
  layout->addLayout(layout1);
  layout1->addWidget(LCDs);
  layout1->addWidget(LCDm);
  layout1->addWidget(LCDh);
  layout1->addWidget(LCDxs);
  setLayout(layout);
}
void TrafficLight::timerEvent(QTimerEvent *e) {


    switch (xd) {
        case 0:
        redlight->toggle();
        break;
    case 4:
         greenlight->toggle();

        break;
    case 6:

           yellowlight->toggle();

        break;

    }
    xd = i % 7;
    i++;
    hi++;

setIt(h, m, s, xs,hi);
LCDs->display(s);
LCDm->display(m);
LCDh->display(h);
LCDxs->display(xs);





}
void TrafficLight::keyPressEvent(QKeyEvent *e) {
    if (e->key() == Qt::Key_Escape)
        qApp->exit();
    if (e->key() == Qt::Key_R)
        xd=0;
    if (e->key() == Qt::Key_Y)
       xd=4;
    if (e->key() == Qt::Key_G)
      xd=6;
}
void TrafficLight:: setIt(int &h, int &m, int &s, int &xs,int hi) {
    h=hi/360000;
    m=(hi-h*360000)/6000;
    s=(hi-((hi-h*360000)/6000)*6000)/100;
    xs= hi - (((hi-((hi-h*360000)/6000)*6000)/100)*100);
}
