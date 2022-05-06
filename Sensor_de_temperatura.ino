int pinodosensor = 0 ; // Declarando o Pino do Sensor
int valorlido = 0; // Declarando uma Variavel do Sensor  
float temperatura = 0;// Declarando uma Variavel para Temperatura

void setup() {
  Serial.begin(9600);// Ativando o Serial Monitor

}

void loop() {
// temperatura = (valorlido * (5/1023 - voltetagem da porta de energia
dividido pelo valor maximo da porta de energia) * 100)
//temperatura = (0.004887 * valorlido)

  valorlido= analogRead(pinodosensor); // Ativando e Lendo o Valor do Sensor
  temperatura = (valorlido * 0.00488); // Calculando a primeira equação
  temperatura = temperatura * 100;// Calculando a Segunda Equação
  Serial.println(temperatura);// Mostrando no Serial Monitor
  delay(1000);

}
