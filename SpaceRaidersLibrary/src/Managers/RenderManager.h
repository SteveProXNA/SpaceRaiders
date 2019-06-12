#ifndef _RENDER_MANAGER_H_
#define _RENDER_MANAGER_H_

namespace SpaceRaiders
{
	class RenderManager
	{
	public:
		RenderManager() {}
		~RenderManager() {}

		void Render( float x, float y, unsigned char sprite );
		void Render( int x, int y, unsigned char sprite );

		void Text();
		void Text( int x, int y, const char* text );
		void Empty();

	private:
		void SetCursorPosition( int x, int y );
	};
}

#endif//_RENDER_MANAGER_H_