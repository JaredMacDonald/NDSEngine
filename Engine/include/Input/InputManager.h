#pragma once
#include <nds.h>

namespace JM
{
	enum EButton
	{
		BUTTON_A				= KEY_A,
		BUTTON_B				= KEY_B,
		BUTTON_SELECT			= KEY_SELECT,
		BUTTON_START			= KEY_START,
		BUTTON_DPAD_RIGHT		= KEY_RIGHT,
		BUTTON_DPAD_LEFT		= KEY_LEFT,
		BUTTON_DPAD_UP			= KEY_UP,
		BUTTON_DPAD_DOWN		= KEY_DOWN,
		BUTTON_RIGHT_SHOULDER	= KEY_R,
		BUTTON_LEFT_SHOULDER	= KEY_L,
		BUTTON_X				= KEY_X,
		BUTTON_Y				= KEY_Y,
		BUTTON_TOUCH			= KEY_TOUCH,
		BUTTON_LID				= KEY_LID
	};

	class InputManager
	{
	public:

		static InputManager* GetInstance() 
		{
			if (Instance == nullptr)
			{
				Instance = new InputManager();
			}

			return Instance; 
		}

		~InputManager();

		void UpdateInput();

		bool IsButtonDown(EButton button);
		bool IsButtonUp(EButton button);
		bool IsButtonHeld(EButton button);


	private:
		InputManager();
				
		uint32 m_CurrentState;
		uint32 m_PrevState;

		static InputManager* Instance;
	};
}