#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <qmath.h>
#include <QSurfaceDataProxy>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //[1] init for Q3DSurface type datavisualization
    Q3DSurface *graph = new Q3DSurface();

    //[2] using QWidget for container of graphic
    QWidget *container = QWidget::createWindowContainer(graph);

    //[3] put widget container into mainwindow central layout
    setCentralWidget(container);

//    graph->setAxisX(new QValue3DAxis);
//    graph->setAxisY(new QValue3DAxis);
//    graph->setAxisZ(new QValue3DAxis);

    //[4] init data proxy and series for data collect to proceed
    QSurfaceDataProxy *proxyseri1= new QSurfaceDataProxy();
    QSurface3DSeries * seri1= new QSurface3DSeries(proxyseri1);
//    QSurfaceDataProxy *proxyseri2= new QSurfaceDataProxy();
//    QSurface3DSeries * seri2= new QSurface3DSeries(proxyseri2);

    //[5] init vector data for graphic, and setup how many data will show
    QSurfaceDataArray *arr1 = new QSurfaceDataArray;
    arr1->reserve(9);

//    QSurfaceDataArray *arr2 = new QSurfaceDataArray;
//    arr2->reserve(2);


    //[6] create data simulation using hanning window formula
    for (int k=0;k<3 ;k++ ) {

        for (int j=0; j< 3; j++)
        {
            float z= 1+k;
            z += (j-1) *0.01;
            QSurfaceDataRow *row1 = new QSurfaceDataRow;
            row1->resize(20);

            int index =0;
            for (int i =0; i< 20; i++)
            {
                float x= i;float y=0.0;
                if((j-1)==0){

                    y= (0.5 +(k*0.2) ) * (1.0 - qCos(2.0 * M_PI * i/19.0));
                }
                else {
                    y=0.0;
                }

                (*row1)[index++].setPosition(QVector3D(x,y,z));
                qDebug("isi x,y,z = (%f,%f,%f)", x,y,z);
            }
        //    qDebug()<< arr1->size() << row1->size();
            arr1->append(row1);
        }
    }


//    float zz= 2;
//    for (int j=0; j< 2; j++)
//    {
//        zz += j*0.01;
//        QSurfaceDataRow *row2 = new QSurfaceDataRow;
//        row2->resize(20);

//        int index =0;
//        for (int i =0; i< 20; i++)
//        {
//            float x= i;
//            float y= 0.6 * (1.0 - qCos(2.0 * M_PI * i/19.0));
//            y *=1.2;

//            (*row2)[index++].setPosition(QVector3D(x,y,zz));
////            qDebug("isi x,y,zz = (%f,%f,%f)", x,y,zz);
//        }
//    //    qDebug()<< arr1->size() << row1->size();
//        arr2->append(row2);
//    }

    //[7] put data into series using data proxy
    seri1->dataProxy()->resetArray(arr1);
//    seri2->dataProxy()->resetArray(arr2);

    //[8] set type f;lag for data drawn in plot
    seri1->setDrawMode(QSurface3DSeries::DrawSurface);
//    seri2->setDrawMode(QSurface3DSeries::DrawWireframe);
    seri1->setFlatShadingEnabled(true);

    //[9] put data series into plot
    graph->addSeries(seri1);
//    graph->addSeries(seri2);

    //[10] adding color gradient for visualization of graphics
    graph->axisX()->setTitle(QStringLiteral("sumbu X") );
    graph->axisY()->setTitle(QStringLiteral("sumbu Y") );
    graph->axisZ()->setTitle(QStringLiteral("sumbu Z") );
    graph->axisX()->setTitleVisible(true);
    graph->axisY()->setTitleVisible(true);
    graph->axisZ()->setTitleVisible(true);

    QLinearGradient gr;
    gr.setColorAt(0.0, Qt::black);
    gr.setColorAt(0.33, Qt::blue);
    gr.setColorAt(0.67, Qt::red);
    gr.setColorAt(1.0, Qt::yellow);


    qDebug()<< "3dgraph serieslist size:" <<graph->seriesList().size();

    graph->seriesList().at(0)->setBaseGradient(gr);
    graph->seriesList().at(0)->setColorStyle(Q3DTheme::ColorStyleRangeGradient);
//    graph->seriesList().at(0)->setColorStyle(Q3DTheme::  ::ColorStyleRangeGradient);


}

MainWindow::~MainWindow()
{
    delete ui;
}

