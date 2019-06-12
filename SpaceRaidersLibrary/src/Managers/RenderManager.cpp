#include "RenderManager.h"
#include <Windows.h>
#include <iostream>

namespace SpaceRaiders
{
	void RenderManager::Render( float x, float y, unsigned char sprite )
	{
		Render( (int)x, (int)y, sprite );
	}
	void RenderManager::Render( int x, int y, unsigned char sprite )
	{
		SetCursorPosition( x, y );
		std::cout << sprite;
	}

	void RenderManager::Text()
	{
		SetCursorPosition( 2, 2 );
		std::cout << "Space Raiders";
	}
	void RenderManager::Text( int x, int y, const char* text )
	{
		SetCursorPosition( x, y );
		std::cout << text;
	}

	void RenderManager::Empty()
	{
		// Print an empty character every frame to prevent blinking cursor
		Render( 1, 1, ' ' );
	}

	void RenderManager::SetCursorPosition( int x, int y )
	{
		static const HANDLE hOut = GetStdHandle( STD_OUTPUT_HANDLE );
		std::cout.flush();
		COORD coord = { (SHORT)x, (SHORT)y };
		SetConsoleCursorPosition( hOut, coord );
	}
}