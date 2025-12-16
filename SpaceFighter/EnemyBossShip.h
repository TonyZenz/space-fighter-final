#pragma once

#include "EnemyShip.h"
#include "Level.h"


class EnemyBossShip : public EnemyShip
{
public:

	//Creates a new instance of EnemyBossShip
	EnemyBossShip();
	virtual ~EnemyBossShip() {}

	
	virtual void SetTexture(Texture* pTexture) { m_pTexture = pTexture; }


	virtual void Update(const GameTime& gameTime);

	virtual void Draw(SpriteBatch& spriteBatch);


	virtual void Hit(const float damage);

	virtual std::string ToString() const { return "Enemy Boss Ship"; }

private:

	Texture* m_pTexture = nullptr;

	bool m_defeatedTriggered = false;


};

