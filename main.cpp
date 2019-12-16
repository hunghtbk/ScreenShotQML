#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "UIBridge.h"
#include <QQuickView>
#include <QDebug>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QQmlContext *ctx = engine.rootContext();
//    QQuickView view(&engine, 0);
//    engine.root

    UIBridge *_uibridge = new UIBridge(&engine);
    ctx->setContextProperty("UIBridge", _uibridge);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
