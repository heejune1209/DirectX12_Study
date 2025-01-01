#include "pch.h"
#include "RootSignature.h"
#include "Engine.h"

void RootSignature::Init()
{
	CreateSamplerDesc();
	CreateRootSignature();
}

void RootSignature::CreateRootSignature()
{
	CD3DX12_DESCRIPTOR_RANGE ranges[] =
	{
		CD3DX12_DESCRIPTOR_RANGE(D3D12_DESCRIPTOR_RANGE_TYPE_CBV, CBV_REGISTER_COUNT, -1, 1 ), // b0~b4
		CD3DX12_DESCRIPTOR_RANGE(D3D12_DESCRIPTOR_RANGE_TYPE_SRV, SRV_REGISTER_COUNT, 0), // t0~t4
	};

	CD3DX12_ROOT_PARAMETER param[2];
	param[0].InitAsConstantBufferView(static_cast<uint32>(CBV_REGISTER::b0)); // b0
	param[1].InitAsDescriptorTable(_countof(ranges), ranges);

	// BufferView 라는 것은 약간 C++에서 포인터와 비슷하게 다른 애를 참조하는 그런 개념

	// descript heap 자체가 다른 리소스에 대한 설명을 하고 있는 역할을 한다라고 했었다
	// 마찬가지로 버퍼 뷰도 결국에는 여기 버퍼에 있는 모든 내용물을 레지스터 안에 넣어줄순 없지만(왜냐면 레지스터는 부피가 워낙 작기 때문이다, 버퍼가 더 큼),
	// 최소한 b0가 안에 어떤 view를 우리가 복사해가지고 b0가 어떤 데이터를 가리키고 있는지를 연결해줄수 있다.


	D3D12_ROOT_SIGNATURE_DESC sigDesc = CD3DX12_ROOT_SIGNATURE_DESC(_countof(param), param, 1, &_samplerDesc);
	sigDesc.Flags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT; // 입력 조립기 단계

	ComPtr<ID3DBlob> blobSignature;
	ComPtr<ID3DBlob> blobError;
	::D3D12SerializeRootSignature(&sigDesc, D3D_ROOT_SIGNATURE_VERSION_1, &blobSignature, &blobError);
	DEVICE->CreateRootSignature(0, blobSignature->GetBufferPointer(), blobSignature->GetBufferSize(), IID_PPV_ARGS(&_signature));
}

void RootSignature::CreateSamplerDesc()
{
	_samplerDesc = CD3DX12_STATIC_SAMPLER_DESC(0);
}