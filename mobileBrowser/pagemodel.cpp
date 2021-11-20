#include "pagemodel.h"
#include "pagelist.h"

#include <QVariant>
#include <QVariantList>

pageModel::pageModel(QObject *parent)
    : QAbstractListModel(parent)
    , mList(nullptr)
{
}


int pageModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return mList->items().size();
}

QVariant pageModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    const PageItem item = mList->items().at(index.row());
    switch (role) {
    case AddrRole:
        return QVariant(item.addr);
    case IdRole:
        return  QVariant(item.id);
    case TitleRole:
        return QVariant(item.title);
    }

    return QVariant();
}

bool pageModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!mList)
        return false;
    PageItem item = mList->items().at(index.row());
    switch (role) {
    case AddrRole:
        item.addr = value.toString();
        break;
    case IdRole:
        item.id = value.toInt();
        break;
    case TitleRole:
        item.title = value.toString();
        break;
    }

    if (mList->setItemAt(index.row(), item)) {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }

    return false;
}

Qt::ItemFlags pageModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::NoItemFlags;
    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> pageModel::roleNames() const
{
    QHash<int,QByteArray> names;
    names[IdRole] = "id";
    names[AddrRole] = "addr";
    names[TitleRole] = "title";
    return names;
}

pageList *pageModel::list() const{
    return mList;
}

void pageModel::setList(pageList *list)
{
    if(mList)
        mList->disconnect(this);

    mList = list;

    if (mList) {
        connect(mList, &pageList::changeValue, this, [=]() {
            emit layoutChanged();
        });
    }
    endResetModel();
}
