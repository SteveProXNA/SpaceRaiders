#ifndef _TEXT_MANAGER_H_
#define _TEXT_MANAGER_H_

namespace SpaceRaiders
{
	class TextManager
	{
	public:
		TextManager() {}
		~TextManager() {}

		void Init( short screenWidth, short screenHeight, short alienStart, short energyTimer );
		void Header();
		void Footer();
		void Footer2();
		void Board();
		void Energy( short life );
		void Start();
		void Over();
		void Fill();

	private:
		short m_screenWidth;
		short m_screenHeight;
		short m_WavesShipStart;
		short m_EnergyTimer;
	};
}

#endif//_TEXT_MANAGER_H_