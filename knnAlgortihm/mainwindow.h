#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qmath.h>
#include <QtAlgorithms>
#include <QFile>
#include <QTextStream>
#include <QStandardPaths>
#include <QDirIterator>
#include <QMessageBox>
#include <QModelIndex>
#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include "qfile.h"
#include "qdir.h"
#include <QDir>
#include <QString>
namespace Ui {




class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


    // Used to sort an array of points by increasing
    // order of distance

public:
    explicit MainWindow(QWidget *parent = 0);   
    ~MainWindow();

    struct Point
    {
        double val;     // Group of point
        double a, b ,c ,d;     // Co-ordinate of point
        double distance; // Distance from test point
    };
    double classifyAPoint(Point arr[100], int n, int k, Point p);
    static bool comparison(Point a, Point b);
    void nodeCiz(QRgb node_renk);
    void simetriBul(int X, int Y,QRgb node_renk);
    QRgb renk,renk_;
    QPoint Nokta;
    QImage res;
    void yazdir();
    QList<QString> listem;
    QList<int> donen_degerler;
    int n = 110; // Number of data points
    Point arr[110];
    Point test[110];
    int k = 10;
    int sonuc[50];

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
