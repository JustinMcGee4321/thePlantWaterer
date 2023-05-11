/*
 * Justin McGee
 * 
 * 2023 Senior Project 
 * This program is going to detect the moisture in the plant. When the plant is dry, the water pump will turn on and water the plant. This program also reads the temperature, humidity, and light. 
 * 
*/

//temp sensor
#include "DHT.h" 
#define DHTTYPE DHT11
#define DHTPIN 5
DHT dht(DHTPIN, DHTTYPE);

int moistureState = 0;

void setup() {

  Serial.begin(9600);
  
  pinMode(14,OUTPUT); //Moisture sensor
  pinMode(25,OUTPUT); //Relay 
  
  //temp sensor
  pinMode(5,OUTPUT);
  dht.begin();
  pinMode(4,OUTPUT);


}

void loop() {
      
  //Show moisture for the serial moniter 
  Serial.print("Moisture:       ");
  Serial.println(analogRead(14));
  delay(1000);

  moistureState = analogRead(14);
   
  if(moistureState > 1900){  
     digitalWrite(25, LOW);  
     delay(45000); 
    }else{ 
     digitalWrite(25, HIGH);  
    }

    //light
  int light = analogRead(4);
  Serial.print("Light:          ");
  Serial.println(light);

     //Get the humidity
  float humidity = dht.readHumidity();
  
  //Get the temperature in Celcius
  float Celcius = dht.readTemperature();

  //Convert to Fahrenheit
  float Fahrenheit = 32 + (Celcius * 1.8);

  //print to the serial monitor
  Serial.print("Humidity:       ");
  Serial.print(humidity);
  Serial.println("%");
 
  Serial.print("Temperature:    ");
  Serial.print(Fahrenheit);
  Serial.println(" °F");

  Serial.println("");
  
}
