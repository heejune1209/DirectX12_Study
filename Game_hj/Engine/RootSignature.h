#pragma once

// [��༭ / ����]

// CPU [        ]    GPU [        ]
// �ѱ� [        ]   ��Ʈ�� [       ]

class RootSignature
{
public:
	void Init(ComPtr<ID3D12Device> device);

	ComPtr<ID3D12RootSignature>	GetSignature() { return _signature; }

private:
	ComPtr<ID3D12RootSignature>	_signature;

	// comptr�� �Ǿ��ִ� ���� ��κ��� ��� �κе��� GPU���� �츮�� ��û�� �ϴ°Ű�
	// �ű� ���ο��� �������� ��ü�� ��������ٰ� ����ȴ�
};

// Root Signature
// ���� ����� �������ͳ� ���۸� GPU �ʿ� ������ִ� ����� �Ѵ�.
// ��༭�� ����� �����̴�. ��� ������ ���� ������ ������ ����ص� ��������� ������ ���� �������� ���̺� ����(������ ���� ���� : Table DescriptorHeap)���� �����ȴٸ� 
// �迭 �������� ������ �����ŭ �������־� ���(����)������Ѵ�.

