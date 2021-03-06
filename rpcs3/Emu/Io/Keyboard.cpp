#include "stdafx.h"
#include "Emu/ConLog.h"
#include "rpcs3/Ini.h"
#include "Keyboard.h"
#include "Null/NullKeyboardHandler.h"

KeyboardManager::KeyboardManager()
	: m_keyboard_handler(nullptr)
	, m_inited(false)
{
}

KeyboardManager::~KeyboardManager()
{
}

void KeyboardManager::Init(const u32 max_connect)
{
	if(m_inited)
		return;

	// NOTE: Change these to std::make_unique assignments when C++14 comes out.
	int numHandlers = rPlatform::getKeyboardHandlerCount();
	int selectedHandler = Ini.KeyboardHandlerMode.GetValue();
	if (selectedHandler > numHandlers)
	{
		selectedHandler = 0;
	}
	m_keyboard_handler.reset(rPlatform::getKeyboardHandler(selectedHandler));

	m_keyboard_handler->Init(max_connect);
	m_inited = true;
}

void KeyboardManager::Close()
{
	if(m_keyboard_handler) m_keyboard_handler->Close();
	m_keyboard_handler = nullptr;

	m_inited = false;
}