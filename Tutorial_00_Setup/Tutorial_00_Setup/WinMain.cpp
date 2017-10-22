#include <memory>
#include "DXApp.h"
#include "SpriteBatch.h"
#include "DDSTextureLoader.h"
#include "SimpleMath.h"
#include "SpriteFont.h"
#include "Sprite.h"

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
	//Auto delete them self
	std::unique_ptr<DirectX::SpriteBatch> spriteBatch;
	std::unique_ptr<DirectX::SpriteFont> spriteFont;

	Sprite* sprite;

};

TestApp::TestApp(HINSTANCE hInstance) : DXApp(hInstance){}

TestApp::~TestApp()
{
	Memory::SafeDelete(sprite);
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

	sprite = new Sprite(DirectX::SimpleMath::Vector2(100, 100));
	sprite->Load(m_pDevice, L"Test.dds");
	return true;
}

void TestApp::Update(float dt){}

void TestApp::Render(float dt)
{
	m_pImmediateContext->ClearRenderTargetView(m_pRenderTargetView, DirectX::Colors::CornflowerBlue);

	spriteBatch->Begin();

	spriteFont->DrawString(spriteBatch.get(), L"Hello World", DirectX::SimpleMath::Vector2(300, 300));

	sprite->Draw(spriteBatch.get());

	spriteBatch->End(); 

	HR(m_pSwapChain->Present(0, 0)); 
}

//Command line Arguments 
int WINAPI WinMain(__in HINSTANCE hInstance, __in_opt HINSTANCE hPrevInstance, __in LPSTR lpCmdLine, __in int nShowCmd)
{
	TestApp tApp(hInstance);

	if (!tApp.Init())
	{
		return 1;
	}

	return tApp.Run();

}
