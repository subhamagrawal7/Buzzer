///  BUZZER ARDUINO CODE
int button_1 = 2;
int button_2 = 3;
int button_3 = 4;
int button_4 = 5;
int buzzer = 12;
int flag_1 = 0;
int flag_2 = 0;
int flag_3 = 0;
int flag_4 = 0;

void setup() {
        // opens serial port, sets data rate to 9600 bps
        Serial.begin(9600); 
        pinMode(button_1 , INPUT_PULLUP);
        pinMode(button_2 , INPUT_PULLUP);
        pinMode(button_3 , INPUT_PULLUP);
        pinMode(button_4 , INPUT_PULLUP);
        pinMode(buzzer , OUTPUT);
        digitalWrite (buzzer , LOW);
        flag_1 = 0;
        flag_2 = 0;
        flag_3 = 0;
        flag_4 = 0;
}

void loop() {
               // Reads the state of each button
               int b_state_1 = digitalRead(button_1);
               int b_state_2 = digitalRead(button_2);
               int b_state_3 = digitalRead(button_3);
               int b_state_4 = digitalRead(button_4);
               //  Checks if the button 1 was pressed first
               if(b_state_1 == 0&&flag_1==0) {
                 Serial.println('1');
                 delay(500);
                 digitalWrite(buzzer , HIGH);
                 delay(1000);
                 digitalWrite(buzzer , LOW);
                 flag_1 = 1;
                 flag_2 = 1;
                 flag_3 = 1;
                 flag_4 = 1;
                 b_state_4 = 0;
                 b_state_3 = 0;
                 b_state_2 = 0;
                 b_state_1 = 0;
               }
               //  Checks if the button 2 was pressed first
               if(b_state_2 == 0&&flag_2==0) {
                 Serial.println('2');
                 delay(500);
                 digitalWrite(buzzer , HIGH);
                 delay(1000);
                 digitalWrite(buzzer , LOW);
                 flag_1 = 1;
                 flag_2 = 1;
                 flag_3 = 1;
                 flag_4 = 1;
                 b_state_4 = 0;
                 b_state_3 = 0;
                 b_state_2 = 0;
                 b_state_1 = 0;
               }
               //  Checks if the button 3 was pressed first
               if(b_state_3 == 0&&flag_3==0) {
                 Serial.println('3');
                 delay(500);
                 digitalWrite(buzzer , HIGH);
                 delay(1000);
                 digitalWrite(buzzer , LOW);
                 flag_1 = 1;
                 flag_2 = 1;
                 flag_3 = 1;
                 flag_4 = 1;
                 b_state_3 = 0;
                 b_state_4 = 0;
                 b_state_2 = 0;
                 b_state_1 = 0;
               }
               //  Checks if the button 4 was pressed first
               if(b_state_4 == 0&&flag_4==0) {
                 Serial.println('4');
                 delay(500);
                 digitalWrite(buzzer , HIGH);
                 delay(1000);
                 digitalWrite(buzzer , LOW);
                 flag_1 = 1;
                 flag_2 = 1;
                 flag_3 = 1;
                 flag_4 = 1;
                 b_state_4 = 0;
                 b_state_3 = 0;
                 b_state_2 = 0;
                 b_state_1 = 0;
               }
}
