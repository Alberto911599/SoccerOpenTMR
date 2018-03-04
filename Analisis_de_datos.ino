//Funcion utilizada para ir hacia algun objetivo ya identificado
//en este caso catch la pelota y fire la porteria
void catch_fire(int i){
  if(i > 100 && i < 220){
//    Serial.println("Adelante");
    direccion = 1;
  }
  //La pelota esta a la izquierda
  else if(i <= 100){
//    Serial.println("Izquierda");
    direccion = 2;
  }
  //La pelota esta a la derecha
  else{
//    Serial.println("Derecha");
    direccion = 3;
  }
}

//Funcion que se utiliza para buscar un objetivo
void find_objective(int i){
  //Si no se detecta, y la ultima vez que se vio fue en medio
  if( i >= 40 && i <= 280 ){
//    Serial.println("Se perdio de vista por distancia, echa reversa");
    direccion = 0;
  }
//  Si no se detecta, y la ultima vez que se vio i fue mayor a 270, el objetivo esta a la derecha
  else if(i > 280){
//    Serial.println("El objetivo salio por la derecha, diagonal hacia atras a la derecha");
    direccion = 4;
  }
  //Si no se detecta, y la ultima vez que se vio i fue menor a 50, el objetivo esta a la izquierda
  else{
//    Serial.println("El objetivo salio por la izquierda, diagonal hacia atras a la izuqierda");
    direccion = 7;
  }
}


void simple_bouncing(){
  int tiempo = 800;
  scanPixy();
  //Toque en meta
  if(on_color[0] == 1 && on_color[1] == 1){
    tiempo = 1100;
    //Toque en frente
    if(direccion == 1 || direccion == 5 || direccion == 6){
      direccion = 0;
    }
    else{
      direccion = x_Amarilla > 160 ? 6 : 5;
    }
  }
    else if(on_color[0] == 0){
      if(y_Amarilla > 90){
        direccion = 3;
      }
      else{
        direccion = x_Amarilla > 80 ? 6 : 4;
      }
    }
    else{
      if(y_Amarilla > 90){
        direccion = 2;
      }
      else{
        direccion = x_Amarilla < 240 ? 5 : 7;
      }
    }
    
    if((direccion == 4 || direccion == 6)&& !viendo_Pelota)
      x_pelota= 399;
    if((direccion == 7 ||direccion == 5) && !viendo_Pelota)
      x_pelota =0;
    
    avanzar(direccion);
    delay(tiempo); 
}
//


int analisis_de_datos(){
  
//  Escanea donde estas parado
  colores();  
  
//  Area libre, no se hatocado ninguna linea de salida
  if((on_color[0] == 0 && on_color[1] == 0)){
    
    alineacion_bno();
    scanPixy();
//  
    if(viendo_amarilla && !alineado){
      alineacion_porteria();
    }
    
//  //Si no esta viendo la pelota, busca la pelota de acuerdo a la ultima vez que se vio
    if(!viendo_Pelota){
      //Buscala
//    //Serial.println("No estoy viendo la pelota y la estoy buscando");
      find_objective(x_pelota);
    }

    //Si estas viendo la pelota evalua si:
    else{
      //Si tengo posesion de la pelota
      if(tengo_Pelota){
        //Y tiro hacia la porteria entonces
        if(equipo){
          //Ve a "disparar" hacia la porteria amarilla
//    Serial.println("Tengo la pelota y voy a disparar a la porteria amarilla");
          catch_fire(x_Amarilla);
        }
        //Si tiro hacia la porteria azul entonces
        else{
          //Ve a "disparar" hacia la porteria azuluuu
//          Serial.println("Tengo la pelota y voy a disparar a la porteria amarilla");
          catch_fire(x_Azul);
        }
      }

      //Si no tengo la pelota, pero la estoy viendo
      else{
//      Ve a atrapar la pelota  
        catch_fire(x_pelota);
      }
    }
  }

//  Si estoy en una linea
  else{
      simple_bouncing();
   }
  return direccion;
}


