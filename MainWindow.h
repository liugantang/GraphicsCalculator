//
// Created by liugantang on 24-8-23.
//

#ifndef GRAPHICCALCULATOR_MAINWINDOW_H
#define GRAPHICCALCULATOR_MAINWINDOW_H

#include <QtWidgets>

class MainWindowPrivate;
class MainWindow:public QMainWindow{
    Q_OBJECT
public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
private:
    void initGui();
    std::unique_ptr<MainWindowPrivate> d;
};


#endif //GRAPHICCALCULATOR_MAINWINDOW_H
