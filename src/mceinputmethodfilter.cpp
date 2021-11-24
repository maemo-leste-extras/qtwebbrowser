#include "mceinputmethodfilter.h"
#include <QDebug>

MceInputMethodFilter::MceInputMethodFilter(QInputMethod *method):
    mceReq("com.nokia.mce", "/com/nokia/mce/request", "com.nokia.mce.request", QDBusConnection::systemBus())
{
    method_ = method;

    if(mceReq.isValid())
    {
        QDBusReply<bool> reply = mceReq.call( "get_keyboard_slide" );
        slider_ = reply.isValid()? reply.value() : false;
    }
    else
    {
        slider_ = false;
    }

    QDBusConnection::systemBus().connect(QString(), QString(), "com.nokia.mce.signal", "get_keyboard_slide", this, SLOT(updateSlider(bool)));

    QObject::connect(method_, &QInputMethod::visibleChanged, this, &MceInputMethodFilter::imVisibleSlot);
}

void MceInputMethodFilter::updateSlider(bool slider)
{
    qDebug()<<__func__<<slider_;
    if(slider != slider_)
    {
        slider_ = slider;
        showImChanged();
    }
}

bool MceInputMethodFilter::getShowIm()
{
    qDebug()<<__func__;
    return method_->isVisible() && !slider_;
}

void MceInputMethodFilter::imVisibleSlot()
{
    qDebug()<<__func__;
    showImChanged();
}
