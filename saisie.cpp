// -----------------------------------------------------------------------------------------------
// Fichier        : saisie.cpp
// Auteur(s)      : OLIVEIRA Vitória & PHILIBERT Alexandre
// Date           : 2022-11-01
// But            : Fonctions responsables de toute la saisie utilisateur, gestion
// 					  du flux, répétition ou fin du programme.
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <limits>
#include "saisie.h"

using namespace std;

int saisie(const string& msgInvite,
           const string& msgErreur,
           const int min,
           const int max
           ) {
   int  saisie;
   bool erreur;

   do {
      // saisie et vérification
      cout << msgInvite << " [" << min << " - " << max << "] : ";
      erreur = not(cin >> saisie) or saisie < min or saisie > max;

      // gestion du flux
      if (erreur) {
         cout << msgErreur << endl;
         cin.clear();
      }

      // vider buffer
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
   } while(erreur);

   return saisie;
}

bool saisie(const string& msgInvite,
            const string& msgErreur,
            const char charVrai,
            const char charFaux
) {
   char  saisie;
   bool erreur;

   do {
      // saisie et vérification
      cout << msgInvite << " [" << charVrai << "/" << charFaux << "] : ";
      erreur = not(cin >> saisie) or (saisie != charVrai and saisie != charFaux);

      // gestion du flux
      if (erreur) {
         cout << msgErreur << endl;
         cin.clear();
      }

      // vider buffer
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
   } while(erreur);

   return saisie == charVrai;
}
