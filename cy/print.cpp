#include "print.h"
#include <QPainter>

Print::Print(QWidget *parent) : QWidget(parent)
{
//    fortest();
}

void Print::setPoints(QList<double> x, QList<double> y, double Cx, double Cy) {
    points.clear();
    //QPoint p(Cx, Cy);
    //points.append(p);
    for (int i = 0; i< x.length(); ++i) {
        x[i] += Cx;
        y[i] += Cy;
        if (i > 1){
            QPoint p(x[i], y[i]);
            points.append(p);
        }
    } 
}

void Print::setPoints1(QList<double> x, QList<double> y, double Xs,double Ys){
    points.clear();
    QPoint p(Xs, Ys);
    for (int i = 0; i < x.length(); i++){
        x[i] += Xs;
        y[i] += Ys;
        if (i > 0){
            QPoint p(x[i],y[i]);
            points.append(p);
        }
    }
}


void Print::paintEvent(QPaintEvent *events){
    QPainter paint(this);
    //    paint.translate(100.,100.);
//    paint.scale(2,2);
    paint.setWindow(QRect(-100,100,200,-200));
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
