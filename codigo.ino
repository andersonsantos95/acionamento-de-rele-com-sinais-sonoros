#define pinSom 4
#define pinRele 13
#define tempoMaximoDeUmaPalma  150
#define tempoMaximoEntrePalmas 500

int contaPalmas = 0;
long tempoEspera = 0;
long tempoEsperaEntrePalmas = 0;

void executarAcao();

void setup() {
  pinMode(pinSom, INPUT);
  pinMode(pinRele, OUTPUT);
}

void loop(){
  int sensorSom = digitalRead(pinSom);
  if (sensorSom == LOW) {
     if (tempoEspera == 0) {
        tempoEspera = tempoEsperaEntrePalmas = millis(); 
        contaPalmas++;
     }else if ((millis() - tempoEspera) >= tempoMaximoDeUmaPalma) {
        tempoEspera = 0;
     }
  } if ( (contaPalmas != 0) && ((millis() - tempoEsperaEntrePalmas) > 500) ) {
     comutarRele();
     contaPalmas = 0;
     tempoEsperaEntrePalmas = millis();
  }  
}

void comutarRele(){
      digitalWrite(pinRele, !digitalRead(pinRele));
}
