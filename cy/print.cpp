#include "print.h"
#include <QPainter>

Print::Print(QWidget *parent) : QWidget(parent)
{
//    fortest();
}

void Print::setPoints(QList<double> vec, QList<double> vec2, double Cx, double Cy) {
    points.clear();
    for (int i = 0; i< vec.length(); ++i) {
        QPoint p(vec[i], vec2[i]);
        points.append(p);
    }
    this->Cx = Cx;
    this->Cy = Cy;
}


void Print::paintEvent(QPaintEvent *events){
    QPainter paint(this);
    //    paint.translate(100.,100.);
    paint.scale(2,2);
    paint.drawPolyline(points);
}

void Print::fortest() {
    QList<double> listx, listy;
    listx.append(10); listy.append(10);
    listx.append(210); listy.append(10);
    listx.append(210); listy.append(230);
    listx.append(10); listy.append(230);
    listx.append(10); listy.append(10);
    setPoints(listx, listy, 0, 0);
    show();
}
