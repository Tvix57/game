#include "profilemanager.h"
#include "gamewindow.h"

ProfileManager::ProfileManager(QObject *parent) : QObject(parent) {

}

void ProfileManager::loadNewProfile() {
    NameWindow * name_window = new NameWindow(this);
    connect(name_window, SIGNAL(newProfile(QString)), this, SLOT(createNewProfile(QString)));
    name_window->show();
}

void ProfileManager::createNewProfile(QString profile_name) {

}
