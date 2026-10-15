const int PINO_TECLADO = A0;

struct TeclaMapeada {
  int valorMin;
  int valorMax;
  char tecla;
};

// Mapeamento das 16 teclas baseado na combinação dos resistores (1k / 4.7k / 10k)
TeclaMapeada tabela[] = {
  {1023, 950, '1'}, {850,  821,  '2'}, {710,  680,  '3'}, {410,  380,  'A'},
  {920,  880,  '4'}, {750,  700,  '5'}, {590,  550,  '6'}, {180,  150,  'B'},
  {820,  790,  '7'}, {670,  630,  '8'}, {500,  460,  '9'}, {108,  100,  'C'},
  {220,  244,  '*'}, {150,  180,  '0'}, {115,  140,  '#'}, {110,  115,  'D'}
};

const int TOTAL_TECLAS = sizeof(tabela) / sizeof(tabela[0]);

char lerTeclado() {
  int leitura = analogRead(PINO_TECLADO);
  
  // Nenhuma tecla pressionada (leitura próxima de zero)
  if (leitura < 1) return '\0';

   // Exibe a leitura continuamente no monitor serial
  Serial.print("Valor lido no A0: ");
  Serial.println(leitura);
  
  for (int i = 0; i < TOTAL_TECLAS; i++) {
    if (leitura >= tabela[i].valorMin && leitura <= tabela[i].valorMax) {
      return tabela[i].tecla;
    }
  }

  
  return '\0';
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  char tecla = lerTeclado();
  
  if (tecla != '\0') {
    Serial.print("Tecla pressionada: ");
    Serial.println(tecla);
    delay(500); // Debounce simples para evitar leituras duplas
  }
  delay(500);
}