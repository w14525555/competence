#pragma once
#include "Tank.h"

using namespace Directions;

class Enemy :
	public Tank
{
public:
	Enemy();
	Enemy(const Vector2& position, ID3D11Device* pDevice);
	const bool IsBulletActive();
	~Enemy();

	void Update(const Tank& player);
	void Hit(Direction hitDirection);
	int GetRandomNumStep();
	Direction GetRandomDirection();
	bool isPushed = false;

private:
	int stepLeft;
	const int COOL_DOWN_TIME = 200;
	int cdLeft;
	Direction newDirection;

	void Move(Direction direction);
	void CheckIfCanSeePlayer(const Tank& player);
	void CheckIfPlayerOnTop(const Vector2& playerPos);
	void CheckIfPlayerDown(const Vector2& playerPos);
	void CheckIfPlayerOnRight(const Vector2& playerPos);
	void CheckIfPlayerOnLeft(const Vector2& playerPos);
	Direction GetOppsiteDirection(Direction direction);
};

