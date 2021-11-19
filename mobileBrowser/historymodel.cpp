#include "historymodel.h"
#include "historylist.h"

historyModel::historyModel(QObject *parent)
    : QAbstractListModel(parent)
{
}


int historyModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return mList->items().size();
}

QVariant historyModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    const HistoryItem item = mList->items().at(index.row());
    switch (role) {
    case AddrRole:
        return QVariant(item.addr);
    case IdRole:
        return  QVariant(item.id);
    }

    return QVariant();
}

bool historyModel::setData(const QModelIndex &index, const QVariant &value, int role)
{

    if(!mList)
        return false;
    HistoryItem item = mList->items().at(index.row());
    switch (role) {
    case AddrRole:
        item.addr = value.toString();
        break;
    case IdRole:
        item.id = value.toInt();
        break;
    }

    if (mList->setItemAt(index.row(), item)) {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }

    return false;
}


Qt::ItemFlags historyModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::NoItemFlags;
    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> historyModel::roleNames() const
{
    QHash<int,QByteArray> names;
    names[IdRole] = "id";
    names[AddrRole] = "addr";
    return names;
}

historyList *historyModel::list() const{
    return mList;
}

void historyModel::setList(historyList *list)
{
    if(mList)
        mList->disconnect(this);

    mList = list;

    if (mList) {
        connect(mList, &historyList::changeValue, this, [=]() {
            emit layoutChanged(); if(mList)
                mList->disconnect(this);

            mList = list;

            if (mList) {
                connect(mList, &historyList::changeValue, this, [=]() {
                    emit layoutChanged();
                });
            }
            endResetModel();
        });
    }
    endResetModel();
}
