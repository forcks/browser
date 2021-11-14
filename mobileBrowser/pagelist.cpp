#include "pagelist.h"

#include <QDebug>

#include <QVariant>
#include <QVariantList>



pageList::pageList(QObject *parent) : QObject(parent)
{

}

QVector<PageItem> pageList::items() const
{
    return mItems;
}

bool pageList::setItemAt(int index, const PageItem &item)
{
    if (index < 0 || index >= mItems.size())
        return false;

    const PageItem &oldItem = mItems.at(index);
    if (item.id == oldItem.id
            && item.addr == oldItem.addr)
        return false;

    mItems[index] = item;
    return true;
}

void pageList::addPage(QString addr)
{
    PageItem item;
    item.id = mItems.isEmpty() ? 0 : mItems[mItems.count()-1].id+1;
    item.addr = addr;
    mItems.append(item);
    changeValue();
}

void pageList::deletePage(int id)
{
    for (int i = 0;i<mItems.count();i++) {
        if(mItems[i].id == id){
            mItems.remove(i);
            changeValue();
            break;
        }
    }
}

void pageList::changeAddress(QString addr, int id)
{
    if(mItems.empty())
        mItems.append({0,""});
    mItems[id].addr = addr;
    changeValue();
}
