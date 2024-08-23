//
// Created by liugantang on 24-8-23.
//

#include "DrawPanel.h"
#include "DrawPanelPrivate.h"

DrawPanelPrivate::DrawPanelPrivate(DrawPanel *parent):parentPtr(parent) {

}

DrawPanelPrivate::~DrawPanelPrivate() {

}


DrawPanel::DrawPanel(QWidget *parent):QWidget(parent),d(new DrawPanelPrivate(this)) {
    init();
}

DrawPanel::~DrawPanel(){

}

void DrawPanel::init() {
    d->chart = new QChart();
    auto series = new QLineSeries(this);
    //![1]

    //![2]
    series->append(-1,-1);
    series->append(0, 6);
    series->append(2, 4);
    series->append(3, 8);
    series->append(7, 4);
    series->append(10, 5);
    *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);
    d->chart->addSeries(series);
    QValueAxis * axisX = new QValueAxis(this);
    axisX->setRange(-50,50);
    d->chart->addAxis(axisX, Qt::AlignBottom);
    QValueAxis * axisY = new QValueAxis(this);
    axisY->setRange(-50,50);
    d->chart->addAxis(axisY, Qt::AlignLeft);
    d->chart->legend()->hide();
    d->chart->setTitle("Line Chart");
    series->attachAxis(axisX);
    series->attachAxis(axisY);

    d->chartView = new QChartView(d->chart, this);
    d->chartView->setRenderHint(QPainter::Antialiasing);
    QVBoxLayout* vLayout = new QVBoxLayout(this);
    vLayout->setContentsMargins(2,2,2,2);
    vLayout->addWidget(d->chartView);
}

