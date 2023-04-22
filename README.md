# BREATH
Vitals Monitoring IoT Device for Marine Archaeologists and Underwater Welders
                                                                                                                                     
### About
This project is a vitals monitoring IoT device that uses LM35 and MAX30102 sensors to measure oxygen level, body temperature, and pulse rate. The device is designed to monitor the vitals of a person and predict whether their vitals are stable or not by using a decision tree model. 
If the vitals are not stable, the device will activate an LED to alert the person. The device is designed to be portable and easy to use, making it a useful tool for monitoring the vitals of individuals in a variety of settings.


## Table of Contents

- [Components](#components)
- [Connections](#connections)
- [Installation](#installation)
- [Usage](#usage)
- [License](#license)

## Components

To build this project, you will need the following components:

- Arduino board
- LM35 temperature sensor
- MAX30102 pulse oximeter sensor
- LED
- Breadboard
- Jumper wires
- USB cable


## Connections
Follow the below Connections Plan for the Proper Working of the Project:
```
MAX30105 sensor: Connect the SDA and SCL pins to the corresponding pins on the Arduino (usually A4 and A5 respectively). Connect the sensor's VCC and GND pins to the Arduino's 3.3V and GND pins respectively.
LM35 sensor: Connect the sensor's VCC pin to the Arduino's 5V pin, its GND pin to the Arduino's GND pin, and its output pin to analog pin A3 on the Arduino.
LED: Connect the LED's positive pin (anode) to digital pin 2 on the Arduino, and its negative pin (cathode) to a resistor and then to the Arduino's GND pin.
```
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



## Usage

To use the device, follow these steps:

1. Power on the device by connecting it to a power source or battery.
2. Wait for the device to collect and analyze the vitals data.
3. If the vitals are stable, the device will continue monitoring without any alerts.
4. If the vitals are unstable, the LED will turn on for 0.5 seconds to alert the person.



## License
This project is licensed under the MIT license. See the LICENSE file for more details.

## Future Works
## Requirements
* Compiler (Recommended: Visual Studio Code)
* MySQL Community Server 8.0.24
* CMake
* Dlib
* Python 3.9









