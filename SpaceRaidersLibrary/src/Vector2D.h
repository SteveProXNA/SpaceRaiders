#ifndef _VECTOR2D_H_
#define _VECTOR2D_H_

namespace SpaceRaiders
{
	struct Vector2D
	{
	public:
		Vector2D() : x( 0 ), y( 0 ) {};

		Vector2D( const Vector2D& vector )
		{
			x = vector.x;
			y = vector.y;
		}

		Vector2D( float x, float y ) : x( x ), y( y ) {};
		~Vector2D() {}

		bool IntCmp( const Vector2D& vec ) { return int( x ) == int( vec.x ) && int( y ) == int( vec.y ); }
		// Operator overloading
		Vector2D operator + ( const Vector2D& other );
		Vector2D operator * ( const Vector2D& other );
		Vector2D operator * ( const float other );
		Vector2D operator / ( const float other );
		Vector2D operator - ( const Vector2D& other );

		float length();

		float x;
		float y;
	};

}

#endif//_VECTOR2D_H_