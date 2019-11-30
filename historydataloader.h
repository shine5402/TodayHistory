#ifndef HISTORYDATALOADER_H
#define HISTORYDATALOADER_H

#include <QObject>
#include "historydatagetter.h"
#include "historydataparser.h"
#include <QThread>

class HistoryDataLoader : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isReady READ isReady NOTIFY isReadyChanged)
public:
    explicit HistoryDataLoader(QObject *parent = nullptr);

    bool isReady() const;
    void loadDataPrivate();
signals:
    void isReadyChanged();
public slots:
    void loadData();
private:
    bool m_isReady = false;

    HistoryDataGetter* historyDataGetter = nullptr;
};

#endif // HISTORYDATALOADER_H
