#include "profilemanager.h"
#include "gamewindow.h"

ProfileManager::ProfileManager(QObject *parent) : QObject(parent),
                            saved_profiles_{"Study_work", "FindeItems.v1"} {}

bool ProfileManager::loadNewProfile() {
    QInputDialog dialog_new_name;
    dialog_new_name.setInputMode(QInputDialog::InputMode::TextInput);
    dialog_new_name.setTextValue("Enter the name");
    if (dialog_new_name.exec() == QDialog::Accepted) {
        QString profile_name;
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
        QInputDialog select_profile;
        profile_list << "test1" << "test2" << "test3";
//        select_profile.setInputMode()
        select_profile.setComboBoxItems(profile_list);
        select_profile.setComboBoxEditable(false);
        if (select_profile.exec() == QDialog::Accepted) {

            QString player_name ;
//            = select_profile.getItem(this->parent(), "Choose profile", profile_list);

            saved_profiles_.beginGroup(player_name);
            int lvl = saved_profiles_.value("lvl", 0).toInt();

//            GameWindow * game = new GameWindow(player_name, lvl);
//            connect(game, SIGNAL(saveGame(QString, int)), this, SLOT(saveGame(QString, int)));
//            game->show();
            return true;
        } else if (select_profile.exec() == QDialog::Rejected) {

          return false;
        }
    }
}

void ProfileManager::saveGame(QString profile_name, int lvl) {
    saved_profiles_.beginGroup(profile_name);
    saved_profiles_.setValue("lvl", lvl);
}
