#include "screenvalues.h"

#include <QScreen>
#include <QGuiApplication>

ScreenValues::ScreenValues(QObject *parent) :
    QObject(parent),
    m_dpi(0),
    m_isTablet(false)
{
    m_dpi = QGuiApplication::primaryScreen()->physicalDotsPerInch();

    m_dpMultiplier = (float) m_dpi / 160;
}

int ScreenValues::dpi() const
{
    return m_dpi;
}

void ScreenValues::setDpi(int dpi)
{
    if (m_dpi == dpi)
        return;

    m_dpi = dpi;
    emit dpiChanged();

    setDpMultiplier((float) m_dpi / 160);
}

float ScreenValues::dpMultiplier() const
{
    return m_dpMultiplier;
}

void ScreenValues::setDpMultiplier(float dpMultiplier)
{
    if (m_dpMultiplier == dpMultiplier)
        return;

    m_dpMultiplier = dpMultiplier;
    emit dpMultiplierChanged();
}

bool ScreenValues::isTablet() const
{
    return m_isTablet;
}

void ScreenValues::setIsTablet(bool isTablet)
{
    if (m_isTablet == isTablet)
        return;

    m_isTablet = isTablet;
    emit isTabletChanged();
}
