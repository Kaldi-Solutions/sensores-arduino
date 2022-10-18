#include "DHT.h"
#define dht_type DHT11 

/** Configurações iniciais **/
int dht_pin = A2;
DHT dht_1 = DHT(dht_pin, dht_type);

int lm35_pin = A0, leitura_lm35 = 0;
float temperatura;

int ldr_pin = A5, leitura_ldr = 0;
int switch_pin = 7;

void setup(){
  Serial.begin(1200);
  dht_1.begin();
  pinMode(switch_pin, INPUT);
}

void loop(){
  /**DHT11**/
  float umidade = dht_1.readHumidity();
  float umidadeProjeto = 0.25 * umidade + 43.75;
  float umidade2 = umidadeProjeto * 1.05;
  float umidade3 = umidadeProjeto * 0.95;
  float umidade4 = umidadeProjeto * 0.90;
  float umidade5 = umidadeProjeto * 1.10;
  float temperatura = dht_1.readTemperature();
  float temperaturaProjeto = 3 * temperatura - 54;
  float temperatura2 = temperaturaProjeto * 1.05;
  float temperatura3 = temperaturaProjeto * 0.95;
  float temperatura4 = temperaturaProjeto * 0.90;
  float temperatura5 = temperaturaProjeto * 1.10;
  if (isnan(temperatura) or isnan(umidade)){
    Serial.println("Erro ao ler o DHT");
  }else{
    Serial.print("Umidade 1:  ");
    Serial.print(umidadeProjeto);
    Serial.println("%; ");
    Serial.print("Umidade 2:  ");
    Serial.print(umidade2);
    Serial.println("%; ");
    Serial.print("Umidade 3:  ");
    Serial.print(umidade3);
    Serial.println("%; ");
    Serial.print("Umidade 4:  ");
    Serial.print(umidade4);
    Serial.println("%; ");
    Serial.print("Umidade 5:  ");
    Serial.print(umidade5);
    Serial.println("%; ");
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.println("°C;");
    Serial.print("Temperatura 1: ");
    Serial.print(temperaturaProjeto);
    Serial.println("°C;");
    Serial.print("Temperatura 2: ");
    Serial.print(temperatura2);
    Serial.println("°C;");
  }
  
  /* LM35 
  leitura_lm35 = analogRead(lm35_pin);
  temperatura = leitura_lm35 * (5.0/1023) * 100;
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
    Serial.println("°C;"); */
  
  /* Bloco do LDR5 
  leitura_ldr = analogRead(ldr_pin);
  Serial.print("Luminosidade: " + leitura_ldr);
  Serial.println(";"); */
  
  /* Bloco do TCRT5000
  if(digitalRead(switch_pin) == LOW){
  Serial.println(1);
  } else {
  Serial.println(0);
  } */
    delay(4000);
}
