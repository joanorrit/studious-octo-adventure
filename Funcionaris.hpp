/** @file Funcionaris.hpp
    @brief Classe Funcionaris
    */

#ifndef FUNCIONARIS_HPP
#define FUNCIONARIS_HPP

#include "Arbre.hpp"
#include <list>
#include <stack>
#include "Agenda.hpp"

/** @class Funcionaris
    @brief Conte la informació del conjunt administratiu de funcionaris.
*/

class Funcionaris {

private: 
  
  int id_cita;
  Arbre<int> administracio;
  
public:
  
   /** @brief Constructora per defecte.
       \pre Cert.
       \post El resultat és un conjunt de funcionaris buits.
   */ 
   Funcionaris();
   
    /** @brief Destructora per defecte.
       \pre Cert.
       \post S'elimina el conjunt de funcionaris.
   */ 
   ~Funcionaris();
  
  /** @brief Lectura.
       \pre Existeix un enter N que defineix el nombre de funcionaris.
       \post El resultat es l'arbre geràrquic del conjunt de funcionaris.
   */ 
  void leer_funcionarios_preorden(Arbre<int> &a);
  
  /** @brief
       \pre 
       \post 
   */ 
  void llegir_funcionaris();
  
  void escriure_arbre_int(Arbre<int> &a);

  /** @brief
       \pre 
       \post 
   */
  void peticion_cita(Agenda &agenda, int tipus, int enter_1, int enter_2); 
  
  /** @brief
       \pre 
       \post 
   */
  void pedir_cita_dia(Arbre<int> a, Agenda &agenda, int dia, int hora, int &altura, int &funcionari);
  
  /** @brief
       \pre 
       \post 
   */
  void pedir_cita_nivel(Arbre<int> a, Agenda &agenda, int hora, int nivel, int dia, int &altura, int &funcionari);
  
  /** @brief
       \pre 
       \post 
   */
  void anular_hora(Agenda &agenda, int enter_1, int enter_2, int funcionari);
  
  /** @brief
       \pre 
       \post 
   */
  Arbre<int> trobar_subarbre(Arbre<int> a, Agenda &agenda, int dia, int hora, int funcionari, bool &trobat);
  
  /** @brief
       \pre 
       \post 
   */
  stack<int> trobar_cami(Agenda &agenda, Arbre<int> a, int dia, int hora, bool &trobat, int &long_min);
  
};
#endif
