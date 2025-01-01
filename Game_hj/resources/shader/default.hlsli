#ifndef _DEFAULT_HLSLI_
#define _DEFAULT_HLSLI_

#include "params.hlsli"
#include "utils.hlsli"

//cbuffer TEST_B1 : register(b1)
//{
//    float4 offset1;
//};

//Texture2D tex_0 : register(t0);
//// 레스토라이저 단계에서 그 UV값을 정해준 다음에 그 UV값에 따라가지고
//// 나중에 픽셀시더 이쪽에서 우리가 원하는 색상을 골라주면 되는데 색상을 사실 고르는 방법이 여려가지다.
//// 그런 정책을 골라주는 방법이라고 일단은 이해를 해주시면 되겠습니다
//SamplerState sam_0 : register(s0);
struct VS_IN
{
    float3 pos : POSITION;
    float2 uv : TEXCOORD;
    float3 normal : NORMAL;
};

struct VS_OUT
{
    float4 pos : SV_Position;
    float2 uv : TEXCOORD;
    float3 viewPos : POSITION;
    float3 viewNormal : NORMAL;
};

VS_OUT VS_Main(VS_IN input)
{
    VS_OUT output = (VS_OUT) 0;

    output.pos = mul(float4(input.pos, 1.f), g_matWVP);
    output.uv = input.uv;

    output.viewPos = mul(float4(input.pos, 1.f), g_matWV).xyz;
    output.viewNormal = normalize(mul(float4(input.normal, 0.f), g_matWV).xyz);

    return output;
}

float4 PS_Main(VS_OUT input) : SV_Target
{
    //float4 color = g_tex_0.Sample(g_sam_0, input.uv);
    float4 color = float4(1.f, 1.f, 1.f, 1.f); // 하얀색

    LightColor totalColor = (LightColor) 0.f;

    for (int i = 0; i < g_lightCount; ++i)
    {
        LightColor color = CalculateLightColor(i, input.viewNormal, input.viewPos);
        totalColor.diffuse += color.diffuse;
        totalColor.ambient += color.ambient;
        totalColor.specular += color.specular;
    }

    color.xyz = (totalColor.diffuse.xyz * color.xyz)
        + totalColor.ambient.xyz * color.xyz
        + totalColor.specular.xyz;

    return color;
}

#endif