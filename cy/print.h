#ifndef PRINT_H
#define PRINT_H

#include <QWidget>

class Print : public QWidget
{
    Q_OBJECT
public:
    explicit Print(QWidget *parent = 0);
    void setPoints(QList<double>, QList<double>, double, double);
    void setPoints1(QList<double>, QList<double>, double, double);

protected:
    void paintEvent(QPaintEvent* events);

    QVector<QPointF> points;
    double Cx;
    double Cy;

    void fortest();
signals:
public slots:
};

#endif // PRINT_H
