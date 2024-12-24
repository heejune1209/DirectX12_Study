#pragma once

class SwapChain;
class DescriptorHeap;

class CommandQueue
{
public:
	~CommandQueue();

	void Init(ComPtr<ID3D12Device> device, shared_ptr<SwapChain> swapChain);
	void WaitSync();

	void RenderBegin(const D3D12_VIEWPORT* vp, const D3D12_RECT* rect);
	void RenderEnd();

	void FlushResourceCommandQueue();

	ComPtr<ID3D12CommandQueue> GetCmdQueue() { return _cmdQueue; }
	ComPtr<ID3D12GraphicsCommandList> GetCmdList() { return	_cmdList; }
	ComPtr<ID3D12GraphicsCommandList> GetResourceCmdList() { return	_resCmdList; }

private:
	// CommandQueue : DX12에 등장
	// 외주를 요청할 때, 하나씩 요청하면 비효율적
	// [외주 목록]에 일감을 차곡차곡 기록했다가 한 방에 요청하는 것
	ComPtr<ID3D12CommandQueue>			_cmdQueue;
	ComPtr<ID3D12CommandAllocator>		_cmdAlloc;
	ComPtr<ID3D12GraphicsCommandList>	_cmdList;

	ComPtr<ID3D12CommandAllocator>		_resCmdAlloc;
	ComPtr<ID3D12GraphicsCommandList>	_resCmdList;

	// Fence : 울타리(?)
	// CPU / GPU 동기화를 위한 간단한 도구
	ComPtr<ID3D12Fence>					_fence;
	uint32								_fenceValue = 0;
	HANDLE								_fenceEvent = INVALID_HANDLE_VALUE;

	shared_ptr<SwapChain>		_swapChain;
};

// Command Queue
// GPU에게 건네줄 실행 목록을 작성해주는 함수이다. 명령어가 호출되었을 때 그 즉시 실행해야 할 명령어도 있지만 
// 나중에 실행해야 할 명령어도 존재할 것이다. 또한 실행해야 할 명령어들이 너무 많으면 CPU가 놀고 반대로 명령어들이 너무 없으면 GPU가 놀게 될 것이다.
// 이러한 일의 비율을 맞춰주기 위해 커맨드 큐를 사용한다.이러한 과정에서 CPU와 GPU의 실행 차이가 생기는데, 
// 둘의 동기화를 위해 Fence 라는 간단한 도구를 사용한다.

// 어떤 행동이 일어났을때 우리가 일을 맡기고 싶을때 그거를 바로 당장 하는게 아니라 일감을 모아놨다가 
// 우리가 renderEnd라는걸 실행하는 순간 모인 일감들을 한번에 수행한다.