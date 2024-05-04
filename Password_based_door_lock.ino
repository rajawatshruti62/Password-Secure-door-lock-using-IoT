#include <Keypad.h>
#include <EEPROM.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#define m1a 10
#define m1b 11
#define buzzer 12
#define led 13

const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8,7 ,6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
char key = "";
String input = "";
String password = "74B56";
int cnt = 0;
int rowCnt = 0;


void setup() {
  delay(500);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  Serial.println("\nPassword door opener");
  delay(1000);
  lcd.begin(16,2);
  lcd.clear();
  lcd.home();
  lcd.print(" Enter Password");
  pinMode(m1a,OUTPUT);
  pinMode(m1b,OUTPUT);
  digitalWrite(m1a,LOW);
  digitalWrite(m1b,HIGH);
  pinMode(buzzer,OUTPUT);
  digitalWrite(buzzer,LOW);
  delay(1500);
  digitalWrite(m1b,LOW);
  
  rowCnt = 0;
}

void loop(){

    key = customKeypad.getKey();
      if (key){
        Serial.print("Pressed:");
        Serial.println(key);
        digitalWrite(led,HIGH);
        switch (key){
          
          case '1':
          input += '1';
          cnt++;
          lcd.setCursor(rowCnt,1);
          lcd.print("*");
          rowCnt++;
          break;
          
          case '2':
          input += '2';
          cnt++;
          lcd.setCursor(rowCnt,1);
          lcd.print("*");
          rowCnt++;
          break;

          case '3':
          input += '3';
          cnt++;
          lcd.setCursor(rowCnt,1);
          lcd.print("*");
          rowCnt++;
          break;

          case '4':
          input += '4';
          cnt++;
          lcd.setCursor(rowCnt,1);
          lcd.print("*");
          rowCnt++;
          break;

          case '5':
          input += '5';
          cnt++;
          lcd.setCursor(rowCnt,1);
          lcd.print("*");
          rowCnt++;
          break;

          case '6':
          input += '6';
          cnt++;
          lcd.setCursor(rowCnt,1);
          lcd.print("*");
          rowCnt++;
          break;

          case '7':
          input += '7';
          cnt++;
          lcd.setCursor(rowCnt,1);
          lcd.print("*");
          rowCnt++;
          break;

          case '8':
          input += '8';
          cnt++;
          lcd.setCursor(rowCnt,1);
          lcd.print("*");
          rowCnt++;
          break;

          case '9':
          input += '9';
          cnt++;
          lcd.setCursor(rowCnt,1);
          lcd.print("*");
          rowCnt++;
          break;

          case 'A':
          input += 'A';
          cnt++;
          lcd.setCursor(rowCnt,1);
          lcd.print("*");
          rowCnt++;
          break;

          case 'B':
          input += 'B';
          cnt++;
          lcd.setCursor(rowCnt,1);
          lcd.print("*");
          rowCnt++;
          break;

          case 'C':
          input += 'C';
          cnt++;
          lcd.setCursor(rowCnt,1);
          lcd.print("*");
          rowCnt++;
          break;

          case 'D':
          input += 'D';
          cnt++;
          lcd.setCursor(rowCnt,1);
          lcd.print("*");
          rowCnt++;
          break;


        }
        delay(50);
        digitalWrite(led,LOW);
      }

      if (cnt >= 5){
        if (input == password){
          Serial.println("matched");
          input = "";
          cnt = 0;
          rowCnt = 0;
          lcd.setCursor(0,1);
          lcd.print("Password Ok     ");
          openCloseDoor();
     }else{
          digitalWrite(buzzer,HIGH);
          input = "";
          cnt = 0;
          Serial.println("Not matched");
          digitalWrite(led,HIGH);
          lcd.setCursor(0,1);
          lcd.print("Wrong Password");
          delay(2000);
          digitalWrite(buzzer,LOW);
          
          rowCnt = 0;
          digitalWrite(led,LOW);
          lcd.setCursor(0,1);
          lcd.print("                ");
          
        }
      }
    delay(200);
     

    

  

    
}

void openCloseDoor(){
  Serial.println("Door Opening");
  digitalWrite(m1a,HIGH);
  delay(1500);
  digitalWrite(m1a ,LOW);
  delay(5000);
  Serial.println("Door Closing");
  digitalWrite(m1b,HIGH);
  delay(1500);
  digitalWrite(m1b,LOW);
  lcd.setCursor(0,1);
  lcd.print("                ");
  
  
}