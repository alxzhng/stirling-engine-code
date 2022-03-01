/***********************************************

UCL MechEng Y1 Stirling Engine Lab (Arduino Part)
For information on usage, visit https://github.com/alxzhng/stirling_engine_code.

 ************************************************/
#include <SoftwareSerial.h>

// Pin Definitions
#define buttonPin 3       // pin connected to button (digital input)
#define irPin 5           // pin connected to IR sensor
#define ledPin 13           // pin connected to green LED
#define tempPin1 A0       // pin connected to temp sensor 1 (analogue input)
#define tempPin2 A1       // temp sensor 2

// Options
unsigned long runTime = 10;  // run time in minutes -- button can be used to interrupt this
long baudrate = 74880;       // frequency at which data is saved -- https://www.arduino.cc/en/Reference/SoftwareSerialBegin

// Initialize input variables
int irState;              // ir sensor trigger
int buttonState;          // button to start/stop measurement
unsigned long startTime, currentTime, delta_t;
float period, freq;       // time taken for one revolution
float temp1, temp2;       // temperature readings

void setup() {
  runTime = runTime * 60000;   // convert run time to milliseconds

  pinMode(ledPin, OUTPUT);
  pinMode(irPin, INPUT);
  pinMode(tempPin1, INPUT);
  pinMode(tempPin2, INPUT);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  digitalWrite(irPin, LOW);
  digitalWrite(ledPin, LOW);

  Serial.begin(baudrate);
  Serial.println("Press button to start taking measurements.");
}

void loop() {
  // Do nothing if button not pressed
  while (true)
  {
    sleep();
    buttonState = digitalRead(buttonPin);

    // Button has been pressed, DO SOMETHING!!
    if (buttonState == HIGH)
    {
      break;
    }
  }

  Serial.println("3...");
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
  Serial.println("2...");
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
  Serial.println("1...");
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
  Serial.println("Writing data. Press button again to terminate.");

  startTime = millis(); // take start time 

  digitalWrite(ledPin, HIGH); // set state indication high 

  while (true)
  {
    getTemperature(); // take temperature readings

    irState = digitalRead(irPin); // take ir beam break -- 1 if broken, 0 if unbroken

    currentTime = millis(); // update timer
    delta_t = currentTime - startTime; // time elapsed since measurement start, in milliseconds

    // Store sensor readings as formatted string
    char str[100];
    char temp1str[30];
    char temp2str[30];
    dtostrf(temp1, 3, 3, temp1str);
    dtostrf(temp2, 3, 3, temp2str);
    sprintf(str, "%6ld,%s,%s,%d", delta_t, temp1str, temp2str, irState);

    // Print string to serial
    Serial.println(str);

    // Check if set time exceeded, or if button interrupt pressed to stop the measurements
    if (digitalRead(buttonPin)==HIGH || delta_t > runTime)
    {
      break;
    }
  }

  Serial.println("Done taking measurements.");
  digitalWrite(ledPin, LOW);

  // Go back to doing nothing
  while (true)
  {
    sleep();
  }
}

void getTemperature()
{
  int volt1 = analogRead(tempPin1);
  int volt2 = analogRead(tempPin2);

  // Convert ADC to voltage in mV
  temp1 = (float) volt1; // 5v, 1024 adc
  temp2 = (float) volt2;

  temp1 = temp1 * 5000.0 / 1024.0;
  temp2 = temp2 * 5000.0 / 1024.0;

  // Refer to TMP36 datasheet for output characteristics
  temp1 = (temp1 - 500)/10; // offset voltage 0.5v, scaling 10mV/C
  temp2 = (temp2 - 500)/10;
}

void sleep()
{

}