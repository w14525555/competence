#include "Sprite.h"
#include "DDSTextureLoader.h"

Sprite::Sprite(){}


Sprite::~Sprite(void)
{
	Memory::SafeRelease(m_pTexture);
	Memory::SafeRelease(m_pResource);
}

Sprite::Sprite(const Vector2& position)
{
	m_Position = position;
	m_Alpha = 1.0f;
	m_Rotation = 0.0f;
	m_Scale = Vector2(1, 1);
	m_Color = DirectX::Colors::White.v;
}

void Sprite::Load(ID3D11Device* device, const wchar_t* pFile)
{
	//Import Texture For Rendering L"Test.dds"
	HR(DirectX::CreateDDSTextureFromFile(device, pFile, &m_pResource, &m_pTexture));
	//Calculate Origin
	Utility::GetTextureDim(m_pResource, &m_Width, &m_Height);
	m_Origin = Vector2(m_Width/2.0f, m_Height/2);
	m_SourceRect.left = 0;
	m_SourceRect.top = 0;
	m_SourceRect.right = m_Width;
	m_SourceRect.bottom = m_Height;

}

const Vector2& Sprite::GetPosition() const
{
	return m_Position;
}

const Vector2& Sprite::GetOrigin() const
{
	return m_Origin;
}

const Vector2& Sprite::GetScale() const
{
	return m_Scale;
}

const Color& Sprite::GetColor() const
{
	return m_Color;
}

const float& Sprite::GetAlpha() const
{
	return m_Alpha;
}

const float& Sprite::GetRotation() const
{
	return m_Rotation;
}

const UINT& Sprite::GetWidth() const
{
	return m_Width;
}

const UINT& Sprite::GetHeight() const
{
	return m_Height;
}

const RECT& Sprite::GetRectangle() const
{
	return m_SourceRect;
}
//Setters
void Sprite::SetPosition(const Vector2& position)
{
	m_Position = position;
}

void Sprite::SetOrigin(const Vector2& origin)
{
	m_Origin = origin;
}

void Sprite::SetScale(const Vector2& scale)
{
	m_Scale = scale;
}

void Sprite::SetColor(const Color& color)
{
	m_Color = color;
}

void Sprite::SetAlpha(const float& alpha)
{
	m_Alpha = alpha;
}

void Sprite::SetRotation(const float& rotation)
{
	m_Rotation = rotation;
}

void Sprite::Draw(DirectX::SpriteBatch* spriteBatch)
{
	spriteBatch->Draw(m_pTexture, m_Position, &m_SourceRect, m_Color, m_Rotation, m_Origin,
		m_Scale, DirectX::SpriteEffects::SpriteEffects_None, 0.0f);
}


