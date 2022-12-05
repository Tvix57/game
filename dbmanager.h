#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QApplication>
#include <QFileInfo>
#include <QDebug>



#ifdef __APPLE__
#define MACOS 0
#elif __linux__
#define MACOS 1
#else
#define MACOS 2
#endif

class DBManager : public QObject
{
    Q_OBJECT
public:
    explicit DBManager(QObject *parent = nullptr);
    ~DBManager();

    QHash<int,QString> GetImageWay(int);
    int GetMaxImage();
private:
    bool MakeFileWay();
    QSqlDatabase db_;
    QString file_path_;
};

#endif // DBMANAGER_H
