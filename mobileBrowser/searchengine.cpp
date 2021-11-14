#include "searchengine.h"
#include "pagelist.h"
#include "appengine.h"

SearchEngine::SearchEngine(QObject *parent) : QObject(parent)
{

}

void SearchEngine::compliteAddress(QString addr)
{
    addr = correctAddress(addr);
    emit search(addr);
}

void SearchEngine::compliteAddress(QString addr,int activeId){
    addr = correctAddress(addr);
    emit changeActiveId(activeId);
    emit search(addr);
    AppEngine *appEngine = &AppEngine::init();
    appEngine->mainWindow();
}

void SearchEngine::createPage()
{
    QString addr = correctAddress(getActiveSearcher());
    //compliteAddress(addr);

    pageList *pageList = &pageList::init();
    pageList->addPage(addr);
}

void SearchEngine::savePage(QString addr,int activeId)
{
    pageList *pageList = &pageList::init();
    pageList->changeAddress(addr,activeId);
}

void SearchEngine::deletePage(int activeId)
{
    pageList *pageList = &pageList::init();
    pageList->deletePage(activeId);

}

bool SearchEngine::checkHttps(QString addr)
{
    return addr.contains("https://") || addr.contains("http://");
}

bool SearchEngine::checkSiteOrGlobalSearch(QString addr)
{
    return addr.contains(".");
}

QString SearchEngine::correctAddress(QString addr)
{
    if(checkSiteOrGlobalSearch(addr)){
        addr = checkHttps(addr) ? addr : "https://"+addr;
    }
    else{
        QStringList addrWords;
        addrWords = addr.split(" ");
        addr = "https://www.google.ru/search?q=";
        for(int i = 0;i<addrWords.count()-1;i++){
            addr+=addrWords[i]+"+";
        }
        addr+=addrWords[addrWords.count()-1];
    }
    return addr;
}

QString SearchEngine::getActiveSearcher()
{
    return "google.com";
}


