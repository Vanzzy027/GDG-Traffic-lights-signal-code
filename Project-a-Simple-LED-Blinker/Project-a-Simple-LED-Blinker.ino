// Project-a-Simple-LED-Blinker.ino
// Description: This program blinks an LED connected to a specified pin on and off at defined intervals. 
 
// Define the pin number where the LED is connected.
// We use a constant integer because this pin assignment will not change.
const int LED_PIN = 13;

//  Setup Function runs ONLY ONCE when the microcontroller powers on
void setup() {
    pinMode(LED_PIN, OUTPUT);     // pinMode() sets the purpose of the pin.
}
//  Loop Function runs forever/repeatedly after setup() is done
void loop() {
    // --- TURN LED ON ---
    digitalWrite(LED_PIN, HIGH);        // Turn the LED ON
    delay(5000);                 // Wait for (5000 milliseconds = 5 seconds) while its on

    // --- TURN LED OFF ---
    digitalWrite(LED_PIN, LOW);         // Turn the LED OFF
    delay(2000);                // Wait for (2000 milliseconds = 2 seconds) then restart the loop 
}
