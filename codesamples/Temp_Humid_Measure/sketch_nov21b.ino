
/*Modified by
 * technical Team,REES52
 */

#include <Adafruit_Sensor.h> // install this library
#include <DHT.h>    // install this library
int speakerPin = D2; //define digital pin 2 for speaker
int length = 1;
#define DHTPIN D1   //define digital pin 5 for DHT11 Module 
#define DHTTYPE DHT11
#define LED_TOO_COLD D8
#define LED_PERFECT D7
#define LED_TOO_HOT D6
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(115200);     //set the baud rate
  Serial.println("DHT11 test!");

  dht.begin();
}

void loop() {
  pinMode(speakerPin, OUTPUT);
  pinMode (D8 , OUTPUT);
  pinMode (D7 , OUTPUT);
  pinMode ( D6 , OUTPUT);
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);


  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");
  if (t <= 20) {
    Serial.println("Too cold!");
    digitalWrite(D8, HIGH);
    digitalWrite(speakerPin, HIGH);
    delay (2000);
    digitalWrite(speakerPin, LOW);
    digitalWrite(D8, LOW);
  }
  if (20 < t && t < 27) {
    Serial.println(t);
    Serial.println("Perfect temperature!");
    digitalWrite(D7, HIGH);
    delay (2000);
    digitalWrite(D7, LOW);
  }
  if (t >= 29) {
    Serial.println("Too hot!");
    digitalWrite(D6, HIGH);
    digitalWrite(speakerPin, HIGH);
    delay (2000);
    digitalWrite(speakerPin, LOW);
    digitalWrite(D6, LOW);
  }

}
