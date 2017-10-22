#include "Tank.h"

Tank::Tank(void)
{
}

Tank::Tank(const Vector2& position, ID3D11Device* pDevice, const wchar_t* pFile)
{
	m_Sprite = new Sprite(position);
	m_Sprite->Load(pDevice, pFile);
}

Tank::~Tank(void)
{
	Memory::SafeDelete(m_Sprite);
}

void Tank::MoveUp() 
{
	float newY = m_Sprite->GetPosition().y - MOVE_SPEED;
	if(newY > UPPER_BOUNDRAY + m_Sprite->GetHeight()/2)
		m_Sprite->SetPosition(DirectX::SimpleMath::Vector2(m_Sprite->GetPosition().x, newY));
}

void Tank::MoveDown()
{
	float newY = m_Sprite->GetPosition().y + MOVE_SPEED;
	if (m_Sprite->GetPosition().y + MOVE_SPEED < LOWER_BOUNDRAY - m_Sprite->GetHeight() / 2)
		m_Sprite->SetPosition(DirectX::SimpleMath::Vector2(m_Sprite->GetPosition().x, newY));
}

void Tank::MoveLeft()
{
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


