#include "import.h";
#include "include.h";

Game::Game() {
    choix_utilisateur = 0;
    finCombat = false;
}
void Game::introGame() {
    AnimationTexte("Suite au discours de Gol D.Roger, une folle envie te dit d'aller monter ton equipage et de trouver le One Piece.\nEn passant devant la maison de ta mamie une musique mystique chante.\n'C'est pas l'homme qui prend la mer, c'est la mer qui prend l'homme'\nEn te baladant tu tombes sur un membre de la marine.\n", 50, 34);
    AnimationTexte("Triple Coucou\n", 50, 37);
    AnimationTexte("Petit tu fait quoi la!\n", 50, 31);
    AnimationTexte("Bah je me promene en direction du port pour me prendre mon navire et devenir le Roi des Pirates!\n", 50, 37);
    AnimationTexte("Je vais devoir arreter ton reve mon petit.\n", 50, 31);
}

void Game::combatContreMarin() {
    Joueur joueur;
    Enemie enemie;
    Boss boss;

    while (!finCombat) {

        joueur.statusCombatJoueur(enemie, boss);
        if (enemie.getPv() == 0 || enemie.getPv() < 0) {
            AnimationTexte("Tu as battu le sbire de la marine\n", 50, 34);
            break;
        }
        enemie.statusCombatEnemie(joueur);
        if (joueur.getPv() == 0 || joueur.getPv() < 0) {
            AnimationTexte("Tu as perdu, recommence\n", 50, 34);
            start();
            break;
        }
    }

}

void Game::dialogBoss() 
{
    AnimationTexte("\nApres avoir fini de battre tous les sbires de la marine,\nTu tombes sur une personne plutot cocasse\n\n", 50, 34);
    AnimationTexte("C'est donc toi la petite racaille qui a battu tout mes moussaillons.\n", 50, 31);
    AnimationTexte("Bah oui logique.\n", 50, 37);
    AnimationTexte("Tu vas devoir payer pour tout tes crimes.\n", 50, 31);
    AnimationTexte("Je t'attends le fameux Hero de la marine.\n", 50, 37);
};

void Game::combatContreBoss() {
    Joueur joueur;
    Enemie enemie;
    Boss boss;

    finCombat = true;
    while (finCombat) {

        joueur.statusCombatJoueur(enemie, boss);
        if (boss.getPv() == 0 || boss.getPv() < 0) {
            AnimationTexte("Tu as battu Garp", 50, 34);
            break;
        }
        boss.statusCombatBoss(joueur);
        if (joueur.getPv() == 0 || joueur.getPv() < 0) {
            AnimationTexte("Tu as perdu, recommence\n", 50, 34);
            start();
            break;
        }
    }

}

void Game::dialogFin() {
    AnimationTexte("C'est donc ca le Hero de la marine,\nla marine n'est plus que l'ombre d'elle meme.\nJe te prends ton bateau j'en ai besoin pour quitter cette ile,\nde toute facon tu n'as pas ton mot a dire, les faibles n'ont pas le droit a la parole.\n", 50, 37);
    AnimationTexte("Je.. je trouve que tu... est bien impertinant\nIl y a des personnes... bien plus fortes que moi.\nMon bateau, prends le... mais on se retrouvera.\n", 50, 31);
    AnimationTexte("To Be Continued", 50, 34);
}

void Game::start() {
    AnimationTexte("\t\t\t\t\t\t\tOne Piece\n(1) Jouer\n(2) Quitter\n", 50, 34);
    cin >> choix_utilisateur;
    if (choix_utilisateur == 1) {
        introGame();
        combatContreMarin();
        dialogBoss();
        combatContreBoss();
        dialogFin();
    }
    else if (choix_utilisateur == 0) {
        exit(0);
    }
}

bool Game::getFin() {
    return finCombat;
}