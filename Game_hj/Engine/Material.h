#pragma once
#include "Object.h"

class Shader;
class Texture;

enum
{
	MATERIAL_INT_COUNT = 5,
	MATERIAL_FLOAT_COUNT = 5,
	MATERIAL_TEXTURE_COUNT = 5,
};

struct MaterialParams
{
	void SetInt(uint8 index, int32 value) { intParams[index] = value; }
	void SetFloat(uint8 index, float value) { floatParams[index] = value; }

	array<int32, MATERIAL_INT_COUNT> intParams;
	array<float, MATERIAL_FLOAT_COUNT> floatParams;
	// array는 배열을 래핑하는 그런 클래스라고 보면됨.
};

class Material : public Object
{
public:
	Material();
	virtual ~Material();

	shared_ptr<Shader> GetShader() { return _shader; }

	void SetShader(shared_ptr<Shader> shader) { _shader = shader; }
	void SetInt(uint8 index, int32 value) { _params.SetInt(index, value); }
	void SetFloat(uint8 index, float value) { _params.SetFloat(index, value); }
	void SetTexture(uint8 index, shared_ptr<Texture> texture) { _textures[index] = texture; }

	void PushData();

private:
	shared_ptr<Shader>	_shader;
	MaterialParams		_params;
	array<shared_ptr<Texture>, MATERIAL_TEXTURE_COUNT> _textures;
};

// Material
// 매번 메쉬를 만들 때 쉐이더, 텍스처도 일일이 만들면 부하가 커질 수 있다.
// 텍스처를 포함해 사용할 쉐이더와 인자들을 모아서 하나의 클래스로 관리한 것을 머테리얼(Material)이라한다.
// 머테리얼을 하나 만들어서 메쉬에 적용만 시키면 프로그램의 부담이 훨씬 덜해질 것이다.
// 쉐이더, 텍스처, 머테리얼 변수들을 변수로 가진다.

