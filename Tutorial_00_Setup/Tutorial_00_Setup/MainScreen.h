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
	void Render(std::unique_ptr<DirectX::SpriteBatch> & spriteBatch) override;

private:
	Tank* tank;
	Sprite* sprite;
	Enemy* enemy;

	void HandleInput();
	void HandleCollisions();
	void HanldeBlockCollisions();
	void HandleEnemyCollisions();
	void UpdateEnemy();
};

