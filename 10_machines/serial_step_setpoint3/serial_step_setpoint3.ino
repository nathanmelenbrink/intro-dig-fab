#include <Stepper.h>

const int stepsPerRevolution = 200;  //200 for our steppers.
int rec_int[100];     //array of numbers to be parsed from serial string.  


// initialize the stepper library for two steppers:
Stepper Stepper1(stepsPerRevolution, 11, 10, 9, 8);
Stepper Stepper2(stepsPerRevolution, 7, 6, 5, 4);

int step_count1 = 0;
int step_count2 = 0;

void setup() {
    Serial.begin(0);              //This is the USB serial.
    Serial.setTimeout(20);        //Set wait time for serial data to 20ms (default 1 sec).
    while (!Serial) {;}        //Wait until Serial wakes up.
    Serial.println("ready");
}

void loop() {

  int ind = get_data();           //calls the function that collects serial data.
  
  
  
 for (int i=0; i<ind; i+=2){
  Serial.print(rec_int[i]);
  Serial.print(", ");
  Serial.println(rec_int[i+1]);
  step_to_target(rec_int[i], rec_int[i+1]);     //execute the step function for both motors, using two adjacent array elements.
  }
    
Serial.print(ind);
Serial.println(" integers received");          //how many bytes sent. 
Serial.print("endpoint");
Serial.print(step_count1); 
Serial.print(", "); 
Serial.println(step_count2); 
}
