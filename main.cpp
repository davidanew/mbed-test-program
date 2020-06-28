#include "mbed.h"

PwmOut led1(LED1);

class Menu 
{ 
    public:
    void print_menu(void) 
    { 
        printf ("1 - Turn LED on\n"); 
        printf ("2 - Turn LED on 50pc\n"); 
        printf ("3 - Turn LED off\n"); 
    } 
    void action_for_key(const char key) 
    { 
       printf ("got character %c\n", key); 
       switch(key)
       {
            case '1':
                printf("Turning LED on");
                led1.write(1);
            break;    
                case '2':
                printf("Turning LED on 50pc");
                led1.write(0.5);
            break;      
                case '3':
                printf("Turning LED off");
                led1.write(0);
            break;        
            default:
            break;
       }
    } 
}; 

int main()
{
    Menu menu;
    printf("Running on Mbed OS %d.%d.%d.\n", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);
    menu.print_menu();

    char c;
    while(true)
    {
        c = getchar();
        putchar(c);
        putchar('\n');
        menu.action_for_key(c);
    }
}
