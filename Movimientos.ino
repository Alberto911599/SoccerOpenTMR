void avanzar(int evento) {
  switch (evento) {
    case -2:
    for(int i = 0; i < 8; i++){
      digitalWrite(motores[i], HIGH); 
    }
//      Serial.println("Esperando...");
    break;
    case -1:
      for(int i = 0; i < 8; i++){
        digitalWrite(motores[i], LOW); 
      }
//      Serial.println("Esperando...");
    break;
    case 0:
      for(int i = 0; i < 8; i++){
        if(i % 2 == 0)
          digitalWrite(motores[i], LOW);
        else
          digitalWrite(motores[i], HIGH);
      }      
//      Serial.println("Retrocediendo");
      break;
    case 1:
      for(int i = 0; i < 8; i++){
        if(i % 2 == 0)
          digitalWrite(motores[i], HIGH);
        else
          digitalWrite(motores[i], LOW);
      }
//      Serial.println("Avanzando");
      break;
    case 2:
      for(int i = 0; i < 8; i++){
        if(i == 0 || i == 3 || i == 4 || i == 7)
          digitalWrite(motores[i], LOW);
        else
          digitalWrite(motores[i], HIGH);
      }
//      Serial.println("Izquierdeando");
    break;
    case 3:
      for(int i = 0; i < 8; i++){
        if(i == 0 || i == 3 || i == 4 || i == 7)
          digitalWrite(motores[i], HIGH);
        else
          digitalWrite(motores[i], LOW);
      }
//      Serial.println("Derecheando");
    break;
    case 4:
      for(int i = 0; i < 8; i++){
        if(i == 3 || i == 7)
          digitalWrite(motores[i], HIGH);
         else
          digitalWrite(motores[i], LOW);
      }
//      Serial.println("Diagonal Back Derecha");
    break;
    case 5:
      for(int i = 0; i < 8; i++){
        if(i == 2 || i == 6)
          digitalWrite(motores[i], HIGH);
         else
          digitalWrite(motores[i], LOW);
      }
//      Serial.println("Diagonal Front Izquierda");
    break;
    case 6:
      for(int i = 0; i < 8; i++){
        if(i == 0 || i == 4)
          digitalWrite(motores[i], HIGH);
         else
          digitalWrite(motores[i], LOW);
      }
//      Serial.println("Diagonal Front Derecha");
    break;
    case 7:
      for(int i = 0; i < 8; i++){
        if(i == 1 || i == 5)
          digitalWrite(motores[i], HIGH);
         else
          digitalWrite(motores[i], LOW);
      }
//      Serial.println("Diagnoal Back Izquierda");
    break;
    case 8:
      for(int i = 0; i < 8; i++){
       if(i == 1 || i == 3 || i == 4 || i == 6)
         digitalWrite(motores[i], 80);
       else
         digitalWrite(motores[i], LOW);
      }
    break;
    case 9:
      for(int i = 0; i < 8; i++){
       if(i == 1 || i == 3 || i == 4 || i == 6)
         digitalWrite(motores[i], LOW);
       else
         digitalWrite(motores[i], 80);
      }
    break;
  }
}

void alineacion_porteria(){
  int temp = x_Amarilla > 250 ? 9 : 8;
  while(viendo_amarilla && !alineado){
    avanzar(temp);
    scanPixy();
//    colores();
//    if(!(on_color[0] == 0 && on_color[1] == 0)){
//      dentro_cancha();
//    }
  }
  avanzar(-1);
}


