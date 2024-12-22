#pragma once


// �η� �繫��
class Device
{
public:
	void Init();

	ComPtr<IDXGIFactory> GetDXGI() { return _dxgi; }
	ComPtr<ID3D12Device> GetDevice() { return _device; }

private:
	// COM(Component Object Model)
	// - DX�� ���α׷��� ��� �������� ���� ȣȯ���� �����ϰ� �ϴ� ���
	// - COM ��ü(COM �������̽�)�� ���. ���λ����� �츮���� ������
	// - ComPtr ������ ����Ʈ ������
	ComPtr<ID3D12Debug>			_debugController;
	ComPtr<IDXGIFactory>		_dxgi; // ȭ�� ���� ��ɵ�
	ComPtr<ID3D12Device>		_device; // ���� ��ü ����
};
// Device
// CPU, GPU�� �ش��ϸ� ���÷��� �����(�׷��� ī��)�� ��������ִ� �Լ��̴�. 
// �����翡 ������� ǥ��ȭ�Ǿ��־� DirectX ���̺귯�� �ϳ��� ����Ͽ� ������ ���� ���� ������ �� �� �ֵ��� ���ش�. 
// �پ��� ����� �ϴ� ������ �Լ����� �����ų �� �ֵ��� �����ش�.

