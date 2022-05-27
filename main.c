#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <graphics.h>
#include <X11/Xlib.h>

#include "commands.h"
 
int main(int argc, char** argv)
{
    // Program breaks(I couldn't fix it :<). Tried to use the function
    // the error message recomended.
    XInitThreads();

    // Initializing variables used in menu and stuff for graphics.h
    int gdriver = DETECT, gmode;
    int input, ok, word_number; 

    // While loop for menu
    while(1)
    {
        // Prints a menu on screen
        printf("Please choose one of the following options:\n");
        printf("1: H-Fractal\n2: Fractal Tree\n3: Koch Snowflake(One Side)\n");
        printf("4: Quadric Koch Curve(Type 1)\n5: EXIT\n");
        printf("Input: ");

        // Allocate memory for input line and a copy
        char *command = malloc(100 * sizeof(char)), *copy = malloc(100 * sizeof(char));
        
        // ok and word_number have to be 0 at beggining of each loop
        // ok = 1 if a command has been executed this loop
        ok = 0;
        word_number = 0;

        // Read a command from input and create a copy
        fgets(command, 100, stdin);

        if (command[0] == '\n')
            fgets(command, 100, stdin);

        command[strlen(command) - 1] = '\0';
        strncpy(copy, command, strlen(command) + 1);
        copy[strlen(copy)] = '\0';

        // Work on copy to check number of words. If it is greater than 1
        // the command is invalid and an error is shown
        char *token;
        token = strtok(copy, " ");

        while (token != NULL)
        {
            word_number++;
            token = strtok(NULL, " ");
        }
        word_number--;

        free(copy);
        if (word_number > 0) {
            printf("Invalid command~\n");
            continue;
        } else 
        {
            token = strtok(command, " \n");
            // input = command number 
            input = atoi(token);
        }
        
        // Each if statement corresponds to a menu option
        if (input == 1) {
            ok = 1;

            int order;
            printf("Number of iterations(Rec. = 5): ");
            scanf("%d", &order);

            initgraph(&gdriver, &gmode, NULL);
            OptionOne(order);
        }
        if (input == 2) {
            ok = 1;

            int order;
            printf("Number of iterations(Rec. = 8): ");
            scanf("%d", &order);

            initgraph(&gdriver, &gmode, NULL);
            OptionTwo(order);
        }
        if (input == 3) {
            ok = 1;

            int order;
            printf("Number of iterations(Rec. = 6): ");
            scanf("%d", &order);

            initgraph(&gdriver, &gmode, NULL);
            OptionThree(order);
        }
        if (input == 4) {
            ok = 1;
            
            int order;
            printf("Number of iterations(Rec. = 5): ");
            scanf("%d", &order);
            
            initgraph(&gdriver, &gmode, NULL);
            OptionFour(order);
        }
        if (input == 5) {
            break;
        }
        if (ok == 0) {
            printf("Invalid command.\n");
            continue;
        }

        // Closes window opened by chosen option and
        // frees command line memory
        closegraph();
        free(command);
    }

    return 0;
}