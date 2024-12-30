#include "pch.h"
#include "Scene.h"
#include "GameObject.h"

void Scene::Awake()
{
	
	/*for (size_t i = 0; i < _gameObjects.size(); i++)
	{
		const shared_ptr<GameObject>& gameObject = _gameObjects[i];
	}*/

	// C#�������� foreach�� ���� ���
	// ���� for���� �Ȱ��� ���
	// �ٵ� �� ������ ����� �ϸ��� 
	// ���࿡ �ȿ� �ִ� �����͸� ��ġ�� �ʰ� �׳� �� ��ĵ�� �ϴ� �뵵�θ� Ȱ���� ���̶�� �ϸ��� 
	// �갡 �ξ� �� �������� �� ���ٴ� �� �� ���� �ִ� ����
	for (const shared_ptr<GameObject>& gameObject : _gameObjects)
	{
		gameObject->Awake();
	}
	// const �����ͷ� �޾� ������ ��� �䷸�� �ص��ȴ�.
	// �ٵ� shared_ptr � ��ü�� �̷� ������ ���縦 �ϰ� �Ǹ��� �갡 ���������� ���� ī��Ʈ�� 1�� �����Ѵ�.
	// �ٵ� const shared_ptr �� �޾��ָ� �� ���۷��� ī��Ʈ �κ��� ������ ���� �ʴ´�
	// ���� ���� ���� �����ذ����� ���� �ѱ�� �̷� ������ �ƴ϶� 
	// ��� �ѹ��� ����� �ߴٰ� �ؾ��ٰű� ������ �̷������� ���۷����� ��� ������ ���������� �� ���� ����� ��´�
}

void Scene::Start()
{
	for (const shared_ptr<GameObject>& gameObject : _gameObjects)
	{
		gameObject->Start();
	}
}

void Scene::Update()
{
	for (const shared_ptr<GameObject>& gameObject : _gameObjects)
	{
		gameObject->Update();
	}
}

void Scene::LateUpdate()
{
	for (const shared_ptr<GameObject>& gameObject : _gameObjects)
	{
		gameObject->LateUpdate();
	}
}

void Scene::FinalUpdate()
{
	for (const shared_ptr<GameObject>& gameObject : _gameObjects)
	{
		gameObject->FinalUpdate();
	}
}

void Scene::AddGameObject(shared_ptr<GameObject> gameObject)
{
	_gameObjects.push_back(gameObject);
}

void Scene::RemoveGameObject(shared_ptr<GameObject> gameObject)
{
	auto findIt = std::find(_gameObjects.begin(), _gameObjects.end(), gameObject);
	if (findIt != _gameObjects.end())
	{
		_gameObjects.erase(findIt);
	}
}