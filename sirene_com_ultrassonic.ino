// ALARME COM ARDUINO E SENSOR ULTRASSONICO
 
#define trigPin 7 // Declara constante trigPin
#define echoPin 8 // Declara constante como echoPin
#define tempo 10 // Declara constante de tempo
 
int frequencia = 0; // Inicializa variável de frequência em 0
int Buzzer = 13; // Inicializa buzzer no pino 13
int duration, distance; // Inicializa variável de distância e tempo
 
void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(Buzzer, OUTPUT);
 pinMode(11, HIGH);
 pinMode(5, HIGH); 
}
 
void loop() {
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance = (duration / 2) / 29.1; // Define base do cálculo de conversão
 
 if (distance >= 40 || distance <= 0) { // Define as distâncias bases de verificação
 Serial.println("Cesta protegida");
 digitalWrite(Buzzer, LOW);
 }
 
 else {
 Serial.println("Pessoa Detectada");
 Serial.print("Distância= ");
 Serial.print(distance); // Imprime o valor da distância no Monitor Serial
 
 for (frequencia = 150; frequencia < 1800; frequencia += 1) { // Tone que produz sirene de polícia
 tone(Buzzer, frequencia, tempo);
 digitalWrite(11, HIGH);
 digitalWrite(5, HIGH);
 delay(3);
 }
 for (frequencia = 1800; frequencia > 150; frequencia -= 1) { // Tone que produz sirene de polícia
 tone(Buzzer, frequencia, tempo);
 digitalWrite(11, LOW);
 digitalWrite(5, LOW,);
 delay(3);
 }
 }
}
