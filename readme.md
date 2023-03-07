# UCL MechEng Y1 Stirling Engine Lab 2023

## Changelog
- **[24/02/2022]** Initial commit. Created 2 part code for stirling engine lab data collection with Arduino. 
- **[01/03/2022]** Final release version for the 2022 lab.
- **[23/02/2023]** Updated for 2023 lab. Issue with trigger sensor noisy data fixed (sensor read delay suspected).
- **[07/03/2023]** Final release version for the 2023 lab.

## Description
This two part code, consisting of an Arduino part 'stirling_engine_arduino.uno' and Python part 'stirling_engine_csvwrite.ipynb', was written to facilitate data acquisition from the sensors connected to the Stirling Engine to measure performance characteristics. The sensors are connected to an Arduino Uno, which reads the sensor data and sends it to a python script over serial communication, which then writes it to a .csv file for convenient saving and post-processing of results. There are 2 temperature sensors measuring the bottom and top plates of the working fluid enclosure, and an infrared beam break sensor that registers when a taped spoke on the flywheel passes between the IR bulb and receiver. The code can either be ran for a fixed amount of time, or measurements can be start and stopped with the push of a button. 

More information can be found on the lab handout (https://alxzhng.notion.site/Stirling-Engine-Lab-2023-440d19d6e7ce431db35d2359fb01bdf8)

## Requirements 
* Software 
    * Arduino IDE (https://www.arduino.cc/en/software)
    * Anaconda (https://www.anaconda.com/products/individual)
        * with Jupyter Notebook
* Hardware 
    * Arduino Uno 
        * Built in LED at pin 13
    * Sensors
        * 2 x TMP36 temperature sensors
        * 1 x IR beam break sensors
        * 1 x pushbutton 

## Usage
Detailed instructions are on the lab handout available on Notion, or as a pdf from Moodle.

1. Download the .zip file from this page and unzip it to the location you want the data files to be saved. It should contain a src folder with the scripts 'stirling_engine_arduino.ino' and 'stirling_engine_csvwrite.ipynb'. 
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

## Instructions to mentors
Before a session: 
- Check the required software is installed.
- Make sure you're familiar with the workflow! Run it yourself to see if it works.
- Get people to trial the workflow and verify the trigger works by manually spinning the wheel, before putting hot water and running the full 10 minutes. 

After a session:
- Clear the old files and download a fresh file from this repo for each group running the lab.
- Reset the Arduino board after each group by uploading a blank sketch.
