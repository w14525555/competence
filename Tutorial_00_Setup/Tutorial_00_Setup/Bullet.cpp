#include "Bullet.h"

Bullet::Bullet()
{
}


Bullet::~Bullet()
{
}

Bullet::Bullet(const DirectX::SimpleMath::Vector2& position, ID3D11Device* pDevice, const enum Direction bulletDirection)
{
	bulletSprite = new Sprite(position);
	bulletSprite->Load(pDevice, L"Bullet.dds");
	m_Direction = bulletDirection;
	isActive = false;
}

const DirectX::SimpleMath::Vector2& Bullet::GetPosition() const
{
	return bulletSprite->GetPosition();
}

const bool& Bullet::IsActive() const
{
	return isActive;
}

void Bullet::SetActive(const bool& aciveOrNot)
{
	isActive = aciveOrNot;
}

void Bullet::SetPosition(const DirectX::SimpleMath::Vector2& position)
{
	bulletSprite->SetPosition(position);
}

void Bullet::SetDirection(const Direction direction)
{
	m_Direction = direction;
}

void Bullet::UpdateBulletPosition()
{
	switch (m_Direction)
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

void Bullet::MoveUp()
{
	float newY = bulletSprite->GetPosition().y - BULLET_SPEED;
	if (newY > UPPER_BOUNDRAY + bulletSprite->GetHeight() / 2)
	{
		bulletSprite->SetPosition(DirectX::SimpleMath::Vector2(bulletSprite->GetPosition().x, newY));
	}
	else
	{
		//If out of boundary, it become inactive
		isActive = false;
	}
}

void Bullet::MoveDown()
{
	float newY = bulletSprite->GetPosition().y + BULLET_SPEED;
	if (newY < LOWER_BOUNDRAY - bulletSprite->GetHeight() / 2)
	{
		bulletSprite->SetPosition(DirectX::SimpleMath::Vector2(bulletSprite->GetPosition().x, newY));
	}
	else
	{
		//If out of boundary, it become inactive
		isActive = false;
	}
}

void Bullet::MoveRight()
{
	float newX = bulletSprite->GetPosition().x + BULLET_SPEED;
	if (newX < RIGHT_BOUNDRAY - bulletSprite->GetWidth() / 2)
	{
		bulletSprite->SetPosition(DirectX::SimpleMath::Vector2(newX, bulletSprite->GetPosition().y));
	}
	else
	{
		//If out of boundary, it become inactive
		isActive = false;
	}
}

void Bullet::MoveLeft()
{
	float newX = bulletSprite->GetPosition().x - BULLET_SPEED;
	if (newX > LEFT_BOUNDRAY + bulletSprite->GetWidth() / 2)
	{
		bulletSprite->SetPosition(DirectX::SimpleMath::Vector2(newX, bulletSprite->GetPosition().y));
	}
	else
	{
		//If out of boundary, it become inactive
		isActive = false;
	}
		
}

void Bullet::Draw(DirectX::SpriteBatch* spriteBatch)
{
	bulletSprite->Draw(spriteBatch);
}