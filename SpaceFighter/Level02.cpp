
#include "Level01.h"
#include "BioEnemyShip.h"
#include "EnemyBossShip.h"
#include "Blaster.h"
#include "GameplayScreen.h"


void Level02::LoadContent(ResourceManager& resourceManager)
{
	// Setup enemy ships
	Texture* pTexture = resourceManager.Load<Texture>("Textures\\BioEnemyShip.png");

	Texture* pBossTexture = resourceManager.Load<Texture>("Textures\\BioEnemyBoss.png");

	const int COUNT = 22;

	double xPositions[COUNT] =
	{
		0.25, 0.2, 0.3,
		0.75, 0.8, 0.7,
		0.3, 0.25, 0.35, 0.2, 0.4,
		0.7, 0.75, 0.65, 0.8, 0.6,
		0.5, 0.4, 0.6, 0.45, 0.55, .6
	};

	double delays[COUNT] =
	{
		0.0, 0.25, 0.25,
		3.0, 0.25, 0.25,
		3.25, 0.25, 0.25, 0.25, 0.25,
		3.25, 0.25, 0.25, 0.25, 0.25,
		3.5, 0.3, 0.3, 0.3, 0.3, 0.3
	};

	float delay = 3.0; // start delay
	Vector2 position;

	for (int i = 0; i < COUNT; i++)
	{
		delay += delays[i];
		position.Set(xPositions[i] * Game::GetScreenWidth(), -pTexture->GetCenter().Y);

		BioEnemyShip* pEnemy = new BioEnemyShip();
		pEnemy->SetTexture(pTexture);
		pEnemy->SetCurrentLevel(this);
		pEnemy->Initialize(position, (float)delay);
		AddGameObject(pEnemy);
	}

	EnemyBossShip* pBoss = new EnemyBossShip();
	pBoss->SetTexture(pBossTexture);
	pBoss->SetCurrentLevel(this);

	Vector2 bossPos;
	bossPos.Set(Game::GetScreenWidth() * 0.5f, 120.0f); // top area
	pBoss->Initialize(bossPos, 0.01); // 0 = active right away (or use delay)
	AddGameObject(pBoss);

	SetBackground(resourceManager.Load<Texture>("Textures\\SpaceBackground03.png"));

	Level::LoadContent(resourceManager);
}


