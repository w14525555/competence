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
	Direction GetRandomDirection();
	int GetRandomNumStep();

private:
	int stepLeft;
	Direction newDirection;

	void Move();
};

