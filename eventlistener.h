#pragma once

#include "kwin/input_event_spy.h"
#include "kwin/input.h"
#include "kwin/plugin.h"

namespace KWin {

class EventListener : public Plugin, public InputEventSpy {
	Q_OBJECT
public:
	EventListener();

	void keyboardKey(KeyboardKeyEvent *event) override;

private:
    bool m_altPressed = false;
    bool m_shiftPressed = false;
};

} // namespace KWin
