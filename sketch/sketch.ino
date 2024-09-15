
#include <LiquidCrystal_I2C.h>
#include <DHT22.h>

#define I2C_ADDR    0x27
#define LCD_COLUMNS 20
#define LCD_LINES   4
#define pinDATA     2  

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);

DHT22 dht22sns(pinDATA);
float T_fix=25;
byte sw = 37;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
lcd.init();
//lcd.begin();
lcd.backlight();
lcd.clear();
pinMode(51, OUTPUT);
pinMode(49, OUTPUT);
pinMode(47, OUTPUT);

pinMode(sw, INPUT_PULLUP);


}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(sw)== LOW){
    
  }
  float temp = dht22sns.getTemperature();
  float h = dht22sns.getHumidity();
  lcd.clear();
lcd.setCursor(0,1);
lcd.print("T: ");

lcd.print(temp);

lcd.setCursor(6,1);
lcd.print(" H ");
lcd.print(h);

if(T_fix<temp){
  digitalWrite(51, LOW);
    digitalWrite(49,HIGH);
    digitalWrite(47,HIGH);
  lcd.setCursor(3,0);
  lcd.print("Over heat");
}
else if(T_fix> temp){
   
    digitalWrite(51, HIGH);
    digitalWrite(49,LOW);
    digitalWrite(47,HIGH);
  
   lcd.setCursor(3,0);
  lcd.print("Cool");
}

else{
   
    digitalWrite(51, HIGH);
    digitalWrite(49,HIGH);
    digitalWrite(47,LOW);
  
   lcd.setCursor(3,0);
  lcd.print("Temp OK");
  
}

delay(100);

}



