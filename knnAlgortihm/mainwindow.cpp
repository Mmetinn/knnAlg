#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    renk = qRgb(255,255,255);
    QImage ortam(1200,450,QImage::Format_RGB32);
    ui->label->setPixmap(QPixmap::fromImage(ortam));
    res = ortam;
    showMaximized();
    yazdir();
}

MainWindow::~MainWindow()
{
    delete ui;
}

double MainWindow::classifyAPoint(Point arr[100], int n, int k, Point p)
{
    for (int i = 0; i < n; i++)
            arr[i].distance =
                sqrt((arr[i].a - p.a) * (arr[i].a - p.a) +
                     (arr[i].b - p.b) * (arr[i].b - p.b) +
                     (arr[i].c - p.c) * (arr[i].c - p.c) +
                     (arr[i].d - p.d) * (arr[i].d - p.d));

        // Sort the Points by distance from p
        qSort(arr, arr+n,comparison);

        // Now consider the first k elements and only
        // two groups
        int freq1 = 0;     // Frequency of group 0
        int freq2 = 0;     // Frequency of group 1
        int freq3= 0;     // Frequency of group 1

        for (int i = 0; i < k; i++)
        {
            if (arr[i].val == 0)
                freq1++;
            else if (arr[i].val == 1)
                freq2++;
            else if (arr[i].val == 2)
                freq3++;
        }
        if(freq1>freq2 && freq1>freq3){
            return (0) ;
        }else if(freq2>freq1 && freq2>freq3){
            return (1) ;
        }else{
            return (2);
        }


}

bool MainWindow::comparison(MainWindow::Point a, MainWindow::Point b)
{
    return (a.distance < b.distance);

}

void MainWindow::nodeCiz(QRgb node_renk)
{
    double a = 3;
    while(a>0){
        double x, y;
        double aci = 0.0;
        while(aci <= 360) {
            x = cos(qDegreesToRadians(aci)) * a;
            y = sin(qDegreesToRadians(aci)) * a;
            simetriBul(x, y,node_renk);
            //res.setPixel(round(x), round(y), renk);
            aci += 1;

        }
        a--;
    }
    ui->label->setPixmap(QPixmap::fromImage(res));
}

void MainWindow::simetriBul(int X, int Y , QRgb node_renk)
{

    res.setPixel(Nokta.x() + X, Nokta.y() + Y, node_renk);
    res.setPixel(Nokta.x() + Y, Nokta.y() + X, node_renk);
    res.setPixel(Nokta.x() - Y, Nokta.y() + X, node_renk);
    res.setPixel(Nokta.x() - X, Nokta.y() + Y, node_renk);
    res.setPixel(Nokta.x() - X, Nokta.y() - Y, node_renk);
    res.setPixel(Nokta.x() - Y, Nokta.y() - X, node_renk);
    res.setPixel(Nokta.x() + Y, Nokta.y() - X, node_renk);
    res.setPixel(Nokta.x() + X, Nokta.y() - Y, node_renk);

}

void MainWindow::yazdir()
{
    QFile file("/home/mmetin/Desktop/data");

       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
           return;

       QTextStream in(&file);
       while (!in.atEnd()) {
           QString line = in.readLine();
           listem.push_back(line);
       }
       for (int i = 0; i < listem.size(); ++i) {
           QStringList l= listem.at(i).split(",");
           arr[i].a=l.at(0).toDouble();
           arr[i].b=l.at(1).toDouble();
           arr[i].c=l.at(2).toDouble();
           arr[i].d=l.at(3).toDouble();
           QPoint a ;

           if(l.at(4)=="Iris-setosa"){
               Nokta.setX(l.at(2).toDouble()*100);
               Nokta.setY(l.at(3).toDouble()*100);
               renk_ = qRgb(255, 0, 0);
               nodeCiz(renk_);
                arr[i].val=0;
           }else if(l.at(4)=="Iris-versicolor"){
               Nokta.setX(l.at(2).toDouble()*100);
               Nokta.setY(l.at(3).toDouble()*100);
               renk_ = qRgb(255, 255, 0);
               nodeCiz(renk_);
               arr[i].val=1;
          }else if(l.at(4)=="Iris-virginica"){
               Nokta.setX(l.at(2).toDouble()*100);
               Nokta.setY(l.at(3).toDouble()*100);
               renk_ = qRgb(255,255,255);
               nodeCiz(renk_);
               arr[i].val=2;
          }
       }
       for (int i = 0; i < listem.size(); ++i) {
           ui->tableWidget->insertRow (ui->tableWidget->rowCount());
           ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(arr[i].a)));
           ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(arr[i].b)));
           ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(arr[i].c)));
           ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(arr[i].d)));
           ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(arr[i].val)));
       }
    file.close();



    /*Testing Point*/
    QFile file2("/home/mmetin/Desktop/testdata");

       if (!file2.open(QIODevice::ReadOnly | QIODevice::Text))
           return;
        QList<QString> listem2;
       QTextStream in2(&file2);
       while (!in2.atEnd()) {
           QString line2 = in2.readLine();
           listem2.push_back(line2);
       }

       for (int i = 0; i < listem2.size(); ++i) {
           QStringList l2= listem2.at(i).split(",");
           test[i].a=l2.at(0).toDouble();
           test[i].b=l2.at(1).toDouble();
           test[i].c=l2.at(2).toDouble();
           test[i].d=l2.at(3).toDouble();
           if(l2.at(4)=="Iris-setosa"){
               sonuc[i]=0;
           }else if(l2.at(4)=="Iris-versicolor"){
               sonuc[i]=1;
           }else if(l2.at(4)=="Iris-virginica"){
               sonuc[i]=2;
           }
           Nokta.setX(l2.at(2).toDouble()*100);
           Nokta.setY(l2.at(3).toDouble()*100);
           renk_ = qRgb(0, 0, 255);
           nodeCiz(renk_);
           donen_degerler.push_back(classifyAPoint(arr, n, k, test[i]));

       }
       ;
       for (int i = 0; i < 50; ++i) {
           ui->tableWidget_2->insertRow (ui->tableWidget_2->rowCount());
           ui->tableWidget_2->setItem(i,0,new QTableWidgetItem(QString::number(test[i].a)));
           ui->tableWidget_2->setItem(i,1,new QTableWidgetItem(QString::number(test[i].b)));
           ui->tableWidget_2->setItem(i,2,new QTableWidgetItem(QString::number(test[i].c)));
           ui->tableWidget_2->setItem(i,3,new QTableWidgetItem(QString::number(test[i].d)));
           ui->tableWidget_2->setItem(i,4,new QTableWidgetItem("-"));
       }
       file2.close();
}

void MainWindow::on_pushButton_clicked()
{
        QString a;
        int yuzdeSayac=0;
        for (int i = 0; i < donen_degerler.size(); ++i) {
            ui->tableWidget_3->insertRow (ui->tableWidget_3->rowCount());
            ui->tableWidget_3->setItem(i,0,new QTableWidgetItem(QString::number(test[i].a)));
            ui->tableWidget_3->setItem(i,1,new QTableWidgetItem(QString::number(test[i].b)));
            ui->tableWidget_3->setItem(i,2,new QTableWidgetItem(QString::number(test[i].c)));
            ui->tableWidget_3->setItem(i,3,new QTableWidgetItem(QString::number(test[i].d)));
            QString clasim;
            if(donen_degerler.at(i)==0){
               clasim="Iris-setosa";
            }else  if(donen_degerler.at(i)==1){
                clasim="Iris-versicolor";
            }else if(donen_degerler.at(i)==2){
                 clasim="Iris-virginica";
            }
            ui->tableWidget_3->setItem(i,4,new QTableWidgetItem(clasim));
            if(sonuc[i]==donen_degerler.at(i)){
                yuzdeSayac++;
            }

        }
        int yuzde=(yuzdeSayac*100)/50;
        QMessageBox::information(this,"SONUC!!","%"+QString::number(yuzde)+" başarılı.","tamam");

}
