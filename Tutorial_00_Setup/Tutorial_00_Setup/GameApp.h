#pragma once

#include "DXApp.h"
#include "Tank.h"
#include "Enemy.h"
#include "SpriteFont.h"


class GameApp : public DXApp
{
public:
	GameApp(HINSTANCE hInstance);
	~GameApp();

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
	void HanldeBlockCollisions();
	void HandleEnemyCollisions();
};

