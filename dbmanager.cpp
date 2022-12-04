#include "dbmanager.h"

DBManager::DBManager(QObject *parent)
    : QObject{parent},
      db_{QSqlDatabase::addDatabase("QSQLITE")} {
    if (MakeFileWay()) {
      db_.setDatabaseName(file_path_);
        if (!db_.isOpen()) {
            if (!db_.open()) {
                qDebug() << "База данных не открылась" << db_.lastError();
            }
        }
    } else {
        qDebug() << "Файл БД не найден." << db_.lastError();
    }
}

QHash<int,QString> DBManager::GetImageWay(int items_count) {
    QHash<int,QString> result;
    QSqlQuery query(db_);
    query.prepare("SELECT * FROM images ORDER BY RANDOM() LIMIT " + QString::number(items_count));
    if (query.exec()) {
        if (query.first()) {
            QSqlRecord record_gr = query.record();
            result.insert(query.value(record_gr.indexOf("img_id")).toInt(),
                          query.value(record_gr.indexOf("img_way")).toString());
        }
    }
    return result;
}

bool DBManager::MakeFileWay() {
    file_path_ = {QCoreApplication::applicationDirPath () +
                QString("/image_DB.sqlite")};
    QFileInfo checkFile(file_path_);
    if (!checkFile.isFile()) {
        return true;
    } else {
        return false;
    }
}

DBManager::~DBManager() {
    db_.close();
}

