#pragma once


class Timer
{
	DECLARE_SINGLE(Timer);
public:
	void Init();
	void Update();

	uint32 GetFps() { return _fps; }
	float GetDeltaTime() { return _deltaTime; }

private:
	uint64	_frequency = 0;
	uint64	_prevCount = 0;
	float	_deltaTime = 0.f;

private:
	uint32	_frameCount = 0;
	float	_frameTime = 0.f;
	uint32	_fps = 0;
};

// 경과된 시간이랑 그 다음에 현재 프레임이 지금 얼마로 실행이 되고 있는지 
// 두 가지만을 지금 계산할 용도로 간단하게만 이렇게