# Keylogger Program in C++
# Overview
This keylogger program, developed as part of my internship at Prodigy Infotech, captures and stores keystrokes entered by the user in real time. 
It handles various special keys and can differentiate between uppercase and lowercase letters. The program starts logging when the user presses 'Y' or 'y' and exits when 'Control' and 'C' are pressed simultaneously.

# Features
Captures and logs keystrokes in real time.
Handles special keys such as BACKSPACE, RETURN, SPACE, TAB, SHIFT, CONTROL, and ESCAPE.
Differentiates between uppercase and lowercase letters.
Starts logging when 'Y' or 'y' is pressed.
Exits logging when 'Control' and 'C' are pressed simultaneously.
Code Explanation
The program uses the Windows API to capture keystrokes and logs them into a file named log.txt.

# Key Functions
LogKeystroke(int key_stroke, const char *file): Logs each keystroke to the specified file. 
Handles special keys and differentiates between uppercase and lowercase letters.
