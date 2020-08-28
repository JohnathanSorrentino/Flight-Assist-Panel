 /* Flight Assist Panel Code V2
  *  by Johnathan Sorrentino
  *  Updated June 27, 2020
  */

#include <Bounce2.h>

// Create Bounce objects for each button.  The Bounce object
// automatically deals with contact chatter or "bounce", and
// it makes detecting changes very simple.

Bounce NextFireGroup = Bounce();
Bounce PrevFireGroup = Bounce();     
Bounce CargoScoop = Bounce();        
Bounce LandingGear = Bounce();       
Bounce Lights = Bounce();
Bounce DeployHPs = Bounce();         
Bounce ChaffLauncher = Bounce();     
Bounce HeatSink = Bounce();          
Bounce FSD = Bounce();
Bounce SilentRunning = Bounce();

void setup() {
  // Configure the pins for active-low input mode with internal pullups 
  // All pins also have external pull-up resistors.

  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP); 
  pinMode(4, INPUT_PULLUP); 
  pinMode(5, INPUT_PULLUP); 
  pinMode(6, INPUT_PULLUP); 
  pinMode(7, INPUT_PULLUP); 
  pinMode(8, INPUT_PULLUP); 
  pinMode(9, INPUT_PULLUP);

  // Assign Bounce objects to pins with 10 ms debounce time

  NextFireGroup.attach(0);  NextFireGroup.interval(10);
  PrevFireGroup.attach(1);  PrevFireGroup.interval(10);
  DeployHPs.attach(2);      DeployHPs.interval(10);
  CargoScoop.attach(3);     CargoScoop.interval(10);
  Lights.attach(4);         Lights.interval(10);
  LandingGear.attach(5);    LandingGear.interval(10);
  ChaffLauncher.attach(6);  ChaffLauncher.interval(10);    
  FSD.attach(7);            FSD.interval(10);   
  HeatSink.attach(8);       HeatSink.interval(10);   
  SilentRunning.attach(9);  SilentRunning.interval(10);
  
  delay(5000);
}

void loop() {
  // Update all the buttons.  There should not be any long
  // delays in loop(), so this runs repetitively at a rate
  // faster than the buttons could be pressed and released.

  NextFireGroup.update();
  PrevFireGroup.update();
  CargoScoop.update();
  LandingGear.update();
  Lights.update();
  DeployHPs.update();
  ChaffLauncher.update();
  HeatSink.update();
  FSD.update();
  SilentRunning.update();

  // These Joystick buttons should act as toggles and remain constantly ON/OFF
  Joystick.button(4, !CargoScoop.read());
  Joystick.button(10, SilentRunning.read());

  // Check each button for "falling" edge.
  // Update SOME Joystick buttons only upon changes.
  // falling = high (not pressed - voltage from pullup resistor)
  //           to low (pressed - button connects pin to ground)
  if (NextFireGroup.fallingEdge()) {
    Joystick.button(1, 1);
  }
  if (PrevFireGroup.fallingEdge()) {
    Joystick.button(2, 1);
  }
  if (LandingGear.fallingEdge()) {
    Joystick.button(5, 1);
    delay(100);
    Joystick.button(5, 0);
  }
  if (Lights.fallingEdge()) {
    Joystick.button(6, 1);
    delay(100);
    Joystick.button(6, 0);
  }
  if (DeployHPs.fallingEdge()) {
    Joystick.button(3, 1);
    delay(100);
    Joystick.button(3, 0);
  }
  if (ChaffLauncher.fallingEdge()) { 
    Joystick.button(7, 1);
  }
  if (HeatSink.fallingEdge()) { 
    Joystick.button(8, 1);
  }
  if (FSD.fallingEdge()) {
    Joystick.button(9, 1);
  }

  // Check each button for "rising" edge. We only
  // care about thes toggle switches which act as
  // momentary push buttons
  
  if (NextFireGroup.risingEdge()) {
    Joystick.button(1, 0);
  }
  if (PrevFireGroup.risingEdge()) {
    Joystick.button(2, 0);
  }
  if (LandingGear.risingEdge()) {
    Joystick.button(5, 1);
    delay(100);
    Joystick.button(5, 0);
  }
  if (Lights.risingEdge()) {
    Joystick.button(6, 1);
    delay(100);
    Joystick.button(6, 0);
  }
  if (DeployHPs.risingEdge()) {
    Joystick.button(3, 1);
    delay(100);
    Joystick.button(3, 0);
  }  
  if (ChaffLauncher.risingEdge()) {
    Joystick.button(7, 0);
  }
  if (HeatSink.risingEdge()) {
    Joystick.button(8, 0);
  }
  if (FSD.risingEdge()) {
    Joystick.button(9, 0);
  }
}
