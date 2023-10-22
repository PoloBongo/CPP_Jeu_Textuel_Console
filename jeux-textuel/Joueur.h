#pragma once
class Enemie;
class Boss;
class Joueur 
{
private:
    int pv;

    int* ptPv;

    int choixAttaque;
    int choixSoins;
    int choixUtilisateur;

public:
    

    Joueur();

    void JoueurDegat(int attack);
    void JoueurSoins(int soins);
    int getPv();
    void statusCombatJoueur(Enemie& enemie, Boss& boss);

    ~Joueur();
};
