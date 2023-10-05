#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int seconds = 0;

boolean manzanas = false, polvos = false, hiervas = false, inicio = false;

float CDT;
int temp;
int segundos;

int r,CDT_T;

int tiempoAnterior = 0; // Almacena el tiempo anterior
int intervalo = 1000;   // Intervalo de 1 segundo en milisegundos
int contadorSegundos = 0; // Contador de segundos

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2); // Set up the number of columns and rows on the LCD.
  
  pinMode(6, INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(10,INPUT);
  pinMode(13,INPUT);
  
  pinMode(9,OUTPUT);
  
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}






void loop(){
  segundos = map(analogRead(A1),0,1023,0,18000);
  float horas = segundos / 3600; // 3600 segundos en una hora
  float minutos = 0.01*(segundos % 3600) / 60; // El residuo dividido por 60 segundos en un minuto
  
  temp = map(analogRead(A0),0,1023,29,120);

  //Inicio del inicio
  if(digitalRead(10) == LOW){
    inicio = true;
  }
  if(inicio == true){
    lcd.clear();
    lcd.print("Temp manual celsius");
  	lcd.setCursor(0, 1);
    lcd.print(temp);
    r=map(analogRead(A0),0,1023,0,255);
  	CDT_T=map(r,0,255,15,61.71);
    analogWrite(9, CDT_T);
    
    delay(1000);
    
    lcd.clear();
    lcd.print("Horas manual");
  	lcd.setCursor(0, 1);
    lcd.print(horas + minutos);
    int tiempoActual = millis(); // Obtiene el tiempo actual

    if (tiempoActual - tiempoAnterior >= intervalo) {
      // Si ha pasado 1 segundo o más
      contadorSegundos++; // Incrementa el contador de segundos
      tiempoAnterior = tiempoActual; // Actualiza el tiempo anterior

      // Puedes hacer algo cada segundo aquí
      Serial.print("Segundos transcurridos: ");
      Serial.println(contadorSegundos);
    }
    if(contadorSegundos==segundos){
      inicio = false;
    }
    delay(1000);

  }
  //
  //
  //
  //  
  //Inicio modo manzanas
  if (digitalRead(6) == LOW){
    seconds = 0;
    CDT = 37.74;
    manzanas = true;
    inicio = false;
    polvos = false;
    hiervas = false;
    lcd.clear();
  }
  if (manzanas == true){
    lcd.clear();
    inicio = false;
    polvos = false;
    hiervas = false;
    CDT = 37.74;

    analogWrite(9, CDT); //740 milivolts 
    lcd.setCursor(1, 0);
    lcd.print("Manzanas 74°C");

    lcd.setCursor(0,1);
    lcd.print(seconds);
    seconds += 1;   
    if(seconds == 3600){
      manzanas = false;    
    }
    delay(1200);
  }           
  //Fin modo manzanas      
  //
  //
  //
  //  
  //Modo polvos
  if (digitalRead(7) == LOW){
    seconds = 0;
    CDT = 61.71;
    polvos = true;
    inicio = false;
    manzanas = false;
    hiervas = false;
    lcd.clear();
  }
  if (polvos == true){
    lcd.clear();
    inicio = false;
    manzanas = false;
    hiervas = false;
    CDT = 61.71;
    

    analogWrite(9, CDT); //1.21 volts 
    lcd.setCursor(1, 0);
    lcd.print("Polvos 121°C");

    lcd.setCursor(0,1);
    lcd.print(seconds);
    delay(1200);
    seconds += 1;
    if(seconds == 1200){
      polvos = false;
    }
  }
  //Fin modo polvos
  //
  //
  //
  //  
  //Inicio modo hiervas
  if(digitalRead(8) == LOW){
    seconds = 0;
    CDT = 20.4;
    inicio = false;
    polvos = false;
    manzanas = false;
    hiervas = true;
    lcd.clear();
  }
  if (hiervas == true){
    lcd.clear();
    manzanas = false;
    inicio = false;
    polvos = false;
    CDT = 20.4;

    analogWrite(9, CDT); //4 milivolts 
    lcd.setCursor(1, 0);
    lcd.print("Hierbas 40°C");

    lcd.setCursor(0,1);
    lcd.print(seconds);
    delay(1200);
    seconds +=1;
    if(seconds == 14400){
      hiervas = false;
    }
    
  }
  //Fin modo hiervas
  //
  //
  //
  //
  //

  
  if(analogRead(A0) != 0){
    lcd.clear();
    
  }
  
  if(digitalRead(13) == LOW){
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Detenido en:");
    lcd.setCursor(0,1);
    lcd.print(seconds);
    analogWrite(9, 0);
    delay(5000);
    inicio = false;
  }
}//Endung


























