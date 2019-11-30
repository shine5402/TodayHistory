#ifndef HISTORYDATAGETTER_H
#define HISTORYDATAGETTER_H

#include <QObject>
#include "historydataparser.h"
#include <QHash>
#include <QPair>
#include <QtCore/qhashfunctions.h>



class HistoryDataGetter : public QObject
{
    Q_OBJECT
    Q_PROPERTY(HistoryItemList entries READ getEntries NOTIFY entriesChanged)
public:
    explicit HistoryDataGetter(HistoryItemList allItems, QObject *parent = nullptr);

    HistoryItemList getEntries() const;

    void setDate(int month, int day);
    struct Date {
        int month;
        int day;
        bool operator==(const HistoryDataGetter::Date& other) const;
    };
signals:
    void entriesChanged();
public slots:

private:
    HistoryItemList entries;
    HistoryItemList allItems;
    int day;
    int month;
    HistoryItemList findEntriesByDate(int month, int day);

    using HistoryItemRefList = QList<HistoryItem *>;
    QHash<Date,HistoryItemRefList *> searcher;
    void initSearcher();
};

uint qHash(const HistoryDataGetter::Date &key);
uint qHash(const HistoryDataGetter::Date &key, uint seed);

#endif // HISTORYDATAGETTER_H
