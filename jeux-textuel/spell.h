#pragma once

#include <vector>
#include <string>
#include "Joueur.h"

class SpellStructure {
private:

	struct Spell {
		int idSpell;
		std::string nomSpell;
		int valeurSpell;
		std::string labelSpell;
	};

public:

	std::vector<Spell> listAttack = {};

	void fichierAttackJoueur();

};