#include "GameApp.h"

GameApp::GameApp(HINSTANCE hInstance) :DXApp(hInstance){}

GameApp::~GameApp()
{
	Memory::SafeDelete(mainScreen);
}

bool GameApp::Init()
{
	if (!DXApp::Init())
	{
		return false;
	}

	//Create Sprite Batch Objects
	spriteBatch.reset(new DirectX::SpriteBatch(m_pImmediateContext));

	spriteFont.reset(new DirectX::SpriteFont(m_pDevice, L"Arial.spritefont"));

	mainScreen = new MainScreen();
	mainScreen->Init(m_pDevice);

	return true;
}

void GameApp::Update(float dt)
{
	mainScreen->Update();
}

void GameApp::Render(float dt)
{
	m_pImmediateContext->ClearRenderTargetView(m_pRenderTargetView, DirectX::Colors::CornflowerBlue);

	spriteBatch->Begin();

	spriteFont->DrawString(spriteBatch.get(), L"Tank Game", DirectX::SimpleMath::Vector2(20, 300));

	mainScreen->Render(spriteBatch);

	HR(m_pSwapChain->Present(0, 0));
}

