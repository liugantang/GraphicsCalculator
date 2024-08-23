//
// Created by liugantang on 24-8-23.
//

#ifndef GRAPHICCALCULATOR_DRAWPANELPRIVATE_H
#define GRAPHICCALCULATOR_DRAWPANELPRIVATE_H
class DrawPanel;
#include <QtCharts>
class DrawPanelPrivate{
public:
    DrawPanelPrivate(DrawPanel* parent);
    ~DrawPanelPrivate();
    DrawPanel* parentPtr = nullptr;
    QChartView * chartView = nullptr;
    QChart* chart = nullptr;
    QList<QLineSeries> lineSeriesList;
};

#endif //GRAPHICCALCULATOR_DRAWPANELPRIVATE_H
