#ifndef QLOGVIRTUALTABLE_H
#define QLOGVIRTUALTABLE_H

#include <QObject>
#include <QMap>

class QLogVirtualTable : public QObject
{
    Q_OBJECT
public:
    explicit QLogVirtualTable(QObject *parent = nullptr);

    bool addFieldDefs(bool bKey,QString sFieldName,int ftFielType,int iSize,bool bRequired);


signals:

public slots:

private:
    QMap <QByteArray,QByteArray> m_Map;
    QByteArray m_baKey;
    QByteArray m_baValue;
    QList <QString>m_lFieldName;
    QList <int> m_ftFieldType;
};

#endif // QLOGVIRTUALTABLE_H
