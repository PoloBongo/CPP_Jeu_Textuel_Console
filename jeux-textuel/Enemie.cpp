#pragma once

#include "import.h";
#include "include.h";

using namespace std;

SpellStructure spell;

Enemie::Enemie()
{
	SpellStructure spell;
	spell.fichierAttackJoueur();

	pv = spell.listAttack[12].valeurSpell;
	ptPv = new int(pv);
};

void Enemie::EnemieDegat(int attack)
{
	*ptPv -= attack;
};

void Enemie::EnemieSoins(int soins) {
	*ptPv += soins;
};

int Enemie::getPv() {
	return *ptPv;
};

void Enemie::statusCombatEnemie(Joueur& joueur) {

	srand(time(nullptr));
	rand_attack = rand() % 3 + 1;
	rand_choose = rand() % 4 + 1;
	rand_health = rand() % 2 + 1;

	spell.fichierAttackJoueur();
	if (rand_choose > 0 && rand_choose < 3)
	{
		AnimationTexte("Le membre de la marine ta touche avec " + spell.listAttack[rand_attack - 1].labelSpell + ", tu perds - " + to_string(spell.listAttack[rand_attack - 1].valeurSpell) + "  pv\n", 50, 34);
		joueur.JoueurDegat(spell.listAttack[rand_attack - 1].valeurSpell);
		cout << "Pv Joueur: " << joueur.getPv() << endl;
	}
	else
	{
		AnimationTexte("Le membre de la marine s'est soigne avec " + spell.listAttack[rand_health + 2].labelSpell + ", il gagne + " + to_string(spell.listAttack[rand_health + 2].valeurSpell) + "  pv\n", 50, 34);
		EnemieSoins(spell.listAttack[rand_health + 2].valeurSpell);
		cout << "Pv Enemie: " << *ptPv << endl;
	}
};



Enemie::~Enemie()
{
	delete ptPv;
};

Boss::Boss()
{
	SpellStructure spell;
	spell.fichierAttackJoueur();

	pv = spell.listAttack[13].valeurSpell;
	ptPvBoss = new int(pv);
};

void Boss::BossDegat(int attack)
{
	*ptPvBoss -= attack;
};

void Boss::BossSoins(int soins) {
	*ptPvBoss += soins;
};

int Boss::getPv() {
	return *ptPvBoss;
}
void Boss::statusCombatBoss(Joueur& joueur) {

	srand(time(nullptr));

	rand_attack = rand() % 6 + 1;
	rand_choose = rand() % 4 + 1;
	rand_health = rand() % 2 + 1;

	spell.fichierAttackJoueur();

	if (rand_choose > 0 && rand_choose < 3)
	{
		AnimationTexte("Garp ta touche avec " + spell.listAttack[rand_attack + 4].labelSpell + ", tu perds - " + to_string(spell.listAttack[rand_attack + 4].valeurSpell) + "  pv\n", 50, 34);
		joueur.JoueurDegat(spell.listAttack[rand_attack + 4].valeurSpell);
		cout << "Pv Joueur: " << joueur.getPv() << endl;
	}
	else
	{
		AnimationTexte("Garp s'est soigne avec " + spell.listAttack[rand_health + 2].labelSpell + ", il gagne + " + to_string(spell.listAttack[rand_health + 2].valeurSpell) + "  pv\n", 50, 34);
		joueur.JoueurDegat(spell.listAttack[rand_health + 2].valeurSpell);
		cout << "Pv Garp: " << *ptPvBoss << endl;
	}

};


Boss::~Boss()
{
	delete ptPvBoss;
};
