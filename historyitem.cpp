#include "historyitem.h"

HistoryItem::HistoryItem(int day,
                         const QString& des,
                         int hits,
                         int id,
                         int month,
                         const QString& pic,
                         const QString& title,
                         const QString& url,
                         int year,
                         QObject *parent) : QObject(parent),day(day),des(des),hits(hits),id(id),month(month),pic(pic),title(title),url(url),year(year)
{

}

HistoryItem::HistoryItem(const HistoryItem& otherItem): QObject(otherItem.parent()),day(otherItem.day),des(otherItem.des),hits(otherItem.hits),id(otherItem.id),month(otherItem.month),pic(otherItem.pic),title(otherItem.title),url(otherItem.url),year(otherItem.year)

{

}

HistoryItem& HistoryItem::operator=(const HistoryItem& other)
{
    setParent(other.parent());
    day = other.getDay();
    des = other.getDes();
    hits = other.getHits();
    id = other.getId();
    month = other.getMonth();
    pic = other.getPic();
    title = other.getTitle();
    url = other.getUrl();
    year = other.getYear();
    return *this;
}

int HistoryItem::getDay() const
{
    return day;
}

QString HistoryItem::getDes() const
{
    return des;
}

int HistoryItem::getHits() const
{
    return hits;
}

int HistoryItem::getId() const
{
    return id;
}

int HistoryItem::getMonth() const
{
    return month;
}

QString HistoryItem::getPic() const
{
    return pic;
}

QString HistoryItem::getTitle() const
{
    return title;
}

QString HistoryItem::getUrl() const
{
    return url;
}

int HistoryItem::getYear() const
{
    return year;
}
