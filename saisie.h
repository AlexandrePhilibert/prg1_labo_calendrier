#ifndef LABO_CALENDRIER_SAISIE_H
#define LABO_CALENDRIER_SAISIE_H

/**
 *  Affiche un message, et valide si la saisie utilisateur est comprise entre
 *  min et max, affiche un message d'erreur si ce n'est pas le cas.
 *  Retourne la valeur saisie par l'utilisateur si la saisie est correcte.
 *
 *  Repris de la démo : https://github.com/gmbreguet/PRG1_DEMO/blob/40f1ef41f8f2ee1d8c1a1c7fc1cc562b88e620c8/04_Fonctions/04_nbreJoursMois.cpp#L45
 */
int saisie(const std::string& msgInvite,
           const std::string& msgErreur,
           int min,
           int max);

/**
 * Affiche un message, et valide si la saisie utilisateur correspond au caractère
 * charVrai ou charFaux, affiche un message d'erreur si ce n'est pas le cas.
 * Retourne vrai si le caractère est égal à charVrai, sinon retourne faux.
 *
 * Repris de la démo : https://github.com/gmbreguet/PRG1_DEMO/blob/40f1ef41f8f2ee1d8c1a1c7fc1cc562b88e620c8/04_Fonctions/04_nbreJoursMois.cpp#L45
 */
bool saisie(const std::string& msgInvite,
            const std::string& msgErreur,
            char charVrai,
            char charFaux);

#endif //LABO_CALENDRIER_SAISIE_H
