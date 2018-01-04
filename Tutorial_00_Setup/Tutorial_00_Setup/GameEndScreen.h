#pragma once
#include "Screen.h"
class GameEndScreen :
	public Screen
{
public:
	GameEndScreen();
	~GameEndScreen();
	void Render(std::unique_ptr<DirectX::SpriteBatch> & spriteBatch, std::unique_ptr<DirectX::SpriteFont> & spriteFont) override;
};

