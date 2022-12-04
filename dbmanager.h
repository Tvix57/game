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

class DBManager : public QObject
{
    Q_OBJECT
public:
    explicit DBManager(QObject *parent = nullptr);
    ~DBManager();

    QHash<int,QString> GetImageWay(int);
private:
    bool MakeFileWay();
    QSqlDatabase db_;
    QString file_path_;
};

#endif // DBMANAGER_H
