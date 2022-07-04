// LIBRERIAS

#include "DHT.h"

// DEFINIR SENSOR DHT11

#define DHT11_PIN A1
#define DHTTYPE DHT11

DHT dht(DHT11_PIN, DHTTYPE);

// IDENTIFICADOR MODO

int modo_value = 3;

// PIN PULSADOR

int pulsador = 1;

// PINES DISPLAY DECENAS

int pines_deco_decenas[4] = {13, 12, 11, 10};

int cero_d[4]  = {0, 0, 0, 0};
int uno_d[4]   = {0, 0, 0, 1};
int dos_d[4]   = {0, 0, 1, 0};
int tres_d[4]  = {0, 0, 1, 1};
int cuatro_d[4]= {0, 1, 0, 0};
int cinco_d[4] = {0, 1, 0, 1};
int seis_d[4]  = {0, 1, 1, 0};
int siete_d[4] = {0, 1, 1, 1};
int ocho_d[4]  = {1, 0, 0, 0};
int nueve_d[4] = {1, 0, 0, 1};

// PINES DISPLAY UNIDADES 

int pines_deco_unidades[4] = {5, 4, 3, 2};

int cero_u[4]  = {0, 0, 0, 0};
int uno_u[4]   = {0, 0, 0, 1};
int dos_u[4]   = {0, 0, 1, 0};
int tres_u[4]  = {0, 0, 1, 1};
int cuatro_u[4]= {0, 1, 0, 0};
int cinco_u[4] = {0, 1, 0, 1};
int seis_u[4]  = {0, 1, 1, 0};
int siete_u[4] = {0, 1, 1, 1};
int ocho_u[4]  = {1, 0, 0, 0};
int nueve_u[4] = {1, 0, 0, 1};

// PINES LEDS TEMPERATURA

int led_azul = 6;
int led_verde = 7;
int led_amarillo = 8;
int led_rojo = 9;

void setup(){
    
  // ACTIVA EL SENSOR DHT
  
  dht.begin();

  // CONFIGURA PINES LEDS TEMPERATURA
  
  pinMode(led_azul, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(led_amarillo, OUTPUT);
  pinMode(led_rojo, OUTPUT);
   
  // SETUP DISPLAY DECENAS
  
  for(int i=0; i<=3; i++){
    pinMode(pines_deco_decenas[i], OUTPUT);
  } 
  
  // SETUP DISPLAY UNIDADES
  
  for(int i=0; i<=3; i++){
    pinMode(pines_deco_unidades[i], OUTPUT);
  }

  // SETUP SENSOR SUELO
  pinMode(0, OUTPUT);
  
}

// FUNCION TEMPERATURA 

int temperatura_dev(){
  
  int temperature = dht.readTemperature();
  
  return temperature;
}

// FUNCION HUMEDAD 

  int humedad_dev(){

  int humedad = dht.readHumidity();

  return humedad;
}

// FUNCION HUMEDAD SUELO

  long humedad_suelo(int valor_analog){
  
    long v1 = 1023 - valor_analog;
  
    long v2 = (long) 99 * v1;
    
    long value = v2 / 673;
    
    return value;
    
  } 

// FUNCION DISPLAY DECENAS

void display_decenas_dev(int decenas){

  if (decenas == 0){
    for(int i=0; i<=3; i++){
      digitalWrite(pines_deco_decenas[i], cero_d[i]);
    }
  }

  if (decenas == 1){
    for(int i=0; i<=3; i++){
      digitalWrite(pines_deco_decenas[i],uno_d[i]);
    }
  }
  
  if (decenas == 2){
   for(int i=0; i<=3; i++){
      digitalWrite(pines_deco_decenas[i],dos_d[i]);
    } 
  }

  if (decenas == 3){
    for(int i=0; i<=3; i++){
      digitalWrite(pines_deco_decenas[i],tres_d[i]);
    }
  }
  
  if (decenas == 4){
   for(int i=0; i<=3; i++){
      digitalWrite(pines_deco_decenas[i],cuatro_d[i]);
    } 
  }

  if (decenas == 5){
    for(int i=0; i<=3; i++){
      digitalWrite(pines_deco_decenas[i],cinco_d[i]);
    }
  }

  if (decenas == 6){
    for(int i=0; i<=3; i++){
      digitalWrite(pines_deco_decenas[i],seis_d[i]);
    }
  }

  if (decenas == 7){
    for(int i=0; i<=3; i++){
      digitalWrite(pines_deco_decenas[i],siete_d[i]);
    }
  }

  if (decenas == 8){
    for(int i=0; i<=3; i++){
      digitalWrite(pines_deco_decenas[i],ocho_d[i]);
    }
  }

  if (decenas == 9){
    for(int i=0; i<=3; i++){
      digitalWrite(pines_deco_decenas[i],nueve_d[i]);
    }
  }
}

// FUNCION DISPLAY UNIDADES

void display_unidades_dev(int unidades){

  if (unidades == 0){
    for(int i=0; i<=3; i++){
      digitalWrite(pines_deco_unidades[i], cero_u[i]);
    }
  }

  if (unidades == 1){
    for(int i=0; i<=3; i++){
      digitalWrite(pines_deco_unidades[i],uno_u[i]);
    }
  }
  
  if (unidades == 2){
   for(int i=0; i<=3; i++){
      digitalWrite(pines_deco_unidades[i],dos_u[i]);
    } 
  }

  if (unidades == 3){
    for(int i=0; i<=3; i++){
      digitalWrite(pines_deco_unidades[i],tres_u[i]);
    }
  }
  
  if (unidades == 4){
   for(int i=0; i<=3; i++){
      digitalWrite(pines_deco_unidades[i],cuatro_u[i]);
    } 
  }

  if (unidades == 5){
    for(int i=0; i<=3; i++){
      digitalWrite(pines_deco_unidades[i],cinco_u[i]);
    }
  }

  if (unidades == 6){
    for(int i=0; i<=3; i++){
      digitalWrite(pines_deco_unidades[i],seis_u[i]);
    }
  }

  if (unidades == 7){
    for(int i=0; i<=3; i++){
      digitalWrite(pines_deco_unidades[i],siete_u[i]);
    }
  }

  if (unidades == 8){
    for(int i=0; i<=3; i++){
      digitalWrite(pines_deco_unidades[i],ocho_u[i]);
    }
  }

  if (unidades == 9){
    for(int i=0; i<=3; i++){
      digitalWrite(pines_deco_unidades[i],nueve_u[i]);
    }
  }
}

void loop(){
     
  if (modo_value == 3 && digitalRead(pulsador) == LOW){
    
    delay(500);
    digitalWrite(0, LOW);

    while (digitalRead(pulsador) == HIGH && modo_value == 3) {
      
      // DIVIDE DIGITOS TEMPERATURA
      
      int unidades_t = (temperatura_dev() % 10);
      int decenas_t = (temperatura_dev() /10 % 10);
    
      // MUESTRA EN DISPLAY LOS DIGITOS DE TEMPERATURA
      
      display_decenas_dev(decenas_t); 
      display_unidades_dev(unidades_t);

      // CHECK LEDS TEMPERATURA
    
      if (temperatura_dev() >= 0 && temperatura_dev() <= 10){ // Si 0 <= Temperatura <= 10
        
        digitalWrite(led_azul, HIGH); // Se prende led azul
        digitalWrite(led_verde, LOW);
        digitalWrite(led_amarillo, LOW);
        digitalWrite(led_rojo, LOW);
        
      } else if (temperatura_dev() > 10  && temperatura_dev() <= 20){ // Si 10 < Temperatura <= 20
       
        digitalWrite(led_azul, LOW);
        digitalWrite(led_verde, HIGH); // Se prende led verde
        digitalWrite(led_amarillo, LOW);
        digitalWrite(led_rojo, LOW);
        
      } else if (temperatura_dev() > 20  && temperatura_dev() <= 30){ // Si 20 < Temperatura <= 30
        
        digitalWrite(led_azul, LOW);
        digitalWrite(led_verde, LOW);
        digitalWrite(led_amarillo, HIGH); // Se prende led amarillo
        digitalWrite(led_rojo, LOW);
        
      } else if (temperatura_dev() > 30){ // Si 30 < Temperatura
        
        digitalWrite(led_azul, LOW);
        digitalWrite(led_verde, LOW);
        digitalWrite(led_amarillo, LOW);
        digitalWrite(led_rojo, HIGH); // Se prende led rojo
    
      }
      
    }
    
    modo_value = 1;
    
  }

  if (digitalRead(pulsador) == LOW && modo_value == 1){

    delay(500);

    while (digitalRead(pulsador) == HIGH && modo_value == 1) {
      
      // DIVIDE DIGITOS HUMEDAD
      
      int unidades_h = (humedad_dev() % 10);
      int decenas_h = (humedad_dev() /10 % 10);
  
      // MUESTRA EN DISPLAY LOS DIGITOS DE HUMEDAD
      
      display_decenas_dev(decenas_h); 
      display_unidades_dev(unidades_h);
  
      // APAGA TODOS LOS LEDS PRENDIDOS
  
      digitalWrite(led_azul, LOW);
      digitalWrite(led_verde, LOW);
      digitalWrite(led_amarillo, LOW);
      digitalWrite(led_rojo, LOW);
      
    }

    modo_value = 2;
    
  }

  if (digitalRead(pulsador) == LOW && modo_value == 2){

    delay(500);

    while (digitalRead(pulsador) == HIGH && modo_value == 2) {

      digitalWrite(0, HIGH);
      int valor = analogRead(A2);
      
      if (valor < 350){
        
        display_decenas_dev(9); 
        display_unidades_dev(9);
        
      } else {

        // DIVIDE DIGITOS PORCENTAJE HUMEDAD SUELO
        
        int unidades_ht = (humedad_suelo(valor) % 10);
        int decenas_ht = (humedad_suelo(valor)/ 10 % 10);
      
        // MUESTRA EN DISPLAY LOS DIGITOS DE HUMEDAD SUELO
        
        display_decenas_dev(decenas_ht); 
        display_unidades_dev(unidades_ht);
        
      }
      
      delay(500);
      
    }

    modo_value = 3;
    
  }
  
}
