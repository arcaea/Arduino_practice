#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
 
 
#define DHTPIN 7     // 設定DHT的接腳
#define DHTTYPE DHT11   // DHT 11 定義DHT的類型為DHT11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
 
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
DHT dht(DHTPIN, DHTTYPE);
 
void setup() {
  lcd.begin(16, 2);      // 初始化 LCD，一行 16 的字元，共 2 行，預設開啟背光
  
  // 閃爍
  lcd.backlight(); // 開啟背光
  delay(200);
  lcd.noBacklight(); // 關閉背光
  delay(200);
  lcd.backlight();
 
  lcd.setCursor(0, 0); // 設定游標位置在第一行行首
  lcd.print("Hello, world!");
  lcd.setCursor(0, 1); // 設定游標位置在第二行行首
  lcd.print("DHT11 test!!");
   
  Serial.begin(9600);
  Serial.println("DHT11 test!");
 
  dht.begin();
}
 
void loop() {
  // 每次偵測間隔2秒
  delay(2000);
 
  //讀取濕度
  float h = dht.readHumidity();
  //讀取攝氏溫度
  float t = dht.readTemperature();
  //讀取華氏溫度
  float f = dht.readTemperature(true);
 
  //檢查是不是有讀到資料
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" ");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(" \n");
 
  lcd.setCursor(0, 0); // 設定游標位置在第一行行首
  lcd.print("Humidity: ");
  lcd.setCursor(10, 0); // 設定游標位置在第一行，10的位置
  lcd.print(h);
   
  lcd.setCursor(0, 1); // 設定游標位置在第二行行首
  lcd.print("Temp  *C: ");
  lcd.setCursor(10, 1); // 設定游標位置在第二行，10的位置
  lcd.print(t);
}
