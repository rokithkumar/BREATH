# BREATH
Vitals Monitoring IoT Device for Marine Archaeologists and Underwater Welders
                                                                                                                                     
### About
This project is a vitals monitoring IoT device that uses LM35 and MAX30102 sensors to measure oxygen level, body temperature, and pulse rate. The device is designed to monitor the vitals of a person and predict whether their vitals are stable or not by using a decision tree model. 
If the vitals are not stable, the device will activate an LED to alert the person. The device is designed to be portable and easy to use, making it a useful tool for monitoring the vitals of individuals in a variety of settings.


## Table of Contents

- [Components](#components)
- [Connections](#connections)
- [Installation](#installation)
- [Execution](#execution)
- [Future Works](#Future Works)
- [License](#license)

## Components

To build this project, you will need the following components:

- Arduino Board
- LM35 Temperature Sensor
- MAX30102 Pulse Oximeter Sensor
- LED
- Breadboard
- Jumper Wires
- USB Cable


## Connections
Follow the below Connections Plan for the Proper Working of the Project:
```
1. MAX30102 Sensor: 
  Connect the SDA and SCL pins to the corresponding pins on the Arduino (usually A4 and A5 respectively). 
  Connect the sensor's VCC and GND pins to the Arduino's 3.3V and GND pins respectively.
2. LM35 Sensor: 
  Connect the sensor's VCC pin to the Arduino's 5V pin, its GND pin to the Arduino's GND pin.
  Its output pin to analog pin A3 on the Arduino.
3. LED: 
  Connect the LED's positive pin (anode) to digital pin 2 on the Arduino.
  Its negative pin (cathode) to a resistor and then to the Arduino's GND pin.
```
Refer the below Circuit Diagram for Hardware Connections:
![CricuitDiagram](https://user-images.githubusercontent.com/75007002/233770910-2642c7de-c64c-44eb-a298-9a313243cb4d.jpg)

## Installation

1. Python 3.9
   * Install Python from this [Link](https://www.python.org/downloads/release/python-396/)
2. Arduino IDE
   * Install Arduino IDE from this [Link](https://www.arduino.cc/en/software)


## Libraries Installation using PIP
Please enter the following commands in CMD to download the required libraries
```
  1. serial
    >> pip install pyserial
  2. Scikit-Learn
    >> pip install scikit-learn
  3. panda
    >> pip install pandas
  4. numpy
    >> pip install numpy
  
```

## Execution
1. Once all the Hardware connections are Made, connect the Arduino to PC or Laptop
2. Open Arduino IDE
3. Note the Port that the Arduino Uno Board is Connected to, we may use this later.
4. Copy and Paste the give Arduino Code in a new Arduino Sketch or Use the Same Provided Arduino File.
5. Verify the Sketch and Upload the Code.
6. Once Verified and Uploaded the Sketch without any errors, Quit the Arduino Sketch.
7. Now Open the Python Source Code File
8. Modify the Dataset path according to your location of the Dataset File.
9. Modify the below Port Connection to your above noted Port Connection:
  ```
  #Serial Connection with Arduino UNO on Port COM5
  #NOTE:It may vary
  ser = serial.Serial('COM5', 9600)
  ```
10. Now Save the File and Execute the File.
11. If there are no errors in the File then the Project will start working.

## Future Works
We can incorporate GPS Module for the above Vitals Monitoring System to get the location of the person.

## License
This project is licensed under the MIT license. See the LICENSE file for more details.

## Future Works
## Requirements
* Compiler (Recommended: Visual Studio Code)
* MySQL Community Server 8.0.24
* CMake
* Dlib
* Python 3.9









