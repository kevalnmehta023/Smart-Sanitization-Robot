// === Arduino UNO: Motor + Pump Controller (Controlled by ESP32) ===

// === Motor Driver Pin Configuration ===
const int IN1 = 2;
const int IN2 = 3;
const int ENA = 5;
const int IN3 = 4;
const int IN4 = 7;
const int ENB = 6;

// === Pump Relay Pin Configuration ===
const int PUMP1_PIN = 8;
const int PUMP2_PIN = 9;

// === UNO Setup ===
void setup() {
    Serial.begin(9600);

    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(ENB, OUTPUT);

    pinMode(PUMP1_PIN, OUTPUT);
    pinMode(PUMP2_PIN, OUTPUT);

    stopMotors();
    digitalWrite(PUMP1_PIN, HIGH);
    digitalWrite(PUMP2_PIN, HIGH);

    Serial.println("UNO ready: Motors + Pumps Controller");
}

// === Listening for Commands from ESP32 ===
void loop() {
    if (Serial.available()) {
        char cmd = Serial.read();

        switch (cmd) {
            case 'F': forward(200); break;
            case 'B': backward(200); break;
            case 'L': leftTurn(200); break;
            case 'R': rightTurn(200); break;
            case 'S': stopMotors(); break;

            case 'P': digitalWrite(PUMP1_PIN, LOW); break;
            case 'p': digitalWrite(PUMP1_PIN, HIGH); break;
            case 'Q': digitalWrite(PUMP2_PIN, LOW); break;
            case 'q': digitalWrite(PUMP2_PIN, HIGH); break;
        }
    }
}

// === Motor Movement: Forward ===
void forward(uint8_t speed) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA, speed);

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, speed);
}

// === Motor Movement: Backward ===
void backward(uint8_t speed) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, speed);

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENB, speed);
}

// === Motor Movement: Turn Right (Pivot) ===
void rightTurn(uint8_t speed) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, speed);

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, speed);
}

// === Motor Movement: Turn Left (Pivot) ===
void leftTurn(uint8_t speed) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA, speed);

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENB, speed);
}

// === Motor Stop Function ===
void stopMotors() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);

    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
}
