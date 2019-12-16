#ifndef UIBRIDGER_H
#define UIBRIDGER_H

#include <QObject>
#include <QQmlApplicationEngine>

class UIBridge: public QObject
{
    Q_OBJECT
public:
    UIBridge(QQmlApplicationEngine *view);
public slots:
    void captureScreen();
    QString buttonName();
private:
    QQmlApplicationEngine *m_view;
};

#endif // UIBRIDGER_H
