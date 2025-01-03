#pragma once

#pragma comment(lib, "Engine.lib") // 속성에 가서 추가 종속성을 굳이 귀찮게 하지 않고 전처리기를 이용해서 한번에 해줬다 

#include "EnginePch.h"
//#include <vector>
//#include <memory>
//using namespace std;
// 여기선 우리가 자주 활용을 할것들을 여기다가 몰빵해서 넣어준다고 보면된다

// Pch란 Pre-Compiled Header의 약자로써 미리 컴파일된 헤더파일이라는 뜻이다. 프로그램이 실행될 때마다 컴파일, 빌드, 실행이 이루어지는데 
// 거의 바뀌지 않을 파일을 매번 컴파일하는 것은 약간의 부담이 된다. 
// 그러한 파일들을 미리 컴파일 해둔 후 빌드할 때마다 연결해주기 위해 사용한다. 
// .pch 확장자로도 사용하는데 지금은 일반 파일로 관리해 볼 것이다.

// 그리고 벡터와 메모리를 이렇게 프로젝트 외부에다가 빼주면 굉장히 많은 장점이 있다
// 해당 코드들을 전부 재사용할 수 있게 되는 굉장히 큰 장점이 생기기 때문에 그렇게 라이브러리로 관리를 한다고 보시면 되겠습니다


// 이렇게 해가지고 라이브러리와 클라이언트로 분할을 한 부분까지 일단 완료가 되었다