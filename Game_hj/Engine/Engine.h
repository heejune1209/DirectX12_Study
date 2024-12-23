#pragma once
#include "Device.h"
#include "CommandQueue.h"
#include "SwapChain.h"
#include "RootSignature.h"
#include "Mesh.h"
#include "Shader.h"
#include "ConstantBuffer.h"
#include "TableDescriptorHeap.h"


class Engine
{
public:

	void Init(const WindowInfo& info);
	void Render();
public:
	shared_ptr<Device> GetDevice() { return _device; }
	shared_ptr<CommandQueue> GetCmdQueue() { return _cmdQueue; }
	shared_ptr<SwapChain> GetSwapChain() { return _swapChain; }
	shared_ptr<RootSignature> GetRootSignature() { return _rootSignature; }
	shared_ptr<ConstantBuffer> GetCB() { return _cb; }
	shared_ptr<TableDescriptorHeap> GetTableDescHeap() { return _tableDescHeap; }
public:
	void RenderBegin();
	void RenderEnd();

	void ResizeWindow(int32 width, int32 height);

private:
	// 그려질 화면 크기 관련
	WindowInfo		_window;
	D3D12_VIEWPORT	_viewport = {};
	D3D12_RECT		_scissorRect = {};

	shared_ptr<Device> _device;
	shared_ptr<CommandQueue> _cmdQueue;
	shared_ptr<SwapChain> _swapChain;
	shared_ptr<RootSignature> _rootSignature;
	shared_ptr<ConstantBuffer> _cb;
	shared_ptr<TableDescriptorHeap> _tableDescHeap;

};

// Client와 Server
// 보통의 게임 개발에는 클라이언트(Client)와 서버(Server)로 나뉜다.
// 클라이언트는 네트워크로 연결된 서버로부터 정보를 제공받는 컴퓨터라는 뜻이며 그러한 컴퓨터를 사용하는 사용자까지 포괄하여 의미를 담고 있다.
// 서버는 사용자에게 보이지 않는 곳에 존재하며 클라이언트에게 네트워크를 통해 정보나 서비스를 제공하는 컴퓨터 시스템으로 컴퓨터 프로그램 또는 장치를 의미한다.
// 엔진(Engine)은 서버단을 뜻한다. 이 두 프로젝트를 따로 분리하여 관리하면서 서로간의 연동을 통해 하나의 솔루션 파일을 만들어 볼 것이다.

// Engine
// DirectX를 공부하기 전에 클라이언트단과 서버단으로 나누어서 코드를 관리할 것이고, 그 중 서버단에 포함되는 엔진에 대해 먼저 알아보자.
// 우선 DirectX12는 11과 다르게 초기화 하는 부분을 직접 설정해주어야한다.그 부분을 천천히 진행해보자.

// 우선 엔진에는 프로그램의 주요 정보들이 포함된다.
// 각 사용자의 환경에 맞춰 그려질 화면 크기와 관련된 정보나 서로 간의 통신을 위한 스마트 포인터, 
// 프로그램이 새로 실행될 때마다 초기화 정보 등이 대표적이다.

// 헤더 파일에는 대부분 함수의 선언부가 멤버 함수로 포함되어 있다. 구현부는 cpp 파일에 작성해 줄 것이다.

// 프로그램이 실행될 때마다 초기화해주는 Init(), 매 프레임마다 실행될 Update(), 
// 그리고 화면에 렌더링해주는 함수들이 포함되어있다.
// 또, 현재 프로그램을 실행한 컴퓨터의 정보를 받아 창을 자유롭게 조절할 수 있는 함수를 추가해주었다.
// DirectX에는 많은 함수들이 등장하는데 일일이 외울 필요는 없고 대략적으로 어떠한 기능을 가지는지 정도만 알아두고 넘어갈 것이다. 
// 업데이트 함수에는 렌더 함수 하나만 존재한다는 것을 알 수 있다.
// DirectX를 공부하면서 나무를 보려하지말고 숲을 보면서 거시적인 관점으로 공부

// DirectX라는것 자체는 GPU한테 외주를 맡기기 위한 우리의 피나는 노력.
// 초기화하는 부분은 중요하지않고 렌더링과 관련된 고급 기법들을 익히는게 중요하다.
// 프로그램 전체의 흐름을 익히는 방식으로 공부를 진행할 예정이다. 
