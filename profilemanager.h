#ifndef PROFILEMANAGER_H
#define PROFILEMANAGER_H

#include <QObject>

#include "namewindow.h"

class ProfileManager : public QObject
{
    Q_OBJECT
public:
    explicit ProfileManager(QObject *parent = nullptr);
    void loadNewProfile();
    void loadProfile();
public slots:
    void createNewProfile(QString);
signals:

};

#endif // PROFILEMANAGER_H
