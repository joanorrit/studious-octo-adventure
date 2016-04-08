#include "Cites.hpp"


Cites::Cites(){

}

Cites::~Cites(){

}

int Cites::get_K(){
  return K;
}

void Cites::set_K(){
  K = readint();
}

void Cites::set_grandaria_cua(int K, int N, int H){
  maxima_grandaria_cua = K*N*H;
}

void Cites::escribir_citas_realizadas(int dia_registro){
  int interval_1, interval_2;
  bool llegits = false;
  if (K < dia_registro){
    interval_1 = dia_registro - K;
    interval_2 = dia_registro - 1;
  }
  else {
    interval_1 = 1;
    interval_2 = dia_registro - 1;
  }
  queue<Cita> q = cites_passades;
  cout << "Citas ya realizadas: el intervalo relevante de dias es el " << interval_1 << " " << interval_2 << endl;
  
  while ((not llegits) and (not q.empty())){
    if (interval_1 <= q.front().dia <= interval_2){
      if (q.front().id_cita > 0) 
	cout << q.front().dia << " " << q.front().funcionari << " " << q.front().hora << " " << q.front().id_cita << endl;
    }
    else if (q.front().dia > interval_2) llegits = true;
    q.pop();
  }
  cout << endl;
}

void Cites::leer_cita(){

}

void Cites::afegir_cita(int id_cita, int hora, int dia, int funcionari){
  Cita cita;
  cita.id_cita = id_cita;
  cita.hora = hora;
  cita.dia = dia;
  cita.funcionari = funcionari;
  cites_passades.push(cita);
  int i = 0;
  while (cites_passades.size() > maxima_grandaria_cua){
    cites_passades.pop();
    i++;
  }
  cita = cites_passades.front();
}

