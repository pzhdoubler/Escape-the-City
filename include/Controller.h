#ifndef _CONTROLLER_H_

#include <GameLogic.h>


class Controller 
{

	public:
		Controller() {};

		bool init(GameLogic &logic);

		enum Controls
		{
			PAUSE,
			FAST_LEFT,
			FAST_RIGHT,
			FAST_JUMP,
			FAST_DOWN,
			FAST_USE,
			JUMP_LEFT,
			JUMP_RIGHT,
			JUMP_JUMP,
			JUMP_DOWN,
			JUMP_USE,
			CONTROLS_LEN
		};

		bool editKey(Controls key, int new_binding);

		bool update(float deltaMs);

	private:

		GameLogic logic;

		int bindings[CONTROLS_LEN];

};

#endif // !_CONTROLLER_H_
