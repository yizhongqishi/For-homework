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
    BGC = new QButtonGroup(this);
    BGL = new QButtonGroup(this);
    BG->addButton(ui->radioButton);
    BG->addButton(ui->radioButton_5);
    BGC->addButton(ui->radioButton_6);
    BGC->addButton(ui->radioButton_7);
    BGC->addButton(ui->radioButton_8);
    BGL->addButton(ui->radioButton_2);
    BGL->addButton(ui->radioButton_3);
    BGL->addButton(ui->radioButton_4);
    
}

MainWindow::~MainWindow()
{
    delete ui;
    delete BG;
    delete BGL;
    delete BGC;
}

void MainWindow::on_pushButton_clicked()
{
    QRadioButton *pbtn = qobject_cast<QRadioButton*>(BG->checkedButton());
    if (pbtn != 0){
        double step = ui->lineEdit_18->text().toDouble();
        QString name = pbtn->objectName();
        if (QString::compare(name,"radioButton")){
            theLine(step);
        }else{
            theCircle(step);
        }
    }else{
        erro();
    }
}

void MainWindow::on_pushButton_2_clicked()
{

}

void MainWindow::theLine(double step){
    QRadioButton *li = qobject_cast<QRadioButton*>(BGL->checkedButton());
    double Xs,Xe,Ys,Ye;
    Qlist<double> listx,listy;
    if (li != 0){
        QString name = li->objectName();
        if (QString::compare(name,"radioButton_2")){
           Xs = ui->lineEdit_21->text().toDouble();
           Xe = ui->lineEdit_22->text().toDouble();
           Ys = ui->lineEdit_19->text().toDouble();
           Ye = ui->lineEdit_20->text().toDouble();
        }else if (QString::compare(name,"radioButton_3")){
            double K = ui->lineEdit_13->text().toDouble();
            double B = ui->lineEdit_12->text().toDouble();
            double L = ui->lineEdit_14->text().toDouble();
            Xs = 0;
            Ys = B;
            Xe = L / sqrt(K * K + 1);
            Ye = K * Xe + B;
        }else{
           double K = ui->lineEdit_24->text().toDouble();
           Xe = ui->lineEdit_25->text().toDouble();
           Ye = ui->lineEdit_26->text().toDouble();
           Xs = 0;
           Ys = Ye - K * Xe;
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
        //画图

    }else{
        erro();
    }
}

void MainWindow::theCircle(double step){
    QRadioButton *ci = qobject_cast<QRadioButton*>(BGC->checkedButton());
    if (ci != 0){
        QString name = li->objectName();
        double R,Alpha,Cx,Cy,pi;
        Alpha = 0;
        pi = 3.1416;
        double theta = ui->lineEdit_3->text().toDouble();
        double deltaTheta = ui->lineEdit_23->text().toDouble();
        if (QString::compare(name,"radioButton_6")){
            Cx = ui->lineEdit->text().toDouble();
            Cy = ui->lineEdit_5->text().toDouble();
            R = ui->lineEdit_2->text().toDouble();
        }else if (QString::compare(name,"radioButton_7")){
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
        }else {
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
    }else {
        erro();
    }
}

void MainWindow::erro(){
    QMessageBox::information(this,"错误","请正确选择");
}
