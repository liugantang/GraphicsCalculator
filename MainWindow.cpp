//
// Created by liugantang on 24-8-23.
//

#include "MainWindow.h"
#include "MainWindowPrivate.h"
#include "DrawPanel.h"

MainWindowPrivate::MainWindowPrivate(MainWindow *p):parentPtr(p) {

}

MainWindowPrivate::~MainWindowPrivate() {

}

MainWindow::MainWindow(QWidget *parent):
QMainWindow(parent),
d(new MainWindowPrivate(this)) {
    initGui();
}

MainWindow::~MainWindow() {

}

void MainWindow::initGui() {
    resize(1024,720);
    QWidget* mainWidget = new QWidget(this);
    this->setCentralWidget(mainWidget);
    QHBoxLayout * hLayoutMain = new QHBoxLayout(mainWidget);
    hLayoutMain->setContentsMargins(0,0,0,0);
    hLayoutMain->setSpacing(0);
    d->drawPanel = new DrawPanel(mainWidget);
    hLayoutMain->addWidget(d->drawPanel);

}
