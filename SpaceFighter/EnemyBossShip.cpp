#include "EnemyBossShip.h"
#include "Level.h"
#include "Level01.h"
#include "Level02.h"
#include <cmath>

EnemyBossShip::EnemyBossShip()
{
	// Boss stats
	SetSpeed(90);
	SetMaxHitPoints(4);   
	SetCollisionRadius(100);
}

void EnemyBossShip::Update(const GameTime& gameTime)
{
	if (IsActive())
	{
		// Movement pattern similar to BioEnemyShip
		float x = 15 * sin(gameTime.GetTotalTime() * Math::PI + GetIndex());
		x *= GetSpeed() * (float)gameTime.GetElapsedTime() * 0.2f;

		TranslatePosition(
			x,
			GetSpeed() * (float)gameTime.GetElapsedTime() * 0.01f
		);

	}

	
	EnemyShip::Update(gameTime);
}


void EnemyBossShip::Draw(SpriteBatch& spriteBatch)
{
	if (IsActive())
	{
		const float alpha = GetCurrentLevel()->GetAlpha();
		spriteBatch.Draw(m_pTexture,
			GetPosition(),
			Color::WHITE * alpha,
			m_pTexture->GetCenter(),
			Vector2::ONE,
			Math::PI,
			1);
	}
}

void EnemyBossShip::Hit(const float damage)
{
	// Let base ship logic subtract HP and deactivate/spawn explosion when HP <= 0
	EnemyShip::Hit(damage);

	if (!IsActive() && !m_defeatedTriggered)
	{
		m_defeatedTriggered = true;
		GetCurrentLevel()->OnBossDefeated();
	}

}



