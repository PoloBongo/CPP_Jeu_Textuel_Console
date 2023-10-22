#pragma once

#include "import.h";
#include "include.h";

using namespace std;
Game game;
Joueur::Joueur()
{
    SpellStructure spell;
    spell.fichierAttackJoueur();

    pv = spell.listAttack[11].valeurSpell;
    choixAttaque = 0;
    choixSoins = 0;
    choixUtilisateur = 0;
    ptPv = new int(pv);
};

void Joueur::JoueurDegat(int attack)
{
    *ptPv -= attack;
};

void Joueur::JoueurSoins(int soins) {
    *ptPv += soins;
};

int Joueur::getPv() {

    return *ptPv;
}

void Joueur::statusCombatJoueur(Enemie& enemie, Boss& boss)
{
    Joueur joueur;
    SpellStructure spell;

    spell.fichierAttackJoueur();

    AnimationTexte("Voulez-vous attaquez(1) ou vous soignez(2) ?\n", 50, 32);
    cin >> choixUtilisateur;

    if (choixUtilisateur == 1)
    {
        AnimationTexte("Attaque disponible :\t1 - Attaque Epee\t2 - Attaque Pistolet\t3 - Attaque Physique\n", 50, 32);
        cin >> choixAttaque;

        AnimationTexte("Tu a touche l'ennemie avec " + spell.listAttack[choixAttaque - 1].labelSpell + "\n", 50, 34);

        if (!game.getFin()) enemie.EnemieDegat(spell.listAttack[choixAttaque - 1].valeurSpell);
        else if (game.getFin()) boss.BossDegat(spell.listAttack[choixAttaque - 1].valeurSpell);
        if (!game.getFin()) cout << "Pv Enemie: " << enemie.getPv() << endl;
        else if (game.getFin()) cout << "Pv Garp: " << boss.getPv() << endl;

    }
    else if (choixUtilisateur == 2)
    {
        AnimationTexte("Soins Disponible :\t1 - Alcool\t2 - Viande\n", 50, 32);
        cin >> choixSoins;
        AnimationTexte("Tu viens de te soigner avec " + spell.listAttack[choixSoins + 2].labelSpell + ", tu gagnes +" + to_string(spell.listAttack[choixSoins + 2].valeurSpell) + "pv\n", 50, 34);
        JoueurSoins(spell.listAttack[choixSoins + 2].valeurSpell);
        cout << "Pv Joueur: " << *ptPv << endl;
    };
};

Joueur::~Joueur()
{
    delete ptPv;
};