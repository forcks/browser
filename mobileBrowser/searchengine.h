#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include <QObject>
#include <QTimer>

class SearchEngine : public QObject
{
    Q_OBJECT
public:
    static SearchEngine &init(){
            static SearchEngine initialization;
            return initialization;
        }


public slots:
    void compliteAddress(QString addr);
    void compliteAddress(QString addr,int activeId);

    void createPage();
    //in temporary memory
    void savePage(QString addr,int activeId);
    //in permanent memory
    void savePageInFile();

    void deletePage(int activeId);
signals:
    void search(QString addr);
    void changeActiveId(int activeId);

private:
    explicit SearchEngine(QObject *parent = nullptr);
    SearchEngine(SearchEngine const&);
    ~SearchEngine();

    bool checkHttps(QString addr);

    // "vk.com" or "vk вход"
    bool checkSiteOrGlobalSearch(QString addr);

    QString correctAddress(QString addr);

    QString getActiveSearcher();

    QString getStandartFileNameToSavePage();
};

#endif // SEARCHENGINE_H
