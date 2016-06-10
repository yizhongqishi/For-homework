#ifndef PRINT_H
#define PRINT_H

#include <QWidget>

class Print : public QWidget
{
    Q_OBJECT
public:
    explicit Print(QWidget *parent = 0);

signals:
protected:
    void paintEvent(QPaintEvent* events);

public slots:
};

#endif // PRINT_H
