#pragma once;

class Game
{
private:
	int choix_utilisateur;
	int finCombat;
public:

	Game();

	void introGame();

	void combatContreMarin();

	void dialogBoss();

	void combatContreBoss();

	void dialogFin();

	void start();

	bool getFin();


};