#define POT_PIN 4    // Pin del potenciómetro (entrada ADC)
#define LED_PIN 5    // Pin del LED (salida PWM)

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Leer el potenciómetro
  int lecturaADC = analogRead(POT_PIN); // 0 - 8191
  float voltage = lecturaADC / 8191.0 * 3.3;  // Convertir a voltaje
  float angulo = voltage / 3.3 * 270.0;  // Convertir a ángulo
  
  // Convertir a brillo PWM (0 - 255)
  int brillo = map(lecturaADC, 0, 8191, 0, 255);

  // Imprimir valores por serial
  Serial.printf("Voltaje: %.2fV, Ángulo: %.1f°\n", voltage, angulo);

  // Ajustar brillo del LED (sin usar ledcSetup)
  analogWrite(LED_PIN, brillo);

  delay(500);
}