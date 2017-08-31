#include "gstplayer.h"

GstPlayer::GstPlayer(QWidget *parent) : QGst::Ui::VideoWidget(parent)
{

}

GstPlayer::~GstPlayer() {
    if(m_pipeline) {
        m_pipeline->setState(QGst::StateNull);
        stopPipelineWatch();
    }
}


void GstPlayer::playRTP(int port) {

    m_pipeline = QGst::Pipeline::create();

    QString rtpPipeDescription01 = QString("udpsrc port=\"%1\" ! "
                                "application/x-rtp, encoding-name=JPEG,payload=26 ! "
                                "rtpjpegdepay ! "
                                "jpegdec ! "
                                "xvimagesink").arg(port);

    try {
        m_pipeline = QGst::Parse::launch(rtpPipeDescription01).dynamicCast<QGst::Pipeline>();
    } catch (const QGlib::Error & error) {
        qCritical() << error;
        qFatal("One or more elements are missing");
    }
    watchPipeline(m_pipeline);
    m_pipeline->setState(QGst::StatePlaying);
}

QGst::State GstPlayer::state() const
{
    return m_pipeline ? m_pipeline->currentState() : QGst::StateNull;
}
