#include "Tank.h"

Tank::Tank(void)
{
}

Tank::Tank(const Vector2& position, ID3D11Device* pDevice)
{
	m_pDevice = pDevice;
	//Load Sprite For Up
	m_UpSprite = new Sprite(position);
	m_UpSprite->Load(pDevice, L"TankUp.dds");

	//Load Sprite For Left
	m_LeftSprite = new Sprite(position);
	m_LeftSprite->Load(pDevice, L"TankLeft.dds");

	//Default Image is Up
	m_Sprite = m_UpSprite;
}

Tank::~Tank(void)
{
	Memory::SafeDelete(m_Sprite);
}

void Tank::MoveUp() 
{
	//Update the position first
	m_UpSprite->SetPosition(m_Sprite->GetPosition());
	//Change the new Direction
	m_Sprite = m_UpSprite;
	float newY = m_Sprite->GetPosition().y - MOVE_SPEED;
	if(newY > UPPER_BOUNDRAY + m_Sprite->GetHeight()/2)
	{
		
		m_Sprite->SetPosition(DirectX::SimpleMath::Vector2(m_Sprite->GetPosition().x, newY));
	}
		
}

void Tank::MoveDown()
{
	float newY = m_Sprite->GetPosition().y + MOVE_SPEED;
	if (m_Sprite->GetPosition().y + MOVE_SPEED < LOWER_BOUNDRAY - m_Sprite->GetHeight() / 2)
		m_Sprite->SetPosition(DirectX::SimpleMath::Vector2(m_Sprite->GetPosition().x, newY));
}

void Tank::MoveLeft()
{
	//Update the position first
	m_LeftSprite->SetPosition(m_Sprite->GetPosition());
	//Change the new Direction
	m_Sprite = m_LeftSprite;

	float newX = m_Sprite->GetPosition().x - MOVE_SPEED;
	if(m_Sprite->GetPosition().x - MOVE_SPEED > LEFT_BOUNDRAY + m_Sprite->GetWidth() / 2)
		m_Sprite->SetPosition(DirectX::SimpleMath::Vector2(newX, m_Sprite->GetPosition().y));
}

void Tank::MoveRight()
{
	float newX = m_Sprite->GetPosition().x + MOVE_SPEED;
	if(m_Sprite->GetPosition().x + MOVE_SPEED < RIGHT_BOUNDRAY - m_Sprite->GetWidth() / 2)
		m_Sprite->SetPosition(DirectX::SimpleMath::Vector2(newX, m_Sprite->GetPosition().y));
}

void Tank::Draw(DirectX::SpriteBatch* spriteBatch)
{
	m_Sprite->Draw(spriteBatch);
}


