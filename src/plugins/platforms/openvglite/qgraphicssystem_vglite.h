/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the plugins of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QGRAPHICSSYSTEM_VGLITE_H
#define QGRAPHICSSYSTEM_VGLITE_H

#include <QtGui/private/qgraphicssystem_p.h>
#include <QtGui/private/qegl_p.h>
#include <QtGui/qimage.h>

QT_BEGIN_NAMESPACE

class QVGLiteWindowSurface;

class QVGLiteGraphicsSystem : public QGraphicsSystem,
                              public QGraphicsSystemScreen
{
public:
    QVGLiteGraphicsSystem();
    ~QVGLiteGraphicsSystem();

    QPlatformPixmap *createPlatformPixmap(QPlatformPixmap::PixelType type) const;
    QWindowSurface *createWindowSurface(QWidget *widget) const;
    QList<QGraphicsSystemScreen *> screens() const { return mScreens; }

    QRect geometry() const { return QRect(0, 0, w, h); }
    int depth() const { return d; }
    QImage::Format format() const { return screenFormat; }
    QSize physicalSize() const { return QSize(physWidth, physHeight); }

private:
    friend class QVGLiteWindowSurface;

    int w;
    int h;
    int d;

    int dw;
    int dh;

    int physWidth;
    int physHeight;

    mutable QVGLiteWindowSurface *surface;
    QEglContext *context;
    EGLSurface rootWindow;
    QImage::Format screenFormat;
    bool preservedSwap;

    QList<QGraphicsSystemScreen *> mScreens;
};

QT_END_NAMESPACE

#endif
