////////////////////////////////////////////////////////////////////////////////
// Filename: skyplaneshaderclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _SKYPLANESHADERCLASS_H_
#define _SKYPLANESHADERCLASS_H_


//////////////
// INCLUDES //
//////////////
#include <d3d11.h>
#include <fstream>
#include <d3dcompiler.h>
#include <DirectXMath.h>
using namespace DirectX;
using namespace std;

#pragma comment(lib, "d3dcompiler.lib")

////////////////////////////////////////////////////////////////////////////////
// Class name: SkyPlaneShaderClass
////////////////////////////////////////////////////////////////////////////////
class SkyPlaneShaderClass
{
private:
	struct MatrixBufferType
	{
		XMMATRIX world;
		XMMATRIX view;
		XMMATRIX projection;
	};

	struct SkyBufferType
	{
		float firstTranslationX;
		float firstTranslationZ;
		float secondTranslationX;
		float secondTranslationZ;
		float brightness;
		XMFLOAT3 padding;
	};

public:
	SkyPlaneShaderClass();
	SkyPlaneShaderClass(const SkyPlaneShaderClass&);
	~SkyPlaneShaderClass();

	bool Initialize(ID3D11Device*, HWND);
	void Shutdown();
	bool Render(ID3D11DeviceContext*, int, XMMATRIX, XMMATRIX, XMMATRIX, ID3D11ShaderResourceView*, ID3D11ShaderResourceView*, float, float, float,
				float, float);

private:
	bool InitializeShader(ID3D11Device*, HWND, WCHAR*, WCHAR*);
	void ShutdownShader();
	void OutputShaderErrorMessage(ID3D10Blob*, HWND, WCHAR*);

	bool SetShaderParameters(ID3D11DeviceContext*, XMMATRIX, XMMATRIX, XMMATRIX, ID3D11ShaderResourceView*, ID3D11ShaderResourceView*, float, float,
							 float, float, float);
	void RenderShader(ID3D11DeviceContext*, int);

private:
	ID3D11VertexShader* m_vertexShader;
	ID3D11PixelShader* m_pixelShader;
	ID3D11InputLayout* m_layout;
	ID3D11SamplerState* m_sampleState;
	ID3D11Buffer* m_matrixBuffer;
	ID3D11Buffer* m_skyBuffer;
};

#endif