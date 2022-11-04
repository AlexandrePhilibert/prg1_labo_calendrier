// -----------------------------------------------------------------------------------------------
// Fichier        : calendrier.cpp
// Auteur(s)      : OLIVEIRA Vitória & PHILIBERT Alexandre
// Date           : 2022-11-01
// But            :
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <ctime>
#include "calendrier.h"

using namespace std;

const int LARGEUR_CELLULE = 2;

/**
 *  Une année est bissextile si elle est divisible par 400,
 *  ou par 4 et pas pas 100.
 */
bool estBissextile(int annee) {
   return (annee % 400 == 0) || ((annee % 4 == 0) && (annee % 100 != 0));
}

/**
 *  Calcule l'index [0-6] d'une date donnée, 0 = Lundi, 6 = Dimanche
 *  Le mois est compris entre [0 - 11]
 *
 *  Repris de : https://cplusplus.com/reference/ctime/mktime/
 */
int indexJourSemaine(int jour, int mois, int annee) {
   time_t rawtime;
   struct tm* timeinfo;

   time(&rawtime);
   timeinfo = localtime(&rawtime);
   timeinfo->tm_year = annee - 1900;
   timeinfo->tm_mon = mois;
   timeinfo->tm_mday = jour;

   mktime(timeinfo);

   return timeinfo->tm_wday;
}

/**
 *  Retourne le nombre de jour d'un mois donné, prends en considération les années
 *  bissextiles.
 *  Le mois doit être compris entre [0, 11], sinon -1 est retourné.
 *
 *  Repris de la démo : https://github.com/gmbreguet/PRG1_DEMO/blob/40f1ef41f8f2ee1d8c1a1c7fc1cc562b88e620c8/04_Fonctions/04_nbreJoursMois.cpp#L79
 */
int nombreJoursMois(int mois, int annee) {
   switch (mois) {
      case 1: return 28 + estBissextile(annee);
      case 3:
      case 5:
      case 8:
      case 10: return 30;
      case 0:
      case 2:
      case 4:
      case 6:
      case 7:
      case 9:
      case 11: return 31;
      default: return -1;   // cas d'erreur
   }
}


/**
 * Mois est compris entre 0 et 11
 *
 * Repris de la démo : https://github.com/gmbreguet/PRG1_DEMO/blob/40f1ef41f8f2ee1d8c1a1c7fc1cc562b88e620c8/04_Fonctions/04_nbreJoursMois.cpp#L100
 */
string nomMois(int mois) {
   static const vector<string> MOIS = { "Janvier", "Fevrier", "Mars",      "Avril",   "Mai",      "Juin",
                                        "Juillet", "Aout",    "Septembre", "Octobre", "Novembre", "Decembre" };

   // volontairement un .at pour lever une exception
   return MOIS.at(size_t(mois));
}

/**
 *  Retourne le nom d'un jour en fonction de sa position, entre [0-6]
 */
string nomJour(int jour) {
   static const vector<string> JOURS = { "L", "M", "M", "J", "V", "S", "D" };

   // volontairement un .at pour lever une exception
   return JOURS.at(size_t(jour));
}

/**
 *  Affiche un mois selon le mois et l'année passé en paramètre.
 *
 *  Un mois est représenté par une entête, suivi d'une grille de cellules
 *  représentant les jours du mois actuel,
 *  ainsi que précédant et suivant si nécessaire selon la position du premier et
 *  dernier jour du mois.
 */
void afficherMois(int mois, int annee) {
   int indexPremierJourMois,
       nombreCellulesTotal;

   indexPremierJourMois = indexJourSemaine(1, mois, annee);
   // Le nombre de cellules total à afficher, en prenant en compte les cellules vides au début de chaque mois.
   nombreCellulesTotal = nombreJoursMois(mois, annee) + indexPremierJourMois;

   // Affichage de l'entête
   cout << nomMois(mois) << " " << annee  << " " << endl;
   for (int jour = 0; jour < 7; ++jour) {
      cout << setw(LARGEUR_CELLULE) << nomJour(jour) << " ";
   }
   cout << endl;

   // affichage de la grille de cellule
   for (int cellule = 1; cellule < nombreCellulesTotal; ++cellule) {
      if (cellule < indexPremierJourMois) {
         cout << string(LARGEUR_CELLULE + 1, ' ');
      } else {
         cout << setw(LARGEUR_CELLULE) << cellule - indexPremierJourMois + 1 << " ";
      }

      // Recommencer une nouvelle ligne lorsque la cellule actuelle = dimanche,
      // et que la cellule n'est pas la dernière du mois, sinon deux retours à la ligne sont effectués.
      if (cellule % 7 == 0 && cellule < nombreCellulesTotal - 1) {
         cout << endl;
      }
   }
}

void afficherCalendrier(int annee) {
   for (int mois = 0; mois < 12; ++mois) {
      afficherMois(mois, annee);

      // Sépare chaque mois d'une ligne vide
      cout << endl << endl;
   }
}
