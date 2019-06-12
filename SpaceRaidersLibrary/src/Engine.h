#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "Managers/ConfigManager.h"
#include "Managers/FrameManager.h"
#include "Managers/GameObjectFactory.h"
#include "Managers/GameObjectManager.h"
#include "Managers/InputManager.h"
#include "Managers/LogManager.h"
#include "Managers/PowerUpManager.h"
#include "Managers/RandomManager.h"
#include "Managers/RenderManager.h"
#include "Managers/ScoreManager.h"
#include "Managers/ScreenManager.h"
#include "Managers/TextManager.h"

namespace SpaceRaiders
{
	class Engine
	{
	public:
		static Engine& Instance()
		{
			static Engine instance;
			return instance;
		}

		void Init();
		void Play();
		void Quit();

		ConfigManager&		ConfigManager() { return configManager; }
		FrameManager&		FrameManager() { return frameManager; }
		GameObjectFactory&	GameObjectFactory() { return gameObjectFactory; }
		GameObjectManager&	GameObjectManager() { return gameObjectManager; }
		InputManager&		InputManager() { return inputManager; }
		LogManager&			LogManager() { return logManager; }
		PowerUpManager&		PowerUpManager() { return powerUpManager; }
		RandomManager&		RandomManager() { return randomManager; }
		RenderManager&		RenderManager() { return renderManager; }
		ScoreManager&		ScoreManager() { return scoreManager; }
		ScreenManager&		ScreenManager() { return screenManager; }
		TextManager&		TextManager() { return textManager; }

	private:
		SpaceRaiders::ConfigManager		configManager;
		SpaceRaiders::FrameManager		frameManager;
		SpaceRaiders::GameObjectFactory	gameObjectFactory;
		SpaceRaiders::GameObjectManager	gameObjectManager;
		SpaceRaiders::InputManager		inputManager;
		SpaceRaiders::LogManager		logManager;
		SpaceRaiders::PowerUpManager	powerUpManager;
		SpaceRaiders::RandomManager		randomManager;
		SpaceRaiders::RenderManager		renderManager;
		SpaceRaiders::ScoreManager		scoreManager;
		SpaceRaiders::ScreenManager		screenManager;
		SpaceRaiders::TextManager		textManager;
	};
}

#endif//_ENGINE_H_