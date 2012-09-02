/*
 * Copyright 2009,2010 Jörg Ehrichs <joerg.ehichs@gmx.de>
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

#ifndef TABLETWIDGET_H
#define TABLETWIDGET_H

//KDE includes
#include <KDE/KSharedConfig>

//Qt includes
#include <QtGui/QWidget>

/**
  * The Ui namespace holds the designer form files for the tablet module
  */
namespace Ui
{
    class TabletWidget;
}

namespace Wacom
{

class TabletWidgetPrivate;


/**
  * This class implements the tabletwidget.ui designer file
  * It is the skeleton for the tablet settings widget and able to show the used tablet
  * as image as well as some basic information. Furthermore this widget holds the KConfig profile
  * selector and handles all profiles.
  * The subgroup setting widgets for the pad/stylus/eraser are grouped together in an KTabWidget
  */
class TabletWidget : public QWidget
{
    Q_OBJECT

public:
    /**
      * default constructor
      *
      * @param parent Parent widget
      */
    explicit TabletWidget(QWidget *parent = 0);

    /**
      * default destructor
      */
    ~TabletWidget();

    /**
      * Reloads the profile to its saved values from the config file
      * Resets all made changes so far
      */
    void reloadProfile();

    /**
      * Saves the current active profile
      * Takes the values from each widget and saves them
      */
    void saveProfile();

signals:
    /**
      * Will be emitted whenever the status of the widget changes to inform the KCModule about it
      *
      * @param change @c true if config changed @c false if not
      */
    void changed(bool change);


public slots:
    /**
      * Initialize the widgets tablet parameter.
      * Shows an image of the connected tablet or a generic image if no image was found.
      * If no tablet is connected an error message will be shown.
      */
    void loadTabletInformation();

    /**
      * Slot that opens up a dialogue to create a new profile for the connected tablet.
      * Starting parameter of the profile will be the default params as detected by xsetwacom.
      */
    void addProfile();

    /**
      * Deletes the currently selected profile.
      * If the last profile was deleted a new default profile will automatically created.
      */
    void delProfile();

    /**
      * Switch from one profile to another and updates all other widgets.
      * This slot will be called from the profile selector combobox.
      *
      * @param profile The profile name the widget should switch to as written in the KConfig file
      */
    void switchProfile(const QString &profile);

    /**
      * Will be called whenever a parameter of the currently selected profile changed.
      * This ensures that changes in the profile will be saved back to the configuration file before
      * the program is closed or the profile switched.
      * The user is asked if the changes should be saved or thrown away.
      */
    void profileChanged();


private:

    /**
      * Activates the current profile for all connected devices (pen/stylus/eraser)
      * Happens when the profile is saved/switched/loaded
      */
    void applyProfile();

    /**
     * Disables the profile selector and hides all configuration tabs.
     */
    void hideConfig();

    /**
     * Hides an error message which was previously shown using showError().
     * If no error message is active, nothing is done.
     */
    void hideError();

    /**
      * Initialize the widget
      * creates all necessary setting widgets and connects their signals
      */
    void init();

    /**
     * Reloads profiles from the profile manager and loads them into the profile
     * selector. If a profile name is given, it will be selected. If no profile
     * is given the default widget selection method applies.
     *
     * @param profile The profile to select (possibly empty)
     *
     * @return True if a profile was given and it could be set, else false.
     */
    bool refreshProfileSelector(const QString& profile = QString());

    /**
     * Activates the profile selector and show all configuration tabs depending
     * on the currently loaded profile. If an error message is currently active,
     * it will be hidden.
     */
    void showConfig();

    /**
      * If an error occurs a widget with some additional text is shown instead of the config widget.
      * Happens if no tablet device can be found or the kded daemon is not working.
      *
      * @param errMsg the message that describes the error in more detail
      */
    void showError(const QString & errMsg);

    /**
     * Shows a dialog which allows the user to save his changes if the currently
     * active configuration was changed.
     */
    void showSaveChanges();

    Q_DECLARE_PRIVATE( TabletWidget )
    TabletWidgetPrivate *const d_ptr; /**< d-pointer for this class */

}; // CLASS
}  // NAMESPACE
#endif /*TABLETWIDGET_H*/
