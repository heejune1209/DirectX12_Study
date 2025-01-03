#pragma once

enum class CONSTANT_BUFFER_TYPE : uint8
{
	GLOBAL,
	TRANSFORM,
	MATERIAL,
	END
};

enum
{
	CONSTANT_BUFFER_COUNT = static_cast<uint8>(CONSTANT_BUFFER_TYPE::END)
};

class ConstantBuffer
{
public:
	ConstantBuffer();
	~ConstantBuffer();

	void Init(CBV_REGISTER reg, uint32 size, uint32 count);

	void Clear();
	void PushData(void* buffer, uint32 size);
	void SetGlobalData(void* buffer, uint32 size);

	D3D12_GPU_VIRTUAL_ADDRESS GetGpuVirtualAddress(uint32 index);
	D3D12_CPU_DESCRIPTOR_HANDLE GetCpuHandle(uint32 index);

private:
	void CreateBuffer();
	void CreateView();

private:
	ComPtr<ID3D12Resource>	_cbvBuffer;
	BYTE*					_mappedBuffer = nullptr;
	uint32					_elementSize = 0;
	uint32					_elementCount = 0;

	ComPtr<ID3D12DescriptorHeap>		_cbvHeap;
	D3D12_CPU_DESCRIPTOR_HANDLE			_cpuHandleBegin = {};
	uint32								_handleIncrementSize = 0;

	uint32					_currentIndex = 0;

	CBV_REGISTER			_reg = {};
};
// Constant Buffer
// 일반적인 상수를 저장하기 위해 사용하는 버퍼(Buffer)이다.
// 정점 버퍼와 비슷하지만 상수를 저장하기 때문에 훨씬 더 범용적으로 사용할 수 있다.
// 그 부분을 제외하고는 크게 다른 부분이 없다.
// 전역 변수처럼 사용이 가능하다.

// 즉시 실행되는 부분과 나중에 실행 되는 부분이 구분이 되기 때문에 이런 식으로
// 버퍼를 여러개를 만들어서 관리를 하고있는 컨셉 자체가 굉장히 중요하다
// 앞으로도 계속 등장하니까 주의깊게 살펴보자
