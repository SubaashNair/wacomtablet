/*
 * Copyright 2012 Alexander Maret-Huskinson <alex@maret.de>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "dbustabletinterface.h"

#include <QtCore/QString>
#include <QMutex>

using namespace Wacom;

// instanciate static class members
DBusTabletInterface* DBusTabletInterface::m_instance = NULL;


DBusTabletInterface::DBusTabletInterface()
    : QDBusInterface( QLatin1String( "org.kde.Wacom" ), QLatin1String( "/Tablet" ), QLatin1String( "org.kde.Wacom" ) )
{
    // nothing to do
}


DBusTabletInterface::DBusTabletInterface(const DBusTabletInterface&)
    : QDBusInterface( QLatin1String( "org.kde.Wacom" ), QLatin1String( "/Tablet" ), QLatin1String( "org.kde.Wacom" ) )
{
    // this class is a singleton - no copying allowed
}


DBusTabletInterface& DBusTabletInterface::operator= (const DBusTabletInterface&)
{
    // this class is a singleton - no copying allowed
    return (*this);
}


DBusTabletInterface& DBusTabletInterface::instance()
{
    if (!m_instance) {
        static QMutex mutex;
        mutex.lock();

        if (!m_instance) {
            resetInterface();
        }

        mutex.unlock();
    }

    return *m_instance;
}


void DBusTabletInterface::resetInterface()
{
    static QMutex mutex;
    mutex.lock();

    if (m_instance) {
        delete m_instance;
        m_instance = NULL;
    }

    m_instance = new DBusTabletInterface();

    mutex.unlock();
}



QDBusMessage DBusTabletInterface::profile()
{
    return call( QLatin1String( "profile" ) );
}

QDBusMessage DBusTabletInterface::profileList()
{
    return call( QLatin1String( "profileList" ) );
}

QDBusMessage DBusTabletInterface::setProfile(const QString& profile)
{
    return call( QLatin1String( "setProfile" ), profile );
}

QDBusMessage DBusTabletInterface::tabletAvailable()
{
    return call( QLatin1String( "tabletAvailable" ) );
}

