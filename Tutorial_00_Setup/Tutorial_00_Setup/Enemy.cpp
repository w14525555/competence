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

void Enemy::Hit(Direction hitDirection)
{
	currentDirection = hitDirection;
	stepLeft = 1000;
}

void Enemy::Update()
{
	if (stepLeft < 1)
	{
		newDirection = GetRandomDirection();
		stepLeft = GetRandomNumStep();
		Move(newDirection);
	}
	else
	{
		Move(currentDirection);
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

void Enemy::Move(Direction direction)
{
	stepLeft -= 1;
	switch (direction)
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
