// -----------------------------------------------------------------------------------------------
// Fichier        : calendrier.cpp
// Auteur(s)      : OLIVEIRA Vitória & PHILIBERT Alexandre
// Date           : 2022-11-01
// But            : Fonctions responsables des calculs des caractéristiques du
// 					  de chaque mois de l'année saisie, ainsi que l'affichage du
// 					  calendrier de l'année en question.
// Modifications  : NIL
// Remarque(s)    : La constante LARGEUR_CELLULE a été déterminée selon l'affiche
//                  imposé.
//                  Plusieurs fonctions ont été reprises ou inspirées des
//                  démonstrations de M. Guy-Michel BREGUET.
//						  La librairie "ctime" est utilisée afin de déterminer le jour
//                  de la semaine du 1er jour de chaque mois de l'année choisie.
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#include <iostream>      // cin et cout
#include <iomanip>       // setw
#include <ctime>         // mktime et time
#include <string>
#include <vector>
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
 *  Calcule l'index [0-6] dans la semaine d'une date donnée ( 0 = Lundi, 6 = Dimanche ).
 *  Le mois est compris entre [0 - 11].
 *
 *  Repris de : https://cplusplus.com/reference/ctime/mktime/
 *
 *  Le type de time_t n'est pas garanti dans la spécification C, il est possible
 *  que selon l'implémentation il ne soit pas possible de représenter les dates avant le 1er janvier 1970.
 *  Dans ce cas la valeur 6 (Dimanche) est retournée
 *
 *  Plus d'informations :
 *  - https://stackoverflow.com/a/471287
 *  - https://en.cppreference.com/w/c/chrono/time_t
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

   // Transforme la représentation du jour de la semaine de timeinfo (0 = Dimanche, 6 = Samedi)
   // au format 0 = Lundi, 6 = Dimanche.
   return timeinfo->tm_wday == 0 ? 6 : timeinfo->tm_wday - 1;
}

/**
 *  Retourne le nombre de jour d'un mois donné en tenant compte des années
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
 * Mois est compris entre 0 et 11.
 *
 * Repris de la démo : https://github.com/gmbreguet/PRG1_DEMO/blob/40f1ef41f8f2ee1d8c1a1c7fc1cc562b88e620c8/04_Fonctions/04_nbreJoursMois.cpp#L100
 */
string nomMois(int mois) {
   static const vector<string> MOIS = { "Janvier", "Fevrier", "Mars",      "Avril",
													 "Mai",      "Juin", "Juillet", "Aout",
													 "Septembre", "Octobre", "Novembre",
													 "Decembre" };

   // volontairement un .at pour lever une exception
   return MOIS.at(size_t(mois));
}

/**
 *  Retourne le nom d'un jour en fonction de sa position ( entre [0-6] ).
 */
string nomJour(int jour) {
   static const vector<string> JOURS = { "L", "M", "M", "J", "V", "S", "D" };

   // volontairement un .at pour lever une exception
   return JOURS.at(size_t(jour));
}

/**
 *  Affiche un mois selon le mois et l'année passé en paramètre.
 *
 *  Un mois est représenté par une entête indiquant les jours de la semaine , suivi
 *  d'une grille de cellules représentant les jours du mois actuel,
 *  ainsi que précédant et suivant si nécessaire selon la position du premier et
 *  dernier jour du mois.
 */
void afficherMois(int mois, int annee) {
   int indexPremierJourMois,
       nombreCellulesTotal;

   // Les cellules sont numérotées de 0 - nombreCellulesTotal, alors que
   // l'index du premier jour commence à 0, il est nécessaire d'ajouter 1.
   indexPremierJourMois = indexJourSemaine(1, mois, annee) + 1;

   // Le nombre de cellules total à afficher, en prenant en compte les cellules
   // vides au début de chaque mois.
   nombreCellulesTotal = nombreJoursMois(mois, annee) + indexPremierJourMois;

   // Affichage de l'entête
   cout << nomMois(mois) << " " << annee  << " " << endl;
   for (int jour = 0; jour < 7; ++jour) {
      cout << setw(LARGEUR_CELLULE) << nomJour(jour) << " ";
   }
   cout << endl;

   // Affichage de la grille de cellules
   for (int cellule = 1; cellule < nombreCellulesTotal; ++cellule) {
      if (cellule < indexPremierJourMois) {
         cout << string(LARGEUR_CELLULE + 1, ' ');
      } else {
         cout << setw(LARGEUR_CELLULE) << cellule - indexPremierJourMois + 1
			<< " ";
      }

      // Recommencer une nouvelle ligne lorsque la cellule actuelle = dimanche,
      // et que la cellule n'est pas la dernière du mois.
      // Dans le cas contraire, deux retours à la ligne sont effectués.
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
