#pragma once

// [����Ƽ¯]�� ���� �������� �̷���� ��ü
// �������� �������� ����ȴ�
class Mesh
{
public:
	void Init(vector<Vertex>& vec);
	void Render();

private:
	ComPtr<ID3D12Resource>		_vertexBuffer;
	D3D12_VERTEX_BUFFER_VIEW	_vertexBufferView = {};
	uint32 _vertexCount = 0;
};
// Mesh
// �������� �̷���� ��ü�� �ǹ��Ѵ�.
// ���ӻ󿡼� ĳ����, ���� ��� ���� ��ü���� ��� �޽��� ���Ѵ�.
// ���� ���� �������� �� ������� �޽��� �����ϱ� ������ �ش� ������ �����ϱ� ���� �Լ��� ���� ������־���.
// ���⿡ �پ��� �ؽ�ó�� ���̴��� �����Ͽ� �ϳ��� �޽��� ������ �� �ִ�.



