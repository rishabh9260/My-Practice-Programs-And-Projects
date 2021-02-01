#include<windows.h>
#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
    float freq[12] = {261.63, 277.18, 293.66, 311.13, 329.63, 349.23, 369.99, 392, 415.3, 440, 466.16, 493.88};
    while(1)
    {
        if(kbhit())
        {
            char ch=getch();
            int key;
            switch(ch)
            {
                case 'q': key = 0; break;
                case 'w': key = 1; break;
                case 'e': key = 2; break;
                case 'r': key = 3; break;
                case 't': key = 4; break;
                case 'y': key = 5; break;
                case 'u': key = 6; break;
                case 'i': key = 7; break;
                case 'o': key = 8; break;
                case 'p': key = 9; break;
                case '[': key = 10; break;
                case ']': key = 11; break;
                default: key = -1; break;
            }
            if(key!=-1)
            {
                Beep(freq[key], 200);
            }
            if(key == -1)
                cout<<"Invalid Key!! Press Ctrl+C to exit"<<endl;
        }
    }
    return 0;
}