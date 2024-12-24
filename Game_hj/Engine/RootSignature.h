#pragma once

// [��༭ / ����]

// CPU [        ]    GPU [        ]
// �ѱ� [        ]   ��Ʈ�� [       ]

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
	// comptr�� �Ǿ��ִ� ���� ��κ��� ��� �κе��� GPU���� �츮�� ��û�� �ϴ°Ű�
	// �ű� ���ο��� �������� ��ü�� ��������ٰ� ����ȴ�

	D3D12_STATIC_SAMPLER_DESC _samplerDesc;
};

// Root Signature
// ���� ����� �������ͳ� ���۸� GPU �ʿ� ������ִ� ����� �Ѵ�.
// �׷��ϱ� �������͸� ��� Ȱ���Ұ����� � �뵵�� Ȱ���� �������� ������ �ϴ� �ܰ�
// �׷��� ������ �����Ͱ� �׷��� ���°� �ƴϴ�
// ��༭�� ����� �����̴�. ��� ������ ���� ������ ������ ����ص� ��������� ������ ���� �������� ���̺� ����(������ ���� ���� : Table DescriptorHeap)���� �����ȴٸ� 
// �迭 �������� ������ �����ŭ �������־� ���(����)������Ѵ�.