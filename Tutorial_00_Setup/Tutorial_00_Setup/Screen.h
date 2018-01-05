
#pragma once
#include <memory>
#include "DXUtil.h"
#include "SpriteFont.h"

class Screen
{
public:
	virtual void Update() = 0;
	virtual void Init(ID3D11Device* m_pDevice) = 0;
	virtual void Render(std::unique_ptr<DirectX::SpriteBatch> & spriteBatch, std::unique_ptr<DirectX::SpriteFont> & spriteFont) = 0;
	bool readyForNextScene = false;
};