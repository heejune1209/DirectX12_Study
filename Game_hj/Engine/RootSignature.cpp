#include "pch.h"
#include "RootSignature.h"

void RootSignature::Init(ComPtr<ID3D12Device> device)
{
	CD3DX12_ROOT_PARAMETER param[2];
	param[0].InitAsConstantBufferView(0); // 0�� -> b0 -> CBV 
	param[1].InitAsConstantBufferView(1); // 1�� -> b1 -> CBV
	
	// BufferView ��� ���� �ణ C++���� �����Ϳ� ����ϰ� �ٸ� �ָ� �����ϴ� �׷� ����
	
	// descript heap ��ü�� �ٸ� ���ҽ��� ���� ������ �ϰ� �ִ� ������ �Ѵٶ�� �߾���
	// ���������� ���� �䵵 �ᱹ���� ���� ���ۿ� �ִ� ��� ���빰�� �������� �ȿ� �־��ټ� ������(�ֳĸ� �������ʹ� ���ǰ� ���� �۱� �����̴�, ���۰� �� ŭ),
	// �ּ��� b0�� �ȿ� � view�� �츮�� �����ذ����� b0�� � �����͸� ����Ű�� �ִ����� �������ټ� �ִ�.


	D3D12_ROOT_SIGNATURE_DESC sigDesc = CD3DX12_ROOT_SIGNATURE_DESC(2, param);
	sigDesc.Flags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT; // �Է� ������ �ܰ�

	ComPtr<ID3DBlob> blobSignature;
	ComPtr<ID3DBlob> blobError;
	::D3D12SerializeRootSignature(&sigDesc, D3D_ROOT_SIGNATURE_VERSION_1, &blobSignature, &blobError);
	device->CreateRootSignature(0, blobSignature->GetBufferPointer(), blobSignature->GetBufferSize(), IID_PPV_ARGS(&_signature));
}