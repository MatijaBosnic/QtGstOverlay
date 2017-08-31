#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

#define overlayImage "Pictures/CameraOverlay.png"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->widget->playRTP(50004);
    ui->label->setWindowOpacity(0);

    player2 = new GstPlayer(this);
    QGridLayout *grLayout = new QGridLayout(this);
    ui->frame->setLayout(grLayout);
    ui->frame->layout()->addWidget(player2);

    player2->playRTP(50004);
//    doMagic();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::doMagic() {


    QStackedLayout *stackedLayout = new QStackedLayout(ui->centralWidget);
    ui->centralWidget->setLayout(stackedLayout);
    stackedLayout->setStackingMode(QStackedLayout::StackAll);


    pictureOverlayGraphicsView = new QGraphicsView(ui->centralWidget);
    pictureOverlayGraphicsView->resize(ui->widget->width(), ui->widget->height());
    pictureOverlayScene = new QGraphicsScene(this);
    pictureOverlayScene->setBackgroundBrush(Qt::transparent);
    ui->centralWidget->layout()->addWidget(pictureOverlayGraphicsView);
    pictureOverlayGraphicsView->setScene(pictureOverlayScene);
    pictureOverlayGraphicsView->setStyleSheet("background: transparent");
    pictureOverlayScene->addPixmap(overlayPicturePixmap);
    overlayPicturePixmap = QPixmap(pictureOverlayGraphicsView->width(),
                                   pictureOverlayGraphicsView->height());
    overlayPicturePixmap.fill(Qt::transparent);
    QPainter painter(&overlayPicturePixmap);
    QPixmap overlayPicture(overlayImage);
    painter.setOpacity(1);
    painter.drawPixmap(0,0, overlayPicturePixmap.width(),
                       overlayPicturePixmap.height(),
                       overlayPicture);
    pictureOverlayScene->clear();
    pictureOverlayScene->addPixmap(overlayPicturePixmap.scaled(pictureOverlayGraphicsView->width(),
                                                               pictureOverlayGraphicsView->height(),
                                                               Qt::IgnoreAspectRatio));
}
