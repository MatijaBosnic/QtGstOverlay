#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

#define overlayImage "Pictures/CameraOverlay.png"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qgstPlayer = new GstPlayer(this);
    qgstPlayer->resize(600, 600);
    qgstPlayer->move(100, 100);
    qgstPlayer->playRTP(50004);

    overlayLabel = new QLabel(this);
    QPixmap image(overlayImage);
    overlayLabel->setPixmap(image);
    overlayLabel->setScaledContents(true);
    overlayLabel->resize(400, 400);
    overlayLabel->setStyleSheet("background: transparent");
}

MainWindow::~MainWindow()
{
    delete ui;
}
