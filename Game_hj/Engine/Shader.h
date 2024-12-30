#pragma once
#include "Object.h"

// [일감 기술서] 외주 인력들이 뭘 해야할지 기술
class Shader : public Object
{
public:
	Shader();
	virtual ~Shader();

	void Init(const wstring& path);
	void Update();

private:
	void CreateShader(const wstring& path, const string& name, const string& version, ComPtr<ID3DBlob>& blob, D3D12_SHADER_BYTECODE& shaderByteCode);
	void CreateVertexShader(const wstring& path, const string& name, const string& version);
	void CreatePixelShader(const wstring& path, const string& name, const string& version);

private:
	ComPtr<ID3DBlob>					_vsBlob;
	ComPtr<ID3DBlob>					_psBlob;
	ComPtr<ID3DBlob>					_errBlob;

	ComPtr<ID3D12PipelineState>			_pipelineState;
	D3D12_GRAPHICS_PIPELINE_STATE_DESC  _pipelineDesc = {};
};

// Shader
// 메쉬에 적용할 여러가지 기능들을 기술해놓은 함수이다.
// 컬러, 위치 등 적용할 기능들이 모두 담겨있는 부분이다.
// 보통 파일을 따로 빼서 관리하며 로드 시에 파일을 읽어와 기능을 적용한다.
// 대부분 Vertex Shader와 Pixel Shader로 분리하여 관리한다.