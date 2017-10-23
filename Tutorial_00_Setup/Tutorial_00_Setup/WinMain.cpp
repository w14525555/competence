#include <memory>
#include "DXApp.h"
#include "SpriteBatch.h"
#include "DDSTextureLoader.h"
#include "SimpleMath.h"
#include "SpriteFont.h"
#include "Sprite.h"
#include "Tank.h"

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

	Tank* tank;
	Sprite* sprite;
};

TestApp::TestApp(HINSTANCE hInstance) : DXApp(hInstance){}

TestApp::~TestApp()
{
	Memory::SafeDelete(tank);
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

	tank = new Tank(DirectX::SimpleMath::Vector2(100, 100), m_pDevice);
	sprite = new Sprite(DirectX::SimpleMath::Vector2(200, 100));
	sprite->Load(m_pDevice, L"TankRight.dds");

	return true;
}

void TestApp::Update(float dt)
{
	const float MOVE_SPEED = 0.1f;

	//Move the tank
	if (GetAsyncKeyState('W'))
	{
		tank->MoveUp();
	}

	if (GetAsyncKeyState('S'))
	{
		tank->MoveDown();
	}

	if (GetAsyncKeyState('A'))
	{
		tank->MoveLeft();
	}

	if (GetAsyncKeyState('D'))
	{
		tank->MoveRight();
	}
}

void TestApp::Render(float dt)
{
	m_pImmediateContext->ClearRenderTargetView(m_pRenderTargetView, DirectX::Colors::CornflowerBlue);

	spriteBatch->Begin();

	spriteFont->DrawString(spriteBatch.get(), L"Hello World", DirectX::SimpleMath::Vector2(300, 300));

	tank->Draw(spriteBatch.get());

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
