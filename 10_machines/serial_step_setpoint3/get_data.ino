
int get_data(){
  
int index=0;   // index of data array  
    
while (!Serial.available() ){;}            //Loop and do nothing until there is a serial character received.
  
while(Serial.available()){                //Receive bytes and parse them into integers.
   rec_int[index] = Serial.parseInt();    //save these in the rec_int array, which is a global variable.
   index++;
   }
return index-1;                              //returns the number of integers received.
   
}
