
#include "GameOverScreen.h"
#include "MainMenuScreen.h"
#include "GameplayScreen.h"
#include "Level.h"



GameOverScreen::GameOverScreen()
{
	SetTransitionInTime(1);
	SetTransitionOutTime(0.5f);

	Show();
}

void GameOverScreen::LoadContent(ResourceManager& resourceManager)
{
	// Loads the Game Over image
	m_pTexture = resourceManager.Load<Texture>("Textures\\YouDied.png");
	m_texturePosition = Game::GetScreenCenter() - Vector2::UNIT_Y * 200;


	// Create the menu items
	const int COUNT = 3;
	MenuItem* pItem;
	Font* pFont = resourceManager.Load<Font>("Fonts\\arial.ttf");

	SetDisplayCount(COUNT);

	enum Items { TRY_AGAIN, MAIN_MENU, QUIT };
	std::string text[COUNT] = { "Try Again","Main Menu", "Quit" };

	for (int i = 0; i < COUNT; i++)
	{
		pItem = new MenuItem(text[i]);
		pItem->SetPosition(Game::GetScreenCenter() - 100 + Vector2::UNIT_Y * i * 100);
		pItem->SetFont(pFont);
		pItem->SetColor(Color::BLUE);
		pItem->SetSelected(i == 0);
		AddMenuItem(pItem);
	}

	// when "Try Again" is selected, loads a new gameplay screen, then exits the Game Over screen
	GetMenuItem(TRY_AGAIN)->SetOnSelect([this]() {
		SetOnRemove([this]() { 
		AddScreen(new GameplayScreen()); 
		Ship::ResetScore();});
		Exit();
		});

	// when "Start Game" is selected, loads the main menu, then exits the Game Over screen
	GetMenuItem(MAIN_MENU)->SetOnSelect([this]() {
		SetOnRemove([this]() { AddScreen(new MainMenuScreen()); });
		Exit();
		});

	// when "Quit" is selected, exits the game
	GetMenuItem(QUIT)->SetOnSelect([this]() {GetGame()->Quit();});
		
}

void GameOverScreen::Update(const GameTime& gameTime)
{
	bool isSelected = false;
	float alpha = GetAlpha();
	float offset = sinf(gameTime.GetTotalTime() * 10) * 5 + 5;

	for (MenuItem* pItem : GetMenuItems())
	{
		pItem->SetAlpha(alpha);
		isSelected = pItem->IsSelected();
		pItem->SetColor(isSelected ? Color::WHITE : Color::BLUE);
		pItem->SetTextOffset(isSelected ? Vector2::UNIT_X * offset : Vector2::ZERO);
	}

	MenuScreen::Update(gameTime);
}

void GameOverScreen::Draw(SpriteBatch& spriteBatch)
{
	spriteBatch.Begin();
	spriteBatch.Draw(m_pTexture, m_texturePosition, Color::WHITE * GetAlpha(), m_pTexture->GetCenter());
	MenuScreen::Draw(spriteBatch);
	spriteBatch.End();
}