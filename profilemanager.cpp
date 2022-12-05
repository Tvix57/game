#include "profilemanager.h"
#include "gamewindow.h"
#include <QDir>

ProfileManager::ProfileManager(QObject *parent) : QObject(parent),
                            saved_profiles_{"Study_work", "FindeItems.v1"} {}

bool ProfileManager::loadNewProfile() {
    bool ok;
    QString profile_name = QInputDialog::getText(nullptr, tr("QInputDialog::getText()"),
                                                   tr("User name:"), QLineEdit::Normal,
                                                   QDir::home().dirName(), &ok);
    if (ok && !profile_name.isEmpty()) {
        GameWindow * game = new GameWindow(profile_name);
        connect(game, SIGNAL(saveGame(QString, int)), this, SLOT(saveGame(QString, int)));
        game->show();
        return true;
    } else {
        return false;
    }
}

bool ProfileManager::loadProfile() {
    QStringList profile_list = saved_profiles_.childGroups();
    if (profile_list.isEmpty()) {
        QMessageBox message;
        message.setText("There is no saved profiles. Please create new.");
        message.exec();
        return false;
    } else {
        bool ok;
        QString player_name = QInputDialog::getItem(nullptr, tr("QInputDialog::getItem()"),
                                             tr("Select profile:"), profile_list, 0, false, &ok);

        if (ok && !player_name.isEmpty()) {
            saved_profiles_.beginGroup(player_name);
            int lvl = saved_profiles_.value("lvl", 1).toInt();
            saved_profiles_.endGroup();
            GameWindow * game = new GameWindow(player_name, lvl);
            connect(game, SIGNAL(saveGame(QString, int)), this, SLOT(saveGame(QString, int)));
            game->show();
            return true;
        } else {
            return false;
        }
    }
}

void ProfileManager::saveGame(QString profile_name, int lvl) {
    saved_profiles_.beginGroup(profile_name);
    saved_profiles_.setValue("lvl", lvl);
    saved_profiles_.endGroup();
}
