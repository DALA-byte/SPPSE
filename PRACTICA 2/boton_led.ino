void setup() {
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(20, OUTPUT);

  pinMode(42, OUTPUT);
  pinMode(41, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
}


const byte dp[10] = {
  0b1000000, // 0
  0b1111001, // 1
  0b0100100, // 2
  0b0110000, // 3
  0b0011001, // 4
  0b0010010, // 5
  0b0000010, // 6
  0b1111000, // 7
  0b0000000, // 8
  0b0011000  // 9
};


const int segmentPins[7] = {2, 4, 5, 18, 19, 21, 20};

void loop() {

  for (int mil = 0; mil <6; mil++){
    for (int centenas = 0; centenas < 10; centenas++){
      for (int decenas = 0; decenas < 6; decenas++) {
        for (int unidades = 0; unidades < 10; unidades++) {
          // Multiplexar cada número 30 veces rápido para evitar parpadeo
          for (int i = 0; i < 8; i++) { 

            
            digitalWrite(42, LOW); // Activar unidades
            digitalWrite(41, LOW);
            digitalWrite(13, LOW);
            digitalWrite(12, HIGH);
            mostrarNumero(dp[unidades]);
            delay(5); 

            
            digitalWrite(42, LOW);
            digitalWrite(41, LOW); // Activar decenas
            digitalWrite(13, HIGH);
            digitalWrite(12, LOW);
            mostrarNumero(dp[decenas]);
            delay(5);

            digitalWrite(42, LOW);
            digitalWrite(41, HIGH); // Activar decenas
            digitalWrite(13, LOW);
            digitalWrite(12, LOW);
            mostrarNumero(dp[centenas]);
            delay(5);

            digitalWrite(42, HIGH);
            digitalWrite(41, LOW); // Activar decenas
            digitalWrite(13, LOW);
            digitalWrite(12, LOW);
            mostrarNumero(dp[mil]);
            delay(5);

          }
        }//for unidades
      }//for decenas
    }//for centenas
  }//for mil
}

// Función para activar los segmentos correctos según el número
void mostrarNumero(byte number) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], (number >> i) & 0x01);
    }
}