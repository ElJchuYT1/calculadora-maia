//bibliotecas-----------------------------------------------------------

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Stepper.h>

//variables-------------------------------------------------------------

// Pinagem dos sensores Infravermelhos (Saida Digital)
const int PIN_SENSOR_IMIX = 2; // Sensor da engranagem de 20 dentes
const int PIN_SENSOR_NUM1 = 5; // Sensor da engranagem de 13 dentes

// Botões de controle
const int avancar = 3;
const int calibrar = 4;

// Nomes dos 20 días do Tzolkin Maya
const char* nombresMaya[20] = {
  "Imix", "Ik'", "Ak'b'al", "K'an", "Chikchan", "Cimi", "Manik'", "Lamat", "Muluk", "Ok", "Chuwen", "Eb'", "B'en", "Ix", "Men", "K'ib'", "Kab'an", "Etz'nab'", "Kawak", "Ajaw"};

//variáveis de calculo dos dias
int numeroTzolkin = 1;     // Cuenta de 1 a 13
int indexNombreMaya = 0;   // Índice de 0 a 19 (0 = Imix)
long pasosAcumuladosUltimoDia = 0;

//configuração dos instrumentos----------------------------------------------------------

//configuração e declaração do Stepper
const int passoXvolta = 2048; 
Stepper motorTzolkin(passoXvolta, 8, 10, 9, 11);

//definição do LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

//setup----------------------------------------------------------------------------------

void setup() {
  //definição da pinagem
  pinMode(PIN_SENSOR_IMIX, INPUT);
  pinMode(PIN_SENSOR_NUM1, INPUT);
  pinMode(avancar, INPUT_PULLUP);
  pinMode(calibrar, INPUT_PULLUP);

  //velocidade do stepper
  motorTzolkin.setSpeed(12);

  //start do LCD
  lcd.init();
  lcd.backlight();
  
  //Calibração completa para "1 Imix"
  calibrarPosicionInicial();
}

//programa principal---------------------------------------------------------------------

void loop() {
  //Avançar 1 dia
  if (digitalRead(avancar) == LOW) {
    incrementarTzolkin();
    moverMotorUnDiente();
    mostrardata();
    apagarBobinasMotor();
    delay(300); //Debounce
  }

  //Recalibrar para 1 imix 
  if (digitalRead(calibrar) == LOW) {
    calibrarPosicionInicial();
    delay(300);
  }
}

//funções---------------------------------------------------------------------------------

void calibrarPosicionInicial() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("TZOLKIN MAYA");
  lcd.setCursor(0, 1);
  lcd.print("Buscando 1 Imix");

  // O motor gira ate que AMBOS sensores detectem os dois referenciais 1 e imix
  // (sensor == LOW ao detectar 1 e imix)
  while (digitalRead(PIN_SENSOR_IMIX) == HIGH || digitalRead(PIN_SENSOR_NUM1) == HIGH) {
    motorTzolkin.step(2); // Avanza en pasos cortos para no pasarse de largo
    delay(2);
  }

  // ao achar 1 e imix, zeramos os dias no codigo
  indexNombreMaya = 0; // 0 = Imix
  numeroTzolkin = 1;   // 1
  pasosAcumuladosUltimoDia = 0;

  //para o motor
  apagarBobinasMotor();
  
  // reset LCD e data 1
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" SINCRO COMPLETA");
  lcd.setCursor(0, 1);
  lcd.print(" FECHA: 1 IMIX  ");
  delay(1500);
  
  //mostrar data
  mostrardata();
}

void moverMotorUnDiente() {
  // Calcula os passos correspondentes a 1 dente (18 graus na engranagem de 20)
  long passodia = ((long)indexNombreMaya * passoXvolta) / 20;
  
  if (indexNombreMaya == 0) {
    passodia = passoXvolta;
  }

  long passosandar = passodia - pasosAcumuladosUltimoDia;
  motorTzolkin.step(passosandar);
  
  pasosAcumuladosUltimoDia = passodia;
  if (indexNombreMaya == 0) {
    pasosAcumuladosUltimoDia = 0;
  }
}

void incrementarTzolkin() {
  // Avance del ciclo numérico (1 a 13)
  numeroTzolkin++;
  if (numeroTzolkin > 13) {
    numeroTzolkin = 1;
  }

  // Avance del ciclo de nombres (0 a 19)
  indexNombreMaya++;
  if (indexNombreMaya >= 20) {
    indexNombreMaya = 0;
  }
}

void mostrardata() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("TZOLKIN MAYA");
  
  lcd.setCursor(0, 1);
  lcd.print(numeroTzolkin);
  lcd.print(" ");
  lcd.print(nombresMaya[indexNombreMaya]);
}

void apagarBobinasMotor() {
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}