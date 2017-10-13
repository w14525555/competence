#include <memory>
#include "DXApp.h"
#include "SpriteBatch.h"
#include "DDSTextureLoader.h"
#include "SimpleMath.h"
#include "SpriteFont.h"

class TestApp : public DXApp
{
public:
	TestApp(HINSTANCE hInstance);
	~TestApp();

	bool Init() override;
	void Update(float dt) override;
	void Render(float dt) override; 

private:
	//Create object
	//Auto delete themself
	std::unique_ptr<DirectX::SpriteBatch> spriteBatch;
	std::unique_ptr<DirectX::SpriteFont> spriteFont;

	ID3D11ShaderResourceView* m_pTexture;
	
};

TestApp::TestApp(HINSTANCE hInstance) : DXApp(hInstance){}

TestApp::~TestApp()
{
	Memory::SafeRelease(m_pTexture);
}

bool TestApp::Init()
{
	if (!DXApp::Init())
	{
		return false;
	}

	//Create Sprite Batch Objects
	spriteBatch.reset(new DirectX::SpriteBatch(m_pImmediateContext));

	spriteFont.reset(new DirectX::SpriteFont(m_pDevice, L"Arial.spritefont"));
	//Import Texture For Rendering
	HR(DirectX::CreateDDSTextureFromFile(m_pDevice, L"Test.dds", nullptr, &m_pTexture));

	return true;
}

void TestApp::Update(float dt){}

void TestApp::Render(float dt)
{
	m_pImmediateContext->ClearRenderTargetView(m_pRenderTargetView, DirectX::Colors::CornflowerBlue);

	spriteBatch->Begin();
	//Draw Sprites
	spriteBatch->Draw(m_pTexture, DirectX::SimpleMath::Vector2(100, 100));

	spriteFont->DrawString(spriteBatch.get(), L"Hello World", DirectX::SimpleMath::Vector2(300, 300));

	spriteBatch->End();

	HR(m_pSwapChain->Present(0, 0)); 
}

//Commandline Arguments 
int WINAPI WinMain(__in HINSTANCE hInstance, __in_opt HINSTANCE hPrevInstance, __in LPSTR lpCmdLine, __in int nShowCmd)
{
	TestApp tApp(hInstance);

	if (!tApp.Init())
	{
		return 1;
	}

	return tApp.Run();

}
