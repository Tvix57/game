#ifndef PROFILEMANAGER_H
#define PROFILEMANAGER_H

#include <QObject>
#include <QSettings>
#include <QInputDialog>
#include <QMessageBox>

class ProfileManager : public QObject
{
    Q_OBJECT
public:
    explicit ProfileManager(QObject *parent = nullptr);
    bool loadNewProfile();
    bool loadProfile();
public slots:
    void saveGame(QString, int);

signals:

private:
    QSettings saved_profiles_;
};

#endif // PROFILEMANAGER_H
