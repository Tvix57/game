#include "dbmanager.h"

DBManager::DBManager(QObject *parent)
    : QObject{parent},
      db_{QSqlDatabase::addDatabase("QSQLITE")} {
    file_path_ = MakeFileWay();
    if (!file_path_.isEmpty()) {
      db_.setDatabaseName(file_path_);
        if (!db_.isOpen()) {
            if (!db_.open()) {
                qDebug() << "База данных не открылась" << db_.lastError();
            }
        }
    }
}

QStringList DBManager::GetImageWay(int items_count) {
    QStringList result;
    QSqlQuery query(db_);
    query.prepare("SELECT img_way FROM items ");
//    if (query.exec()) {
//        if (query.first()) {
//            QSqlRecord record_gr = query.record();
//            result. = query.value(record_gr.indexOf("img_way")).toString();
//        }
//    }
    return result;
}

QString DBManager::MakeFileWay() {
//    file_path_ {QCoreApplication::applicationDirPath () +
//                QString("/image_DB.sqlite")};
    QFileInfo checkFile(file_path_);
    if (!checkFile.isFile()) {
      file_path_  = QCoreApplication::applicationDirPath () + QString("/../image_DB.sqlite");
      checkFile.setFile(file_path_);
    }
}

DBManager::~DBManager() {
    db_.close();
}

