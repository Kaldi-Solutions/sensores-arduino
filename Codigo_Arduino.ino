#include "DHT.h"
#define dht_type DHT11 

/** Configurações iniciais **/
int dht_pin = A2;
DHT dht_1 = DHT(dht_pin, dht_type);

void setup(){
  Serial.begin(9600);
  dht_1.begin();
}

void loop(){
  /**DHT11**/
  float umidade = dht_1.readHumidity();
  float temperatura = dht_1.readTemperature();
  if (isnan(temperatura) or isnan(umidade)){
    Serial.println("Erro ao ler o DHT");
  }else{
    Serial.print("Umidade:  ");
    Serial.print(umidade);
    Serial.print("%; ");
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.println("°C;");
  }
  
//  /* LM35 */
//  leitura_lm35 = analogRead(lm35_pin);
//  temperatura = leitura_lm35 * (5.0/1023) * 100;
//  Serial.print("Temperatura: ");
//  Serial.print(temperatura);
//  Serial.println(";");
  
  /* Bloco do LDR5 */
//  leitura_ldr = analogRead(ldr_pin);
//  Serial.print("Luminosidade: " + leitura_ldr);
//  Serial.println(";");
  
  /* Bloco do TCRT5000 */
//  if(digitalRead(switch_pin) == LOW){
//    Serial.println(1);
//  } else {
//    Serial.println(0);
//  }
    delay(4000);
}
