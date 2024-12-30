#pragma once
#include "Object.h"

class Texture : public Object
{
public:
	Texture();
	virtual ~Texture();

	void Init(const wstring& path);

	D3D12_CPU_DESCRIPTOR_HANDLE GetCpuHandle() { return _srvHandle; }

public:
	void CreateTexture(const wstring& path);
	void CreateView();

private:
	// �ؽ�ó ����� �κ�
	ScratchImage			 		_image;
	ComPtr<ID3D12Resource>			_tex2D;
	// �ε� �κ�
	ComPtr<ID3D12DescriptorHeap>	_srvHeap;
	D3D12_CPU_DESCRIPTOR_HANDLE		_srvHandle = {};
};

// �ؽ�ó�� ����� �ε��ϴ� �Լ��̴�.
// �ؽ�ó ���� ��� �� �� �ε� �Ŀ� ���� ���� ����� ���̱� ������ �並 �ϳ��� ���� �ȴ�.
