#ifndef MCEINPUTMETHODFILTER_H
#define MCEINPUTMETHODFILTER_H

#include <QObject>
#include <QQuickItem>
#include <QInputMethod>
#include <QtDBus>

class MceInputMethodFilter : public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY(bool showIm READ getShowIm NOTIFY showImChanged)

    bool slider_;

    QInputMethod *method_;

    QDBusInterface mceReq;

signals:
    void showImChanged();

private slots:
    void imVisibleSlot();
    void updateSlider(bool slider);

public:
    MceInputMethodFilter(QInputMethod *method);
    bool getShowIm();

};

#endif // MCEINPUTMETHODFILTER_H
