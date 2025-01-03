#pragma once
#include "Object.h"

class Material;

// [유니티짱]과 같이 정점으로 이루어진 물체
class Mesh : public Object
{
public:
	Mesh();
	virtual ~Mesh();

	void Init(const vector<Vertex>& vertexBuffer, const vector<uint32>& indexbuffer);
	void Render();

private:
	void CreateVertexBuffer(const vector<Vertex>& buffer);
	void CreateIndexBuffer(const vector<uint32>& buffer);

private:
	ComPtr<ID3D12Resource>		_vertexBuffer;
	D3D12_VERTEX_BUFFER_VIEW	_vertexBufferView = {};
	uint32 _vertexCount = 0;

	ComPtr<ID3D12Resource>		_indexBuffer;
	D3D12_INDEX_BUFFER_VIEW		_indexBufferView;
	uint32 _indexCount = 0;

};
// Mesh
// 정점으로 이루어진 물체를 의미한다.
// 게임상에서 캐릭터, 몬스터 등과 같은 물체들이 모두 메쉬에 속한다.
// 여러 개의 폴리곤이 모여 만들어진 메쉬도 존재하기 때문에 해당 단위로 관리하기 위해 함수를 따로 만들어주었다.
// 여기에 다양한 텍스처나 쉐이더를 적용하여 하나의 메쉬로 정의할 수 있다.
