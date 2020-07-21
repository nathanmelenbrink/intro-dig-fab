int rec_int[100];     //byte array of numbers parsed from serial string.  Received on Serial.

void setup() {
    Serial.begin(0);              //This is the USB serial.
    Serial.setTimeout(20);        //Set wait time for serial data to 20ms (default 1 sec).
        while (!Serial) {             //Wait until Serial wakes up.
    ; 
    }

    Serial.println("ready");
}

void loop() {
    int ind=0;   // index of data array  
    
    while (!Serial.available() ){             //Loop and do nothing until there is a serial character received.
      ;
    }
    
    while(Serial.available()){                //Receive bytes and parse them into integers.
       rec_int[ind] = Serial.parseInt();
       ind++;
       }

   for (int i=0; i<ind; i++){
  
   Serial.print(rec_int[i]);
   Serial.print(", ");
   }
    
   Serial.print(ind);
   Serial.println(" integers received");          //how many bytes sent.
   
}
