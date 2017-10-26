#pragma once
#include "Sprite.h"
using namespace Directions;


class Bullet
{
public:
	//Constructions
	Bullet();
	Bullet(const Vector2& position, ID3D11Device* pDevice, const enum Direction bulletDirection);
	~Bullet();

	//Getters
	const DirectX::SimpleMath::Vector2& GetPosition() const;
	const RECT& GetRect() const;
	const Direction& GetDirection() const;
	const bool& IsActive() const;
	//Setters
	void SetActive(const bool& aciveOrNot);
	void SetPosition(const DirectX::SimpleMath::Vector2& position);
	void SetDirection(const Direction direction);

	void UpdateBulletPosition();
	void Draw(DirectX::SpriteBatch* spriteBatch);

private:
	Sprite* bulletSprite;
	enum Direction m_Direction;
	bool isActive;
	const float BULLET_SPEED = 0.5f;
	const float UPPER_BOUNDRAY = 0.0f;
	const float LOWER_BOUNDRAY = 600.0f;
	const float LEFT_BOUNDRAY = 0.0f;
	const float RIGHT_BOUNDRAY = 800.0f;
	
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
};

