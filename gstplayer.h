#ifndef GSTPLAYER_H
#define GSTPLAYER_H

#include <Qt5GStreamer/QGst/Pipeline>
#include <Qt5GStreamer/QGst/Ui/VideoWidget>
#include <Qt5GStreamer/QGst/Element>
#include <Qt5GStreamer/QGst/ElementFactory>
#include <Qt5GStreamer/QGst/Parse>

class GstPlayer : public QGst::Ui::VideoWidget
{
    Q_OBJECT
public:
    GstPlayer(QWidget *parent = 0);

    ~GstPlayer();

    QGst::State state() const;

    void playRTP(int port);
private:
    QGst::PipelinePtr m_pipeline;



};

#endif // GSTPLAYER_H
