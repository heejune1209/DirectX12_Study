#pragma once


class Texture
{
public:
	void Init(const wstring& path);

	D3D12_CPU_DESCRIPTOR_HANDLE GetCpuHandle() { return _srvHandle; }

public:
	void CreateTexture(const wstring& path);
	void CreateView();

private:
	// 텍스처 만드는 부분
	ScratchImage			 		_image;
	ComPtr<ID3D12Resource>			_tex2D;
	// 로드 부분
	ComPtr<ID3D12DescriptorHeap>	_srvHeap;
	D3D12_CPU_DESCRIPTOR_HANDLE		_srvHandle;
};

// 텍스처를 만들고 로드하는 함수이다.
// 텍스처 같은 경우 한 번 로드 후에 변경 없이 사용할 것이기 때문에 뷰를 하나만 만들어도 된다.
