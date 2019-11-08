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
			FAST_RESPAWN,
			JUMP_LEFT,
			JUMP_RIGHT,
			JUMP_JUMP,
			JUMP_DOWN,
			JUMP_USE,
			JUMP_RESPAWN,
			CONTROLS_LEN,
			PAUSE_RELEASE,
			FAST_LEFT_RELEASE,
			FAST_RIGHT_RELEASE,
			FAST_JUMP_RELEASE,
			FAST_DOWN_RELEASE,
			FAST_USE_RELEASE,
			FAST_RESPAWN_RELEASE,
			JUMP_LEFT_RELEASE,
			JUMP_RIGHT_RELEASE,
			JUMP_JUMP_RELEASE,
			JUMP_DOWN_RELEASE,
			JUMP_USE_RELEASE,
			JUMP_RESPAWN_RELEASE
		};

		bool editKey(Controls key, int new_binding);

		bool update(float deltaMs);

	private:

		GameLogic* logic;

		int bindings[CONTROLS_LEN];

		bool key_pressed[CONTROLS_LEN];

		bool fast_jumped, jump_jumped;

};

#endif // !_CONTROLLER_H_
