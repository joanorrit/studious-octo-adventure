/** @file Agenda.hpp
    @brief Classe Agenda
    */

#ifndef AGENDA_HPP
#define AGENDA_HPP

#include "utils.PRO2"
#include "Cites.hpp"
#include <vector>

/** @class Agenda
    @brief 
*/

class Agenda {

private: 
  
  struct Cal{
    int id_cita;
    int nivell;
  };
  
  //Cal calendari = {1,1};
  
  typedef vector <vector<Cal> > Dia;
  //int id_cita;
  int D;
  int H;
  int N;
  int dia_actual;
  int mida_agenda;
  vector<Dia> agenda; //Columnes funcionaris, files dies.
  //queue<Cita> cites_passades;
  
public:
  
   /** @brief Constructora per defecte.
       \pre Cert.
       \post El resultat és un conjunt agenda buit, que podrà contenir el conjunt de totes les cites.
   */ 
  Agenda();
  

  /** @brief Consultora
       \pre Existeix un paràmetre D>0.
       \post El resultat és el paràmetre D actual.
   */ 
  int get_D();
  
   /** @brief Constructora
       \pre Cert.
       \post El resultat és el paràmetre D>0.
   */ 
   void set_D();
   
   /** @brief
       \pre 
       \post 
   */
  int get_H();
 
  /** @brief
       \pre 
       \post 
   */
   void set_H();
   
   /** @brief
       \pre 
       \post 
   */ 
  void set_N();
  
  /** @brief
       \pre 
       \post 
   */ 
  int get_N();
  
  /** @brief
       \pre 
       \post 
   */
  void set_dia_actual();
  
  /** @brief
       \pre 
       \post 
   */
  int get_dia_actual();
  
  /** @brief
       \pre 
       \post 
   */
  int get_nivell(int dia, int funcionari, int hora);
  
  /** @brief
       \pre 
       \post 
   */
  void actualizar_dia_actual(int dia_nou, Cites &cit);
  
  /** @brief Constructora. 
       \pre tipus = 1 ó tipus = 2, enter_1 > 0, enter_2 > 0.
       \post El resultat és una cita tenint en compte el tipus de petició.
   */
  void peticion_cita(int tipus, int enter_1, int enter_2);
  
  /** @brief
       \pre 
       \post 
   */
  void afegir_id_cita(int id_cita, int dia, int funcionari, int hora);
  
  /** @brief
       \pre 
       \post 
   */
  bool esta_lliure(int funcionari, int dia, int hora);
  
  /** @brief Constructora
       \pre tipus = 1 ó tipus = 2, enter_1 > 0, enter_2 > 0.
       \post És deixa lliure les cites que tingui el funcionari tenint en compte 
   */ 
  void peticion_vacaciones(int interval_1, int interval_2, int funcionari);
  
  /** @brief Cosultora
       \pre K < dia_registro < D.
       \post El resultat són les cites realitzades en els K dies anteriors. 
   */ 
  void consultar_citas_realizadas(int dia_registro);
  
  /** @brief Cosnsultora.
       \pre K < dia_registro < D 
       \post El resultat són totes les cites que flaten per realitzar en els propers D dies.
   */ 
  
  int get_id_cita(int dia, int funcionari, int hora);
 
  void consultar_citas_vivas();
  
  /** @brief
       \pre 
       \post 
   */
  void afegir_nivell(int nivel, int hora, int funcionari, int dia);
  
  /** @brief
       \pre 
       \post 
   */
  void anular_una_hora(int funcionari, int dia, int hora);
  
  /** @brief
       \pre 
       \post 
   */
  void dimensionar_agenda();
  
  /** @brief
       \pre 
       \post 
   */
  void size_agenda(int D, int H, int N);
  
  
};
#endif