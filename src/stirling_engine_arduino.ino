/***********************************************
UCL MechEng Y1 Stirling Engine Lab (Arduino Part)
For information on usage, visit https://github.com/alxzhng/stirling_engine_code.
Run this code as step
 ************************************************/
#include <SoftwareSerial.h>

// Settings
unsigned long runTime = 5; // run time in minutes -- button can be used to interrupt this
int baudrate = 9600;       // https://www.arduino.cc/en/Reference/SoftwareSerialBegin

// Pin Definitions
#define buttonPin 3       // pin connected to button (digital input)
#define ledPin 13         // pin connected to LED
#define irPin 5           // pin connected to IR sensor
#define tempPin1 A0       // pin connected to temp sensor 1 (analogue input)
#define tempPin2 A1       // temp sensor 2

// Initialize input variables
int irState;              // ir sensor trigger
int buttonState;          // button to start/stop measurement
unsigned long startTime, currentTime, delta_t;
float rpm, period, freq;  // time taken for one revolution
float temp1, temp2;       // temperature readings

void setup() {
  runTime = runTime * 60000;   // convert run time to milliseconds

  pinMode(ledPin, OUTPUT);
  pinMode(irPin, INPUT);
  pinMode(tempPin1, INPUT);
  pinMode(tempPin2, INPUT);
  pinMode(buttonPin, INPUT);

  digitalWrite(irPin, HIGH);

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
  delay(1000);
  Serial.println("2...");
  delay(1000);
  Serial.println("1...");
  delay(1000);
  Serial.println("Writing time (ms), temp 1 (degC), temp 2 (degC), trigger");
  Serial.println("Press button again to terminate.")

  startTime = millis();
  while (true)
  {
    getTemperature(); // take temperature readings

    irState = digitalRead(irPin); // take ir beam break -- 0 if broken, 1 if unbroken

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

/*
void getRPM()
{
  irState = digitalRead(irPin);

  if (irState == HIGH)
  {
    rpm = rpm;
  }
  // beam broken, one full revolution
  else if (irState == LOW)
  {
    period = (float) currentTime - (float) previousTime;
    previousTime = currentTime;
    freq = 1/(period/1000.0); // cycles per second
    rpm = freq * 60;
  }
}
*/
