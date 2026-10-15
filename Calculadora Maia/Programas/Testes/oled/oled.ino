#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

// Definições para o display SH1106 128x64 I2C
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     -1 // Reset pin # (-1 se compartilhar o pino de reset do Arduino)
#define i2c_Address 0x3C // Endereço I2C comum para estes displays (pode ser 0x3D)

Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);

  // Inicializa o display no endereço I2C 0x3C
  if(!display.begin(i2c_Address, true)) {
    Serial.println(F("Falha ao inicializar o display SH1106"));
    for(;;); // Trava o código caso falhe
  }

  // Limpa o buffer da tela
  display.clearDisplay();

  // Configurações de texto
  display.setTextSize(2);          // Tamanho da fonte (1, 2, 3...)
  display.setTextColor(SH110X_WHITE); // Cor do texto (Branco)
  display.setCursor(10, 25);        // Posição inicial (Coluna X, Linha Y)
  
  // Escreve o texto na memória temporária
  display.println(F("Ola Mundo"));

  // Envia para o display físico
  display.display();
}

void loop() {
  // Nada necessário no loop para este exemplo estático
}