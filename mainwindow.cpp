#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "CommonFunctions.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //Declaring a math function
    auto Function = ((1 / CrazyMath::X) - 2);
    double StartX = ui->lineEditStartValue->text().toDouble();
    double a = -StartX;//left
    double b = StartX;//right
    double h = 0.01;//step
    int N = (b - a) / h + 2;//quantity of steps
    QVector<double> x(N), y(N);//coordinates
    int i = 0;
    for (double X = a; X <= b; X += h) {
        x[i] = X;
        y[i] = Function(X);
        i++;
    }
    //clear
    ui->widget->clearGraphs();
    ui->widget->addGraph();
    //Add to our graph data
    ui->widget->graph(0)->setData(x, y);
    //Set labels of Axis
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");
    //Set range of X
    ui->widget->xAxis->setRange(a, b);
    //Set range of Y Axis
    double minY = -5, maxY = 5;
    //MinMaxY(&minY, &maxY, y);
    ui->widget->yAxis->setRange(minY, maxY);
    //ui->widget->graph(0)->setPen(QPen(Qt::red)); // line color red for graph
    //Draw graphic
    ui->widget->replot();
}
