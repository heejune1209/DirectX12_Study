#pragma once
#include "Component.h"


// �̵���ǥ ��ų� �ΰ��ӿ��� ��ġ�� ���õ� �κе��� �� Ʈ���������� �Ⱦ� �־��ָ� �ȴ�
// ������ �ѹ��� ������ָ� �� ������Ʈ ����� ������ ���ϴ�
class Transform : public Component
{
public:
	Transform();
	virtual ~Transform();

	virtual void FinalUpdate() override;
	void PushData();
	
public:
	// Parent ����
	const Vec3& GetLocalPosition() { return _localPosition; }
	const Vec3& GetLocalRotation() { return _localRotation; }
	const Vec3& GetLocalScale() { return _localScale; }

	// �ڽ��� �θ� ��Ⱑ �ƴ϶� �� ��ü�� ���� �����̽����� ����� �پ�ѱ����� ����� ����ϰ��ִ�
	const Matrix& GetLocalToWorldMatrix() { return _matWorld; }
	// _matWorld�� ����� �������� ��ȯ����̴�
	Vec3 GetWorldPosition() { return _matWorld.Translation(); }
	// _matWorld.Translation() -> (Vector3(_41, _42, _43))�� ������ǥ�̴�

	Vec3 GetRight() { return _matWorld.Right(); }
	Vec3 GetUp() { return _matWorld.Up(); }
	Vec3 GetLook() { return _matWorld.Backward(); }
	// �ӽð��� ����ְ� �ֱ� ������ �ӽð��� �������� �ϱ�� �׷��� ���縦 �ϴ� ���·� �����

	void SetLocalPosition(const Vec3& position) { _localPosition = position; }
	void SetLocalRotation(const Vec3& rotation) { _localRotation = rotation; }
	void SetLocalScale(const Vec3& scale) { _localScale = scale; }

public:
	void SetParent(shared_ptr<Transform> parent) { _parent = parent; }
	weak_ptr<Transform> GetParent() { return _parent; }

	// TODO : �°� Parent/Child ����

private:
	// Parent ����
	Vec3 _localPosition = {};
	Vec3 _localRotation = {};
	Vec3 _localScale = { 1.f, 1.f, 1.f };

	Matrix _matLocal = {}; // �� �θ� �������� ��ǥ��
	Matrix _matWorld = {};

	weak_ptr<Transform> _parent;
};

