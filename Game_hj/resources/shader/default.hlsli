
cbuffer TEST_B0 : register(b0)
{
    float4 offset0;
};

// material의 인자들을 받아주는 그런 부분.
cbuffer MATERIAL_PARAMS : register(b1)
{
    int int_0;
    int int_1;
    int int_2;
    int int_3;
    int int_4;
    float float_0;
    float float_1;
    float float_2;
    float float_3;
    float float_4;
};

Texture2D tex_0 : register(t0);
Texture2D tex_1 : register(t1);
Texture2D tex_2 : register(t2);
Texture2D tex_3 : register(t3);
Texture2D tex_4 : register(t4);

SamplerState sam_0 : register(s0);


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
    float4 color : COLOR;
    float2 uv : TEXCOORD;
};

struct VS_OUT
{
    float4 pos : SV_Position;
    float4 color : COLOR;
    float2 uv : TEXCOORD;
};

VS_OUT VS_Main(VS_IN input)
{
    VS_OUT output = (VS_OUT)0;

    output.pos = float4(input.pos, 1.f);
    // output.pos += offset0;
    output.pos.x += float_0;
    output.pos.y += float_1;
    output.pos.z += float_2;
    
    output.color = input.color;
    output.uv = input.uv;

    return output;
}

float4 PS_Main(VS_OUT input) : SV_Target
{
    float4 color = tex_0.Sample(sam_0, input.uv);
    return color;
}