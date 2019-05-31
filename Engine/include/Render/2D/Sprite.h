#pragma once

#include <nds.h>
namespace JM
{
	class Sprite
	{
	public:
		Sprite(OamState* oamState, int oamIndex, const unsigned char* imageData,
			int x, int y, int width, int height, SpriteSize spriteSize, SpriteColorFormat colorFormat, bool doubleSize = false, int affineIndex = -1);

		virtual ~Sprite();

		void Init();

		void Draw();

		void SetPosition(int x, int y);
		void SetXPosition(int x);
		void SetYPosition(int y);

		void MovePosition(int x, int y);

		int GetXPosition() const { return m_X; }
		int GetYPosition() const { return m_Y; }

		int GetWidth() const { return m_Width; }
		void SetWidth(int width);

		void SetHeight(int height);
		int GetHeight() const { return m_Height; }

	private:

		u16* m_OamGFX;
		const unsigned char* m_Data;
		int m_OamIndex;

		OamState* m_OamState;
		SpriteSize m_SpriteSize;
		SpriteColorFormat m_ColorFormat;

		int m_AffineIndex;
		int m_X;
		int m_Y;
		int m_Width;
		int m_Height;

		bool m_Alive;
		bool m_DoubleSize;
	};
}
