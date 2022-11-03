// -----------------------------------------------------------------------------------------------
// Fichier        : Labo_04_K.cpp
// Auteur(s)      : Cosmo De Oliveira Maria Vitória & PHILIBERT Alexandre
// Date           : 2022-11-01
// But            : Affiche le calendrier complet pour une année [1800 - 2100].
// Modifications  : NIL
// Remarque(s)    : Le calendrier est imprimé selon le format demandé dans la
// 					  consigne et prend en compte les années bissextiles. La saisie
// 					  utilisateur est contrôlée et doit être comprise dans l'intervalle
// 					  [1800 - 2100]. Une fois le calendrier affiché, l'application
// 					  demande à l'utilisateur de quitter ou recommencer l'opération.
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
   const string MSG_ERREUR_CHOIX = "Choix non valide";
   const char RECOMMENCER_VRAI = 'O',
              RECOMMENCER_FAUX = 'N';

   const int    ANNEE_MIN  = 1800,
                ANNEE_MAX  = 2100;
   int          annee;
   bool         recommencer;

   do {
      annee = saisie("Veuillez saisir l'annee a afficher : ",
							MSG_ERREUR, ANNEE_MIN, ANNEE_MAX);

      afficherCalendrier(annee);

      recommencer = saisie("Voulez-vous recommencer",
									MSG_ERREUR_CHOIX, RECOMMENCER_VRAI,
									RECOMMENCER_FAUX);
   } while (recommencer);

   cout << "Pressez ENTER pour quitter";
   cin.ignore(numeric_limits<streamsize>::max(), '\n');

   return EXIT_SUCCESS;
}

