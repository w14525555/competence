#include <memory>
#include <iostream>
#include "DXApp.h"
#include "SpriteBatch.h"
#include "DDSTextureLoader.h"
#include "SimpleMath.h"
#include "SpriteFont.h"
#include "Sprite.h"
#include "Tank.h"
#include "Enemy.h"

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
	Enemy* enemy;

	void HandleInput();
	void HandleCollisions();
	const bool& IsIntersected(const RECT& rectA, const RECT& B) const;
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
	enemy = new Enemy(DirectX::SimpleMath::Vector2(500, 100), m_pDevice);

	return true;
}

void TestApp::Update(float dt)
{
	HandleInput();
	HandleCollisions();
	enemy->Update();
}

void TestApp::HandleInput()
{
	if (tank)
	{
		//Move the tank
		if (GetAsyncKeyState(VK_UP))
		{
			tank->MoveUp();
		}

		if (GetAsyncKeyState(VK_DOWN))
		{
			tank->MoveDown();
		}

		if (GetAsyncKeyState(VK_LEFT))
		{
			tank->MoveLeft();
		}

		if (GetAsyncKeyState(VK_RIGHT))
		{
			tank->MoveRight();
		}

		if (GetAsyncKeyState('X'))
		{
			tank->Shoot();
		}

		if (GetAsyncKeyState('C'))
		{
			
			RECT rect = tank->GetTankRect();
			
			RECT rectB = sprite->GetRectangle();
			char buffer[1000];
			sprintf_s(buffer, "Tank: %ld, %ld, %ld, %ld\n", rect.left, rect.right, rect.top, rect.bottom);
			OutputDebugString(buffer);
			sprintf_s(buffer, "Block: %ld, %ld, %ld, %ld\n", rectB.left, rectB.right, rectB.top, rectB.bottom);
			OutputDebugString(buffer);

		}

		tank->UpdateBulletPosition();
	}
}

//Handle collisions 
void TestApp::HandleCollisions()
{
	if (sprite->IsActive())
	{
		RECT rectA = sprite->GetRectangle();
		RECT rectB = tank->GetBulletRect();
		if (IsIntersected(rectA, rectB) || IsIntersected(rectB, rectA))
		{
			sprite->SetActive(false);
			tank->SetBulletInactive();
		}
	}

}

//A function to check if two rectangle is intersected.
const bool& TestApp::IsIntersected(const RECT& rectA, const RECT& rectB) const
{
	if (rectA.left <= rectB.right && rectA.right >= rectB.left &&
		rectA.top <= rectB.bottom && rectA.bottom >= rectB.top)
	{
		OutputDebugString("Intersected\n");
		return true;
	}
	else
	{
		return false;
	}
}

void TestApp::Render(float dt)
{
	m_pImmediateContext->ClearRenderTargetView(m_pRenderTargetView, DirectX::Colors::CornflowerBlue);

	spriteBatch->Begin();

	spriteFont->DrawString(spriteBatch.get(), L"Tank Game", DirectX::SimpleMath::Vector2(20, 300));

	tank->Draw(spriteBatch.get());

	if (sprite->IsActive())
	{
		sprite->Draw(spriteBatch.get());
	}

	enemy->Draw(spriteBatch.get());

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
