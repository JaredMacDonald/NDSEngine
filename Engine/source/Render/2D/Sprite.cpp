#include <nds.h>
#include "Sprite.h"

namespace JM
{
	Sprite::Sprite(OamState* oamState, int oamIndex, const unsigned char* imageData,
		int x, int y, int width, int height, SpriteSize spriteSize, SpriteColorFormat colorFormat, bool doubleSize, int affineIndex)
		: m_OamGFX(nullptr)
		, m_Data(imageData)
		, m_OamIndex(oamIndex)
		, m_OamState(oamState)
		, m_SpriteSize(spriteSize)
		, m_ColorFormat(colorFormat)
		, m_AffineIndex(affineIndex)
		, m_X(x)
		, m_Y(y)
		, m_Width(width)
		, m_Height(height)
		, m_Alive(true)
		, m_DoubleSize(doubleSize)
	{

	}

	Sprite::~Sprite()
	{
		if (m_OamGFX != nullptr)
		{
			oamFreeGfx(m_OamState, m_OamGFX);
			m_OamGFX = nullptr;
		}
	}

	void Sprite::SetPosition(int x, int y)
	{
		m_X = x;
		m_Y = y;
	}

	void Sprite::SetXPosition(int x)
	{
		m_X = x;
	}

	void Sprite::SetYPosition(int y)
	{
		m_Y = y;
	}

	void Sprite::MovePosition(int x, int y)
	{
		m_X += x;
		m_Y += y;
	}

	void Sprite::SetWidth(int width)
	{
		m_Width = width;
	}

	void Sprite::SetHeight(int height)
	{
		m_Height = height;
	}

	void Sprite::Init()
	{
		m_OamGFX = oamAllocateGfx(m_OamState, m_SpriteSize, m_ColorFormat);

		dmaCopy((u8*)m_Data, m_OamGFX, m_Width * m_Height / 2);
	}

	void Sprite::Draw()
	{
		oamSet(m_OamState, //main graphics engine context
			m_OamIndex,           //oam index (0 to 127)  
			m_X, m_Y,//x and y pixel location of the sprite
			0,                    //priority, lower renders last (on top)
			0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
			m_SpriteSize,
			m_ColorFormat,
			m_OamGFX,                  //pointer to the loaded graphics
			-1,                  //sprite rotation data  
			false,               //double the size when rotating?
			false,			//hide the sprite?
			false, false, //vflip, hflip
			false	//apply mosaic
		);
	}
}