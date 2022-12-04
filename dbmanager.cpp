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
            for (; query.isValid(); query.next()) {
                QSqlRecord record_gr = query.record();
                result.insert(query.value(record_gr.indexOf("img_id")).toInt(),
                              query.value(record_gr.indexOf("img_way")).toString());
            }
        }
    } else {
        qDebug() << "Ошибка запроса" <<query.lastError();
    }
    return result;
}

int DBManager::GetMaxImage() {
    QSqlQuery query(db_);
    int result = 0;
    query.prepare("SELECT COUNT(*) as count FROM images");
    if (query.exec()) {
        if (query.first()) {
            QSqlRecord record_gr = query.record();
            result = query.value(record_gr.indexOf("count")).toInt();
        }
    } else {
        qDebug() << "Ошибка запроса" <<query.lastError();
    }
    return result;
}

bool DBManager::MakeFileWay() {
    file_path_ = QCoreApplication::applicationDirPath ();
    if (MACOS) {
        file_path_.truncate(file_path_.indexOf(".app"));
        file_path_.truncate(file_path_.lastIndexOf("/"));
        file_path_ += "/";
    } else {
        file_path_ += "\\";
    }
    file_path_ += "image_DB.sqlite3";
    QFileInfo checkFile(file_path_);
    if (checkFile.isFile()) {
        return true;
    } else {
        return false;
    }
}

DBManager::~DBManager() {
    db_.close();
}

