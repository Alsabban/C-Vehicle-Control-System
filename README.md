# C-Vehicle-Control-System

## Vehicle Data
The vehicle is defined as a struct that has 7 attributes
- Engine Status (ON,OFF)
- Traffic Light Reading (R=Red, Y=Yellow, G=Green) (Sensor)
- Vehicle Speed
- Room Temperature (Sensor)
- AC Status (ON,OFF)
- Engine Temperature (Sensor)
- Engine Temperature control status(ON/OFF)

*Sensor readings are read as input from user for simulation*

## Program steps
### Engine Off
Initial state of the engine is **OFF**, the user is asked to choose what to do from the following:
a. Turn on the vehicle engine
b. Turn off the vehicle engine
c. Quit the system

Choosing 'a' turns on the engine and gives the new list of actions to the user.
Choosing 'b' returns the same list to the user.
Choosing 'c' terminates the program.

### Engine On
When the engine is turned on, the user is asked to choose what to do from the following:
a. Turn off the engine
b. Set the traffic light color.
c. Set the room temperature (Temperature Sensor)
d. Set the engine temperature (Engine Temperature Sensor)

*engine must be off to terminate the program*

## Automation
The following list shows what automatically happens when the user changes the sensor readings:
- If the traffic light is ‘G’ set vehicle speed to 100 km/hr
- If the traffic light is ‘O’ set vehicle speed to 30 km/hr
- If the traffic light is ‘R’ set vehicle speed to 0 km/h
- If room temperature less than 10, Turn AC ON and set temperature to 20
- If room temperature is greater than 30, Turn AC ON and set temperature to 20
- If room temperature is otherwise, Turn AC OFF
- If engine temperature less than 100, Turn “Engine Temperature Controller” ON and set temperature to 125
- If engine temperature is greater than 150, Turn “Engine Temperature Controller” ON and set temperature to 125
- If engine temperature is otherwise, Turn “Engine Temperature Controller” OFF
- If vehicle speed is 30 km/hr
    1. Turn ON AC if it was OFF and set room temperature to: current temperature * (5/4) + 1
    2. Turn ON “Engine Temperature Controller” if it was OFF and set engine temperature to: current temperature * (5/4) + 1
- The new vehicle status is displayed

## Bonus preprocessor task
Using `#DEFINE WITH_ENGINE_TEMP_CONTROLLER` and `#IF WITH_ENGINE_TEMP_CONTROLLER`, if the define was 0, anything that has to do with the engine temperature and its controller is not compiled.
Otherwise if the define was 1, everything is compiled normally.
