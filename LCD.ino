#include <LiquidCrystal.h>//VIVLIOTHIKES
#include <Keypad.h>
//ANTWNHS TSIGGERHS 2026

const int rs =13,en=12,d4=8,d5=9,d6=10,d7=11;//CONNECTIONS
int cursor=0,digit1=0,digit2=-1,num=0;//VARIABLES
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);//LCD

const byte ROWS = 4;//GIA TO KEYPAD
const byte COLS = 3;
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {7, 6, 5, 4}; 
byte colPins[COLS] = {3, 2, 1};

Keypad customkeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);//KEYPAD

void setup() {      //EMFANISI ONOMATOS MIA FORA
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("2026 TSIGGERHS");
}

void loop(){//EISAGWGH DIPSIFIOY ARITHMOU KAI YPOLOGISMOS TOY TETRAGWNOY  ME ELEGXO 
  char key = customkeypad.getKey();
  if (key >= '0' && key <= '9'&& cursor<=1) { //ELEGXOS AN EINAI ARITHMOS  
    lcd.setCursor(cursor, 1);   
    lcd.print(key);
    if(cursor == 0){
      digit1 = key - '0';           //APOTHIKEUSI PRWTOY PSIFIOY
    }else if(cursor == 1){
      digit2 = key - '0'; //APOTHIKEUSI DEYTEROY PSIFIOY
    }
    num = digit1 *10 + digit2;  //YPOLOGISMOS ARITHMOU
    if(digit2 != -1){
    lcd.setCursor(6,1);
    lcd.print(num*num);    //EKTYPWSH TETRAGWNOY DIPSIFIOY ARITHMOU
    }
    cursor++;
  }
  else if(key >= '0' && key <= '9' && cursor == 2){   //EISAGWGH ALLOY DIPSIFIOY ARITHMOU
    cursor=0;
    lcd.setCursor(cursor, 1); 
    lcd.print("            ");//DIAGRAFH DEYTERHS SEIRAS 
    lcd.setCursor(cursor,1);
    lcd.print(key);
    digit1 = key - '0';
    digit2=-1;
    cursor++;          
  }

}