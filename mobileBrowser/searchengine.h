#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include <QObject>

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
    void savePage(QString addr,int activeId);
    void deletePage(int activeId);

signals:
    void search(QString addr);
    void changeActiveId(int activeId);

private:
    explicit SearchEngine(QObject *parent = nullptr);
    SearchEngine(SearchEngine const&);

    bool checkHttps(QString addr);

    // "vk.com" or "vk вход"
    bool checkSiteOrGlobalSearch(QString addr);

    QString correctAddress(QString addr);

    QString getActiveSearcher();
};

#endif // SEARCHENGINE_H
