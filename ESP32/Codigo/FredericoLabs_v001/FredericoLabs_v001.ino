#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

#define LED_VERDE 4

void setup() {
  Serial.begin(115200);

  pinMode(LED_VERDE, OUTPUT);
  digitalWrite(LED_VERDE, LOW);

  SerialBT.begin("Frederico_Lab_ID");

  Serial.println("=================================");
  Serial.println(" Frederico Labs");
  Serial.println(" Sistema pronto");
  Serial.println("=================================");
  Serial.println("Aguardando comando ABRIR...");
}

void loop() {

  if (SerialBT.available()) {

    String comando = SerialBT.readStringUntil('\n');
    comando.trim();

    Serial.print("Comando recebido: ");
    Serial.println(comando);

    if (comando.equalsIgnoreCase("ABRIR")) {

      Serial.println("ACESSO LIBERADO");

      digitalWrite(LED_VERDE, HIGH);

      SerialBT.println("OK_ABRIR");

      delay(10000);

      digitalWrite(LED_VERDE, LOW);

      Serial.println("FECHADURA TRANCADA");
    }
    else {

      Serial.println("COMANDO INVALIDO");

      SerialBT.println("ERRO");
    }
  }
}