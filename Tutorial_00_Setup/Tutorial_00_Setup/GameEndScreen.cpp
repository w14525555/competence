#include "GameEndScreen.h"
#include "SimpleMath.h"

GameEndScreen::GameEndScreen()
{
}


GameEndScreen::~GameEndScreen()
{
}

void GameEndScreen::Render(std::unique_ptr<DirectX::SpriteBatch> & spriteBatch, std::unique_ptr<DirectX::SpriteFont> & spriteFont)
{
	if (isPlayerKilled)
	{
		spriteFont->DrawString(spriteBatch.get(), L"Game Over!", DirectX::SimpleMath::Vector2(300, 300));
	}
	else
	{
		spriteFont->DrawString(spriteBatch.get(), L"You Win!", DirectX::SimpleMath::Vector2(300, 300));
	}
	
}

void GameEndScreen::Init(ID3D11Device* m_pDevice)
{
}

void GameEndScreen::Update()
{
}