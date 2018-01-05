#include "Enemy.h"

Enemy::Enemy(void)
{
}

Enemy::Enemy(const Vector2& position, ID3D11Device* pDevice)
	:Tank(position, pDevice)
{
	stepLeft = 1000;
	cdLeft = 0;
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

Direction Enemy::GetOppsiteDirection(Direction direction)
{
	switch (direction)
	{
	case UP:
		return DOWN;
		break;
	case DOWN:
		return UP;
		break;
	case RIGHT:
		return LEFT;
		break;
	case LEFT:
		return RIGHT;
		break;
	default:
		return UP;
		break;
	}
}

void Enemy::Update(const Tank& player)
{
	//If the way is blocked, change to oppsite direction
	if (isBlocked)
	{
		newDirection = GetOppsiteDirection(currentDirection);
		stepLeft = GetRandomNumStep();
		isBlocked = false;
		Move(newDirection);
	}
	else if (stepLeft < 1)
	{
		newDirection = GetRandomDirection();
		stepLeft = GetRandomNumStep();
		Move(newDirection);
	}
	else
	{
		Move(currentDirection);
	}

	CheckIfCanSeePlayer(player);

	if (cdLeft > 0)
	{
		cdLeft--;
	}
}

Direction Enemy::GetRandomDirection()
{
	//Return a random direction
	return Direction(rand() % 4);
}

int Enemy::GetRandomNumStep()
{
	return rand() % 2000 + 500;
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

void Enemy::CheckIfCanSeePlayer(const Tank& player)
{
	Vector2 playerPos = player.GetPlayerPosition();
	if (cdLeft == 0)
	{
		switch (currentDirection)
		{
		case UP:
			CheckIfPlayerOnTop(playerPos);
			break;
		case DOWN:
			CheckIfPlayerDown(playerPos);
			break;
		case RIGHT:
			CheckIfPlayerOnRight(playerPos);
			break;
		case LEFT:
			CheckIfPlayerOnLeft(playerPos);
			break;
		}
		cdLeft = COOL_DOWN_TIME;
	}
	
}

void Enemy::CheckIfPlayerOnTop(const Vector2& playerPos)
{
	if (abs(playerPos.x - m_Sprite->GetPosition().x) < 50 && playerPos.y - m_Sprite->GetPosition().y < 0)
	{
		Shoot();
	}
}

void Enemy::CheckIfPlayerDown(const Vector2& playerPos)
{
	if (abs(playerPos.x - m_Sprite->GetPosition().x) < 50 && playerPos.y - m_Sprite->GetPosition().y > 0)
	{
		Shoot();
	}
}

void Enemy::CheckIfPlayerOnRight(const Vector2& playerPos)
{
	if (abs(playerPos.y - m_Sprite->GetPosition().y) < 50 && playerPos.x - m_Sprite->GetPosition().x > 0)
	{
		Shoot();
	}
}

void Enemy::CheckIfPlayerOnLeft(const Vector2& playerPos)
{
	if (abs(playerPos.y - m_Sprite->GetPosition().y) < 50 && playerPos.x - m_Sprite->GetPosition().x < 0)
	{
		Shoot();
	}
}