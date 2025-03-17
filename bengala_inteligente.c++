#include <Ultrasonic.h>

#define TRIGGER_PIN_1  6
#define ECHO_PIN_1     7
#define TRIGGER_PIN_2  12
#define ECHO_PIN_2     13

Ultrasonic ultrasonic1(TRIGGER_PIN_1, ECHO_PIN_1);
Ultrasonic ultrasonic2(TRIGGER_PIN_2, ECHO_PIN_2);

int vibracall = 9;
int button = 8;

void setup() {
  Serial.begin(9600);
  pinMode(vibracall, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  if (digitalRead(button) == HIGH) {
    delay(100);
    long range_1 = ultrasonic1.Ranging(CM);
    Serial.print("Distancia 1 lida: ");
    Serial.print(range_1);
    Serial.println(" centimetros");
    
    delay(150);
    long range_2 = ultrasonic2.Ranging(CM);
    Serial.print("Distancia 2 lida: ");
    Serial.print(range_2);
    Serial.println(" centimetros");
    Serial.println("=========================");

    if (range_1 <= 50 || range_2 <= 50) {
      digitalWrite(vibracall, HIGH);
      delay(1000);
      digitalWrite(vibracall, LOW);
      delay(100);
    }
  } else {
    digitalWrite(vibracall, LOW); // Desliga a vibração quando o sistema está desligado
    Serial.println("Sistema desligado.");
  }
}