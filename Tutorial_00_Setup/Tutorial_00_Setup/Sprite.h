#pragma once
#include "IElement2D.h"

class Sprite: public IElement2D
{
public:
	Sprite();
	Sprite(const Vector2& position);
	~Sprite(void);

	//Getters
	virtual const Vector2& GetPosition() const;
	virtual const Vector2& GetOrigin() const;
	virtual const Vector2& GetScale() const;
	virtual const Color& GetColor() const;
	virtual const float& GetAlpha() const;
	virtual const float& GetRotation() const;
	virtual const UINT& GetWidth() const;
	virtual const UINT& GetHeight() const;
	virtual const RECT& GetRectangle() const;

	//Setters
	virtual void SetPosition(const Vector2& position);
	virtual void SetOrigin(const Vector2& origin);
	virtual void SetScale(const Vector2& scale);
	virtual void SetColor(const Color& color);
	virtual void SetAlpha(const float& alpha);
	virtual void SetRotation(const float& rotation);

	//Render Function
	virtual void Draw(DirectX::SpriteBatch* spriteBatch);

	//Load
	virtual void Load(ID3D11Device* device, const wchar_t* file);

protected:
	ID3D11Resource*				m_pResource;
	ID3D11ShaderResourceView*	m_pTexture;
	UINT						m_Width;
	UINT						m_Height;
	RECT						m_SourceRect;

	Vector2						m_Position;
	Vector2						m_Origin;
	Vector2						m_Scale;
	Color						m_Color;
	float						m_Alpha;
	float						m_Rotation;

};

