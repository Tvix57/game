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



#ifdef __APPLE__
#define MACOS true
#else
#define MACOS false
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
