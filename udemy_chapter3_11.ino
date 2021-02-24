//Pin number declaration
int ledPin = 13;
int buttonPin = 2;

//Global variables
int toggleState;
int lastButtonState = 0;
long unsigned int lastPress;
int debounceTime = 20;

void setup()
{
  //Pin modes declaration
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop()
{
  //Read the state of button and store it as buttonState(0 or 1)
  int buttonState = digitalRead(buttonPin);

  //if the time between the last buttonChange is greater than the debounceTime
  if ((millis() - lastPress) > debounceTime)
  {
    //update lastPress
  	lastPress = millis();

    //if button is pressed, and was released last change
    if (buttonState == 0 && lastButtonState == 1)
    {
      //toggle the LED state by mturn its current state to the opposite state	
      toggleState =! toggleState;
      digitalWrite(ledPin, toggleState);
      lastButtonState = 0;
    }

    //if button is pressed, and was pressed last change
    if (buttonState == 1 && lastButtonState == 0)
    {
      //record the last button state
      lastButtonState = 1;
    }

  }

}

/*
millis()

Description
Returns the number of milliseconds since the Arduino board began running the current program. This number will overflow (go back to zero), after approximately 50 days.

Parameters
None

Returns
Number of milliseconds since the program started (unsigned long)
*/