#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

//Forward declaration of logic
class GameLogic;


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
			FAST_JUMP_RELEASE,
			JUMP_JUMP_RELEASE,
			CONTROLS_LEN
		};

		bool editKey(Controls key, int new_binding);

		bool update(float deltaMs);

	private:

		GameLogic* logic;

		int bindings[CONTROLS_LEN];

		bool fast_jumped, jump_jumped;

};

#endif // !_CONTROLLER_H_
