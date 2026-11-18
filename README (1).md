# Smart Sanitization Robot

A semi-autonomous sanitization robot project built around an ESP32 and an Arduino UNO.

## Source files

- `ESP32/esp32_controller.ino` — Wi-Fi access point, web dashboard, sensor readings, and command forwarding over UART.
- `Arduino_UNO/arduino_motor_controller.ino` — receives serial commands and controls the motors and pump relays.

## Implemented in the code included here

- ESP32-hosted Wi-Fi access point and HTTP dashboard.
- Readings from three ultrasonic sensors, two IR sensors, and a water-level sensor.
- Browser commands forwarded from the ESP32 to the Arduino UNO over serial.
- Arduino UNO motor direction/speed control and two pump relay outputs.

## Before uploading

1. Open the relevant `.ino` file in the Arduino IDE.
2. For the ESP32, replace `CHANGE_ME_123` with a private Wi-Fi password of at least 8 characters. Do not commit your real password.
3. Select the correct board and port.
4. Check the wiring and common ground between the boards.
5. Confirm the UART wiring and voltage compatibility before powering the circuit.

## Important scope note

These files are reconstructed from the source-code listings in the project report. They have not been independently compiled or tested here. The report discusses additional sensors and autonomous behaviours, but those are not implemented in the code listings extracted here. The web dashboard currently exposes motor controls and Pump 1 controls; the UNO code also accepts `Q`/`q` commands for Pump 2, but the ESP32 dashboard does not provide buttons for those commands.

## Project documentation

This repository was prepared from the project report. Add actual project photographs, wiring/circuit diagrams, and dashboard screenshots if available.
