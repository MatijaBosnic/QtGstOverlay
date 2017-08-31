#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <gstplayer.h>
#include <QMainWindow>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimediaWidgets>
#include <Qt5GStreamer/QGst/Pipeline>
#include <Qt5GStreamer/QGst/Element>
#include <Qt5GStreamer/QGst/ElementFactory>
#include <Qt5GStreamer/QGst/Parse>
#include <Qt5GStreamer/QGst/Init>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void doMagic();
    QGraphicsView *pictureOverlayGraphicsView;
    QGraphicsScene *pictureOverlayScene;
    QPixmap overlayPicturePixmap;


    GstPlayer *player2;
};

#endif // MAINWINDOW_H
