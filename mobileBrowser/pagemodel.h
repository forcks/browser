#ifndef PAGEMODEL_H
#define PAGEMODEL_H

#include <QAbstractListModel>
#include <QObject>

#include "pagelist.h"

class pageList;

class pageModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(pageList *list READ list WRITE setList)

public:
    explicit pageModel(QObject *parent = nullptr);

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


    pageList *list() const;
    void setList(pageList *list);

private:
    pageList *mList;
};

#endif // PAGEMODEL_H
