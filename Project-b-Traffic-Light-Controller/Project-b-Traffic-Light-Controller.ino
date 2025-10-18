//Traffic lights code 

//Defining pins we want to connect to
const int RED_PIN = 14;
const int GREEN_PIN = 12;
const int YELLOW_PIN = 4;

const int DELAY_TIME = 1000;
 

//The setup runs only once when the device is turned on ie the microcontroller connecting to wifi, defination of pins etc
void setup() {
//Initializing the pins as outputs
pinMode(RED_PIN, OUTPUT);
pinMode(GREEN_PIN, OUTPUT);
pinMode(YELLOW_PIN, OUTPUT);

//Giving a smooth output of all LEDs off before proceeding to the loop function
digitalWrite(RED_PIN, LOW);
digitalWrite(GREEN_PIN, LOW);
digitalWrite(YELLOW_PIN, LOW);
}




/// The loop functions runs infinetely (forever) 
void loop() {
//Red LED
digitalWrite(RED_PIN, HIGH); // High means power is sent to the pin thus the LED goes on and the opposite is true thus red is on
digitalWrite(GREEN_PIN, LOW);
digitalWrite(YELLOW_PIN, LOW);
delay(1000);

//GREEN LED
digitalWrite(RED_PIN, LOW);
digitalWrite(GREEN_PIN, HIGH);
digitalWrite(YELLOW_PIN, LOW);
delay(DELAY_TIME);

//YELLOW LED
digitalWrite(RED_PIN, LOW);
digitalWrite(GREEN_PIN, LOW);
digitalWrite(YELLOW_PIN, HIGH);
delay(1000);
}

