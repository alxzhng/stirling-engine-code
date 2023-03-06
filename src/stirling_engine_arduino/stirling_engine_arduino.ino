/***********************************************

UCL MechEng Y1 Stirling Engine Lab (Arduino Part)
For information on usage, visit https://github.com/alxzhng/stirling_engine_code.

 ************************************************/

//---------------------- SET UP ------------------------//
// Pin Definitions
#define buttonPin 3          // pin connected to button 
#define irSensorPin 5        // pin connected to IR sensor
#define ledPin 13            // pin connected to green LED (internal Arduino connection)
#define tempPin1 A0          // pin connected to temp sensor 1 (top)
#define tempPin2 A1          // pin connected to temp sensor 2 (bottom)

// Options
unsigned long runTime = 10;  // run time in minutes -- button can be used to interrupt this
long baudrate = 9600;      // frequency at which data is written to serial (symbols per second)

// Initialize input variables
int irState;              // ir sensor trigger
int buttonState;          // button to start/stop measurement
unsigned long startTime, currentTime, delta_t;
float period, freq;       // time taken for one revolution
int volt1, volt2;         // temp sensor voltage readings

// Storage variables for printing to serial
char str[100];
char temp1str[30];
char temp2str[30];

//---------------------- MAIN CODE ------------------------//

void setup() {
  runTime = runTime * 60000;   // convert run time to milliseconds

  pinMode(ledPin, OUTPUT);
  pinMode(irSensorPin, INPUT);
  pinMode(tempPin1, INPUT);
  pinMode(tempPin2, INPUT);
  pinMode(buttonPin, INPUT);

  digitalWrite(irSensorPin, HIGH);
  digitalWrite(ledPin, LOW);

  Serial.begin(baudrate);
  Serial.println("Press button to start taking measurements.");
}

void loop() {
  while (true)                            // Do nothing if button not pressed
  {
    sleep();
    buttonState = digitalRead(buttonPin);

    if (buttonState == HIGH)              // Button has been pressed, DO SOMETHING!!
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

  startTime = millis();                 // Take start time 

  digitalWrite(ledPin, HIGH);           // Set state indication high 

  while (true)
  {
    // Read input pins
    volt1 = analogRead(tempPin1);       // Temperature sensor 1 voltage (upper)
    volt2 = analogRead(tempPin2);       // Temperature sensor 2 voltage (lower)
    irState = digitalRead(irSensorPin); // IR receiver state -- 0 if broken, 1 if broken

    currentTime = millis();             // Update timer counter
    delta_t = currentTime - startTime;  // Time elapsed since measurement start, in milliseconds

    // Store sensor readings as formatted string
    sprintf(str, "%6ld,%d,%d,%d", delta_t, volt1, volt2, irState);
    
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

void sleep()
{

}
