#ifndef LABO_CALENDRIER_SAISIE_H
#define LABO_CALENDRIER_SAISIE_H

/**
 *  Affiche un message, et valide si la saisie utilisateur est comprise entre
 *  min et max, affiche un message d'erreur si ce n'est pas le cas.
 *  Retourne la valeur saisie par l'utilisateur si la saisie est correcte.
 */
int saisie(const std::string& msgInvite,
           const std::string& msgErreur,
           int min,
           int max);

bool saisie(const std::string& msgInvite,
            const std::string& msgErreur,
            char charVrai,
            char charFaux);

#endif //LABO_CALENDRIER_SAISIE_H
