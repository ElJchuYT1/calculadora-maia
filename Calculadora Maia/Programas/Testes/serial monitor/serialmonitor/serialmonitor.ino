#include <Wire.h>
#include <LiquidCrystal_I2C.h> //frank de brabander
#include <Stepper.h> //arduino

//variables-------------------------------------------------------------

// Pinagem dos sensores Infravermelhos (Saida Digital)
const int PIN_SENSOR_IMIX = 2; // Sensor da engrenagem de 20 dentes
const int PIN_SENSOR_NUM1 = 5; // Sensor da engrenagem de 13 dentes

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
  // Inicialização do Serial Monitor
  Serial.begin(9600);
  Serial.println(F("========================================"));
  Serial.println(F("   SISTEMA TZOLKIN MAYA INICIALIZADO    "));
  Serial.println(F("========================================"));

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
  //Modo de Busca ao pressionar 'avancar'
  if (digitalRead(avancar) == LOW) {
    Serial.println(F("\n[BOTAO] Botao de busca pressionado."));
    encontrarTzolkin();
    delay(300); //Debounce
  }

  //Recalibrar para 1 imix 
  if (digitalRead(calibrar) == LOW) {
    Serial.println(F("\n[BOTAO] Calibrador pressionado."));
    calibrarPosicionInicial();
    delay(300);

     motorTzolkin.setSpeed(12);
  }
}

//funções---------------------------------------------------------------------------------

void calibrarPosicionInicial() {
  Serial.println(F("\n--- INICIANDO CALIBRACAO ---"));
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("TZOLKIN MAYA");
  lcd.setCursor(0, 1);
  lcd.print("Buscando 1 Imix");

  Serial.println(F("[LCD] L1: TZOLKIN MAYA | L2: Buscando 1 Imix"));

  long passosCalibracao = 0;
  // O motor gira ate que AMBOS sensores detectem os dois referenciais 1 e imix
  // (sensor == LOW ao detectar 1 e imix)
  while (digitalRead(PIN_SENSOR_IMIX) == HIGH || digitalRead(PIN_SENSOR_NUM1) == HIGH) {
    motorTzolkin.step(2); // Avanza en pasos cortos para no pasarse de largo
    passosCalibracao += 2;
    delay(2);
  }

  Serial.print(F("Posicao de referencia encontrada! Passos executados na busca: "));
  Serial.println(passosCalibracao);

  // ao achar 1 e imix, zeramos os dias no codigo
  indexNombreMaya = 0; // 0 = Imix
  numeroTzolkin = 1;   // 1
  pasosAcumuladosUltimoDia = 0;

  //para o motor
  apagarBobinasMotor();
  
  // reset LCD e data 1
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SINCRONIZADO");
  lcd.setCursor(0, 1);
  lcd.print(" FECHA: 1 IMIX  ");
  
  Serial.println(F("[LCD] L1:  SINCRONIA COMPLETA | L2:  FECHA: 1 IMIX  "));
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
  
  Serial.print(F("[STEPPER] Mover dente -> Passos a andar: "));
  Serial.print(passosandar);
  Serial.print(F(" | Passos acumulados no ciclo: "));
  Serial.println(passodia);

  motorTzolkin.step(passosandar);
  
  pasosAcumuladosUltimoDia = passodia;
  if (indexNombreMaya == 0) {
    pasosAcumuladosUltimoDia = 0;
  }
}

void incrementarTzolkin() {
  // Avance o ciclo numérico (1 a 13)
  numeroTzolkin++;
  if (numeroTzolkin > 13) {
    numeroTzolkin = 1;
  }

  // Avance o ciclo de nomes (0 a 19)
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

  // Projeção no Serial do contedo exibido no LCD
  Serial.print(F("[LCD EXIBINDO] L0: \"TZOLKIN MAYA\" | L1: \""));
  Serial.print(numeroTzolkin);
  Serial.print(F(" "));
  Serial.print(nombresMaya[indexNombreMaya]);
  Serial.println(F("\""));
}

void apagarBobinasMotor() {
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}

// ---------------------------------------------------------------------------------
// NOVA FUNÇÃO IMPLEMENTADA
// ---------------------------------------------------------------------------------
void encontrarTzolkin() {
  Serial.println(F("\nDigite o dia e o mes Tzolkin (Ex: 4 K'an):"));

  // Limpa o buffer de qualquer sujeira prévia
  while (Serial.available() > 0) {
    Serial.read();
  }

  // Aguarda até o usuário digitar algo no Serial Monitor
  while (Serial.available() == 0) {
    // Fica em loop travado aguardando o input do Serial Monitor
  }

  // Lê o dado digitado
  String entrada = Serial.readStringUntil('\n');
  entrada.trim(); // Remove espaços antes e depois

  // Isola o numero e o nome através do espaço entre eles
  int espacoIndex = entrada.indexOf(' ');
  if (espacoIndex == -1) {
    Serial.println(F("Formato invalido! Use o formato: Numero Nome. Ex: 4 K'an"));
    return;
  }

  int alvoNumero = entrada.substring(0, espacoIndex).toInt();
  String alvoNome = entrada.substring(espacoIndex + 1);
  alvoNome.trim();

  Serial.print(F("=> Iniciando busca por: "));
  Serial.print(alvoNumero);
  Serial.print(F(" "));
  Serial.println(alvoNome);

  bool encontrado = false;
   motorTzolkin.setSpeed(13);

  // Um ciclo Tzolkin completo possui exatamente 260 dias. 
  // O For percorre os 260 dias possíveis procurando o alvo.
  for (int i = 0; i < 260; i++) {
    // Verifica se o dia atual bate com o alvo digitado
    if (numeroTzolkin == alvoNumero && String(nombresMaya[indexNombreMaya]).equalsIgnoreCase(alvoNome)) {
      encontrado = true;
      break; // Encontrou! Quebra o sistema do for para parar a busca
    }
    
    // Se ainda não encontrou, avança um dia fisicamente
    incrementarTzolkin();
    moverMotorUnDiente();
    mostrardata();
  }

  // Desliga o motor para não aquecer após parar
  apagarBobinasMotor();

  // Resultado Final
  if (encontrado) {
    Serial.println(F("\n========================================"));
    Serial.println(F("        DATA ENCONTRADA COM SUCESSO!    "));
    Serial.print(F("        Ficou travado em: "));
    Serial.print(numeroTzolkin);
    Serial.print(F(" "));
    Serial.println(nombresMaya[indexNombreMaya]);
    Serial.println(F("========================================"));
  } else {
    Serial.println(F("\n[ERRO] Data nao encontrada. Verifique se o nome foi digitado exatamente como na lista."));
  }
}