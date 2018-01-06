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
	gameEndScreen = new GameEndScreen();
	currentScreen = mainScreen;

	return true;
}

void GameApp::Update(float dt)
{
	currentScreen->Update();
	if (currentScreen->readyForNextScene)
	{
		gameEndScreen->isPlayerKilled = currentScreen->isPlayerKilled;
		currentScreen = gameEndScreen;
	}
}

void GameApp::Render(float dt)
{
	m_pImmediateContext->ClearRenderTargetView(m_pRenderTargetView, DirectX::Colors::CornflowerBlue);

	spriteBatch->Begin();

	currentScreen->Render(spriteBatch, spriteFont);

	spriteBatch->End();

	HR(m_pSwapChain->Present(0, 0));
}

