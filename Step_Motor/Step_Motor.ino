// Incluímos la librería para poder utilizarla
#include <Stepper.h>

// Esto es el número de pasos por revolución
#define STEPS 1024
// Número de pasos que queremos que de
#define NUMSTEPS 256

// Constructor, pasamos STEPS y los pines donde tengamos conectado el motor
Stepper stepper(STEPS, 8, 9, 10, 11);

void setup()
{
    // Asignamos la velocidad en RPM (Revoluciones por Minuto)
    stepper.setSpeed(1);
    Serial.begin(9600);
}

void loop()
{
    // Movemos el motor un número determinado de pasos
    stepper.step(NUMSTEPS);
    delay(2000);
    Serial.println("Test");
}