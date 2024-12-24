#pragma once

// [계약서 / 결재]

// CPU [        ]    GPU [        ]
// 한국 [        ]   베트남 [       ]

class RootSignature
{
public:
	void Init();

	ComPtr<ID3D12RootSignature>	GetSignature() { return _signature; }

private:
	void CreateSamplerDesc();
	void CreateRootSignature();

private:
	ComPtr<ID3D12RootSignature>	_signature;
	// comptr로 되어있는 거의 대부분의 모든 부분들은 GPU한테 우리가 요청을 하는거고
	// 거기 내부에서 실질적인 객체가 만들어진다고 보면된다

	D3D12_STATIC_SAMPLER_DESC _samplerDesc;
};

// Root Signature
// 내가 사용할 레지스터나 버퍼를 GPU 쪽에 명시해주는 기능을 한다.
// 그러니까 레지스터를 어떻게 활용할것인지 어떤 용도로 활용할 것인지를 설명을 하는 단계
// 그래서 실제로 데이터가 그렇게 들어가는건 아니다
// 계약서와 비슷한 개념이다. 상수 버퍼의 수가 적으면 일일이 명시해도 상관없지만 버퍼의 수가 많아져서 테이블 형식(다음에 나올 개념 : Table DescriptorHeap)으로 생성된다면 
// 배열 형식으로 버퍼의 사이즈만큼 지정해주어 명시(서명)해줘야한다.