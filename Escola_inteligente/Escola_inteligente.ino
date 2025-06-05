

//biblioteca
#include <DHT.h>
#include <DHT_U.h>
#include <DHT11.h>

#define DHTPINO A2 
#define DHTTYPE DHT11

DHT dht(DHTPINO, DHT11);// inicializa o objeto cm pino e o tipo



// variaveis acenderLEDaPresenca() {    
const int PIR = 2;
const int ledAmarelo = 13;
//
const int MQ135 = A0;
const int buzzer = 12;

void acenderLEDPresenca() {
  int estadoPIR = digitalRead(PIR);

  if (estadoPIR == HIGH) {
    digitalWrite(ledAmarelo , HIGH);
    Serial.println("LEd ligado");
  } else {
    digitalWrite(ledAmarelo, LOW);
    Serial.println("LED apagado");

  }
}


void VerificarVazamentoGas(){
  int estadoMQ135 = analogRead(MQ135);

if (estadoMQ135 >= 400){
  alarme_dois_tons();
}
else{
  noTone(buzzer);
}

}

void alarme_dois_tons() {
  int freqAlta = 1000;
  int freqBaixa = 2000;
  int duracaoTom = 150;

  tone(buzzer, freqAlta, duracaoTom);
  delay(duracaoTom);
  tone(buzzer, freqBaixa, duracaoTom);
  delay(duracaoTom);
}

void VerificarTemperaturaEUmidade(){
 float umidade = dht.readHumidity();
 float temperatura = dht.readTemperature();

 Serial.println("Umidade" + String(umidade) + "%");
 Serial.println("Temperatura" + String(temperatura) + "C");
delay(7000);
}

void setup() {

  Serial.begin(9600);

  pinMode(ledAmarelo, OUTPUT);
  pinMode(MQ135, INPUT);
  pinMode(buzzer, OUTPUT);

  //inicializar o sensor DHT
  dht.begin();


  Serial.println("Calibrando sensores");
  delay(10000);
  Serial.println("Sensores calibrados!!!");
}

void loop() {
 // acenderLEDPresenca();

  //VerificarVazamentoGas();
VerificarTemperaturaEUmidade();
}
