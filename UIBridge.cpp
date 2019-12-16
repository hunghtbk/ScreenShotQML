#include "UIBridge.h"
#include <QDebug>
#include <QImage>
#include <QQuickWindow>
#include <QDateTime>

UIBridge::UIBridge(QQmlApplicationEngine *view)
{
    m_view = view;
}

void UIBridge::captureScreen()
{
    qDebug() << "Call me from QML: Start ScreenShot";
    QQuickWindow *_rootObject = qobject_cast<QQuickWindow *>(m_view->rootObjects().at(0));
    if (_rootObject) {
        QImage _image = _rootObject->grabWindow();
        QFile _file("capture_screen/Screenshot_" + QDateTime::currentDateTime().toString("yyyy_MM_dd_HH_mm_ss_zzz") + ".png");
        _file.open(QIODevice::WriteOnly);
        if (_file.isOpen()) {
            _image.save(&_file, "PNG");
        }
    }
}

QString UIBridge::buttonName()
{
    return "Screen shot";
}
