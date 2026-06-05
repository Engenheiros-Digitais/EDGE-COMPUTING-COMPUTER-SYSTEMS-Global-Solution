#define LED_AZUL     13
#define LED_VERDE    12
#define LED_VERMELHO 11
#define BUZZER        8
#define TMP_PIN      A1
#define POT_PIN      A0

int calcularScore(float temp, int seca) {
  int score = 0;

  if (temp >= 40) score += 3;
  else if (temp >= 35) score += 2;
  else if (temp >= 30) score += 1;

  if (seca >= 8) score += 3;
  else if (seca >= 5) score += 2;
  else if (seca >= 3) score += 1;

  return score;
}

void setup() {
  Serial.begin(9600);
  pinMode(LED_AZUL, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(LED_AZUL, HIGH);
  delay(1000);
  digitalWrite(LED_AZUL, LOW);
  digitalWrite(LED_VERDE, HIGH);
  delay(1000);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_VERMELHO, HIGH);
  delay(1000);
  digitalWrite(LED_VERMELHO, LOW);

  Serial.println("FireWatch iniciado.");
}

void loop() {
  int leitura = analogRead(TMP_PIN);
  float tensao = leitura * (5.0 / 1023.0);
  float temp = (tensao - 0.5) * 100.0;

  int potValor = analogRead(POT_PIN);
  int seca = map(potValor, 0, 1023, 0, 10);

  int score = calcularScore(temp, seca);

  digitalWrite(LED_AZUL, LOW);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_VERMELHO, LOW);
  noTone(BUZZER);

  if (score >= 6) {
    digitalWrite(LED_VERMELHO, HIGH);
    tone(BUZZER, 1000);
    Serial.println("NIVEL: CRITICO");
  } else if (score >= 4) {
    digitalWrite(LED_VERDE, HIGH);
    Serial.println("NIVEL: MODERADO");
  } else {
    digitalWrite(LED_AZUL, HIGH);
    Serial.println("NIVEL: CONTROLADO");
  }

  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print("C | Seca: ");
  Serial.print(seca);
  Serial.print("/10 | Score: ");
  Serial.println(score);

  delay(2000);
}
