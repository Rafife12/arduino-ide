#include <LiquidCrystal.h>

// Pinos do LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Pino do sensor de temperatura LM35
const int pinoLM35 = A0;

void setup() {
  lcd.begin(16, 2); // Inicia LCD 16x2
  lcd.print("Monitor Temp");
  delay(2000);
  lcd.clear();
}

void loop() {
  int leitura = analogRead(pinoLM35);

  // Conversão para Celsius (LM35 = 10mV/°C, resolução ADC = 5V/1024 = ~4.88mV)
  float temperaturaC = (leitura * 5.0 * 100.0) / 1024.0;

  lcd.setCursor(0, 0);
  lcd.print("Temperatura:");

  lcd.setCursor(0, 1);
  lcd.print(temperaturaC);
  lcd.print(" ");
  lcd.write(byte(223)); // símbolo de grau
  lcd.print("C");

  delay(1000); // Atualiza a cada 1 segundo
}
