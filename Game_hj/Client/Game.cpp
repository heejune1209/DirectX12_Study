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
	//	// 위의 적용 코드에서 * 0.001 부분이 시간(프레임)에 해당한다. 
	//	// 마찬가지로 함수를 따로 빼서 시간을 계산하여 적용해보자.
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

	// 하나만 그리기 위해서 주석
	/*{
		Transform t;
		t.offset = Vec4(0.f, 0.f, 0.3f, 0.f);
		mesh->SetTransform(t);

		mesh->Render();
	}*/
	// 주석을 풀면 이미지가 두개가 나타나서 가려지는 부분이 생긴다
    // 넣어주자마자 투영좌표로 세팅
}
