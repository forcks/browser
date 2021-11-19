#ifndef HISTORYMODEL_H
#define HISTORYMODEL_H

#include <QAbstractListModel>
#include <QObject>

#include "historylist.h"

class historyList;

class historyModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(historyList *list READ list WRITE setList)

public:
    explicit historyModel(QObject *parent = nullptr);

    enum{
        IdRole = Qt::UserRole,
        AddrRole
    };

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value,int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;


    historyList *list() const;
    void setList(historyList *list);

private:
    historyList *mList;
};

#endif // HISTORYMODEL_H
