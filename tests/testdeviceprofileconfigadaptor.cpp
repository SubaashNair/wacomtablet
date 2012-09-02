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

#include <KDE/KSharedConfig>
#include <KDE/KConfigGroup>

#include <QDir>
#include <QString>
#include <QTemporaryFile>

#include "deviceprofile.h"
#include "deviceprofileconfigadaptor.h"

#include "deviceprofiletestutils.h"
#include "testdeviceprofileconfigadaptor.moc"

using namespace Wacom;

void TestDeviceProfileConfigAdaptor::testConfig()
{
    QTemporaryFile tempFile(QDir::tempPath() + QDir::separator() + QLatin1String("testdeviceprofileconfigadaptorrc_XXXXXX"));
    QVERIFY(tempFile.open());
    tempFile.close();
    tempFile.setAutoRemove(true);

    KSharedConfig::Ptr config = KSharedConfig::openConfig(tempFile.fileName(), KConfig::SimpleConfig );
    QVERIFY(config);

    KConfigGroup configGroup = KConfigGroup( config, QLatin1String("DEVICE") );

    DeviceProfile writeProfile;
    DeviceProfileTestUtils::setValues(writeProfile);

    DeviceProfileConfigAdaptor writeAdaptor(writeProfile);
    writeAdaptor.saveConfig(configGroup);

    config->sync();

    DeviceProfile readProfile;
    readProfile.setName(QLatin1String("Name")); // we have to set the name manually as only properties are copied atm
    DeviceProfileConfigAdaptor readAdaptor(readProfile);
    readAdaptor.loadConfig(configGroup);

    DeviceProfileTestUtils::assertValues(readProfile);
}
