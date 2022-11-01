// -----------------------------------------------------------------------------------------------
// Fichier        : Labo_04_K.cpp
// Auteur(s)      : Cosmo De Oliveira Maria Vitória & PHILIBERT Alexandre
// Date           : 2022-11-01
// But            :
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#include <iostream> // cin et cout
#include <cstdlib>  // EXIT_SUCCESS
#include <limits>   // numeric_limits<streamsize>

using namespace std;

int main() {
   std::cout << "Hello, World!" << std::endl;

   cout << "Pressez ENTER pour quitter";
   cin.ignore(numeric_limits<streamsize>::max(), '\n');

   return EXIT_SUCCESS;
}
