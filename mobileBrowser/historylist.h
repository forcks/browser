#ifndef HISTORYLIST_H
#define HISTORYLIST_H

#include <QObject>

struct HistoryItem{
    int id;
    QString addr;
};

class historyList : public QObject
{
    Q_OBJECT
public:
    static historyList &init(){
        static historyList initialivation;
        return initialivation;
    }
    QVector<HistoryItem> items() const;
    bool setItemAt(int index, const HistoryItem &item);

    void saveHistory(QString addr);
    void saveHistory();
    void loadHistory();
    void deleteSelectedAddrHistory(int id);
    void clearAllHistory();

signals:
    void changeValue();

private:
    explicit historyList(QObject *parent = nullptr);
    historyList(historyList const&);
    QVector<HistoryItem> mItems;
    QString getStandartFileNameToSaveHistory();

};

#endif // HISTORYLIST_H
