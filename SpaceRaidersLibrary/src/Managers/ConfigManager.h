#ifndef _CONFIG_MANAGER_H_
#define _CONFIG_MANAGER_H_

namespace SpaceRaiders
{
	class ConfigManager
	{
	public:
		ConfigManager() {}
		~ConfigManager() {}

		void Init();
		int GetConfig( const char index )
		{
			return m_iConfig[index];
		}

	private:
		void LogConfiguration();
		short m_iConfig[25];
	};
}

#endif//_CONFIG_MANAGER_H_