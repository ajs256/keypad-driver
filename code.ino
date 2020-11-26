/*
  Non-Multiplexed Keypad Driver code.
  (C) 2020 ajs256 for Fishy Circuits.
  Licensed under MIT license.
*/
#include <SoftwareSerial.h>
char buttons[] = {'\0', '\0', '*', '7', '4', '1', '0', '8', '5', '2', '#', '9', '6', '\0', '3'}; // Each entry corresponds to a digital pin.
                                                                                                 // D14 = A0 on ATmega328 based boards
                                                                                                 // such as the Uno, original Nano, and Pro Mini.
                                                                                                 // THIS MAY NOT WORK ON OTHER BOARDS!
                                                                                                 // Check the pinout diagram.
                                                                                                 // We skip 0 and 1 because they are used by USB
                                                                                                 // and may interfere with programming,
                                                                                                 // and 13 because the onboard LED was giving us trouble.

SoftwareSerial serial_out(15, 16); // RX, TX. D15 and D16 are A1 and A2 on ATmega328 based boards such as the Uno and original Nano.
                                   // THIS MAY NOT WORK ON OTHER BOARDS! Check the pinout diagram for your board.


void setup() {
  for (int p = 2; p <= sizeof buttons; p++) { // For each pin "p", starting at 2 and going until the size of the "buttons" array, incrementing each time,
    pinMode(p, INPUT_PULLUP);                 // set it to a pulled-up input (reads LOW when connected to ground).
  }
  // serial_out.begin(9600);                  // Open the SoftwareSerial port.
  Serial.begin(9600);                         // Open the USB serial port, for debugging.
}

void loop() {
  for (int p = 2; p <= sizeof buttons; p++) {  // For each pin "p", starting at 2 and going until the size of the "buttons" array, incrementing each time,
    if (buttons[p] && digitalRead(p) == LOW) { // If pin "p" isn't null in the array and it reads LOW,
      // serial_out.print(buttons[p]);         // print the corresponding character in buttons to the SoftwareSerial port.
      Serial.print(buttons[p]);                // Print the character to the USB serial port, for debugging.
    }
  }
}
