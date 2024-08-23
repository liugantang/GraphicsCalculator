//
// Created by liugantang on 24-8-23.
//

#ifndef GRAPHICCALCULATOR_DRAWPANEL_H
#define GRAPHICCALCULATOR_DRAWPANEL_H

#include <QtWidgets>
class DrawPanelPrivate;
class DrawPanel: public QWidget{
    Q_OBJECT
public:
    DrawPanel(QWidget* parent = nullptr);
    ~DrawPanel();

private:
    void init();

    std::unique_ptr<DrawPanelPrivate> d;
};


#endif //GRAPHICCALCULATOR_DRAWPANEL_H
