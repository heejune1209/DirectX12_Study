#pragma once


// 인력 사무소
class Device
{
public:
	void Init();

	ComPtr<IDXGIFactory> GetDXGI() { return _dxgi; }
	ComPtr<ID3D12Device> GetDevice() { return _device; }

private:
	// COM(Component Object Model)
	// - DX의 프로그래밍 언어 독립성과 하위 호환성을 가능하게 하는 기술
	// - COM 객체(COM 인터페이스)를 사용. 세부사항은 우리한테 숨겨짐
	// - ComPtr 일종의 스마트 포인터
	ComPtr<ID3D12Debug>			_debugController;
	ComPtr<IDXGIFactory>		_dxgi; // 화면 관련 기능들
	ComPtr<ID3D12Device>		_device; // 각종 객체 생성
};
// Device
// CPU, GPU에 해당하며 디스플레이 어댑터(그래픽 카드)와 연결시켜주는 함수이다. 
// 제조사에 상관없이 표준화되어있어 DirectX 라이브러리 하나만 사용하여 별도의 설정 없이 개발을 할 수 있도록 해준다. 
// 다양한 기능을 하는 나머지 함수들을 실행시킬 수 있도록 도와준다.

