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
	// �׷��� ȭ�� ũ�� ����
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

// Client�� Server
// ������ ���� ���߿��� Ŭ���̾�Ʈ(Client)�� ����(Server)�� ������.
// Ŭ���̾�Ʈ�� ��Ʈ��ũ�� ����� �����κ��� ������ �����޴� ��ǻ�Ͷ�� ���̸� �׷��� ��ǻ�͸� ����ϴ� ����ڱ��� �����Ͽ� �ǹ̸� ��� �ִ�.
// ������ ����ڿ��� ������ �ʴ� ���� �����ϸ� Ŭ���̾�Ʈ���� ��Ʈ��ũ�� ���� ������ ���񽺸� �����ϴ� ��ǻ�� �ý������� ��ǻ�� ���α׷� �Ǵ� ��ġ�� �ǹ��Ѵ�.
// ����(Engine)�� �������� ���Ѵ�. �� �� ������Ʈ�� ���� �и��Ͽ� �����ϸ鼭 ���ΰ��� ������ ���� �ϳ��� �ַ�� ������ ����� �� ���̴�.

// Engine
// DirectX�� �����ϱ� ���� Ŭ���̾�Ʈ�ܰ� ���������� ����� �ڵ带 ������ ���̰�, �� �� �����ܿ� ���ԵǴ� ������ ���� ���� �˾ƺ���.
// �켱 DirectX12�� 11�� �ٸ��� �ʱ�ȭ �ϴ� �κ��� ���� �������־���Ѵ�.�� �κ��� õõ�� �����غ���.

// �켱 �������� ���α׷��� �ֿ� �������� ���Եȴ�.
// �� ������� ȯ�濡 ���� �׷��� ȭ�� ũ��� ���õ� ������ ���� ���� ����� ���� ����Ʈ ������, 
// ���α׷��� ���� ����� ������ �ʱ�ȭ ���� ���� ��ǥ���̴�.

// ��� ���Ͽ��� ��κ� �Լ��� ����ΰ� ��� �Լ��� ���ԵǾ� �ִ�. �����δ� cpp ���Ͽ� �ۼ��� �� ���̴�.

// ���α׷��� ����� ������ �ʱ�ȭ���ִ� Init(), �� �����Ӹ��� ����� Update(), 
// �׸��� ȭ�鿡 ���������ִ� �Լ����� ���ԵǾ��ִ�.
// ��, ���� ���α׷��� ������ ��ǻ���� ������ �޾� â�� �����Ӱ� ������ �� �ִ� �Լ��� �߰����־���.
// DirectX���� ���� �Լ����� �����ϴµ� ������ �ܿ� �ʿ�� ���� �뷫������ ��� ����� �������� ������ �˾Ƶΰ� �Ѿ ���̴�. 
// ������Ʈ �Լ����� ���� �Լ� �ϳ��� �����Ѵٴ� ���� �� �� �ִ�.
// DirectX�� �����ϸ鼭 ������ ������������ ���� ���鼭 �Ž����� �������� ����

// DirectX��°� ��ü�� GPU���� ���ָ� �ñ�� ���� �츮�� �ǳ��� ���.
// �ʱ�ȭ�ϴ� �κ��� �߿������ʰ� �������� ���õ� ��� ������� �����°� �߿��ϴ�.
// ���α׷� ��ü�� �帧�� ������ ������� ���θ� ������ �����̴�. 
