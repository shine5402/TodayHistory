#include "historydatagetter.h"

HistoryDataGetter::HistoryDataGetter(HistoryItemRefList allItems, QQmlContext* context, QObject *parent) : QObject(parent), allItems(allItems), context(context)
{
    initSearcher();
    setDate(QDate::currentDate().month(),QDate::currentDate().day());
}

HistoryDataGetter::~HistoryDataGetter()
{
    clearSearcher();
}


void HistoryDataGetter::refreshEntries()
{
    entries = findEntriesByDate(month, day);
    QList<QObject*> objList;
    for (auto i : entries)
    {
        objList.append(i);
    }
    context->setContextProperty("HistoryItemEntries",QVariant::fromValue(objList));
    emit entriesChanged();
}

void HistoryDataGetter::setDate(int month, int day)
{
    this->day = day;
    emit dayChanged();
    this->month = month;
    emit monthChanged();
    refreshEntries();
}

void HistoryDataGetter::setDate(HistoryDataGetter::Date date)
{
    setDate(date.month,date.day);
}

void HistoryDataGetter::setMonth(int month)
{
    this->month = month;
    emit monthChanged();
    refreshEntries();
}

void HistoryDataGetter::setDay(int day)
{
    this->day = day;
    emit dayChanged();
    refreshEntries();
}

int HistoryDataGetter::getDay() const
{
    return day;
}

int HistoryDataGetter::getMonth() const
{
    return month;
}

HistoryItemRefList HistoryDataGetter::findEntriesByDate(int month, int day)
{
    auto refList = searcher.value(Date{month,day});
    if (refList && !refList->isEmpty())
    {
        return *refList;
    }
    else {
        return HistoryItemRefList{};
    }
}

void HistoryDataGetter::clearSearcher()
{
    for (auto i : searcher) {
        delete i;
    }
    searcher.clear();
}

void HistoryDataGetter::initSearcher()
{
    clearSearcher();
    for (auto item : allItems)
    {
        auto list = searcher.value(Date{item->getMonth(),item->getDay()});
        if (list)
            list->append(item);
        else {
            auto newList = new HistoryItemRefList{item};
            searcher.insert(Date{item->getMonth(),item->getDay()},newList);
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
