#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h> // Biblioteca da Adafruit para displays 1.3"
#include <stdio.h>

/* Configurações do Display */
#define i2c_Address 0x3C // Endereço I2C padrão (tente 0x3d se a tela não ligar)
#define SCREEN_WIDTH 128 // Largura em pixels
#define SCREEN_HEIGHT 64 // Altura em pixels
#define OLED_RESET -1    // Pino de reset (-1 indica que não estamos usando)
#define GMT_CORRELATION 584283L

// Cria o objeto do display
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const char* haab[] = {"Pop","Wo","Sip","Sotz'","Sek","Xul","Yaxk'in","Mol","Ch'en","Yax","Sak","Keh","Mak","K'ank'in","Muwan","Pax","K'ayab","Kumk'u","Wayeb"};
const char* tzolkin[] = {"Imix","Ik","Akbal","Kan","Chicchan","Cimi","Manik","Lamat","Muluc","Oc","Chuen","Eb","Ben","Ix","Men","Cib","Caban","Etznab","Cauac","Ahau"};
int opcion;

long gregorian_to_julian(int d, int m, int y) {
    if (m <= 2) { y--; m += 12; }
    long a = y / 100;
    long b = a / 4;
    return (2 - a + b) + d + (1461L * (y + 4716) / 4) + (306001L * (m + 1) / 10000) - 1524;
}

void julian_to_gregorian(long jd, int *d, int *m, int *y) {
    long l = jd + 68569, n = (4 * l) / 146097;
    l -= (146097 * n + 3) / 4;
    long i = (4000 * (l + 1)) / 1461001;
    l = l - (1461 * i) / 4 + 31;
    long j = (80 * l) / 2447;
    *d = l - (2447 * j) / 80;
    *m = j + 2 - (12 * (j / 11));
    *y = 100 * (n - 49) + i + (j / 11);
}

void print_maya_info(long jd, long maya_days) {
    int h_days = (maya_days + 348) % 365;
    int t_days = (maya_days + 159) % 260;

    printf("\n[Resultado]\n");
    printf("Dia Juliano (JD): %ld\nTotal de Dias Maya: %ld\n", jd, maya_days);
    printf("Cuenta Larga: %ld.%ld.%ld.%ld.%ld\n", 
            maya_days / 144000L, (maya_days % 144000L) / 7200L, 
            (maya_days % 7200L) / 360L, (maya_days % 360L) / 20L, maya_days % 20L);
    printf("Dia Haab: %03d | Haab: %d %s\n", h_days, h_days % 20, haab[h_days / 20]);
    printf("Dia Tzolkin: %03d | Tzolk'in: %d %s\n", t_days + 1, (t_days % 13) + 1, tzolkin[t_days % 20]);
}

void convertir_gregorian_a_maya() {
    int d, m, y;
    printf("\n--- Gregoriano a Cuenta Larga Maya ---\nIngrese fecha (Dia Mes Ano): ");
    if (scanf("%d %d %d", &d, &m, &y) != 3) return;

    long jd = gregorian_to_julian(d, m, y);
    long maya_days = jd - GMT_CORRELATION;

    if (maya_days < 0) {
        printf("Error: Fecha anterior a la creacion Maya (11/08/-3114).\n");
        return;
    }
    print_maya_info(jd, maya_days);
}

void convertir_maya_a_gregorian() {
    long b, k, t, u, kin;
    int d, m, y;
    printf("\n--- Cuenta Larga Maya a Gregoriano ---\nIngrese fecha (Baktun Katun Tun Uinal Kin): ");
    if (scanf("%ld %ld %ld %ld %ld", &b, &k, &t, &u, &kin) != 5) return;

    long maya_days = (b * 144000L) + (k * 7200L) + (t * 360L) + (u * 20L) + kin;
    long jd = maya_days + GMT_CORRELATION;
    
    julian_to_gregorian(jd, &d, &m, &y);
    printf("\nFecha Gregoriana: %02d/%02d/%d", d, m, y);
    print_maya_info(jd, maya_days);
}

void begintela(){
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(15, 1);           
  display.println("Calculadora Maia");
  display.display();

  display.setCursor(1, 5);     
  display.println("1. Gregoriano - 2. Maya");
  display.display();
}

void clearSerialBuffer() {
    while (Serial.available() > 0) { Serial.read(); }
}

void setup() {
  Serial.begin(9600);

  // Inicia a comunicação com o display
  if (!display.begin(i2c_Address, true)) {
    Serial.println("Falha ao encontrar o display OLED!");
    while (1); // Trava o código aqui se o display não for encontrado
  }

  // 1. Limpa o buffer de memória (remove qualquer logo da Adafruit)
  display.clearDisplay();

  // 2. Configura a aparência do texto
  display.setTextSize(2);             // Tamanho da fonte (1 é pequeno, 2 é médio)
  display.setTextColor(SH110X_WHITE); // Cor do texto
  
  // 3. Posiciona o cursor (X, Y)
  display.setCursor(5, 25);           

  // 4. Escreve a mensagem na memória
  display.println("Ola mundo");

  // 5. Envia o que está na memória para a tela física
  display.display();
}

void loop() {
  begintela();

  if (Serial.available() > 0) {
    int op = Serial.read();
    if (op == '1') convertir_gregorian_a_maya();
    else if (op == '2') convertir_maya_a_gregorian();
    else if (op != '\n' && op != '\r') {
        Serial.println(F("Opcao nao valida. Digite 1 ou 2."));
        }
        
    // Limpa o buffer para não ler dados residuais de "Enter"
    delay(50);
    clearSerialBuffer();
    }
}
