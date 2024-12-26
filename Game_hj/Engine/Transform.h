#pragma once
#include "Component.h"

struct TransformMatrix
{
	Vec4 offset;
};

// 이동좌표 라거나 인게임에서 위치와 관련된 부분들은 다 트랜스폼에다 꽂아 넣어주면 된다
// 오히려 한번만 만들어주면 이 컴포넌트 방식이 굉장히 편하다
class Transform : public Component
{
public:
	Transform();
	virtual ~Transform();

	// TODO : 온갖 Parent/Child 관계

private:
	// TODO : World 위치 관련

};

