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

#ifndef XSETWACOMPROPERTY_H
#define XSETWACOMPROPERTY_H

#include <QString>

#include "property.h"
#include "propertyset.h"

namespace Wacom {

// forward declarations & typedefs
class XsetwacomProperty;
typedef PropertySet<XsetwacomProperty> XsetwacomPropertyTemplateSpecialization;

/**
 * The property set for configuration files. It defines all properties which
 * can be written to or read from config files.
 */
class XsetwacomProperty : public XsetwacomPropertyTemplateSpecialization
{

public:
    static const XsetwacomProperty AbsWheel2Down;
    static const XsetwacomProperty AbsWheel2Up;
    static const XsetwacomProperty AbsWheelDown;
    static const XsetwacomProperty AbsWheelUp;
    static const XsetwacomProperty Area;
    static const XsetwacomProperty Button1;
    static const XsetwacomProperty Button2;
    static const XsetwacomProperty Button3;
    static const XsetwacomProperty Button4;
    static const XsetwacomProperty Button5;
    static const XsetwacomProperty Button6;
    static const XsetwacomProperty Button7;
    static const XsetwacomProperty Button8;
    static const XsetwacomProperty Button9;
    static const XsetwacomProperty Button10;
    static const XsetwacomProperty CursorProximity;
    static const XsetwacomProperty Gesture;
    static const XsetwacomProperty MapToOutput;
    static const XsetwacomProperty Mode;
    static const XsetwacomProperty PressureCurve;
    static const XsetwacomProperty RawSample;
    static const XsetwacomProperty RelWheelDown;
    static const XsetwacomProperty RelWheelUp;
    static const XsetwacomProperty Rotate;
    static const XsetwacomProperty ScrollDistance;
    static const XsetwacomProperty StripLeftDown;
    static const XsetwacomProperty StripLeftUp;
    static const XsetwacomProperty StripRightDown;
    static const XsetwacomProperty StripRightUp;
    static const XsetwacomProperty Suppress;
    static const XsetwacomProperty TabletPcButton;
    static const XsetwacomProperty TapTime;
    static const XsetwacomProperty Threshold;
    static const XsetwacomProperty Touch;
    static const XsetwacomProperty ZoomDistance;

private:
    XsetwacomProperty(const Property& id, const QString& key) : XsetwacomPropertyTemplateSpecialization(this, id, key) {}

}; // CLASS

// instances container specialization declaration
template<>
XsetwacomPropertyTemplateSpecialization::PropertySetTemplateSpecialization::Container XsetwacomPropertyTemplateSpecialization::PropertySetTemplateSpecialization::instances;

}      // NAMESPACE
#endif // HEADER PROTECTION
