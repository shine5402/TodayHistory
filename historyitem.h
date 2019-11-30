#ifndef HISTORYITEM_H
#define HISTORYITEM_H

#include <QObject>

class HistoryItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int day READ getDay CONSTANT)
    Q_PROPERTY(QString des READ getDes CONSTANT)
    Q_PROPERTY(int hits READ getHits CONSTANT)
    Q_PROPERTY(int id READ getId CONSTANT)
    Q_PROPERTY(int month READ getMonth CONSTANT)
    Q_PROPERTY(QString pic READ getPic CONSTANT)
    Q_PROPERTY(QString title READ getTitle CONSTANT)
    Q_PROPERTY(QString url READ getUrl CONSTANT)
    Q_PROPERTY(int year READ getYear CONSTANT)
public:
    explicit HistoryItem(int day, const QString& des, int hits, int id, int month, const QString& pic, const QString& title, const QString& url, int year, QObject *parent = nullptr);
    HistoryItem(const HistoryItem & otherItem);
    HistoryItem(HistoryItem && otherItem) = default;
    HistoryItem& operator=(const HistoryItem&);
    int getDay() const;

    QString getDes() const;

    int getHits() const;

    int getId() const;

    int getMonth() const;

    QString getPic() const;

    QString getTitle() const;

    QString getUrl() const;

    int getYear() const;



signals:

public slots:
private:
    int day = 0;
    QString des{};
    int hits = 0;
    int id = 0;
    int month = 0;
    QString pic{};
    QString title{};
    QString url{};
    int year = 0;
};

using HistoryItemList = QList<HistoryItem>;
using HistoryItemRef = HistoryItem *;
using HistoryItemRefList = QList<HistoryItemRef>;


#endif // HISTORYITEM_H
