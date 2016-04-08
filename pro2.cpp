#include "utils.PRO2"
#include "Funcionaris.hpp"
#include "Agenda.hpp"

int main(){
  
  Agenda agenda;
  agenda.set_N();
  agenda.set_D();
  
  Cites cit;
  cit.set_K();
  agenda.set_H();
  Funcionaris func;
  func.llegir_funcionaris();
  
  agenda.dimensionar_agenda();
  cit.set_grandaria_cua(cit.get_K(), agenda.get_N(), agenda.get_H());
  
  int op = readint();
  int dia_registro; 
  
  while (op != -5){
    if (op == -1){
      dia_registro = readint();
      if (dia_registro > agenda.get_dia_actual()) agenda.actualizar_dia_actual(dia_registro, cit);
      int tipus = readint();
      int enter_1 = readint();
      int enter_2 = readint();
      func.peticion_cita(agenda, tipus, enter_1, enter_2);
    }
    else if (op == -2){
      dia_registro = readint();
      if (dia_registro > agenda.get_dia_actual()) agenda.actualizar_dia_actual(dia_registro, cit);
      int tipus = readint();
      int funcionari = readint();
      int enter_1 = readint();
      int enter_2 = readint();
      if (tipus == 1)
	agenda.peticion_vacaciones(enter_1, enter_2,funcionari);
      if (tipus == 2)
	func.anular_hora(agenda, enter_1, enter_2, funcionari);
    }
    else if(op == -3){
      dia_registro = readint();
      if (dia_registro > agenda.get_dia_actual()) agenda.actualizar_dia_actual(dia_registro, cit);
      cit.escribir_citas_realizadas(dia_registro);
    }
    else if (op == -4){
      dia_registro = readint();
      if (dia_registro > agenda.get_dia_actual()) agenda.actualizar_dia_actual(dia_registro, cit);
      agenda.consultar_citas_vivas();
    }
    op = readint();
  }
}

      
      
  