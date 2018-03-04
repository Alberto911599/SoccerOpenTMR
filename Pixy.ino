void scanPixy(){
  
  int signature;
  int area_max_azul = 0;
  int area_max_amarilla = 0;
  int area_max_pelota = 0;
  int area_temp;
  
  
  blocks = pixy.getBlocks();
 
  
  if(blocks){

    for (int h = 0; h < blocks; h++){
      
      signature = pixy.blocks[h].signature;
      area_temp = pixy.blocks[h].height * pixy.blocks[h].width;
      
      if(signature == 1){

        if(area_temp > area_max_pelota/*area_max_pelota < area_temp*/){
          conteo_umbral = 0;
          area_max_pelota = area_temp;
          x_pelota = pixy.blocks[h].x; //Regresa la coordenada x del centro del rectangulo (de 0 a 319)
          y_pelota = pixy.blocks[h].y; //Regresa la coordenada x del centro del rectangulo (de 0 a 199)
        }


        tengo_Pelota = ((x_pelota >= 140 && x_pelota <= 200) && (y_pelota >= 180 ) && (pixy.blocks[h].height <= 35) && (pixy.blocks[h].width <= 85));           
  
      }
      else if(signature == 2){

          if(area_temp > area_max_amarilla){
            conteo_amarilla = 0;
            area_max_amarilla = area_temp;
            x_Amarilla = pixy.blocks[h].x; //Regresa la coordenada x del centro del rectangulo de la porteria amarilla(de 0 a 319)
            y_Amarilla = pixy.blocks[h].y; //Regresa la coordenada x del centro del rectangulo de la porteria amarilla (de 0 a 199)
            height_amarilla = pixy.blocks[h].height;
            alineado = x_Amarilla >= 70 && x_Amarilla <= 250;
          }
          //else{conteo_amarilla = 1000000;}

      }
////      else{
////        if(area_temp > 50){
////          conteo_azul = 0;
////          x_Azul = pixy.blocks[h].x; //Regresa la coordenada x del centro del rectangulo de la porteria azul(de 0 a 319)
////          y_Azul = pixy.blocks[h].y; //Regresa la coordenada x del centro del rectangulo de la porteria azul (de 0 a 199)
////          height_amarilla = pixy.blocks[h].height;
////          alineado =x_Azul >= 70 && x_Amarilla <= 250;
////        }
////      }
    }
  }
  if(viendo_amarilla){
    digitalWrite(led, HIGH);
  }
  else{
    digitalWrite(led, LOW);
  }
  viendo_Pelota = conteo_umbral < 300;
  viendo_amarilla = conteo_amarilla < 500;
  if(conteo_umbral < 350)
    conteo_umbral++; 
  if(conteo_amarilla < 550)
    conteo_amarilla++;
}



