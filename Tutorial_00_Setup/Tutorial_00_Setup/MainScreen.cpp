#include "MainScreen.h"

MainScreen::MainScreen()
{
}

MainScreen::~MainScreen()
{
	Memory::SafeDelete(tank);
	Memory::SafeDelete(blackHole);
}

void MainScreen::HandleInput()
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

			RECT rectB = blackHole->GetRectangle();
			char buffer[1000];
			sprintf_s(buffer, "Tank: %ld, %ld, %ld, %ld\n", rect.left, rect.right, rect.top, rect.bottom);
			OutputDebugString(buffer);
			sprintf_s(buffer, "Block: %ld, %ld, %ld, %ld\n", rectB.left, rectB.right, rectB.top, rectB.bottom);
			OutputDebugString(buffer);

		}

		tank->UpdateBulletPosition();
	}
}

void MainScreen::HandleCollisions()
{
	HanldeBlackHoleCollisions();
	HandleEnemyCollisions();
}

void MainScreen::HanldeBlackHoleCollisions()
{
	if (blackHole->IsActive())
	{
		RECT rectA = blackHole->GetRectangle();
		RECT rectB = enemy->GetTankRect();
		if (Utility::IsIntersected(rectA, rectB) || Utility::IsIntersected(rectB, rectA))
		{
			blackHole->SetActive(false);
			tank->SetBulletInactive();
		}
	}
}

void MainScreen::HandleEnemyCollisions()
{
	RECT rectA = enemy->GetTankRect();
	RECT rectB = tank->GetBulletRect();
	if (Utility::IsIntersected(rectA, rectB) || Utility::IsIntersected(rectB, rectA))
	{
		tank->SetBulletInactive();
		enemy->Hit(tank->GetBulletDirection());
		OutputDebugString("Hit!");
	}
}

void MainScreen::Init(ID3D11Device* m_pDevice)
{
	tank = new Tank(DirectX::SimpleMath::Vector2(100, 100), m_pDevice);
	blackHole = new Sprite(DirectX::SimpleMath::Vector2(400, 300));
	blackHole->Load(m_pDevice, L"BlackHole.dds");
	enemy = new Enemy(DirectX::SimpleMath::Vector2(500, 100), m_pDevice);
}

void MainScreen::Update()
{
	HandleInput();
	HandleCollisions();
	UpdateEnemy();
}

void MainScreen::Render(std::unique_ptr<DirectX::SpriteBatch> & spriteBatch)
{

	tank->Draw(spriteBatch.get());

	if (blackHole->IsActive())
	{
		blackHole->Draw(spriteBatch.get());
	}

	enemy->Draw(spriteBatch.get());

	spriteBatch->End();
}

void MainScreen::UpdateEnemy()
{
	enemy->Update(*tank);
	enemy->UpdateBulletPosition();
}