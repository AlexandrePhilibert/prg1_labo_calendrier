#include <iostream>
#include <string>
#include <vector>
#include "calendrier.h"

using namespace std;

bool estBissextile(const int annee) {
   return (annee % 400 == 0) || (annee % 4 == 0) && (annee % 100 != 0);
}

// Repris de la démo : https://github.com/gmbreguet/PRG1_DEMO/blob/40f1ef41f8f2ee1d8c1a1c7fc1cc562b88e620c8/04_Fonctions/04_nbreJoursMois.cpp#L100
// Mois est compris entre 0 et 12
string nomMois(const int mois) {
   static const vector<string> MOIS = { "Janvier", "Fevrier", "Mars",      "Avril",   "Mai",      "Juin",
                                        "Juillet", "Aout",    "Septembre", "Octobre", "Novembre", "Decembre" };

   // volontairement un .at pour lever une exception
   return MOIS.at(size_t(mois));
}

void afficherMois(const int mois, const int annee) {
   cout << nomMois(mois) << " " << annee << endl;
   cout << "L M M J V S D" << endl;
}

void afficherCalendrier(const int annee) {
   for (int mois = 0; mois < 12; ++mois) {
      afficherMois(mois, annee);
   }
}