#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>

// Declarar la pantalla (para I2C)
#define OLED_RESET -1
Adafruit_SH1106 display(OLED_RESET);

void setup() {
  // Iniciar la comunicación I2C y la pantalla con dirección 0x3C
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);  
  display.clearDisplay(); // Limpiar buffer
  
  // Configurar texto
  display.setTextSize(1);      // Tamaño de letra
  display.setTextColor(WHITE); // Color blanco
  display.setCursor(0, 0);     // Posición X, Y
  display.print("Hola Mundo!");  // Texto a mostrar
  
  display.display(); // Enviar a la pantalla
}

void loop() {
  displayLED.setTextColor(WHITE); //Define a cor das letras, mas no nosso exemplo o display é Azul, então independente da cor que for colocada neste campo as letras ficarão azul. Por padrão deixe WHITE.
  displayLED.setTextSize(1); //Define o tamanho da letra
  displayLED.setCursor(10, 12); //Define o local(Horizontal e vertical), de onde irá aparecer a mensagem no display.
  displayLED.print("Calculadora Maia");//Envia mensagem para o display
  displayLED.display();//Confirma a escrita no display
  
  delay(1500); //Tempo de espera de 1500 milissegundos
  
  displayLED.clearDisplay(); //Limpa a mensagem do display
  displayLED.setCursor(7, 12); //Define um novo local para a próxima mensagem do display
  displayLED.print("Tzolkin Haab Choltun"); //Envia mensagem para o display
  displayLED.display(); //Confirma a escrita no display
  
  delay(1500); //Tempo de espera de 1500 milissegundos
  
  displayLED.clearDisplay(); //Limpa a mensagem do display
}
