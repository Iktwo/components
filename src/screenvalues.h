#ifndef SCREENVALUES_H
#define SCREENVALUES_H

#include <QObject>

class ScreenValues : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int dpi READ dpi WRITE setDpi NOTIFY dpiChanged)
    Q_PROPERTY(float dpMultiplier READ dpMultiplier WRITE setDpMultiplier NOTIFY dpMultiplierChanged)
    Q_PROPERTY(bool isTablet READ isTablet NOTIFY isTabletChanged)
public:
    explicit ScreenValues(QObject *parent = 0);

    int dpi() const;
    void setDpi(int dpi);

    float dpMultiplier() const;
    void setDpMultiplier(float dpMultiplier);

    bool isTablet() const;
    void setIsTablet(bool isTablet);

signals:
    void dpiChanged();
    void dpMultiplierChanged();
    void isTabletChanged();

private:
    int m_dpi;
    float m_dpMultiplier;
    bool m_isTablet;
};

#endif // SCREENVALUES_H

