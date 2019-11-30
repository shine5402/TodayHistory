#include "historydatagetter.h"

HistoryDataGetter::HistoryDataGetter(HistoryItemList allItems, QObject *parent) : QObject(parent), allItems(allItems)
{
    initSearcher();
}

HistoryItemList HistoryDataGetter::getEntries() const
{
    return entries;
}

void HistoryDataGetter::setDate(int month, int day)
{
    entries = findEntriesByDate(month, day);
    emit entriesChanged();
}

HistoryItemList HistoryDataGetter::findEntriesByDate(int month, int day)
{
    auto refList = searcher.value(Date{month,day});
    if (refList && !refList->isEmpty())
    {
        HistoryItemList list;
        for (auto i : *refList)
        {
            if (i)
                list.append(*i);
        }
        return list;
    }
    else {
        return HistoryItemList{};
    }
}

void HistoryDataGetter::initSearcher()
{
    searcher.clear();
    for (auto item : allItems)
    {
        auto list = searcher.value(Date{item.getMonth(),item.getDay()});
        if (list)
            list->append(&item);
        else {
            auto newList = new HistoryItemRefList{&item};
            searcher.insert(Date{item.getMonth(),item.getDay()},newList);
        }
    }
}



uint qHash(const HistoryDataGetter::Date& key)
{
    return qHash(qMakePair(key.month,key.day));
}

uint qHash(const HistoryDataGetter::Date& key, uint seed)
{
    return qHash(qMakePair(key.month,key.day),seed);
}

bool HistoryDataGetter::Date::operator==(const HistoryDataGetter::Date& other) const
{
    return other.day == day && other.month == month;
}
