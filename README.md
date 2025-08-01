# **Home automation system**
This project simulates a smart room automation system using an Arduino. It intelligently controls room lighting, temperature-based fan activation, and a basic security alert mechanism. The system uses sensor inputs to make decisions and control outputs like a fan (servo motor), LED light, and a buzzer, creating an automated and responsive environment.

## Components
| Component      | Pin      | Description   |
| ------------- | ------------- | ------------- |
| LDR (Light Sensor) | AO | Detects ambient light levels. Used for controlling the LED based on darkness.|
| PIR Motion Sensor | 8 |Detects motion/presence of a person in the room.|
| Push Button (Switch)| 4 | Simulates a door or window trigger for the security system.|
| Buzzer | 2 | Sounds an alarm when motion is detected and the switch is active (simulating a security breach) |
| TMP36 (Temperature Sensor) | A1 | Monitors room temperature and triggers the fan when temperature exceeds threshold.|
| Servo Motor (Fan Simulation) | 10 | Simulates a fan. Rotates back and forth when temperature is high.|
| LED | 13 | Represents room light. Turns on when motion is detected in darkness.|

## Simulation 

[Tinker cad simulation Link](https://www.tinkercad.com/things/h52kM4YNCut-embeded-project-)

https://github.com/user-attachments/assets/260944d8-d86b-46ea-a96e-6b78d05e4589


