# 89C52-driving-7-segment-display
Using a timer2 interrupt to drive 4 digit 7 segment display  reducing CPU load and brighter display

Boards such as the NH5100 and BK-51 include a 4 digit 7 segment display directly CPU driven.
Driving the 7 segment display directly from the CPU requires 8 bits – 7 for the digit and one for the decimal point.  Then an enable line lights up one segment at a time usually for several milliseconds. 
It is a saving in hardware but under some conditions the 7 segment display is very faint because the CPU is being used for other functions – not sitting in a delay loop to keep the LED powered.
Ideally for a 4 segment display each segment would stay lit for 25% of the time but this means the CPU has zero  time left for other functions.  By creating an interrupt driven routine to operate the 7 segment display, maximum brightness is provided with minimum CPU overhead.
The application program merely places the data to be displayed – already translated to 7 segment code – into 4 bytes of  static RAM.  The interrupt routine looks after the display task with minimal CPU overhead.  Coding the 89C52 or 89S52 is a delight due to the bit oriented instructions. These allow the other 4 bits of P1 to be available for other purposes.

