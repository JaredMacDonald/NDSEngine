#include <nds.h>
#include <InputManager.h>

namespace JM
{
	InputManager* InputManager::Instance = nullptr;

	InputManager::InputManager()
	{

	}

	InputManager::~InputManager()
	{

	}

	void InputManager::UpdateInput()
	{
		scanKeys();

		m_PrevState = m_CurrentState;

		m_CurrentState = keysCurrent();
	}

	bool InputManager::IsButtonDown(EButton button)
	{
		uint32 keys = keysDown();
		return keys & button;
	}

	bool InputManager::IsButtonUp(EButton button)
	{
		uint32 keys = keysUp();
		return keys & button;
	}

	bool InputManager::IsButtonHeld(EButton button)
	{
		uint32 keys = keysHeld();
		return keys & button;
	}
}