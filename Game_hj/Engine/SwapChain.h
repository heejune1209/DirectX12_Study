#pragma once


// 교환 사슬
// [외주 과정]
// - 현재 게임 세상에 있는 상황을 묘사
// - 어떤 공식으로 어떻게 계산할지 던져줌
// - GPU가 열심히 계산 (외주)
// - 결과물 받아서 화면에 그려준다

// [외주 결과물]을 어디에 받지?
// - 어떤 종이(Buffer)에 그려서 건내달라고 부탁해보자
// - 특수 종이를 만들어서 -> 처음에 건내주고 -> 결과물을 해당 종이에 받는다 OK
// - 우리 화면에 특수 종이(외주 결과물) 출력해준다

// [?]
// - 그런데 화면에 현재 결과물 출력하는 와중에, 다음 화면도 외주를 맡겨야 함
// - 현재 화면 결과물은 이미 화면 출력에 사용중
// - 특수 종이를 2개 만들어서, 하나는 현재 화면을 그려주고, 하나는 외주 맡기고...
// - Double Buffering!

// - [0] [1]
// 현재 화면 [1]  <-> GPU 작업중 [1] BackBuffer

class SwapChain
{
public:
	void Init(const WindowInfo& info, ComPtr<ID3D12Device> device, ComPtr<IDXGIFactory> dxgi, ComPtr<ID3D12CommandQueue> cmdQueue);
	void Present();
	void SwapIndex();

	ComPtr<IDXGISwapChain> GetSwapChain() { return _swapChain; }
	ComPtr<ID3D12Resource> GetRenderTarget(int32 index) { return _rtvBuffer[index]; }

	ComPtr<ID3D12Resource> GetBackRTVBuffer() { return _rtvBuffer[_backBufferIndex]; }
	D3D12_CPU_DESCRIPTOR_HANDLE GetBackRTV() { return _rtvHandle[_backBufferIndex]; }

private:
	void CreateSwapChain(const WindowInfo& info, ComPtr<IDXGIFactory> dxgi, ComPtr<ID3D12CommandQueue> cmdQueue);
	void CreateRTV(ComPtr<ID3D12Device> device);

private:
	ComPtr<IDXGISwapChain>	_swapChain;
	
	ComPtr<ID3D12Resource>			_rtvBuffer[SWAP_CHAIN_BUFFER_COUNT];
	ComPtr<ID3D12DescriptorHeap>	_rtvHeap;
	D3D12_CPU_DESCRIPTOR_HANDLE		_rtvHandle[SWAP_CHAIN_BUFFER_COUNT];

	uint32					_backBufferIndex = 0;
};

// Swap Chain
// Device 함수에서 내가 동작시킬 장치의 정보를 담았다면, 그 장치에 전달할 내용을 도와주는 함수이다.
// 현재 게임 세상에 있는 상황을 묘사하고, 어떤 공식으로 어떻게 계산할지 정해줘야한다.
// 그런 다음 GPU가 계산을 완료하면 결과물이 나오게 되는데, 이 결과물을 어디에 받을지 정해주는 기능을 한다.
// 결과물은 보통 버퍼(Buffer)를 통해 받게 되는데 두 개 이상의 버퍼를 이용해 결과물을 받고, 다음 결과물을 다른 버퍼에 그리는 동작을 반복 수행한다.
// 그리고 참고로 버퍼(Buffer)란, 데이터를 한 곳에서 다른 한 곳으로 전송하는 동안 일시적으로 그 데이터를 보관하는 메모리의 영역이다.
// 결국 버퍼는 두개의 장치 사이에서 데이터 전송할 때 데이터의 전송 속도나 처리 속도의 차이를 완화하는 목적으로 사용하는 기억장치인 것이다.