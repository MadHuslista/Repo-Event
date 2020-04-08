/*
Purpose: Control PWM ventilator 
*/

#define IA 11
#define IB 10

void setup()
{
    pinMode(IA, OUTPUT);
    pinMode(IB, OUTPUT);
    Serial.begin(9600);
}
void loop()
{
    ventilation(60, 2);
    Serial.println("BPM: 60, I:E = 1:2");

/*        int pot = analogRead(A2);
    //Serial.println(pot);
    pot = map(pot, 0, 1023, 0, 255);
    pot = 94;
    girar(1, pot);
 */}

void ventilation(int bpm, int Esp)
{ //Motor RPM: 109
    //Periodo: 0.5505
    //bpm -> rpm
    //I:E

    float vent_time = 60.0 / bpm;
    float ins_time = vent_time / (Esp + 1);
    float esp_time = Esp * vent_time / (Esp + 1); //Revisado y correctos

    //considerando el rango de movimiento = 180° y eso es medio giro...
    float ins_rpm = 30.0 / ins_time;
    float esp_rpm = 30.0 / esp_time; //revisado y correcto

    Serial.print(ins_time, 4);
    Serial.print(",");
    Serial.print(esp_time, 4);
    Serial.print("        ");
    Serial.print(ins_rpm, 4);
    Serial.print(",");
    Serial.println(esp_rpm, 4);

    int ins_pwm = 255.0 * (ins_rpm / 109.0);
    int esp_pwm = 255.0 * (esp_rpm / 109.0);

    girar(1, ins_pwm);
    delay(ins_time * 1000);
    girar(0, esp_pwm);
    delay(esp_time * 1000);
}

void girar(int direction, int duty_cicle)
{
    if (direction == 1)
    {
        analogWrite(IA, duty_cicle);
        digitalWrite(IB, LOW);
    }
    else if (direction == 0)
    {
        analogWrite(IB, duty_cicle);
        digitalWrite(IA, LOW);
    }
}