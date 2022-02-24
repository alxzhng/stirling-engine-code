# UCL MechEng Y1 Stirling Engine Lab 2022

## Version History 
V1.0.: 

## Description
This two part code, consisting of an Arduino part 'stirling_engine_arduino.uno' and Python part 'stirling_engine_csvwrite.ipynb', was written to facilitate data acquisition from the sensors connected to the Stirling Engine to measure performance characteristics. The sensors are connected to an Arduino Uno, which reads the sensor data and sends it to a python script over serial communication, which then writes it to a .csv file for convenient post-processing of results. There are 2 temperature sensors measuring the bottom and top plates of the working fluid enclosure, and an infrared beam break sensor that registers when a taped spoke on the flywheel passes between the IR bulb and receiver. The code can either be ran for a fixed amount of time, or measurements can be start and stopped with the push of a button. 

## Requirements 
* Software 
    * Arduino IDE (https://www.arduino.cc/en/software)
    * Anaconda (https://www.anaconda.com/products/individual)
    * Jupyter Notebook (https://jupyter.org/install) 
* Hardware 
    * Arduino Uno 
    * Sensors
        * 2 x temperature sensors
        * 1 x ir beam break sensors
        * 1 x pushbutton 

## Usage
1. Download the .zip file from (https://github.com/alxzhng/stirling_engine_code) and unzip it to the location you want the data files to be saved. It is recommended to have one folder for each lab group as the .csv files will be saved to the same place as the .ipynb script. 
2. Connect the Arduino board to the laptop with the usb cable. 
3. Open the 'stirling_engine_arduino.ino' script in Arduino IDE. If you are prompted to create a folder, click on OK. 
4. Under 'Tools' in the top bar, make sure the correct board and port are selected.
5. Change the runTime variable to be the time to record the measurements for. The pushbutton can also be used to stop measurements at any point. 
6. Check that the pins are defined correctly. 
7. Upload the code to the Arduino, or use the reset button on the board if already uploaded previously. 
8. Launch Jupyter Notebook, navigate to the group's folder and open the 'stirling_engine_csvwrite.ipynb' script. 
9. Edit the Settings and run it. 
10. Run the next cell and follow instructions printed onto the console. 
11. Navigate to the group folder and export the .csv file saved there. 
12. If another reading is required, press the reset button on the Arduino or reupload the .ino code, change the file name and run the two cells again.