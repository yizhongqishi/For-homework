#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QButtonGroup *BG;
    QButtonGroup *BGL;
    QButtonGroup *BGC;

private slots:
    void on_pushButton_clicked();
    
    void on_pushButton_2_clicked();

    void theLine(double);

    void theCircle(double);

    void erro(QString);

    void print(QList<double>,QList<double>,double,double,int);
    
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
