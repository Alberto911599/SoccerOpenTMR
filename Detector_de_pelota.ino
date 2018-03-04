
//Documentacion de la pixy camera: http://cmucam.org/projects/cmucam5/wiki/Arduino_API
#include <Pixy.h>
#include <PixyI2C.h>
#include <PixySPI_SS.h>
#include <PixyUART.h>
#include <SPI.h>
#include <Wire.h>
#include <TPixy.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>


//MOTORES
int motores[8] = {23, 22, 24, 25, 43, 42, 40, 41};
int enable[4] = {7, 8, 9, 10};
/////////////////////////////////////////////////////////////////////////////////////////////////////
int led = 13;
///////////////////////////////////////DECLARACION DE VARIABLES/////////////////////////////////////////
Pixy pixy;                                        //1 = Pelota; 2 = Porteria Amarilla; 3 = Porteria Azul
                                                  //4 = Morado; 5 = Rojo; 
Adafruit_BNO055 bno = Adafruit_BNO055(55);
//Servo angulo;
//                                                   
bool viendo_Pelota;                               //Es verdadero si la pelota esta siendo detectada
bool tengo_Pelota;
bool equipo;                                      //True = porteria amarilla  False = porteria azul
//bool morado;
//bool rojo;
bool viendo_amarilla;
bool alineado;
//bool viendo_azul;
//
int on_color[2] = {2, 3};                                  //00 = libre; 01 = derecha; 10 = izquierda; 11 = lineas meta
int x_pelota, y_pelota;                           //Coordenadas cartesianas de la posicion de la pelota
int x_Amarilla, y_Amarilla;                       //Coordenadas cartesianas de la posicion de la porteria amarilla
int x_Azul, y_Azul;                               //Coordenadas cartesianas de la posicion de la porteria azul
int height_amarilla;
int height_azul;
int rotacion;
int conteo_umbral=0;
int conteo_amarilla =0;
int conteo_azul = 0;
uint16_t blocks;                                  //Bloques detectados por la Pixy
unsigned int direccion;                           //Hacia donde se mueve el robot
//unsigned int distancias[4];                       //Arreglo donde se guardan las 4 distancias

//////////////////////////////////////////  ////////////////////////////////////////////////////////////////  

                                                  
/////////////////////////////////////////DECLARACION DE CONSTANTES/////////////////////////////////////////
//const unsigned int largo = 243;
//const unsigned int ancho = 182;
//const unsigned int altura_gotPelota = h;
//const unsigned int base_gotPelota = b;
//const unsigned int y_gotPelota = h;
//const int sal_Linea = 750;
//////////////////////////////////////////////////////////////////////////////////////////////////////////  


void setup() {
  pixy.init();
  bno.begin();
  bno.setExtCrystalUse(true);
  equipo = true; // = digitalRead(porteria);
  for(int i = 0; i < 8; i++){
    pinMode(motores[i], OUTPUT);
  }
  for(int i = 0; i < 4; i++){
    pinMode(enable[i], OUTPUT);
    analogWrite(enable[i], 110);
  }
  pinMode(led, OUTPUT);
  pinMode(on_color[0], INPUT);
  pinMode(on_color[1], INPUT);                                  
}

void loop() {
  avanzar(analisis_de_datos());
}
