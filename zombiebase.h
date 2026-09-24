#pragma once

#include <QObject>

class ZombieBase : public QObject
{
    Q_OBJECT
public:
    explicit ZombieBase(QObject *parent = nullptr);

signals:
};
