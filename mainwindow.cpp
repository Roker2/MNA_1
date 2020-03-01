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

double FirstFunction(double x)
{
    return (1 / x) - 2;
}

double FirstDerivative(double x)
{
    return - 1 / (x * x);
}

double SecondDerivative(double x)
{
    return 2 / (x * x * x);
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
    ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    //Draw graphic
    ui->widget->replot();
    i = 1;
    double  x_new = StartX, x_old;
    do
    {
        x_old = x_new;
        double temp1, temp2, a = SecondDerivative(x_old) / 2,
                b = FirstDerivative(x_old) - x_old * SecondDerivative(x_old) / 4,
                c = FirstFunction(x_old) - x_old * FirstDerivative(x_old) + x_old * x_old * SecondDerivative(x_old) / 2;
        int mode = QuadraticEquation(a, b, c, &temp1, &temp2);
        switch (mode) {
        case (0):
            if (AbsDifference(x_old, temp1) >= AbsDifference(x_old, temp2))
                x_new = temp2;
            else
                x_new = temp1;
            break;
        case (1):
            x_new = temp1;
            break;
        case (-1):
            ui->lineEditAnswer->setText(QString::number(x_new));
            return;
            break;
        }
        ui->widget->addGraph();
        ui->widget->graph(i)->setPen(QPen(Qt::red));
        QVector<double> x_(1), y_(1);
        x_[0] = x_new;
        y_[0] = Function(x_new);
        ui->widget->graph(i)->setData(x_, y_);
        ui->widget->graph(i)->setLineStyle(QCPGraph::lsImpulse);
        ui->widget->replot();
        i++;
    }
    while (AbsDifference(x_new, x_old) > 0.01);
    //while (i < 1000);
    ui->lineEditAnswer->setText(QString::number(x_new));
}
