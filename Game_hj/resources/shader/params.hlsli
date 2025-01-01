#ifndef _PARAMS_HLSLI_
#define _PARAMS_HLSLI_

struct LightColor
{
    float4      diffuse;
    float4      ambient;
    float4      specular;
};

struct LightInfo
{
    LightColor  color;
    float4	    position;
    float4	    direction; 
    int		    lightType;
    float	    range;
    float	    angle;
    int  	    padding;
};

cbuffer GLOBAL_PARAMS : register(b0)
{
    int         g_lightCount; 
    float3      g_lightPadding;
    LightInfo   g_light[50];
}
// material의 인자들을 받아주는 그런 부분.
cbuffer TRANSFORM_PARAMS : register(b1)
{
    row_major matrix g_matWorld;
    row_major matrix g_matView;
    row_major matrix g_matProjection;
    row_major matrix g_matWV;
    row_major matrix g_matWVP;
};
// 패킹 룰
// 어떤 구조체를 만들 때 그게 실질적으로 메모리 올라가는 그 메모리 정렬 순서이다
// Window에선 기본적으로 4바이트 바운더리를 지키지만 HLS에서는 어떤 데이터가 16바이트 바운더리를 넘어가면 안 된다라고 하고있다. 
// 이것은 HLSL 쉐이더 쪽에서 사용하고 있는 정렬 방법인데 우리가 이 C++ 코드를 작업을 할 때 이 부분을 신경 안 쓴다고 가정을 하면은 
// 데이터 순서가 이제 어긋나게 된다는 얘기가 된다.
// 즉 정렬을 안지켜준 상태에서 데이터가 넘어가면 양쪽에서 생각하는 그 데이터 포맷이 다르기 때문에 엉뚱한 값으로 이걸 읽어드리는 상태가 발생할 수가 있겠다
// 그냥 손쉽게 생각하면 16바이트 단위로 정렬을 해줘서 넘겨주면 된다
cbuffer MATERIAL_PARAMS : register(b2)
{
    int     g_int_0;
    int     g_int_1;
    int     g_int_2;
    int     g_int_3;
    int     g_int_4;
    float   g_float_0;
    float   g_float_1;
    float   g_float_2;
    float   g_float_3;
    float   g_float_4;
};

Texture2D g_tex_0 : register(t0);
Texture2D g_tex_1 : register(t1);
Texture2D g_tex_2 : register(t2);
Texture2D g_tex_3 : register(t3);
Texture2D g_tex_4 : register(t4);

SamplerState g_sam_0 : register(s0);

#endif