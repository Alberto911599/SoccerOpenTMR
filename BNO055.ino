bool giro(){
  sensors_event_t event; 
  bno.getEvent(&event);
  rotacion = event.orientation.x;
  return (rotacion > 50 && rotacion < 310);
}

void alnbno(){
  giro();
  int temp = rotacion < 180 ? 8 : 9;
  while(giro()){
    avanzar(temp);
  }
  avanzar(-1);
}

void alineacion_bno(){
  if(!giro())
    return;
  alnbno();
//  int temp = rotacion < 180 ? 8 : 9;
//  while(giro()){
//    avanzar(temp);
//    colores();
//    if(!(on_color[0] == 0 && on_color[1] == 0)){
//      dentro_cancha();
//    }
//  }
  avanzar(-1);
}
