#include "Agenda.hpp"

Agenda::Agenda(){
  dia_actual = -1;
}


int Agenda::get_D(){
  return D;
}

void Agenda::set_D(){
  D = readint();
}

int Agenda::get_H(){
  return H;
}

void Agenda::set_H(){
  H = readint();
}

void Agenda::set_N(){
  N = readint();
}

int Agenda::get_N(){
  return N;
}

void Agenda::set_dia_actual(){
  dia_actual = readint();
}

int Agenda::get_dia_actual(){
  return dia_actual;
}

int Agenda::get_nivell(int dia, int funcionari, int hora){
  int posicio = dia % mida_agenda;
  return agenda[posicio][funcionari][hora].nivell;
}

int Agenda::get_id_cita(int dia, int funcionari, int hora){
  int posicio = dia % mida_agenda;
  return agenda[posicio][funcionari][hora].id_cita;
}

void Agenda::afegir_id_cita(int id_cita_nou, int dia, int funcionari, int hora){
  int posicio;
  posicio = dia % mida_agenda;
  agenda[posicio][funcionari][hora].id_cita = id_cita_nou;
}

void Agenda::actualizar_dia_actual(int dia_nou, Cites &cit){
  if (dia_actual == -1) dia_actual = dia_nou;
  
  else {
    int i = dia_actual;
    int j;
    int k;
    int posicio;
    Cal cal;
    cal.id_cita = 0;
    cal.nivell = -1;
    Dia dia(N+1,vector<Cal>(H+1,cal));
    
    while (i < dia_nou){
      posicio = i % mida_agenda;
      j = 1;
      while (j <= N){
	k = 1;
	while (k <= H){
	  cit.afegir_cita(agenda[posicio][j][k].id_cita, k, i, j); 
	  k++;
	}
	j++;
      }
      agenda[posicio] = dia;
      i++;
    }
    
    dia_actual = dia_nou;
  }
}

bool Agenda::esta_lliure(int funcionari, int dia, int hora){
  int posicio;
  posicio = dia % mida_agenda;
  return (agenda[posicio][funcionari][hora].id_cita == 0);
}

void Agenda::peticion_cita(int tipus, int enter_1, int enter_2){
}

void Agenda::anular_una_hora(int funcionari, int dia, int hora){
  int posicio = dia % mida_agenda;
  agenda[posicio][funcionari][hora].id_cita = -1;
}

void Agenda::afegir_nivell(int nivel, int hora, int funcionari, int dia){
  int posicio = dia % mida_agenda;
  agenda[posicio][funcionari][hora].nivell = nivel;
}

void Agenda::peticion_vacaciones(int interval_1, int interval_2, int funcionari){
  if (interval_1 <= (dia_actual + D)){
    if (interval_2 > (dia_actual + D)) interval_2 = dia_actual + D;
    int i, j, posicio;
    i = interval_1;
    
    while (i <= interval_2){
      posicio = i % mida_agenda;
      j = 1;
      while (j <= H){
	agenda[posicio][funcionari][j].id_cita = -1;
	j++;
      }
      i++;
    }
  }
}

void Agenda::consultar_citas_vivas(){
  int interval_1, interval_2;
  interval_1 = dia_actual + 1;
  interval_2 = dia_actual + D;
  int j, k;
  int posicio;
  int i = interval_1;
  Dia dia(N+1,vector<Cal>(H+1));
  
  cout << "Citas vivas: el intervalo relevante de dias es el " << interval_1 << " " << interval_2 << endl;
  
  while (i <= interval_2){
    posicio = i % mida_agenda;
    j = 1;
    while (j <= N){
      k = 1;
      while (k <= H){
	if (agenda[posicio][j][k].id_cita > 0)
	 cout << i << " " << j << " " << k << " " << agenda[posicio][j][k].id_cita << endl;
	k++;
      }
      j++;
    }
    i++;
  }
  cout << endl;
}

void Agenda::dimensionar_agenda(){
  size_agenda(D, H, N);
}

void Agenda::size_agenda(int D, int H , int N){
  Cal calendari = {0,-1};
  int i = 0;
  agenda = vector<Dia> (D+1);
  Dia dia(N+1, vector<Cal>(H+1, calendari));
  while (i < agenda.size()){
    agenda[i] = dia;
    i++;
  }
  mida_agenda = agenda.size();
}
