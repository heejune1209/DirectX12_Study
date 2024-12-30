#include "pch.h"
#include "Mesh.h"
#include "Engine.h"
#include "Material.h"

Mesh::Mesh() : Object(OBJECT_TYPE::MESH)
{

}

Mesh::~Mesh()
{

}

void Mesh::Init(const vector<Vertex>& vertexBuffer, const vector<uint32>& indexBuffer)
{
	CreateVertexBuffer(vertexBuffer);
	CreateIndexBuffer(indexBuffer);
}

void Mesh::Render()
{
	CMD_LIST->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	CMD_LIST->IASetVertexBuffers(0, 1, &_vertexBufferView); // Slot: (0~15)
	CMD_LIST->IASetIndexBuffer(&_indexBufferView);

	// TODO
	// 1) Buffer에다가 데이터 세팅(디바이스를 통해서 작업을 하니까 당장 일어나는 개념, 즉시 데이터가 복사된다.)
	// 2) Buffer의 주소를 register에다가 전송(두번째 단계에선 SetGraphicsRootConstantBufferView를 요청할건데 얘는 커맨드 리스트를 통해서 요청한다.
	// 그래서 두번 부분은 나중에 버퍼의 주소를 넘겨줘서 레지스터를 가리키게 만든다.

	// TODO
	// 1) Buffer에다가 데이터 세팅
	// 2) TableDescHeap에다가 CBV 전달
	// 3) 모두 세팅이 끝났으면 TableDescHeap 커밋

	// 아까랑 기능은 똑같은데 결국에는 이제 사용하는 방법이 달라졌다.
	// 루트 시그니처를 설명하는 부분에서 기존에는 루트 시그니처를 이용했다면 
	// 이제는 루트 디스크립터 테이블을 이용해 가지고 관리를 하는 방법으로 수정을 해봤다

	// 이렇게 버퍼를 하나를 사용해 가지고 밀어 넣는 게 아니라 항상 버퍼도 여러 개를 만들어 줘야 되는 거고 
	// 버퍼를 묘사하는 view도 컨트롤 버퍼 view도 여러 개를 만들어 줘야 되는 거고 
	// 그 다음에 그거를 제출하기 위한 용도의 이 테이블 디스크립터 heap도 하나만 만들어 주는 게 아니라 
	// 여러 개를 세트를 몇백 개를 만들어 줘 가지고 하나씩 하나씩 채워서 개를 이제 올려주게끔 
	// 일단은 만들어지는 것까지 일단은 알 수가 있었다

	// 즉, 즉시 되는 부분과 나중에 되는 부분을 잘 구분해야한다

	GEngine->GetTableDescHeap()->CommitTable();

	CMD_LIST->DrawIndexedInstanced(_indexCount, 1, 0, 0, 0);
	// 하나만 그리기 위해서 주석
	/*{
		D3D12_CPU_DESCRIPTOR_HANDLE handle = GEngine->GetCB()->PushData(0, &_transform, sizeof(_transform));
		GEngine->GetTableDescHeap()->SetCBV(handle, CBV_REGISTER::b1);
	}*/
}

void Mesh::CreateVertexBuffer(const vector<Vertex>& buffer)
{
	_vertexCount = static_cast<uint32>(buffer.size());
	uint32 bufferSize = _vertexCount * sizeof(Vertex);

	D3D12_HEAP_PROPERTIES heapProperty = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD);
	D3D12_RESOURCE_DESC desc = CD3DX12_RESOURCE_DESC::Buffer(bufferSize);

	DEVICE->CreateCommittedResource(
		&heapProperty,
		D3D12_HEAP_FLAG_NONE,
		&desc,
		D3D12_RESOURCE_STATE_GENERIC_READ,
		nullptr,
		IID_PPV_ARGS(&_vertexBuffer));

	// Copy the triangle data to the vertex buffer.
	void* vertexDataBuffer = nullptr;
	CD3DX12_RANGE readRange(0, 0); // We do not intend to read from this resource on the CPU.
	_vertexBuffer->Map(0, &readRange, &vertexDataBuffer);
	::memcpy(vertexDataBuffer, &buffer[0], bufferSize);
	_vertexBuffer->Unmap(0, nullptr);

	// Initialize the vertex buffer view.
	_vertexBufferView.BufferLocation = _vertexBuffer->GetGPUVirtualAddress();
	_vertexBufferView.StrideInBytes = sizeof(Vertex); // 정점 1개 크기
	_vertexBufferView.SizeInBytes = bufferSize; // 버퍼의 크기	
}

void Mesh::CreateIndexBuffer(const vector<uint32>& buffer)
{
	_indexCount = static_cast<uint32>(buffer.size());
	uint32 bufferSize = _indexCount * sizeof(uint32);

	D3D12_HEAP_PROPERTIES heapProperty = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD);
	D3D12_RESOURCE_DESC desc = CD3DX12_RESOURCE_DESC::Buffer(bufferSize);

	DEVICE->CreateCommittedResource(
		&heapProperty,
		D3D12_HEAP_FLAG_NONE,
		&desc,
		D3D12_RESOURCE_STATE_GENERIC_READ,
		nullptr,
		IID_PPV_ARGS(&_indexBuffer));

	void* indexDataBuffer = nullptr;
	CD3DX12_RANGE readRange(0, 0); // We do not intend to read from this resource on the CPU.
	_indexBuffer->Map(0, &readRange, &indexDataBuffer);
	::memcpy(indexDataBuffer, &buffer[0], bufferSize);
	_indexBuffer->Unmap(0, nullptr);

	_indexBufferView.BufferLocation = _indexBuffer->GetGPUVirtualAddress();
	_indexBufferView.Format = DXGI_FORMAT_R32_UINT; // int32라서 이렇게 씀
	_indexBufferView.SizeInBytes = bufferSize;
}