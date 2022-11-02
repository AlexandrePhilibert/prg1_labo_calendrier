// -----------------------------------------------------------------------------------------------
// Fichier        : Labo_04_K.cpp
// Auteur(s)      : Cosmo De Oliveira Maria Vitória & PHILIBERT Alexandre
// Date           : 2022-11-01
// But            : Affiche le calendrier complet pour une année [1800 - 2100] en tenant compte
//                  des années bissextiles.
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#include <iostream> // cin et cout
#include <cstdlib>  // EXIT_SUCCESS
#include <limits>   // numeric_limits<streamsize>
#include "saisie.h"
#include "calendrier.h"

using namespace std;

int main() {
   const string MSG_ERREUR = "/!\\ erreur de saisie ...";
   const int    ANNEE_MIN  = 1800,
                ANNEE_MAX  = 2100;
   int          annee;
   bool         recommencer;

   do {
      annee = saisie("Veuillez saisir l'annee a afficher : ", MSG_ERREUR, ANNEE_MIN, ANNEE_MAX);

      afficherCalendrier(annee);

      char choix;
      cout << "Voulez-vous recommencer [O/N] : ";
      // TODO: Gérer les erreurs
      cin >> choix;
      recommencer = choix == 'O';
   } while (recommencer);

   cout << "Pressez ENTER pour quitter";
   cin.ignore(numeric_limits<streamsize>::max(), '\n');

   return EXIT_SUCCESS;
}

