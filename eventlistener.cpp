#include "eventlistener.h"
#include "kwin/input.h"
#include "kwin/input_event.h"
#include "kwin/keyboard_input.h"
#include "kwin/keyboard_layout.h"
#include <linux/input-event-codes.h>

#include <QDebug>

namespace KWin {

EventListener::EventListener() {
	input()->installInputEventSpy(this);
}

void EventListener::keyboardKey(KeyboardKeyEvent *event) {
	if (event->state != KeyboardKeyState::Pressed && event->state != KeyboardKeyState::Released)
		return;

	if (event->nativeScanCode != KEY_LEFTALT && event->nativeScanCode != KEY_LEFTSHIFT)
		return;

	switch (event->nativeScanCode) {
		case KEY_LEFTALT:
			m_altPressed = (event->state == KeyboardKeyState::Pressed);
		break;

		case KEY_LEFTSHIFT:
			m_shiftPressed = (event->state == KeyboardKeyState::Pressed);
		break;
	}

	if (m_altPressed && m_shiftPressed) {
		auto layout = input()->keyboard()->keyboardLayout();
		layout->switchToNextLayout();
		return;
	}
}

} // namespace KWin

#include "moc_eventlistener.cpp"
