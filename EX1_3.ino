void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Basic Calculator");
  Serial.println("Enter: ");
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    input.replace('\r', ' ');

    int opIndex = -1;
    char op;

    if (input.indexOf('+') >= 0) { opIndex = input.indexOf('+'); op = '+'; }
    else if (input.indexOf('-') >= 0) { opIndex = input.indexOf('-'); op = '-'; }
    else if (input.indexOf('*') >= 0) { opIndex = input.indexOf('*'); op = '*'; }
    else if (input.indexOf('/') >= 0) { opIndex = input.indexOf('/'); op = '/'; }

    if (opIndex != -1) {
      float num1 = input.substring(0, opIndex).toFloat();
      float num2 = input.substring(opIndex + 1).toFloat();
      float result;

      if (op == '+') result = num1 + num2;
      else if (op == '-') result = num1 - num2;
      else if (op == '*') result = num1 * num2;
      else if (op == '/') {
        if (num2 == 0) {
          Serial.println("Error: Cannot divide by zero!");
          Serial.println("Next:");
          return;
        }
        result = num1 / num2;
      }

      Serial.print("= ");
      Serial.println(result, 2);
    } else {
      Serial.println("Wrong");
    }

    Serial.println("Next:");
  }
}
