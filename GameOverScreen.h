
#pragma once

#include "KatanaEngine.h"

using namespace KatanaEngine;

class GameOverScreen : public MenuScreen
{

public:

	// Instantiate new game over screen
	GameOverScreen();
	virtual ~GameOverScreen() { }

	// Loads the content for the game over screen
	virtual void LoadContent(ResourceManager& resourceManager);

	// Updates the screen
	virtual void Update(const GameTime& gameTime);

	// Draws textures and fonts
	virtual void Draw(SpriteBatch& spriteBatch);

private:

	Texture* m_pTexture = nullptr;

	Vector2 m_texturePosition;

	












};
