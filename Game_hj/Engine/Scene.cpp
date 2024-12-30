#include "pch.h"
#include "Scene.h"
#include "GameObject.h"

void Scene::Awake()
{
	
	/*for (size_t i = 0; i < _gameObjects.size(); i++)
	{
		const shared_ptr<GameObject>& gameObject = _gameObjects[i];
	}*/

	// C#기준으로 foreach와 같은 기능
	// 위에 for문과 똑같은 기능
	// 근데 이 버전을 사용을 하면은 
	// 만약에 안에 있는 데이터를 고치지 않고 그냥 쭉 스캔을 하는 용도로만 활용할 것이라고 하면은 
	// 얘가 훨씬 더 가독성이 또 좋다는 걸 알 수가 있는 거죠
	for (const shared_ptr<GameObject>& gameObject : _gameObjects)
	{
		gameObject->Awake();
	}
	// const 포인터로 받아 놨느냐 사실 요렇게 해도된다.
	// 근데 shared_ptr 어떤 물체를 이런 식으로 복사를 하게 되면은 얘가 내부적으로 참조 카운트가 1이 증가한다.
	// 근데 const shared_ptr 로 받아주면 그 레퍼런스 카운트 부분이 동작을 하지 않는다
	// 지금 같은 경우는 복사해가지고 딴데 넘기고 이런 개념이 아니라 
	// 잠시 한번만 사용을 했다가 잊어줄거기 때문에 이런식으로 레퍼런스를 들고 있으면 성능적으로 더 좋은 향상을 얻는다
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