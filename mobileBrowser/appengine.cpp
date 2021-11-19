#include "appengine.h"

AppEngine::AppEngine(QObject *parent) : QObject(parent)
{

}

void AppEngine::pages()
{
    emit goToPages();
}

void AppEngine::mainWindow()
{
    emit goToMainWindow();
}

void AppEngine::menu()
{
    emit goToMenu();
}

void AppEngine::history()
{
    emit goToHistory();
}
