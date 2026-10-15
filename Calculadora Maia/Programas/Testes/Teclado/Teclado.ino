#include <Keypad.h>

// Define o número de linhas e colunas do teclado
const byte LINHAS = 4;
const byte COLUNAS = 4;

// Mapeia as teclas do teclado 0.6.9
char matrizTeclas[LINHAS][COLUNAS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Pinos das linhas conectados no Arduino 0.6.6
byte pinoLinhas[LINHAS] = {9, 8, 7, 6}; 

// Pinos das colunas conectados no Arduino 0.6.6
byte pinoColunas[COLUNAS] = {5, 4, 3, 2}; 

// Inicializa o teclado 0.6.6
Keypad teclado = Keypad(makeKeymap(matrizTeclas), pinoLinhas, pinoColunas, LINHAS, COLUNAS);

void setup() {
  Serial.begin(9600); // Inicia a comunicação serial 0.6.3
}

void loop() {
  char teclaPressionada = teclado.getKey(); // Lê a tecla pressionada 0.6.8
  
  if (teclaPressionada) {
    Serial.print("Tecla: ");
    Serial.println(teclaPressionada); // Mostra no monitor serial 0.6.3
  }
}
