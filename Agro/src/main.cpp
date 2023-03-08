#include <Arduino.h>
#include <heltec.h>

#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHTPIN 25     // Pin de datos del sensor DHT11
#define DHTTYPE DHT11   // Tipo de sensor DHT11


#define OLED_RST 16

#define ANALOG_PIN 36 // pin analógico utilizado para leer el valor


DHT dht(DHTPIN, DHTTYPE);


void setup() {
  Serial.begin(115200);
  dht.begin();  // Inicializar el sensor DHT11

  // Inicia el display OLED
  Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Disable*/, true /*Serial Enable*/);
  Heltec.display->init();
  Heltec.display->flipScreenVertically();
  Heltec.display->setFont(ArialMT_Plain_16);

  pinMode(OLED_RST, OUTPUT);
  digitalWrite(OLED_RST, LOW);
  delay(20);
  digitalWrite(OLED_RST, HIGH);
  delay(20);
}

void loop() {

  /*
  int sensorValue = analogRead(ANALOG_PIN);

  Heltec.display->clear();
  Heltec.display->drawString(0, 0, "Valor analógico:");
  Heltec.display->drawString(0, 16, String(sensorValue));
  Heltec.display->display();

    int valor_analogico = analogRead(A0);  // Leer el valor analógico en el pin A0
  Serial.println(valor_analogico);  // Enviar el valor a través del puerto serie

*/


 float humedad = dht.readHumidity();
  float temperatura = dht.readTemperature();

  // Comprobar si la lectura del sensor fue exitosa
  if (isnan(humedad) || isnan(temperatura)) {
    Serial.println("Error al leer el sensor DHT11.");
    return;
  }

  // Enviar los valores a través del puerto serie

  Serial.print(humedad);
  Serial.print(" ");
  Serial.print(temperatura);
  Serial.println("");


  

  delay(500);
}