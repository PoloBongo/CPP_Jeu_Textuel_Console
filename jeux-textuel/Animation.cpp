#include "import.h";
#include "include.h";

using namespace std;

void AnimationTexte(const string& texte, int delai, int couleur) {
    for (char c : texte) {
        cout << "\033[1;" << couleur << "m" << c << "\033[0m";
        this_thread::sleep_for(chrono::milliseconds(delai));
    }
}