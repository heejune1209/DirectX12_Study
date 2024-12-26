#pragma once

enum class KEY_TYPE
{
	UP = VK_UP,
	DOWN = VK_DOWN,
	LEFT = VK_LEFT,
	RIGHT = VK_RIGHT,

	W = 'W',
	A = 'A',
	S = 'S',
	D = 'D',
};

enum class KEY_STATE
{
	NONE,
	PRESS,
	DOWN,
	UP,
	END
};

enum
{
	KEY_TYPE_COUNT = static_cast<int32>(UINT8_MAX + 1),
	KEY_STATE_COUNT = static_cast<int32>(KEY_STATE::END),
};

class Input
{
	DECLARE_SINGLE(Input);

public:
	void Init(HWND hwnd);
	void Update();

	// 누르고 있을 때
	bool GetButton(KEY_TYPE key) { return GetState(key) == KEY_STATE::PRESS; }
	// 맨 처음 눌렀을 때
	bool GetButtonDown(KEY_TYPE key) { return GetState(key) == KEY_STATE::DOWN; }
	// 맨 처음 눌렀다 뗐을 때
	bool GetButtonUp(KEY_TYPE key) { return GetState(key) == KEY_STATE::UP; }

private:
	inline KEY_STATE GetState(KEY_TYPE key) { return _states[static_cast<uint8>(key)]; }
	// 각 키에 해당하는 벡터를 하나를 만들어가지고 각 키에 해당하는 상태를 지금 이렇게 관리를
	// 하고 있다고 보시면 되겠습니다. 예를 들면 내가 W키를 눌렀는지를 보고 싶으면 이 W키에 해당하는 번호의 state를
	// 검색해가지고 지금 이렇게 확인을 할 수가 있는 거죠.
private:
	HWND _hwnd;
	vector<KEY_STATE> _states;
};

// 3D 작업엔 필연적으로 다양한 기능이 필요하다. 
// 그 중 카메라 기능이 반드시 들어가는데, 해당 기능을 자유자재로 컨트롤하기 위해선 입력값이 필요하다. 
// 또한 캐릭터 등이 이동할 때도 시간에 비례한 거리를 이동해야 하기 때문에 시간을 재주는 기능도 필요하다.

// Input
// 입력값에 대해 알맞은 이벤트를 적용해줄 수 있는 함수이다.
// 입력값을 받는 기능을 이미 정의되어있다.알맞은 기능을 골라서 사용하면 쉽게 입력값을 받을 수 있다.
// KEY_TYPE과 KEY_STATE은 enum class로 설정된 상수값이고 
// 매 프레임마다 키를 체크하여 상태를 변경하고 _state를 설정한다.