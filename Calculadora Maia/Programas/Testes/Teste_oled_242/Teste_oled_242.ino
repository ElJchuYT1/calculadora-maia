#include <Arduino.h>
#include <Wire.h>
#include <U8x8lib.h> // Usamos U8x8 de U8g2 (Cero consumo de memoria RAM)

/* Configuración del Display OLED SSD1309 (128x64) I2C */
U8X8_SSD1309_128X64_NONAME0_HW_I2C display(/* reset=*/ U8X8_PIN_NONE);

void begintela(){
  display.clear();
  display.setFont(u8x8_font_pressstart2p_r); // Fuente pequeña nativa para texto
}

void setup() {
  display.begin();
  display.setPowerSave(0); 
  begintela();
}

void loop() {
  display.setCursor(0, 1);
  display.print(F("Calculadora Maia"));
  delay(1000);

  display.clear();
  
  display.setCursor(0, 1);
  display.print(F("XDDDD"));
  delay(1000);

  display.clear();
}
