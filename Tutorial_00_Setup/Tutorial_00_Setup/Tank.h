#pragma once
#include "Sprite.h"

class Tank
{
public:
	Tank();
	Tank(const Vector2& position, ID3D11Device* pDevice, const wchar_t* file);
	~Tank();
	
	//GetT
	//Functions
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();

	void Draw(DirectX::SpriteBatch* spriteBatch);

private:
	Sprite* m_Sprite;
	const float MOVE_SPEED = 0.1f;
	const float UPPER_BOUNDRAY = 0.0f;
	const float LOWER_BOUNDRAY = 600.0f;
	const float LEFT_BOUNDRAY = 0.0f;
	const float RIGHT_BOUNDRAY = 800.0f;
};

