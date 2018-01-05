#pragma once
#include "Screen.h"
class GameEndScreen :
	public Screen
{
public:
	GameEndScreen();
	~GameEndScreen();
	void Init(ID3D11Device* m_pDevice) override;
	void Update() override;
	void Render(std::unique_ptr<DirectX::SpriteBatch> & spriteBatch, std::unique_ptr<DirectX::SpriteFont> & spriteFont) override;
};

