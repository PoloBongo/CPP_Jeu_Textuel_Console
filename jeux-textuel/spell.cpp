#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include "spell.h";
#include "Animation.h";

using namespace std;

void SpellStructure::fichierAttackJoueur()
{

	ifstream fichierAttackJoueur("spell.txt");

	if (!fichierAttackJoueur.is_open())
	{
		cout << "Le fichier ne s'est pas ouvert!" << endl;
	}
	else
	{
		string nombreLigne;

		while (getline(fichierAttackJoueur, nombreLigne))
		{
			Spell attack;
			char virgule = ',';

			istringstream linestream(nombreLigne);
			if (linestream >> attack.idSpell >> virgule && getline(linestream, attack.nomSpell, virgule) && linestream >> attack.valeurSpell >> virgule && getline(linestream, attack.labelSpell, virgule)) {
				listAttack.push_back(attack);
			}
		};

		fichierAttackJoueur.close();
	}
}