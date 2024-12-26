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

	// ������ ���� ��
	bool GetButton(KEY_TYPE key) { return GetState(key) == KEY_STATE::PRESS; }
	// �� ó�� ������ ��
	bool GetButtonDown(KEY_TYPE key) { return GetState(key) == KEY_STATE::DOWN; }
	// �� ó�� ������ ���� ��
	bool GetButtonUp(KEY_TYPE key) { return GetState(key) == KEY_STATE::UP; }

private:
	inline KEY_STATE GetState(KEY_TYPE key) { return _states[static_cast<uint8>(key)]; }
	// �� Ű�� �ش��ϴ� ���͸� �ϳ��� �������� �� Ű�� �ش��ϴ� ���¸� ���� �̷��� ������
	// �ϰ� �ִٰ� ���ø� �ǰڽ��ϴ�. ���� ��� ���� WŰ�� ���������� ���� ������ �� WŰ�� �ش��ϴ� ��ȣ�� state��
	// �˻��ذ����� ���� �̷��� Ȯ���� �� ���� �ִ� ����.
private:
	HWND _hwnd;
	vector<KEY_STATE> _states;
};

// 3D �۾��� �ʿ������� �پ��� ����� �ʿ��ϴ�. 
// �� �� ī�޶� ����� �ݵ�� ���µ�, �ش� ����� ��������� ��Ʈ���ϱ� ���ؼ� �Է°��� �ʿ��ϴ�. 
// ���� ĳ���� ���� �̵��� ���� �ð��� ����� �Ÿ��� �̵��ؾ� �ϱ� ������ �ð��� ���ִ� ��ɵ� �ʿ��ϴ�.

// Input
// �Է°��� ���� �˸��� �̺�Ʈ�� �������� �� �ִ� �Լ��̴�.
// �Է°��� �޴� ����� �̹� ���ǵǾ��ִ�.�˸��� ����� ��� ����ϸ� ���� �Է°��� ���� �� �ִ�.
// KEY_TYPE�� KEY_STATE�� enum class�� ������ ������̰� 
// �� �����Ӹ��� Ű�� üũ�Ͽ� ���¸� �����ϰ� _state�� �����Ѵ�.