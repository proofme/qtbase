/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtGui module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the Technology Preview License Agreement accompanying
** this package.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <qstylehints.h>
#include <qplatformintegration_qpa.h>
#include <private/qguiapplication_p.h>

static inline QVariant hint(QPlatformIntegration::StyleHint h)
{
    return QGuiApplicationPrivate::platformIntegration()->styleHint(h);
}

QStyleHints::QStyleHints()
    : QObject()
{
}


int QStyleHints::mouseDoubleClickInterval() const
{
    return hint(QPlatformIntegration::MouseDoubleClickInterval).toInt();
}

int QStyleHints::startDragDistance() const
{
    return hint(QPlatformIntegration::StartDragDistance).toInt();
}

int QStyleHints::startDragTime() const
{
    return hint(QPlatformIntegration::StartDragTime).toInt();
}

int QStyleHints::keyboardInputInterval() const
{
    return hint(QPlatformIntegration::KeyboardInputInterval).toInt();
}

int QStyleHints::cursorFlashTime() const
{
    return hint(QPlatformIntegration::CursorFlashTime).toInt();
}
