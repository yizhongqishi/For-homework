#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <qmath.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    BG = new QButtonGroup(this);
    BGG = new QButtonGroup(this);
    BG->addButton(ui->radioButton);
    BG->addButton(ui->radioButton_5);
    /*BGC->addButton(ui->radioButton_6);
    BGC->addButton(ui->radioButton_7);
    BGC->addButton(ui->radioButton_8);
    BGL->addButton(ui->radioButton_2);
    BGL->addButton(ui->radioButton_3);
    BGL->addButton(ui->radioButton_4);*/
    BGG->addButton(ui->radioButton_6);
    BGG->addButton(ui->radioButton_7);
    BGG->addButton(ui->radioButton_8);
    BGG->addButton(ui->radioButton_2);
    BGG->addButton(ui->radioButton_3);
    BGG->addButton(ui->radioButton_4);


}

MainWindow::~MainWindow()
{
    delete ui;
    delete BG;
    delete BGG;
}

void MainWindow::on_pushButton_clicked()
{
    QRadioButton *pbtn = qobject_cast<QRadioButton*>(BG->checkedButton());
    if (pbtn != 0){
        if (ui->lineEdit_18->text().isEmpty()) {
            erro(QString::fromLocal8Bit("请输入代码迭代步数"));
            return ;
        }
        double step = ui->lineEdit_18->text().toDouble();
        QString name = pbtn->objectName();
        if (QString::compare(name, "radioButton") == 0){
            theLine(step);
        }else{
            theCircle(step);
        }
    }else{
        erro(QString::fromLocal8Bit("请选择绘制的是直线还是圆"));
    }
}

void MainWindow::on_pushButton_2_clicked()
{

    ui->radioButton_2->clearFocus();
    ui->radioButton_6->setChecked(false);
    ui->lineEdit_18->clear();
}

void MainWindow::theLine(double step){
    QRadioButton *li = qobject_cast<QRadioButton*>(BGG->checkedButton());
    double Xs,Xe,Ys,Ye;
    QList<double> listx,listy;
    if (li != 0){
        QString name = li->objectName();
        if (QString::compare(name,"radioButton_2") == 0){
            if (ui->lineEdit_21->text().isEmpty()
                ||ui->lineEdit_22->text().isEmpty()
                ||ui->lineEdit_19->text().isEmpty()
                ||ui->lineEdit_20->text().isEmpty()){
                errotext();
                return;
            }
           Xs = ui->lineEdit_21->text().toDouble();
           Xe = ui->lineEdit_22->text().toDouble();
           Ys = ui->lineEdit_19->text().toDouble();
           Ye = ui->lineEdit_20->text().toDouble();
        }else if (QString::compare(name,"radioButton_3") == 0){
            if (ui->lineEdit_13->text().isEmpty()
                ||ui->lineEdit_12->text().isEmpty()
                ||ui->lineEdit_14->text().isEmpty()){
                errotext();
                return;
            }
            double K = ui->lineEdit_13->text().toDouble();
            double B = ui->lineEdit_12->text().toDouble();
            double L = ui->lineEdit_14->text().toDouble();
            Xs = 0;
            Ys = B;
            Xe = L / sqrt(K * K + 1);
            Ye = K * Xe + B;
        }else if (QString::compare(name,"radioButton_4") == 0){
            if (ui->lineEdit_24->text().isEmpty()
                ||ui->lineEdit_25->text().isEmpty()
                ||ui->lineEdit_26->text().isEmpty()){
                errotext();
                return;
            }
           double K = ui->lineEdit_24->text().toDouble();
           Xe = ui->lineEdit_25->text().toDouble();
           Ye = ui->lineEdit_26->text().toDouble();
           Xs = 0;
           Ys = Ye - K * Xe;
        }else {
            erro(QString::fromLocal8Bit("请选择一种画直线的方式"));
            return;
        }
        double Xre,Yre,Xrs,Yrs;
        Xrs = Yrs = 0;
        Xre = Xe - Xs;
        Yre = Ye - Ys;
        double Tstep = (qAbs(Xre) + qAbs(Yre)) / step;
        double Fs;
        int count = 0;
        while (count < Tstep){
            Fs = (qAbs(Xre)  * qAbs(Yrs) - qAbs(Xrs) * qAbs(Yre));
            if (Fs >= 0){
                if (Xre >= 0) Xrs += step;
                else Xrs -= step;
            }else {
                if (Yre >= 0) Yrs += step;
                else Yrs -= step;
            }
            listx << Xrs;
            listy << Yrs;
            count++;
        }
        print(listx,listy,Xs,Ys,1);//画图
    }else {
        erro(QString::fromLocal8Bit("请选择一种画直线的方式"));
        return;
    }
}

void MainWindow::theCircle(double step){
    QRadioButton *ci = qobject_cast<QRadioButton*>(BGG->checkedButton());
    QList<double> listx,listy;

    if (ci != 0){
        QString name = ci->objectName();
        double R,Alpha,Cx,Cy,pi;
        Alpha = 0;
        pi = 3.1416;
        if (ui->lineEdit_3->text().isEmpty()){
            errotext();
            return;
        }
        double theta = ui->lineEdit_3->text().toDouble();
        double deltaTheta = ui->lineEdit_23->text().toDouble();
        if (QString::compare(name,"radioButton_6") == 0){
            if (ui->lineEdit->text().isEmpty()
                ||ui->lineEdit_5->text().isEmpty()
                ||ui->lineEdit_2->text().isEmpty()){
                errotext();
                return;
            }
            Cx = ui->lineEdit->text().toDouble();
            Cy = ui->lineEdit_5->text().toDouble();
            R = ui->lineEdit_2->text().toDouble();
        }else if (QString::compare(name,"radioButton_7") == 0){
            if (ui->lineEdit_7->text().isEmpty()
                ||ui->lineEdit_6->text().isEmpty()
                ||ui->lineEdit_8->text().isEmpty()
                ||ui->lineEdit_10->text().isEmpty()
                ||ui->lineEdit_11->text().isEmpty()
                ||ui->lineEdit_9->text().isEmpty()){
                errotext();
                return;
            }
            double x1 = ui->lineEdit_7->text().toDouble();
            double x2 = ui->lineEdit_6->text().toDouble();
            double x3 = ui->lineEdit_8->text().toDouble();
            double y1 = ui->lineEdit_10->text().toDouble();
            double y2 = ui->lineEdit_11->text().toDouble();
            double y3 = ui->lineEdit_9->text().toDouble();
            double a = 2 * (x2 - x1);
            double b = 2 * (y2 - y1);
            double c = x2 * x2 + y2 * y2 - x1 * x1 - y1 * y1;
            double d = 2 * (x3 - x2);
            double e = 2 * (y3 - y2);
            double f = x3 * x3 + y3 * y3 - x2 * x2 - y2 * y2;
            Cx = (b * f - e * c) / (b * d - e * a);
            Cy = (d * c - a * f) / (b * d - e * a);
            R = (Cx - x1) * (Cx - x1) + (Cy - y1) * (Cy - y1);
            R = sqrt(R);
        }else if (QString::compare(name,"radioButton_8") == 0){
            if (ui->lineEdit_27->text().isEmpty()
                ||ui->lineEdit_29->text().isEmpty()
                ||ui->lineEdit_28->text().isEmpty()
                ||ui->lineEdit_16->text().isEmpty()
                ||ui->lineEdit_17->text().isEmpty()
                ||ui->lineEdit_15->text().isEmpty()){
                errotext();
                return;
            }
            double x1 = ui->lineEdit_27->text().toDouble();
            double x2 = ui->lineEdit_29->text().toDouble();
            Cx = ui->lineEdit_28->text().toDouble();
            double y1 = ui->lineEdit_16->text().toDouble();
            double y2 = ui->lineEdit_17->text().toDouble();
            Cy = ui->lineEdit_15->text().toDouble();
            double K = (x1 - x2) / (y1 - y2);
            double B = y1 - K * x1;
            double D = qAbs(K * Cx - Cy + B);
            R = D / (sqrt(K * K + 1));
        }else {
            erro(QString::fromLocal8Bit("请选择一种画圆的方式"));
            return;
        }
        while (theta >= 360) theta -= 360;
        theta = pi * theta / (double)180;
        if (deltaTheta < 0){
            double D = qAbs(deltaTheta);
            while (D >= 360) D -= 360;
            deltaTheta = (double)(0 - pi) * D / (double)180;
        }else{
            while (deltaTheta >= 360) deltaTheta -= 360;
            deltaTheta = pi * deltaTheta / (double)180;
        }
        double X1,Y1,X2,Y2,yCurval,xCurval;
        X1 = R * cos(theta);
        Y1 = R * sin(theta);
        X2 = R * cos(theta + deltaTheta);
        Y2 = R * sin(theta + deltaTheta);
        xCurval = X1;
        yCurval = Y1;
        while (qAbs(Alpha) < qAbs(deltaTheta)){
            double a = atan(yCurval / xCurval);
            double devVal = xCurval * xCurval + yCurval * yCurval - R * R;
            if (deltaTheta >= 0){
                double nDir = -1;
                if (xCurval >=0 && yCurval >= 0) nDir = 1;
                else if (xCurval <= 0 && yCurval >= 0) nDir =2;
                else if (xCurval <= 0 && yCurval <= 0) nDir =3;
                else nDir = 4;
                if (nDir == 1){
                    if (devVal >= 0) xCurval -= step;
                    else yCurval += step;
                }else if (nDir == 2){
                    if (devVal >= 0) yCurval -= step;
                    else xCurval -= step;
                }else if (nDir == 3){
                    if (devVal >= 0) xCurval += step;
                    else yCurval -= step;
                }else {
                    if (devVal >= 0) yCurval += step;
                    else xCurval += step;
                }
                listx << xCurval;
                listy << yCurval;
             }
            double b = atan(qAbs(yCurval) / qAbs(xCurval));
           double alphaStep = qAbs(b) - qAbs(a);
           Alpha += qAbs(alphaStep);
           }
            print(listx,listy,Cx,Cy,2);//画图
    }else {
        erro(QString::fromLocal8Bit("请选择一种画圆的方式"));
        return;
    }
}

void MainWindow::erro(QString errmsg){
    QMessageBox::information(this, QString::fromLocal8Bit("错误！"), errmsg);
}

void MainWindow::errotext(){
    QMessageBox::information(this, QString::fromLocal8Bit("错误！"), QString::fromLocal8Bit("请填写数据"));
}

void MainWindow::print(QList<double> listx ,QList<double> listy,double x,double y,int flag){
    if (flag == 1){
        ui->widget->setPoints1(listx,listy, x,y);
    }else {
        ui->widget->setPoints(listx,listy, x,y);
    }
    ui->widget->update();

}
