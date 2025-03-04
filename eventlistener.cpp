/*
    SPDX-FileCopyrightText: 2024 Vlad Zahorodnii <vlad.zahorodnii@kde.org>

    SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDE-Accepted-GPL
*/
#include "eventlistener.h"
#include "kwin/input.h"
#include "kwin/input_event.h"
#include "kwin/keyboard_input.h"
#include "kwin/keyboard_layout.h"
#include <linux/input-event-codes.h>

#include <QDebug>

namespace KWin
{

EventListener::EventListener()
{
    qInfo() << "xuj?";
    input()->installInputEventSpy(this);
}

void EventListener::keyEvent(KeyEvent *event)
{
    if (event->type() != QEvent::KeyPress && event->type() != QEvent::KeyRelease) {
        return;
    }

    QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
    bool pressed = event->type() == QEvent::KeyPress;

    if (keyEvent->nativeScanCode() != KEY_LEFTALT && keyEvent->nativeScanCode() != KEY_LEFTSHIFT) {
        return;
    }

    switch (keyEvent->nativeScanCode())
    {
        case KEY_LEFTALT:
            pressed? m_keysPressed |= Qt::AltModifier : m_keysPressed &= ~Qt::AltModifier;
            break;

        case KEY_LEFTSHIFT:
            pressed? m_keysPressed |= Qt::ShiftModifier : m_keysPressed &= ~Qt::ShiftModifier;
            break;
    }

    if ((m_keysPressed & Qt::AltModifier) && (m_keysPressed & Qt::ShiftModifier)) {
        auto layout = input()->keyboard()->keyboardLayout();
        layout->switchToNextLayout();
        return;
    }
}

} // namespace KWin

#include "moc_eventlistener.cpp"
