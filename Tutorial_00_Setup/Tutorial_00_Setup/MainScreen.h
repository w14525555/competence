#include "Screen.h"
#include "Tank.h"
#include "Enemy.h"

#pragma once
class MainScreen : public Screen
{
public:
	MainScreen();
	~MainScreen();
	void Init(ID3D11Device* m_pDevice) override;
	void Update() override;
	void Render(std::unique_ptr<DirectX::SpriteBatch> & spriteBatch, std::unique_ptr<DirectX::SpriteFont> & spriteFont) override;

private:
	Tank* tank;
	Sprite* blackHole;
	Enemy* enemy;
	int bulletProfTime = 0;

	void HandleInput();
	void HandleCollisions();
	void HanldeBlackHoleCollisions();
	void HandleEnemyCollisions();
	void HandlePlayerCollisions();
	void UpdateEnemy();
};

