#include "DHT.h"
#define dht_type DHT11 //define qual o tipo de sensor DHTxx que se está utilizando
/**
* Configurações iniciais sobre os sensores
* DHT11, LM35, LDR5 e TCRT5000
*/
int dht_pin = A2;
DHT dht_1 = DHT(dht_pin, dht_type); //pode-se configurar diversos sensores DHTxx
int lm35_pin = A0, leitura_lm35 = 0;
float temperatura;
int ldr_pin = A5, leitura_ldr = 0;
int switch_pin = 7;
void setup()
{
Serial.begin(9600);
dht_1.begin();
pinMode(switch_pin, INPUT);
}
void loop()
{
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
if (isnan(temperatura) or isnan(umidade))
{
Serial.println("Erro ao ler o DHT");
}
else
{
Serial.print(umidadeProjeto);
Serial.print(";");
Serial.print(umidade2);
Serial.print(";");
Serial.print(umidade3);
Serial.print(";");
Serial.print(umidade4);
Serial.print(";");
Serial.print(umidade5);
Serial.print(";");
Serial.print(temperaturaProjeto);
Serial.print(";");
Serial.print(temperatura2);
Serial.print(";");
Serial.print(temperatura3);
Serial.print(";");
Serial.print(temperatura4);
Serial.print(";");
Serial.print(temperatura5);
Serial.print(";");
}
delay(2000);
}
