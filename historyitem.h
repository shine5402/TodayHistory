#ifndef HISTORYITEM_H
#define HISTORYITEM_H

#include <QObject>

class HistoryItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int day READ getDay)
    Q_PROPERTY(QString des READ getDes)
    Q_PROPERTY(int hits READ getHits)
    Q_PROPERTY(int id READ getId)
    Q_PROPERTY(int month READ getMonth)
    Q_PROPERTY(QString pic READ getPic)
    Q_PROPERTY(QString title READ getTitle)
    Q_PROPERTY(QString url READ getUrl)
    Q_PROPERTY(int year READ getYear)
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

#endif // HISTORYITEM_H
