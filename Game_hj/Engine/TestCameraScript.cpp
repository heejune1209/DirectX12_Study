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
	// �̷��� �Լ��� �Լ��� ȣ���ϴ� ���� �޼��� ü�̴��̶�� �ϰ� 
	// �̴� ��ü�� �޼��尡 �����ͳ� ������ ��ȯ�� �� �����ϴ�.
	// GetTransform() �� �Լ��� ��ü�� ��ü �����͸� ��ȯ�Ѵ�. ���⼭ ��ȯ�� ��ü��
	// GetLocalPosition�� ȣ���Ҽ� �ִ� �޼��带 �����ϰ� �־���Ѵ�.

	// GetLocalPosition()
	// GetTransform()���� ��ȯ�� ��ü(������)�� �޼����̴�.
	// �̴� ���� ��ǥ�� ��Ÿ���� Vec3 ���� ��ȯ�ϴ� �޼����̴�.

	// �۵� ���
	
	// ��ü ��ȯ:
	// GetTransform()�� Ư�� ��ü(�Ǵ� ��ü ������)�� ��ȯ�Ѵ�.
	// GetTransform()�� ��ü�� ��ȯ ������ ��� �ִ� Transform ��ü�� ��ȯ�Ѵ�.
	
	// ��ü�� �޼��� ȣ�� :
	// ��ȯ�� ��ü�� Transform Ŭ������ �����Ͷ��, -> �����ڸ� ����� GetLocalPosition()�� ȣ���� �� �ִ�.

	// ���� GetTransform()�� ������ ��ȯ�ߴٸ�, . (�� ������)�� �����ؾ� �Ѵ�.
	// ��ø ȣ���� ����
	// 1) �� ������(��ü ����)
	/*Transform& transform = gameObject.GetTransform();
	Vec3 pos = transform.GetLocalPosition();*/
	
	// (2) �Լ� ü�̴� (������)
	/*Vec3 pos = gameObject.GetTransform()->GetLocalPosition();*/
	// �� �ڵ�� �����ϰ� �۵��ϸ�, �Լ� ü�̴��� �ڵ带 �� �����ϰ� �����.

	// ������
	// 1) ������ NULL üũ:
	// GetTransform()�� nullptr�� ��ȯ�ϸ�->�����ڸ� ����� �� ��Ÿ�� ������ �߻��Ѵ�.
	// �׻� �����͸� �����ϴ� ���� �߿��ϴ�.

	// 2) ����� �����:
	// �Լ� ü�̴��� ���������� �ڵ尡 ������������, ������̳� ���������� ������� �� �ֽ��ϴ�.�ʿ��� ��� ü���� �и��� ����ϴ°� ����.
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