# UCL MechEng Y1 Stirling Engine Lab 2022

## Version History 
V1.0.: 

## Description
This two part code, consisting of an Arduino part 'stirling_engine_arduino.uno' and Python part 'stirling_engine_csvwrite.ipynb', was written to facilitate data acquisition from the sensors connected to the Stirling Engine to measure performance characteristics. The sensors are connected to an Arduino Uno, which reads the sensor data and sends it to a python script over serial communication, which then writes it to a .csv file for convenient saving and post-processing of results. There are 2 temperature sensors measuring the bottom and top plates of the working fluid enclosure, and an infrared beam break sensor that registers when a taped spoke on the flywheel passes between the IR bulb and receiver. The code can either be ran for a fixed amount of time, or measurements can be start and stopped with the push of a button. 

## Requirements 
* Software 
    * Arduino IDE (https://www.arduino.cc/en/software)
    * Anaconda (https://www.anaconda.com/products/individual)
* Hardware 
    * Arduino Uno 
    * Sensors
        * 2 x temperature sensors
        * 1 x ir beam break sensors
        * 1 x pushbutton 
        * 1 x led 

## Usage
1. Download the .zip file from this page and unzip it to the location you want the data files to be saved. It should contain a src folder with the scripts 'stirling_engine_arduino.ino' and 'stirling_engine_csvwrite.ipynb'. It is recommended to have one folder for each lab group as the .csv files will be saved to the src folder containing the scripts. 
2. Connect the Arduino board to the laptop with the usb cable. 
3. Open the .ino file in Arduino IDE. If you are prompted to create a folder, click on OK. 
4. Under 'Tools' in the top bar, make sure the correct board and port are selected. Take note of the port number. 
5. Check that the pins are defined correctly.
6. Upload the .ino code to the Arduino.
7. Launch Jupyter Notebook, navigate to the group's folder and open the .ipynb file. 
8. Edit the Settings cell and run it. 
9. Run the next cell and follow instructions printed onto the console to take measurements. The code will take measurements for a full 10 minutes by default, but can be stopped if the red button is pressed at any time. 
10. When done taking measurements, navigate to the group folder and export the .csv file saved there.

If another reading is required, press the reset button on the Arduino or reupload the .ino code, change the file name and run the two cells again.