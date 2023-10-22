#pragma once
#include <vector>
#include "Joueur.h"

class Enemie {
private:
	int rand_attack;
	int rand_health;
	int rand_choose;
	int pv; 
	int* ptPv = nullptr;

public:
	
	Enemie();

	void EnemieDegat(int attack);

	void EnemieSoins(int soins);

	int getPv();

	void statusCombatEnemie(Joueur& joueur);

	~Enemie();
};


class Boss {
private:
	int rand_attack;
	int rand_health;
	int rand_choose;
	int pv;
	int* ptPvBoss;
public:
	Boss();

	void BossDegat(int attack);

	void BossSoins(int soins);

	int getPv();

	void statusCombatBoss(Joueur& joueur);

	~Boss();
};