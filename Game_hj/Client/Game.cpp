#include "pch.h"
#include "Game.h"
#include "Engine.h"
#include "SceneManager.h"



void Game::Init(const WindowInfo& info)
{
	GEngine->Init(info);
	GET_SINGLE(SceneManager)->LoadScene(L"TestScene");
	
}

void Game::Update()
{
	GEngine->Update();


	
	//{
	//	static Transform t = {};

	//	if (INPUT->GetButton(KEY_TYPE::W))
	//		//t.offset.y += 1.f * 0.001;
	//		t.offset.y += 1.f * DELTA_TIME;
	//	if (INPUT->GetButton(KEY_TYPE::S))
	//		t.offset.y -= 1.f * DELTA_TIME;
	//	if (INPUT->GetButton(KEY_TYPE::A))
	//		t.offset.x -= 1.f * DELTA_TIME;
	//	if (INPUT->GetButton(KEY_TYPE::D))
	//		t.offset.x += 1.f * DELTA_TIME;
	//	// ���� ���� �ڵ忡�� * 0.001 �κ��� �ð�(������)�� �ش��Ѵ�. 
	//	// ���������� �Լ��� ���� ���� �ð��� ����Ͽ� �����غ���.
	//	mesh->SetTransform(t);

	//	mesh->Render();
	//}

	/*{
		Transform t;
		t.offset = Vec4(0.f, 0.f, 0.3f, 0.f);
		mesh->SetTransform(t);

		mesh->SetTexture(texture);

		mesh->Render();
	}*/

	// �ϳ��� �׸��� ���ؼ� �ּ�
	/*{
		Transform t;
		t.offset = Vec4(0.f, 0.f, 0.3f, 0.f);
		mesh->SetTransform(t);

		mesh->Render();
	}*/
	// �ּ��� Ǯ�� �̹����� �ΰ��� ��Ÿ���� �������� �κ��� �����
    // �־����ڸ��� ������ǥ�� ����
}
