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
