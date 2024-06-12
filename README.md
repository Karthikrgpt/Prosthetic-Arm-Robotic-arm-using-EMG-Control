# Prosthetic-Arm-Robotic-arm-using-EMG-Control

**Objective:**

To Develop a 3D Printed Myoelectric Prosthetic Arm / Robotic arm to Control Hand Movements. This is achieved by utilizing myoelectric sensor (muscle sensor), Arduino microcontroller and servo motors to control hand movements.

**Working principle:**

The controlling of prosthetic arm is based on Electromyography sensor module, which is controlled by another hand by wearing the band.

**Step-1:** Electromyography sensor (EMG) is connected to dry electrode and further, the dry electrode is attached to bicep muscle.
**Step-2:** EMG sensor will detect the moment of the muscle and produce some reference value depending on the EMG signal received on the sensor.
**Step-3:** the produced reference value if filtered and amplified, then amplified signal is fed to microcontroller.
**Step-4:** The microcontroller uses the Second order Digital IIR Butterworth Band-Pass filter, which produces frequency and envelop value.
**Step-5:** Using the envelop value servo rotation is given. Rotation signal is given for 6 different servo motor are used wrist moment and fingers moment of prosthetic arm.
**Step-6:** servo motor will rotate at angle of 90º and these servo motors are connected to the fingers of prosthetic arm using the fishing wires.
**Step-7:** servo angle calculations, Taking Calculations
