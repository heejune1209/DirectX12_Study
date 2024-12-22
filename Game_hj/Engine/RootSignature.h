#pragma once

// [계약서 / 결재]

// CPU [        ]    GPU [        ]
// 한국 [        ]   베트남 [       ]

class RootSignature
{
public:
	void Init(ComPtr<ID3D12Device> device);

	ComPtr<ID3D12RootSignature>	GetSignature() { return _signature; }

private:
	ComPtr<ID3D12RootSignature>	_signature;

	// comptr로 되어있는 거의 대부분의 모든 부분들은 GPU한테 우리가 요청을 하는거고
	// 거기 내부에서 실질적인 객체가 만들어진다고 보면된다
};

// Root Signature
// 내가 사용할 레지스터나 버퍼를 GPU 쪽에 명시해주는 기능을 한다.
// 계약서와 비슷한 개념이다. 상수 버퍼의 수가 적으면 일일이 명시해도 상관없지만 버퍼의 수가 많아져서 테이블 형식(다음에 나올 개념 : Table DescriptorHeap)으로 생성된다면 
// 배열 형식으로 버퍼의 사이즈만큼 지정해주어 명시(서명)해줘야한다.

