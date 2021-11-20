#ifndef PAGELIST_H
#define PAGELIST_H

#include <QObject>
#include <QString>
#include <QVector>

#include <QVariant>
#include <QVariantList>


struct PageItem{
    int id;
    QString addr;
    QString title;
};

class pageList : public QObject
{
    Q_OBJECT
public:
    static pageList &init(){
            static pageList initialization;
            return initialization;
        }

    QVector<PageItem> items() const;
    bool setItemAt(int index, const PageItem &item);
    void addPage(QString addr);
    void deletePage(int id);
    void changeAddress(QString addr, int id,QString title);

    //in permanent memory
    void savePage(QString fileName);
    void loadPage(QString fileName);

    QVector<PageItem> getPages();

    int getNumberPages();

signals:
    void changeValue();

private:
    explicit pageList(QObject *parent = nullptr);
    pageList(pageList const&);
    QVector<PageItem> mItems;

};

#endif // PAGELIST_H
