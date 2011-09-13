/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (info@qt.nokia.com)
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

#ifndef QTWINDOWSGLOBAL_H
#define QTWINDOWSGLOBAL_H

#include "qtwindows_additional.h"
#include <QtCore/qnamespace.h>

QT_BEGIN_NAMESPACE

namespace QtWindows
{

enum
{
    WindowEventFlag = 0x10000,
    MouseEventFlag = 0x20000,
    NonClientEventFlag = 0x40000,
    InputMethodEventFlag = 0x80000,
    KeyEventFlag = 0x100000,
    KeyDownEventFlag = 0x200000,
    TouchEventFlag = 0x400000,
    ClipboardEventFlag = 0x800000,
    ApplicationEventFlag = 0x1000000
};

enum WindowsEventType // Simplify event types
{
    ExposeEvent = WindowEventFlag + 1,
    ActivateWindowEvent = WindowEventFlag + 2,
    DeactivateWindowEvent = WindowEventFlag + 3,
    LeaveEvent = WindowEventFlag + 5,
    CloseEvent = WindowEventFlag + 6,
    ShowEvent = WindowEventFlag + 7,
    HideEvent = WindowEventFlag + 8,
    DestroyEvent = WindowEventFlag + 9,
    MoveEvent = WindowEventFlag + 10,
    ResizeEvent = WindowEventFlag + 12,
    QuerySizeHints = WindowEventFlag + 15,
    CalculateSize = WindowEventFlag + 16,
    MouseEvent = MouseEventFlag + 1,
    MouseWheelEvent = MouseEventFlag + 2,
    TouchEvent = TouchEventFlag + 1,
    NonClientMouseEvent = NonClientEventFlag + MouseEventFlag + 1,
    KeyEvent = KeyEventFlag + 1,
    KeyDownEvent = KeyEventFlag + KeyDownEventFlag + 1,
    InputMethodKeyEvent = InputMethodEventFlag + KeyEventFlag + 1,
    InputMethodKeyDownEvent = InputMethodEventFlag + KeyEventFlag + KeyDownEventFlag + 1,
    ClipboardEvent = ClipboardEventFlag + 1,
    ActivateApplicationEvent = ApplicationEventFlag + 1,
    DeactivateApplicationEvent = ApplicationEventFlag + 2,
    InputMethodStartCompositionEvent = InputMethodEventFlag + 1,
    InputMethodCompositionEvent = InputMethodEventFlag + 2,
    InputMethodEndCompositionEvent = InputMethodEventFlag + 3,
    InputMethodOpenCandidateWindowEvent = InputMethodEventFlag + 4,
    InputMethodCloseCandidateWindowEvent = InputMethodEventFlag + 5,
    InputMethodRequest = InputMethodEventFlag + 6,
    UnknownEvent = 542
};

} // namespace QtWindows

inline QtWindows::WindowsEventType windowsEventType(UINT message, WPARAM wParamIn)
{
    switch (message) {
    case WM_PAINT:
    case WM_ERASEBKGND:
        return QtWindows::ExposeEvent;
    case WM_CLOSE:
        return QtWindows::CloseEvent;
    case WM_DESTROY:
        return QtWindows::DestroyEvent;
    case WM_ACTIVATEAPP:
        return (int)wParamIn ?
        QtWindows::ActivateApplicationEvent : QtWindows::DeactivateApplicationEvent;
    case WM_ACTIVATE:
        return  LOWORD(wParamIn) == WA_INACTIVE ?
            QtWindows::DeactivateWindowEvent : QtWindows::ActivateWindowEvent;
    case WM_MOUSELEAVE:
        return QtWindows::MouseEvent;
    case WM_MOUSEWHEEL:
    case WM_MOUSEHWHEEL:
        return QtWindows::MouseWheelEvent;
    case WM_MOVE:
        return QtWindows::MoveEvent;
    case WM_SHOWWINDOW:
        return wParamIn ? QtWindows::ShowEvent : QtWindows::HideEvent;
    case WM_SIZE:
        return QtWindows::ResizeEvent;
    case WM_NCCALCSIZE:
        return QtWindows::CalculateSize;
    case WM_GETMINMAXINFO:
        return QtWindows::QuerySizeHints;
    case WM_KEYDOWN:                        // keyboard event
    case WM_SYSKEYDOWN:
        return QtWindows::KeyDownEvent;
    case WM_KEYUP:
    case WM_SYSKEYUP:
    case WM_CHAR:
        return QtWindows::KeyEvent;
    case WM_IME_CHAR:
        return QtWindows::InputMethodKeyEvent;
    case WM_IME_KEYDOWN:
        return QtWindows::InputMethodKeyDownEvent;
    case WM_TOUCH:
        return QtWindows::TouchEvent;
    case WM_CHANGECBCHAIN:
    case WM_DRAWCLIPBOARD:
    case WM_RENDERFORMAT:
    case WM_RENDERALLFORMATS:
    case WM_DESTROYCLIPBOARD:
        return QtWindows::ClipboardEvent;
    case WM_IME_STARTCOMPOSITION:
        return QtWindows::InputMethodStartCompositionEvent;
    case WM_IME_ENDCOMPOSITION:
        return QtWindows::InputMethodEndCompositionEvent;
    case WM_IME_COMPOSITION:
        return QtWindows::InputMethodCompositionEvent;
    case WM_IME_REQUEST:
        return QtWindows::InputMethodRequest;
    case WM_IME_NOTIFY:
         switch (int(wParamIn)) {
         case IMN_OPENCANDIDATE:
             return QtWindows::InputMethodOpenCandidateWindowEvent;
         case IMN_CLOSECANDIDATE:
             return QtWindows::InputMethodCloseCandidateWindowEvent;
         default:
             break;
         }
    default:
        break;
    }
    if (message >= WM_NCMOUSEMOVE && message <= WM_NCMBUTTONDBLCLK)
        return QtWindows::NonClientMouseEvent; //
    if ((message >= WM_MOUSEFIRST && message <= WM_MOUSELAST)
         || (message >= WM_XBUTTONDOWN && message <= WM_XBUTTONDBLCLK))
        return QtWindows::MouseEvent;
    return QtWindows::UnknownEvent;
}

QT_END_NAMESPACE

#endif // QTWINDOWSGLOBAL_H
