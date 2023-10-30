#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Repair.h"
#include <QCloseEvent>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

//protected:
//    void closeEvent(QCloseEvent *event);

private slots:
    void on_pushButtonCreateRepair_clicked();
    void on_pushButtonDisplayRepair_clicked();
    void on_pushButtonMarkRepairDone_clicked();
    void on_pushButtonDisplayBreakCode_clicked();

private:
    Repair repair;
    std::vector<Repair> repairs;
};

#endif // MAINWINDOW_H

