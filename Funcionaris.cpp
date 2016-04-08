#include "Funcionaris.hpp"

Funcionaris::Funcionaris(){
  id_cita = 1;
}

Funcionaris::~Funcionaris(){

}

void Funcionaris::leer_funcionarios_preorden(Arbre<int> &a){
  int x = readint();
  
  if (x != 0) {
    Arbre<int> a1 = Arbre<int>();
    Arbre<int> a2 = Arbre<int>();
    leer_funcionarios_preorden(a1);
    leer_funcionarios_preorden(a2); 
    a.plantar(x,a1,a2);
  }
  else{
    a.a_buit();
  }
}

void Funcionaris::llegir_funcionaris(){
  leer_funcionarios_preorden(administracio);
}

void Funcionaris::peticion_cita(Agenda &agenda, int tipus, int enter_1, int enter_2){
 int dia_maxim;
 
  if (tipus == 1){
    bool assignat = false;
    int funcionari = 0;
    int altura = 0;
    dia_maxim = agenda.get_dia_actual() + agenda.get_D();
    
    while ((not assignat) and (enter_1 <= dia_maxim)){
      pedir_cita_dia(administracio, agenda, enter_1, enter_2, altura, funcionari);
      if (funcionari > 0){
	agenda.afegir_id_cita(id_cita, enter_1, funcionari, enter_2);
	assignat = true;
      }
      ++enter_1;
    }
    if (assignat) ++id_cita;
  }
  
  else{
    int altura;
    bool trobat = false;
    int dia = agenda.get_dia_actual() + 1;
    dia_maxim = agenda.get_dia_actual() + agenda.get_D();
    int funcionari = 0;
    
    while ((not trobat) and (dia <= dia_maxim)){
      pedir_cita_nivel(administracio, agenda, enter_1, enter_2, dia, altura, funcionari);
      if (funcionari > 0){
	agenda.afegir_id_cita(id_cita, dia, funcionari, enter_1);
	agenda.afegir_nivell(enter_2, enter_1, funcionari, dia);
	trobat = true;
      }
      ++dia;
    }
    if (trobat) ++id_cita;
  }
}

void Funcionaris::pedir_cita_dia(Arbre<int> a, Agenda &agenda, int dia, int hora, int &altura, int &funcionari){
  if (a.es_buit()){
    altura = 0; //representa el nivell on estem.
  }
  else if ((agenda.esta_lliure(a.arrel(), dia, hora))){
    funcionari = a.arrel();
    altura = 0;
  }
  else {
    Arbre<int> a1;
    Arbre<int> a2;
    a.fills(a1,a2);
    int altura1 = 0;
    int altura2 = 0;
    int funcionari1 = 0;//Possible error!
    int funcionari2 = 0;
    pedir_cita_dia(a1, agenda, dia, hora, altura1, funcionari1);
    pedir_cita_dia(a2, agenda, dia, hora, altura2, funcionari2);
     
    if ((altura1 <= altura2) and (funcionari1 > 0)){
      altura = altura1 + 1;
      funcionari = funcionari1;
    }
    else if ((altura1 > altura2) and (funcionari2 > 0)){
      altura = altura2 + 1;
      funcionari = funcionari2;
    }
  }
}

void Funcionaris::pedir_cita_nivel(Arbre<int> a, Agenda &agenda, int hora, int nivel, int dia, int &altura, int &funcionari){
  if (a.es_buit()){
    altura = 0; //representa el nivell on estem.
  }
  else if ((agenda.esta_lliure(a.arrel(), dia, hora))){
    funcionari = a.arrel();
    altura = 0;
  }
  else { 
    Arbre<int> a1;
    Arbre<int> a2;
    a.fills(a1,a2);
    int altura1 = 0; //Possible error!
    int altura2 = 0;
    int funcionari1 = 0;
    int funcionari2 = 0;
    pedir_cita_nivel(a1, agenda, hora, nivel, dia, altura1, funcionari1);
    pedir_cita_nivel(a2, agenda, hora, nivel, dia, altura2, funcionari2);
     
    if ((altura1 <= altura2) and (funcionari1 > 0)){
      altura = altura1 + 1;
      if (altura <= nivel)  funcionari = funcionari1;
    }
    else if ((altura1 > altura2) and (funcionari2 > 0)){
      altura = altura2 + 1;
      if (altura <= nivel) funcionari = funcionari2;
    }
  }
}

Arbre<int> Funcionaris::trobar_subarbre(Arbre<int> a, Agenda &agenda, int dia, int hora, int funcionari, bool &trobat){
  Arbre<int>a_nou;
  if (a.es_buit()){trobat = false;}
  
  else if (a.arrel() == funcionari){
      trobat = true;
      a_nou = a;
  }
  
  else{
    Arbre<int> a1;
    Arbre<int> a2;
    a.fills(a1,a2);
    Arbre<int> a_nou1;
    Arbre<int> a_nou2;
    bool trobat1;
    bool trobat2;
    a_nou1 = trobar_subarbre(a1, agenda, dia, hora, funcionari, trobat1);
    a_nou2 = trobar_subarbre(a2, agenda, dia, hora, funcionari, trobat2);
    
    if (trobat1){
      //cout << "El trobat al if 1 val " << trobat << endl;
      a_nou = a_nou1;
    }
    else if (trobat2) {
      a_nou = a_nou2;
      //cout << "El trobat al if 2 val " << trobat << endl;
    }
  }
  //cout << "Trobat dins la funico val " << trobat << endl;
  return a_nou;
}

void Funcionaris::escriure_arbre_int(Arbre<int> &a) {
/* Pre: cert */ 
/* Post: El canal estandar de sortida conté el recorregut en inordre d'a */ 
  if (not a.es_buit()) {
    Arbre<int> a1;
    Arbre<int> a2;
    int x = a.arrel();
    a.fills(a1,a2);
    escriure_arbre_int(a1); 
    //cout << " " << x;
    escriure_arbre_int(a2);
    a.plantar(x,a1,a2);
  }
}


stack<int> Funcionaris::trobar_cami(Agenda &agenda, Arbre<int> a, int dia, int hora, bool &trobat, int &long_min){
  stack<int> p;
  
  if (a.es_buit()){
    trobat = false;
  }
  
  else if (agenda.esta_lliure(a.arrel(), dia, hora)){
    cout << "Ha trobat un element lliure " << endl;
    trobat = true;
    p.push(a.arrel());
    //cout << "Element trobat " << endl;
    //cout << "L'arrel a else if val " << a.arrel() << endl;
    return p;
  }
  
  else{
    
    int arrel = a.arrel();
    //cout << "L'arrel a else val " << arrel << endl;
    Arbre<int> a1;
    Arbre<int> a2;
    a.fills(a1,a2);
    stack<int> p1;
    stack<int> p2;
    int long_min1, long_min2;
    bool trobat1 = false; 
    bool trobat2 = false;
    p1 = trobar_cami(agenda, a1, dia, hora, trobat1, long_min1);
    p2 = trobar_cami(agenda, a2, dia, hora, trobat2, long_min2);
    
    if ((trobat1) and (trobat2)){
      if (p1.size() <= p2.size()){
	p = p1;
	p.push(arrel);
      }
      else{
	p = p2;
	p.push(arrel);
      }
    }
    else if ((trobat1) and (not trobat2)){
      p = p1;
      p.push(arrel);
    }
    else if ((not trobat1) and (trobat2)){
      p = p2;
      p.push(arrel);
    }
    else if ((not trobat1) and (not trobat2)){
      p = p1;
      p.push(arrel);
      //stack<int> p;
    }
  }
  return p;
}

void Funcionaris::anular_hora(Agenda &agenda, int enter_1, int enter_2, int funcionari){
  if (agenda.esta_lliure(funcionari, enter_1, enter_2)){
    agenda.anular_una_hora(funcionari, enter_1, enter_2);
  }
  
  else{
    bool trobat = false;
    Arbre<int> a;
    if (agenda.esta_lliure(2, 2, 3)) cout << "El funcionari 2 a la hora 3 el dia 2 esta lliure" << endl;
    else cout << "El funcionari 5 a la hora 3 el dia 2 NO esta lliure" << endl;
    a = trobar_subarbre(administracio, agenda, enter_1, enter_2, funcionari, trobat);
    if (agenda.esta_lliure(2, 2, 3)) cout << "El funcionari 2 a la hora 3 el dia 2 esta lliure" << endl;
    else cout << "El funcionari 5 a la hora 3 el dia 2 NO esta lliure" << endl;
    bool acabat = false;
    int id_cita_assignar = -1;
    int long_min = 0;
    trobat = false;
    stack<int>p = stack<int>();
    p = trobar_cami(agenda, a, enter_1, enter_2, trobat, long_min);
    stack<int>p1 = stack<int>();
    //cout << "A dalt de la pila hi ha " << p.top() << endl;
    //if (p.top() > 0){
    cout << "A dalt de la pila p hi ha " << p.top() << endl;
    if (agenda.esta_lliure(2, 2, 3)) cout << "El funcionari 2 a la hora 3 el dia 2 esta lliure" << endl;
    
    while (not p.empty()){
      p1.push(p.top());
      p.pop();
    }
    
    if (agenda.esta_lliure(p1.top(), enter_1, enter_2)){    
    cout << "A dalt de la pila p1 hi ha " << p1.top() << endl;
      int func;
      int id_cit;
      int nivell;
      while (not p1.empty()){
	func = p1.top();
	p1.pop();
	if (not p1.empty()){
	id_cit = agenda.get_id_cita(enter_1, p1.top(), enter_2);
	nivell = agenda.get_nivell(enter_1, p1.top(), enter_2);
	agenda.afegir_id_cita(id_cit, enter_1, func, enter_2);
	agenda.afegir_nivell(nivell, enter_2, func, enter_1);
	}
	else{
	  agenda.anular_una_hora(func, enter_1, enter_2);
	}
      }
    acabat = true;
    }
    
    else if (agenda.get_nivell(enter_1, funcionari, enter_2) > -1){
    int nivell = agenda.get_nivell(enter_1, funcionari, enter_2);
    //cout << "El nivell es " << nivell << endl;
    int altura = 0;
    bool trobat = false;
    //int dia = agenda.get_dia_actual() + 1;
    int dia_maxim = agenda.get_dia_actual() + agenda.get_D();
    int funcionari = 0;
    int id_cit = agenda.get_id_cita(enter_1, funcionari, enter_2);
    ++enter_1;
    
    while ((not trobat) and (enter_1 <= dia_maxim)){
      pedir_cita_nivel(administracio, agenda, enter_2, nivell, enter_1, altura, funcionari);
      if (funcionari > 0){
	agenda.afegir_id_cita(id_cit, enter_1, funcionari, enter_2);
	agenda.afegir_nivell(nivell, enter_2, funcionari, enter_1);
	trobat = true;
      }
      ++enter_1;
    }
   }
   
   else{
    bool assignat = false;
    int func = 0;
    int altura = 0;
    int dia_maxim = agenda.get_dia_actual() + agenda.get_D();
    int id_cit = agenda.get_id_cita(enter_1, funcionari, enter_2);
    int nivell = agenda.get_nivell(enter_1, funcionari, enter_2);
    agenda.anular_una_hora(funcionari, enter_1, enter_2);
    //cout << "El dia abans d'actualitzar " << enter_1 << " " << assignat << endl;
    //cout << "Dia maxim " << dia_maxim << endl;
    ++enter_1;
    
    while ((not assignat) and (enter_1 <= dia_maxim)){
     pedir_cita_dia(administracio, agenda, enter_1, enter_2, altura, func);
     if (func > 0){
      agenda.afegir_id_cita(id_cit, enter_1, func, enter_2); 
      agenda.afegir_nivell(nivell, enter_2, func, enter_1);
      assignat = true;
     }
     ++enter_1;
    }
   //cout << "L'id_cita es " << id_cita << endl;
   }
  }
}
     
     
    
    /*if ((id_cita_assignar > 0) or (not acabat)){
      int nivell = agenda.get_nivell(enter_1, funcionari, enter_2);
      if (nivell > 0){
	int altura;
	bool trobat = false;
	int dia = agenda.get_dia_actual() + 1;
	int dia_maxim = agenda.get_dia_actual() + agenda.get_D();
	int funcionari = 0;
    
	while ((not trobat) and (dia <= dia_maxim)){
	  pedir_cita_nivel(administracio, agenda, enter_1, enter_2, dia, altura, funcionari);
	    if (funcionari > 0){
	      agenda.afegir_id_cita(id_cita_assignar, dia, funcionari, enter_1);
	      //agenda.afegir_nivell(enter_2, enter_1, funcionari, dia);
	      trobat = true;
	    }
	++dia;
	}
      }
    else {
      bool assignat = false;
      int funcionari = 0;
      int altura = 0;
      int dia_maxim = agenda.get_dia_actual() + agenda.get_D();
    
      while ((not assignat) and (enter_1 <= dia_maxim)){
	pedir_cita_dia(administracio, agenda, enter_1, enter_2, altura, funcionari);
	if (funcionari > 0){
	  agenda.afegir_id_cita(id_cita, enter_1, funcionari, enter_2); 
	  assignat = true;
	}
	++enter_1;
      }
    }
   }
  }
}

    //id_cit = q.front();
  
    
    
  
    
  
  /*cout << p.size() << endl;
  while (not p.empty()){
    //cout << p.top() << endl;
    p.pop();
  }*/
      
  
  /*if (not estava_lliure){
    int func = 0;
    int altura = 0;
    bool assignat = false;
    int dia_maxim = agenda.get_dia_actual() + agenda.get_D();
    pedir_cita_dia(a, agenda, enter_1, enter_2, altura, func);
    if (func > 0){
      agenda.afegir_id_cita(id_cit, enter_1, func, enter_2);
      assignat = true;
    }
    int nivell = agenda.get_nivell(enter_1, funcionari, enter_2); //Picar codi.
    int dia = enter_1 + 1;
    while ((not assignat) and (dia <= dia_maxim)){
      if (nivell != -1) //Picar codi.
	pedir_cita_nivel(administracio, agenda, enter_2, nivell, dia, altura, func);
      else pedir_cita_dia(administracio, agenda, enter_1, enter_2, altura, func);
      if (func > 0){
      agenda.afegir_id_cita(id_cit, enter_1, func, enter_2);
      assignat = true;
      }
      ++dia;
    }
  }*/




