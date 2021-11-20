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
    void compliteAddress();

    void createPage(QString addr);
    //in temporary memory
    void savePage(QString addr,int activeId,QString title);
    //in permanent memory
    void savePageInFile();

    void deletePage(int activeId);

    void saveHistory(QString addr);
    void loadHistory();
    void deleteSelectedAddrHistory(int id);
    void clearAllHistory();

    QString getActiveSearcher();

    void startApp();

signals:
    void search(QString addr);
    void changeActiveId(int activeId);
    void getNumberPages(int numberPages);


private:
    explicit SearchEngine(QObject *parent = nullptr);
    SearchEngine(SearchEngine const&);
    ~SearchEngine();

    bool checkHttps(QString addr);

    // "vk.com" or "vk вход"
    bool checkSiteOrGlobalSearch(QString addr);

    QString correctAddress(QString addr);


    QString getStandartFileNameToSavePage();
    QString getStandartFileNameToSaveHistory();
};

#endif // SEARCHENGINE_H
