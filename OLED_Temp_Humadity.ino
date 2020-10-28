
// Include Wire Library for I2C
#include <Wire.h>
 
// Include Adafruit Graphics & OLED libraries
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 
// Temp Humid Library
#include <DHT.h>

#define DHTTYPE DHT11   // DHT 11
// Reset pin not used but needed for library
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

// DHT Sensor
uint8_t DHTPin = 7; 
               
// Initialize DHT sensor.
DHT dht(DHTPin, DHTTYPE);                

float temperature;
float humidity;

void setup() {
  // Start Wire library for I2C
 Wire.begin();
 
  // initialize OLED with I2C addr 0x3C
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  
  pinMode(DHTPin, INPUT);

  dht.begin();  
}
 
void displayTempHumid(){
  // Delay to allow sensor to stabalize
  delay(2000);
 
  // Read Humidity
  humidity = dht.readHumidity();
  // Read temperature as Celsius
  temperature = dht.readTemperature();
 
  // Clear the display
  display.clearDisplay();
  //Set the color - always use white despite actual display color
  display.setTextColor(WHITE);
  //Set the font size
  display.setTextSize(1);
  //Set the cursor coordinates
  display.setCursor(0,0);
  display.print("OLED Display Interfacing");
  display.setCursor(0,10); 
  display.print("Temp:    "); 
  display.print(temperature);
  display.print(" C");
  display.setCursor(0,20);
  display.print("Humidity: "); 
  display.print(humidity);
  display.print(" %");
}
void loop() {
  displayTempHumid();
  display.display();
}
