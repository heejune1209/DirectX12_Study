#include "pch.h"
#include "TestCameraScript.h"
#include "Transform.h"
#include "Camera.h"
#include "GameObject.h"
#include "Input.h"
#include "Timer.h"

TestCameraScript::TestCameraScript()
{
}

TestCameraScript::~TestCameraScript()
{
}

void TestCameraScript::LateUpdate()
{
	Vec3 pos = GetTransform()->GetLocalPosition();
	// 이렇게 함수에 함수를 호출하는 것은 메서드 체이닝이라고 하고 
	// 이는 객체의 메서드가 포인터나 참조를 반환할 때 가능하다.
	// GetTransform() 이 함수는 객체나 객체 포인터를 반환한다. 여기서 반환된 객체는
	// GetLocalPosition을 호출할수 있는 메서드를 포함하고 있어야한다.

	// GetLocalPosition()
	// GetTransform()으로 반환된 객체(포인터)의 메서드이다.
	// 이는 로컬 좌표를 나타내는 Vec3 값을 반환하는 메서드이다.

	// 작동 방식
	
	// 객체 반환:
	// GetTransform()은 특정 객체(또는 객체 포인터)를 반환한다.
	// GetTransform()은 객체의 변환 정보를 담고 있는 Transform 객체를 반환한다.
	
	// 객체의 메서드 호출 :
	// 반환된 객체가 Transform 클래스의 포인터라면, -> 연산자를 사용해 GetLocalPosition()을 호출할 수 있다.

	// 만약 GetTransform()이 참조를 반환했다면, . (점 연산자)로 접근해야 한다.
	// 중첩 호출의 예시
	// 1) 점 연산자(객체 참조)
	/*Transform& transform = gameObject.GetTransform();
	Vec3 pos = transform.GetLocalPosition();*/
	
	// (2) 함수 체이닝 (포인터)
	/*Vec3 pos = gameObject.GetTransform()->GetLocalPosition();*/
	// 두 코드는 동일하게 작동하며, 함수 체이닝은 코드를 더 간결하게 만든다.

	// 주의점
	// 1) 포인터 NULL 체크:
	// GetTransform()이 nullptr을 반환하면->연산자를 사용할 때 런타임 오류가 발생한다.
	// 항상 포인터를 검증하는 것이 중요하다.

	// 2) 디버깅 어려움:
	// 함수 체이닝이 많아질수록 코드가 간결해지지만, 디버깅이나 유지보수가 어려워질 수 있습니다.필요한 경우 체인을 분리해 사용하는게 좋다.
	if (INPUT->GetButton(KEY_TYPE::W))
		pos += GetTransform()->GetLook() * _speed * DELTA_TIME;

	if (INPUT->GetButton(KEY_TYPE::S))
		pos -= GetTransform()->GetLook() * _speed * DELTA_TIME;

	if (INPUT->GetButton(KEY_TYPE::A))
		pos -= GetTransform()->GetRight() * _speed * DELTA_TIME;

	if (INPUT->GetButton(KEY_TYPE::D))
		pos += GetTransform()->GetRight() * _speed * DELTA_TIME;

	if (INPUT->GetButton(KEY_TYPE::Q))
	{
		Vec3 rotation = GetTransform()->GetLocalRotation();
		rotation.x += DELTA_TIME * 0.5f;
		GetTransform()->SetLocalRotation(rotation);
	}

	if (INPUT->GetButton(KEY_TYPE::E))
	{
		Vec3 rotation = GetTransform()->GetLocalRotation();
		rotation.x -= DELTA_TIME * 0.5f;
		GetTransform()->SetLocalRotation(rotation);
	}

	GetTransform()->SetLocalPosition(pos);
}