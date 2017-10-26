#pragma once
#include "Tank.h"

using namespace Directions;

class Enemy :
	public Tank
{
public:
	Enemy();
	Enemy(const Vector2& position, ID3D11Device* pDevice);
	~Enemy();

	void Update();
	void Hit(Direction hitDirection);
	int GetRandomNumStep();
	Direction GetRandomDirection();

private:
	int stepLeft;
	Direction newDirection;

	void Move(Direction direction);
};

