#include <SoftwareSerial.h>
#include <Servo.h>

#define SAMPLE_RATE 500
#define BAUD_RATE 9600
#define INPUT_PIN A0
#define BUFFER_SIZE 128

#define ServoWrist_Pin 3   // Connect to the Servo Motor
#define ServoThumb_Pin 5    // Connect to the Servo Motor
#define ServoIndex_Pin 6    // Connect to the Servo Motor
#define ServoMiddle_Pin 9   // Connect to the Servo Motor
#define ServoRing_Pin 10    // Connect to the Servo Motor
#define ServoLittle_Pin 11  // Connect to the Servo Motor

Servo objWrist;
Servo objThumb;
Servo objIndex;
Servo objMiddle;
Servo objRing;
Servo objLittle;

int circular_buffer[BUFFER_SIZE];
int data_index, sum;

void setup() {

  Serial.begin(BAUD_RATE);
}

void loop() {

  static unsigned long past = 0;
  unsigned long present = micros();
  unsigned long interval = present - past;
  past = present;

  static long timer = 0;
  timer -= interval;

  if(timer < 0) {
    timer += 1000000 / SAMPLE_RATE;
    int sensor_value = analogRead(INPUT_PIN);
    int signal = EMGFilter(sensor_value);
    int envelop = getEnvelop(abs(signal));
    Serial.println(envelop);
    if (envelop > 60){
        OpenAll();
    }else{
        CloseAll();
    }
  }
}

int getEnvelop(int abs_emg){
  sum -= circular_buffer[data_index];
  sum += abs_emg;
  circular_buffer[data_index] = abs_emg;
  data_index = (data_index + 1) % BUFFER_SIZE;
  return (sum/BUFFER_SIZE) * 2;
}


float EMGFilter(float input)
{
  float output = input;
  {
    static float z1, z2; // filter section state
    float x = output - 0.05159732*z1 - 0.36347401*z2;
    output = 0.01856301*x + 0.03712602*z1 + 0.01856301*z2;
    z2 = z1;
    z1 = x;
  }
  {
    static float z1, z2; // filter section state
    float x = output - -0.53945795*z1 - 0.39764934*z2;
    output = 1.00000000*x + -2.00000000*z1 + 1.00000000*z2;
    z2 = z1;
    z1 = x;
  }
  {
    static float z1, z2; // filter section state
    float x = output - 0.47319594*z1 - 0.70744137*z2;
    output = 1.00000000*x + 2.00000000*z1 + 1.00000000*z2;
    z2 = z1;
    z1 = x;
  }
  {
    static float z1, z2; // filter section state
    float x = output - -1.00211112*z1 - 0.74520226*z2;
    output = 1.00000000*x + -2.00000000*z1 + 1.00000000*z2;
    z2 = z1;
    z1 = x;
  }
  return output;
}

void OpenAll() {
  
  objThumb.attach(ServoThumb_Pin);
  objThumb.write(90);

  objIndex.attach(ServoIndex_Pin);
  objIndex.write(90);

  objMiddle.attach(ServoMiddle_Pin);
  objMiddle.write(90);

  objRing.attach(ServoRing_Pin);
  objRing.write(90);

  objLittle.attach(ServoLittle_Pin);
  objLittle.write(90);

}

void CloseAll() {
  
  objThumb.attach(ServoThumb_Pin);
  objThumb.write(0);

  objIndex.attach(ServoIndex_Pin);
  objIndex.write(0);

  objMiddle.attach(ServoMiddle_Pin);
  objMiddle.write(0);

  objRing.attach(ServoRing_Pin);
  objRing.write(0);

  objLittle.attach(ServoLittle_Pin);
  objLittle.write(0);

}
