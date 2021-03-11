# I Don't Have A Keyboard 
An Arduino based USB Keyboard that uses a serial console as the input

## What is this?
This is my answer to setting up a new computer but not having an external keyboard handy. It takes input from a serial console and (poorly) emulates a USB keyboard.

## Should I use it?
Probably not. You're better off getting a cheap keyboard (I did, not even 2 hours after building this...) but it is handy in a pinch.

## Can I use it?
You're free to do whatever<sup>[1]</sup> you want with this.   
<sub>1. Well almost whatever you want, just [read the license](LICENSE). <sub>
  
## How do I use it?
### Things you'll need
1. An Arduino compatible with the [keyboard library](https://www.arduino.cc/reference/en/language/functions/usb/keyboard/)
1. A USB-Serial Adapter

### Using it
1. Program the arduino with the firmware
1. Connect your USB-Serial adapter to the RX/TX lines on the arduino
1. Connect the adapter to the computer with the keyboard you want to use
1. Open a serial console (for example: `screen /dev/ttyUSB0 9600`)
1. Anything you type in the console will show up on the other end as a key press. 

### Limitations
Because I’m lazy, it will only emulate printable ASCII characters, arrow keys, return and backspace.
