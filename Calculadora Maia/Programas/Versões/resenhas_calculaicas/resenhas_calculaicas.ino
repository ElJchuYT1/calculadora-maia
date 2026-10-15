#include <Arduino.h>
#include <Wire.h>
#include <U8x8lib.h> // Usamos U8x8 de U8g2 (Cero consumo de memoria RAM)
#include <avr/pgmspace.h>
#include <Keypad.h>

/* Configuración del Display OLED SH1109 (128x64) I2C */
U8X8_SSD1309_128X64_NONAME0_HW_I2C display(/* reset=*/ U8X8_PIN_NONE);

/* teclado config */

//const byte LINHAS = 4;
//const byte COLUNAS = 4; [linhas][colunas]
char letras[4][4] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte pinoLinhas[4] = {9, 8, 7, 6}; 
byte pinoColunas[4] = {5, 4, 3, 2}; 

Keypad teclado = Keypad(makeKeymap(letras), pinoLinhas, pinoColunas, 4, 4);



/* maya parametros */
#define GMT_CORRELATION 584283L

const char h0[] PROGMEM = "Pop";     const char h10[] PROGMEM = "Sak";
const char h1[] PROGMEM = "Wo";      const char h11[] PROGMEM = "Keh";
const char h2[] PROGMEM = "Sip";     const char h12[] PROGMEM = "Mak";
const char h3[] PROGMEM = "Sotz'";   const char h13[] PROGMEM = "K'ank'in";
const char h4[] PROGMEM = "Sek";     const char h14[] PROGMEM = "Muwan";
const char h5[] PROGMEM = "Xul";     const char h15[] PROGMEM = "Pax";
const char h6[] PROGMEM = "Yaxk'in"; const char h16[] PROGMEM = "K'ayab";
const char h7[] PROGMEM = "Mol";     const char h17[] PROGMEM = "Kumk'u";
const char h8[] PROGMEM = "Ch'en";   const char h18[] PROGMEM = "Wayeb";
const char h9[] PROGMEM = "Yax";

const char* const haab[] PROGMEM = {h0,h1,h2,h3,h4,h5,h6,h7,h8,h9,h10,h11,h12,h13,h14,h15,h16,h17,h18};

const char t0[] PROGMEM = "Imix";      const char t10[] PROGMEM = "Chuen";
const char t1[] PROGMEM = "Ik";        const char t11[] PROGMEM = "Eb";
const char t2[] PROGMEM = "Akbal";     const char t12[] PROGMEM = "Ben";
const char t3[] PROGMEM = "Kan";       const char t13[] PROGMEM = "Ix";
const char t4[] PROGMEM = "Chicchan";  const char t14[] PROGMEM = "Men";
const char t5[] PROGMEM = "Cimi";      const char t15[] PROGMEM = "Cib";
const char t6[] PROGMEM = "Manik";     const char t16[] PROGMEM = "Caban";
const char t7[] PROGMEM = "Lamat";     const char t17[] PROGMEM = "Etznab";
const char t8[] PROGMEM = "Muluc";     const char t18[] PROGMEM = "Cauac";
const char t9[] PROGMEM = "Oc";        const char t19[] PROGMEM = "Ahau";

const char* const tzolkin[] PROGMEM = {t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19};



/*calculos*/
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

//corregir
void print_maya_info(long jd, long maya_days) {
    int h_days = (maya_days + 348) % 365;
    int t_days = (maya_days + 159) % 260;

    long baktun = maya_days / 144000L;
    long katun = (maya_days % 144000L) / 7200L;
    long tun = (maya_days % 7200L) / 360L;
    long uinal = (maya_days % 360L) / 20L;
    long kin = maya_days % 20L;

    // Buffer para leer las palabras desde PROGMEM a la RAM dinámicamente
    char buffer_haab[15];
    char buffer_tzolkin[15];
    strcpy_P(buffer_haab, (char*)pgm_read_ptr(&(haab[h_days / 20])));
    strcpy_P(buffer_tzolkin, (char*)pgm_read_ptr(&(tzolkin[t_days % 20])));

    // --- IMPRESIÓN EN MONITOR SERIE ---
    Serial.println(F("\n[Resultado]"));
    Serial.print(F("Dia Juliano (JD): ")); Serial.println(jd);
    Serial.print(F("Total de Dias Maya: ")); Serial.println(maya_days);
    
    Serial.print(F("Cuenta Larga: "));
    Serial.print(baktun); Serial.print("."); Serial.print(katun); Serial.print(".");
    Serial.print(tun); Serial.print("."); Serial.print(uinal); Serial.print(".");
    Serial.println(kin);
    
    Serial.print(F("Dia Haab: ")); Serial.print(h_days);
    Serial.print(F(" | Haab: ")); Serial.print(h_days % 20); Serial.print(F(" ")); Serial.println(buffer_haab);
    
    Serial.print(F("Dia Tzolkin: ")); Serial.print(t_days + 1);
    Serial.print(F(" | Tzolk'in: ")); Serial.print((t_days % 13) + 1); Serial.print(F(" ")); Serial.println(buffer_tzolkin);



    // --- IMPRESIÓN EN PANTALLA OLED (U8X8) ---
    display.clear(); // Limpia la pantalla rápido sin memoria
    
    display.setCursor(0, 0);
    display.print(baktun); display.print("."); display.print(katun); display.print(".");
    display.print(tun); display.print("."); display.print(uinal); display.print("."); display.print(kin);

    display.setCursor(0, 2);
    display.print(F("Haab: ")); display.print(h_days % 20); 
    display.setCursor(0, 3);
    display.print(buffer_haab);

    display.setCursor(0, 5);
    display.print(F("Tzolkin: ")); display.print((t_days % 13) + 1);
    display.setCursor(0, 6);
    display.print(buffer_tzolkin);
}

/*opções de conversão*/
void convertir_gregorian_a_maya() {
    Serial.println(F("\n--- Gregoriano a Cuenta Larga Maya ---"));
    Serial.println(F("Ingrese fecha: Dia, luego Mes, luego Ano (Use espacio o Enter): "));
    
    while(Serial.available() == 0); int d = Serial.parseInt();
    while(Serial.available() == 0); int m = Serial.parseInt();
    while(Serial.available() == 0); int y = Serial.parseInt();

    long jd = gregorian_to_julian(d, m, y);
    long maya_days = jd - GMT_CORRELATION;

    if (maya_days < 0) {
        Serial.println(F("Error: Fecha anterior a la creacion Maya (11/08/-3114)."));
        display.clear();
        display.setCursor(0,2);
        display.print(F("Error: Fecha"));
        display.setCursor(0,3);
        display.print(F("pre-creacion."));
        return;
    }
    print_maya_info(jd, maya_days);
}

void convertir_maya_a_gregorian() {
    int d, m, y;
    Serial.println(F("\n--- Cuenta Larga Maya a Gregoriano ---"));
    Serial.println(F("Ingrese fecha (Baktun Katun Tun Uinal Kin): "));
    
    while(Serial.available() == 0); long b = Serial.parseInt();
    while(Serial.available() == 0); long k = Serial.parseInt();
    while(Serial.available() == 0); long t = Serial.parseInt();
    while(Serial.available() == 0); long u = Serial.parseInt();
    while(Serial.available() == 0); long kin = Serial.parseInt();

    long maya_days = (b * 144000L) + (k * 7200L) + (t * 360L) + (u * 20L) + kin;
    long jd = maya_days + GMT_CORRELATION;
    
    julian_to_gregorian(jd, &d, &m, &y);
    
    Serial.print(F("\nFecha Gregoriana: "));
    Serial.print(d); Serial.print("/"); Serial.print(m); Serial.print("/"); Serial.println(y);
    
    print_maya_info(jd, maya_days);
    
    // Imprimimos el resultado gregoriano al final de la pantalla OLED
    display.setCursor(0, 7); // Última línea
    display.print(d); display.print("/"); display.print(m); display.print("/"); display.print(y);
}

/*tela*/
void begintela(){
  display.clear();
  display.setFont(u8x8_font_pressstart2p_r); // Fuente pequeña nativa para texto
  display.setCursor(0, 1);
  display.print(F("Calculadora Maia"));
  
  display.setCursor(0, 4);
  display.print(F("1. Greg -> Maya"));
  display.setCursor(0, 5);
  display.print(F("2. Maya -> Greg"));

  Serial.print(F("Seleccione (1 o 2 en el Serial): "));
}

void setup() {
  Serial.begin(9600);

  // Inicia la comunicación de la pantalla con U8g2 (U8x8 text-mode)
  display.begin();
  display.setPowerSave(0); 

  begintela();
}

void loop() {
  char teclaPressionada = teclado.getKey();
  
  if (Serial.available() > 0) {
    int op = Serial.parseInt();
    
    if (op == 1) {
      convertir_gregorian_a_maya();
      delay(15000); // Pausa para que el usuario lea la pantalla
      begintela();
    } 
    else if (op == 2) {
      convertir_maya_a_gregorian();
      delay(15000);
      begintela();
    }
    else {
      // Evita lectura de "Enter" o basura en el buffer
      while(Serial.available() > 0) Serial.read(); 
    }
  }
  delay(50);
}