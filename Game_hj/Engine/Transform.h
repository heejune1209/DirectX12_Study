#pragma once
#include "Component.h"

struct TransformMatrix
{
	Vec4 offset;
};

// �̵���ǥ ��ų� �ΰ��ӿ��� ��ġ�� ���õ� �κе��� �� Ʈ���������� �Ⱦ� �־��ָ� �ȴ�
// ������ �ѹ��� ������ָ� �� ������Ʈ ����� ������ ���ϴ�
class Transform : public Component
{
public:
	Transform();
	virtual ~Transform();

	// TODO : �°� Parent/Child ����

private:
	// TODO : World ��ġ ����

};

