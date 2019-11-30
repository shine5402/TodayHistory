#ifndef HISTORYDATAGETTER_H
#define HISTORYDATAGETTER_H

#include <QObject>
#include "historydataparser.h"
#include <QHash>
#include <QPair>
#include <QtCore/qhashfunctions.h>
#include <QQmlContext>
#include <QDate>


class HistoryDataGetter : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int day READ getDay WRITE setDay NOTIFY dayChanged)
    Q_PROPERTY(int month READ getMonth WRITE setMonth NOTIFY monthChanged)
public:
    explicit HistoryDataGetter(HistoryItemRefList allItems, QQmlContext* context, QObject *parent = nullptr);
    ~HistoryDataGetter();

    struct Date {
        int month;
        int day;
        bool operator==(const HistoryDataGetter::Date& other) const;
    };
    void setDate(Date date);
    void setMonth(int month);
    void setDay(int day);
    int getDay() const;

    int getMonth() const;

signals:
    void entriesChanged();
    void dayChanged();
    void monthChanged();
public slots:
    void setDate(int month, int day);

private:
    HistoryItemRefList entries;
    HistoryItemRefList allItems;
    int day;
    int month;
    HistoryItemRefList findEntriesByDate(int month, int day);
    QHash<Date,HistoryItemRefList *> searcher;
    void initSearcher();
    void refreshEntries();
    QQmlContext* context;
    void clearSearcher();
};

uint qHash(const HistoryDataGetter::Date &key);
uint qHash(const HistoryDataGetter::Date &key, uint seed);

#endif // HISTORYDATAGETTER_H
