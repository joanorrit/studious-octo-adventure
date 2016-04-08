/** @file Cites.hpp
    @brief Classe Cites
    */

#ifndef CITES_HPP
#define CITES_HPP

#include "utils.PRO2"
#include <queue>

/** @class Cites
    @brief 
*/

class Cites {

private: 
  
  struct Cita{
  int id_cita;
  int hora;
  int dia;
  int funcionari;
  };
  int K;
  int maxima_grandaria_cua;
  queue<Cita> cites_passades;

public:
  
   /** @brief Constructora per defecte.
       \pre Cert
       \post El resultat és una cita buida.
   */ 
   Cites();
   
    /** @brief Destructora per defecte.
       \pre Cert.
       \post S'elimina la cita.
   */ 
   ~Cites();
   
   /** @brief Consultora.
       \pre Existeix un paràmetre K>0.
       \post El resultat és el paràmetre K actual.
   */ 
  int get_K();
  
  /** @brief Constructora.
       \pre Cert.
       \post El resultat és el paràmetre K>0.
   */ 
   void set_K();
  
  /** @brief Escriptura.
       \pre La cita no es buida.
       \post S'escriu la cita passada com a paràmetre implícit per panatalla.
   */ 
  void escribir_citas_realizadas(int dia_registro);
  
  /** @brief Lectura.
       \pre Cert.
       \post Es llegeix una cita per pantalla.
   */ 
  void leer_cita();
  
  /** @brief Constructora
       \pre Cert.
       \post El resultat és una cita amb el seu identificador, el dia de registre, la hora i el numero del funcionari que l'ha fet.
   */ 
  void afegir_cita(int id_cita, int hora, int dia, int funcionari);
  
  void set_grandaria_cua(int K, int N, int H);
};
#endif