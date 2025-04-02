#define POT_PIN 4    // Pin del potenciómetro (entrada ADC)
#define LED_PIN 5    // Pin del LED (salida PWM)

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);  // Configura el pin del LED como salida
}

void loop() {
  int lecturaADC = analogRead(POT_PIN); // Lee el potenciómetro (0 - 4095 o 8191)
  float voltage = lecturaADC / 8191.0 * 3.3;  // Convierte a voltaje (ajusta a 8191 si es necesario)
  float angulo = voltage / 3.3 * 270.0;  // Calcula el ángulo

  int brillo = map(analogRead(POT_PIN), 0, 8191, 0, 255);  // Convierte a nivel PWM (0 - 255)
  float brilloPorcentaje = (brillo / 255.0) * 100;  // Calcula el porcentaje de brillo

  // Imprimir en el monitor serie sin printf
  Serial.print("Voltaje: ");
  Serial.print(voltage, 2);  // 2 decimales
  Serial.print("V, Ángulo: ");
  Serial.print(angulo, 1);  // 1 decimal
  Serial.print("°, Brillo: ");
  Serial.print(brillo);
  Serial.print(" (");
  Serial.print(brilloPorcentaje, 1);  // 1 decimal
  Serial.println("%)");

  analogWrite(LED_PIN, brillo);  // Ajusta el brillo del LED
}
