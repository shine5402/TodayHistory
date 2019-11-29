#ifndef HISTORYITEM_H
#define HISTORYITEM_H

#include <QObject>

class HistoryItem : public QObject
{
    Q_OBJECT
public:
    explicit HistoryItem(QObject *parent = nullptr);

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

#endif // HISTORYITEM_H
