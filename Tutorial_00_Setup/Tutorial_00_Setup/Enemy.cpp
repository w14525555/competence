#include "Enemy.h"

Enemy::Enemy(void)
{
}

Enemy::Enemy(const Vector2& position, ID3D11Device* pDevice)
	:Tank(position, pDevice)
{
	stepLeft = 1000;
	newDirection = currentDirection;
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	if (stepLeft < 1)
	{
		newDirection = GetRandomDirection();
		stepLeft = GetRandomNumStep();
		Move();
	}
	else
	{
		Move();
	}
}

Direction Enemy::GetRandomDirection()
{
	//Return a random direction
	return Direction(rand() % 4);
}

int Enemy::GetRandomNumStep()
{
	return rand() % 2000 + 1000;
}

void Enemy::Move()
{
	stepLeft -= 1;
	switch (newDirection)
	{
	case UP:
		MoveUp();
		break;
	case DOWN:
		MoveDown();
		break;
	case RIGHT:
		MoveRight();
		break;
	case LEFT:
		MoveLeft();
		break;
	default:
		break;
	}
}
