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
// �̱��� ����(Singleton Pattern)
// ��ü�� �ν��Ͻ��� ���� 1���� �����Ǵ� ������ �ǹ��Ѵ�.

// ����
// �� �޸� ���� ������ �� �ִ�.
// �� �̹� ������ �ν��Ͻ��� ����ϱ� ������ �ӵ� ���鿡���� ������ �ִ�.
// �� �ٸ� Ŭ���� ���� ������ ������ ����.
// �� ������ �������� �ν��Ͻ��� �� ���� �����ϴ� ���� �����ϰ� ���� ��쿡�� ����ϱ⵵ �Ѵ�.

// ����
// �� ������ �����ϴ� �ڵ� ��ü�� ���� �ʿ��ϴ�. (���ü� ����)
// �� �׽�Ʈ�ϱ� ��ƴ�.
// �� Ŭ���̾�Ʈ�� ��ü Ŭ������ �����ϰ� �ȴ�.
// �� �ڽ� Ŭ������ ���� �� ����.
// �� ���� ���¸� �����ϱ� ��ƴ�.

