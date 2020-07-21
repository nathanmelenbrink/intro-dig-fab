/*
 * This function steps motors until both targets are reached.  Called from loop().
 */


void step_to_target(int target1, int target2){
  int step_dir1 = 1;                                //The step_dir variables can be 1,-1,or 0.
  int step_dir2 = 1;
  
  while( !( (step_dir1 == 0)&&(step_dir2 == 0) ) ){       //Keep looping until both targets are reached.
    if (target1 - step_count1 > 0) step_dir1 = 1;         //This portion updates motor 1. First check to see which way to go.
    else if (target1 - step_count1 < 0 ) step_dir1 = -1;    //
    else step_dir1 = 0;
    step_count1 += step_dir1;                               //update step count according to next step.

    if (target2 - step_count2 > 0) step_dir2 = 1;          //This portion updates motor 2
    else if (target2 - step_count2 < 0 ) step_dir2 = -1;
    else step_dir2 = 0;
    step_count2 += step_dir2;
    
    Stepper1.step(step_dir1);                       //Now step both, +,-, or 0.
    Stepper2.step(step_dir2);
      
    delay(10);              //delay sets speed.
  }
}
