//
// Created by liugantang on 24-8-23.
//

#ifndef GRAPHICCALCULATOR_MAINWINDOWPRIVATE_H
#define GRAPHICCALCULATOR_MAINWINDOWPRIVATE_H
class MainWindow;
class DrawPanel;
class MainWindowPrivate{
public:
    MainWindowPrivate(MainWindow* p);
    ~MainWindowPrivate();

    MainWindow* parentPtr = nullptr;
    DrawPanel* drawPanel;
};
#endif //GRAPHICCALCULATOR_MAINWINDOWPRIVATE_H
