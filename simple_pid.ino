/*https://en.wikipedia.org/wiki/PID_controller
add a sensor of some kind and replace "inputValue" with that sensors data such as temputure.
*/

double kp = 0; //Proportional
double ki = 0; //Integral
double kd = 0; //Derivative

float setpoint = 5;
float error, cumError, rateError;
float lastError;
float output;

float inputValue; //Replace this with the temperature.

float dt = 0.01;

void setup() {
   Serial.begin(115200);
   delay(250);
}

void loop() {
  
  error = setpoint - inputValue; //take a input such as a temperature.
  cumError += error * dt; //Amount of error that has accumulated 
  rateError = (error - lastError) / dt; // rate of error 
  output = (kp * error) + (ki * cumError) + (kd * rateError); // ouput of the PID to be used to control a thermostat. 

  lastError = error;

//print all the values.
Serial.print(inputValue);
Serial.print(dt);
Serial.print(setpoint);
Serial.print(error);
Serial.print(cumError);
Serial.print(rateError);
Serial.print(lastError);
Serial.println(output);
}
