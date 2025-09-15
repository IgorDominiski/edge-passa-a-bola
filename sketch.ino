#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <PubSubClient.h>

// LCD I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);


const int botao = 4;
const int leds[] = {18, 19, 26, 25, 23}; 
const int numLeds = sizeof(leds)/sizeof(leds[0]);


int contador = 0;
int lastButtonState = HIGH;

// Wi-Fi e MQTT
const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* mqttServer = "test.mosquitto.org";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);

  // Configura botão e LEDs
  pinMode(botao, INPUT_PULLUP);
  for(int i=0;i<numLeds;i++) pinMode(leds[i], OUTPUT);

  // LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Passa a Bola");
  lcd.setCursor(0,1);
  lcd.print("Total: 0");

  // Conectar Wi-Fi
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectado!");

  // Conectar MQTT
  client.setServer(mqttServer, 1883);
  while(!client.connected()){
    Serial.println("Conectando MQTT...");
    client.connect("ESP32-Contador");
    delay(1000);
  }
  Serial.println("MQTT conectado!");
}

void loop() {
  int buttonState = digitalRead(botao);

  
  if(lastButtonState==HIGH && buttonState==LOW){
    contador++;
    Serial.println(contador);

  
    lcd.setCursor(0,1);
    lcd.print("Total: ");
    lcd.print(contador);

    // Pisca LED 
    int ledAtual = contador % numLeds;
    digitalWrite(leds[ledAtual], HIGH);
    delay(200);
    digitalWrite(leds[ledAtual], LOW);

    
    char msg[10];
    sprintf(msg,"%d",contador);
    client.publish("jogo/passes/yan", msg);
  }

  lastButtonState = buttonState;
  client.loop();
  delay(20); 
}
