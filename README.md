💡 Microcontroller Basics: Sequential Logic and the delay() Problem

This repository contains two fundamental embedded C projects designed to introduce the core concepts of microcontroller programming: setting up pins, controlling outputs, and managing time using the delay() function.

Target Audience: Absolute beginners in embedded systems and those transitioning to more professional embedded software development.

 ###### [Youtube link](https://www.youtube.com/watch?v=-gcknc2NcbA)



# 1. Project 1: Simple LED Blinker

Overview

This is the "Hello World" of embedded programming. It demonstrates the most basic function of a microcontroller: turning an output pin ON and OFF at regular intervals.

Hardware Required

Microcontroller (e.g.ESP32, ESP8266, Arduino Uno)

One LED

One 220-ohm Resistor

Jumper Wires

Code Breakdown (Based on Pin 13, 1-second interval)

Code Line

Purpose

Explanation for Beginners

const int LED_PIN = 13;

Define Pin

Assigns an easy-to-read name (LED_PIN) to the physical pin number (13) on the board.

pinMode(LED_PIN, OUTPUT);

Configuration

Tells the microcontroller: "I will be sending an electrical signal OUT of this pin to power something (the LED)."

digitalWrite(LED_PIN, HIGH);

Action (ON)

Sends the maximum voltage (ON) to the pin, causing the LED to light up.

delay(5000);

Pause

Stops the entire program for 1000 milliseconds (5 seconds). The LED remains on during this pause.

digitalWrite(LED_PIN, LOW);

Action (OFF)

Sets the pin voltage to zero (OFF), cutting power to the LED.

# 2. Project B: Traffic Light Controller

Overview

This project expands on the basic blink by controlling three different output pins in a specific, timed sequence (Red $\rightarrow$ Green $\rightarrow$ Yellow $\rightarrow$ Red).

Hardware Required

Microcontroller

Three LEDs (Red, Yellow, Green)

Three 220-ohm Resistors

Jumper Wires

Pin Assignments and Delays (Based on your provided code)

Light

Pin Number

Delay Duration

RED

14

2000 ms (2 seconds)

GREEN

12

3000 ms (3 seconds)

YELLOW

4

5000 ms (5 seconds)

Code Breakdown

The core logic resides in the loop() function, which defines the strict sequence:

RED ON (Wait 2s):

digitalWrite(RED_PIN, HIGH);
digitalWrite(GREEN_PIN, LOW);
digitalWrite(YELLOW_PIN, LOW);
delay(2000); // Stop for 2 seconds


GREEN ON (Wait 3s):

digitalWrite(RED_PIN, LOW);
digitalWrite(GREEN_PIN, HIGH);
digitalWrite(YELLOW_PIN, LOW);
delay(DELAY_TIME); // Stop for 3 seconds (DELAY_TIME = 3000)


YELLOW ON (Wait 5s):

digitalWrite(RED_PIN, LOW);
digitalWrite(GREEN_PIN, LOW);
digitalWrite(YELLOW_PIN, HIGH);
delay(5000); // Stop for 5 seconds


The loop then restarts from step 1.

## 🛑 The Critical Lesson: The delay() Problem

Both of these projects use the delay() function to manage timing. This is the main topic for discussion.

Sequential Problem: When the microcontroller hits a delay(N) command, the entire program stops for N milliseconds.

The Bottleneck: Imagine adding a crosswalk button to the Traffic Light. If the button is pressed while the code is stuck in the delay(5000) for the Yellow light, the microcontroller cannot read the button press until the 5-second delay is completely finished.

Real-Time Need: In real-world systems (drones, medical devices, IoT), you need to handle multiple, time-sensitive events simultaneously (e.g., check the network, read a sensor, and move a motor).

This limitation is the reason advanced embedded applications move beyond the simple loop() and adopt Real-Time Operating Systems (RTOS) like FreeRTOS, which allow the microcontroller to juggle multiple independent tasks without blocking.