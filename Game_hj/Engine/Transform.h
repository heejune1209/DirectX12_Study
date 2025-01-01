#pragma once
#include "Component.h"


// 이동좌표 라거나 인게임에서 위치와 관련된 부분들은 다 트랜스폼에다 꽂아 넣어주면 된다
// 오히려 한번만 만들어주면 이 컴포넌트 방식이 굉장히 편하다
class Transform : public Component
{
public:
	Transform();
	virtual ~Transform();

	virtual void FinalUpdate() override;
	void PushData();
	
public:
	// Parent 기준
	const Vec3& GetLocalPosition() { return _localPosition; }
	const Vec3& GetLocalRotation() { return _localRotation; }
	const Vec3& GetLocalScale() { return _localScale; }

	// 자신의 부모 얘기가 아니라 그 물체의 로컬 스페이스에서 월드로 뛰어넘기위한 행렬을 얘기하고있다
	const Matrix& GetLocalToWorldMatrix() { return _matWorld; }
	// _matWorld이 월드로 가기위한 변환행렬이다
	Vec3 GetWorldPosition() { return _matWorld.Translation(); }
	// _matWorld.Translation() -> (Vector3(_41, _42, _43))는 월드좌표이다

	Vec3 GetRight() { return _matWorld.Right(); }
	Vec3 GetUp() { return _matWorld.Up(); }
	Vec3 GetLook() { return _matWorld.Backward(); }
	// 임시값을 뱉어주고 있기 때문에 임시값에 참조값을 하기는 그래서 복사를 하는 형태로 뱉어줌

	void SetLocalPosition(const Vec3& position) { _localPosition = position; }
	void SetLocalRotation(const Vec3& rotation) { _localRotation = rotation; }
	void SetLocalScale(const Vec3& scale) { _localScale = scale; }

public:
	void SetParent(shared_ptr<Transform> parent) { _parent = parent; }
	weak_ptr<Transform> GetParent() { return _parent; }

	// TODO : 온갖 Parent/Child 관계

private:
	// Parent 기준
	Vec3 _localPosition = {};
	Vec3 _localRotation = {};
	Vec3 _localScale = { 1.f, 1.f, 1.f };

	Matrix _matLocal = {}; // 내 부모를 기준으로 좌표계
	Matrix _matWorld = {};

	weak_ptr<Transform> _parent;
};

