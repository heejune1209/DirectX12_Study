#pragma once

class Scene;

class SceneManager
{
	DECLARE_SINGLE(SceneManager);

public:
	void Update();
	void Render();
	void LoadScene(wstring sceneName);

public:
	shared_ptr<Scene> GetActiveScene() { return _activeScene; }

private:
	shared_ptr<Scene> LoadTestScene();

private:
	shared_ptr<Scene> _activeScene;
};
// 싱글톤 패턴(Singleton Pattern)
// 객체의 인스턴스가 오직 1개만 생성되는 패턴을 의미한다.

// 장점
// ● 메모리 낭비를 방지할 수 있다.
// ● 이미 생성된 인스턴스를 사용하기 때문에 속도 측면에서도 이점이 있다.
// ● 다른 클래스 간에 데이터 공유가 쉽다.
// ● 도메인 관점에서 인스턴스가 한 개만 존재하는 것을 보증하고 싶은 경우에도 사용하기도 한다.

// 단점
// ● 패턴을 구현하는 코드 자체가 많이 필요하다. (동시성 문제)
// ● 테스트하기 어렵다.
// ● 클라이언트가 구체 클래스에 의존하게 된다.
// ● 자식 클래스를 만들 수 없다.
// ● 내부 상태를 변경하기 어렵다.

