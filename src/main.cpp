#include <Arduino.h>

unsigned long long stepCount = 0;
unsigned long long oldStepCount = 0;

unsigned long long collatzStep(unsigned long long n);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  delay(10000); // Wait for 10 seconds before starting the loop
  Serial.println("Starting esp32c3-mini-collatz...");
}

void loop() {
  for (unsigned long long i = 1; i <= 18446744073709551615ULL; i++) {
    unsigned long long n = i;
    stepCount = 0;
    while (n != 1) {
      n = collatzStep(n);
      if (n == 0) {
        Serial.println("Stopping the program due to overflow.");
        while (true) {
          delay(10000);
          // Infinite loop to stop the program
        }
      }
    }
    if (stepCount > oldStepCount) {
      oldStepCount = stepCount;
      Serial.print("New max steps found for number: ");
      Serial.print(i);
      Serial.print(", Steps: ");
      Serial.println(stepCount);
    }
  }
  // put your main code here, to run repeatedly:
}

unsigned long long collatzStep(unsigned long long n) {
  if ((n & 1) == 1) {
    unsigned long long t = 3 * n + 1;
    if (t < n) {
      Serial.println("Overflow detected! Stopping the program.");
      return 0;
    }
    stepCount++;
    return 3 * n + 1;
  }
  stepCount++;
  return n / 2;
}