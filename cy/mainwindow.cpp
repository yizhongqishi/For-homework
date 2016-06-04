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
    }else{
        erro();
    }
}

void MainWindow::theCircle(double step){
    QRadioButton *ci = qobject_cast<QRadioButton*>(BGC->checkedButton());
}

void MainWindow::erro(){
    QMessageBox::information(this,"错误","请正确选择");
}
