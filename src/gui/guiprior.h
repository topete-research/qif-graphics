#ifndef _guiprior
#define _guiprior

#include <vector>
#include <string>
#include <string.h>
#include <stdio.h>
#include "../../libs/raylib/src/raylib.h"
#include "../graphics.h"
using namespace std;

class GuiPrior{
private:
    /* data */
public:
    GuiPrior();

    //------------------------------------------------------------------------------------
    // Attributes
    //------------------------------------------------------------------------------------

    // Const text
    char panelPriorText[CHAR_BUFFER_SIZE];
    char buttonRandomText[CHAR_BUFFER_SIZE];
    string LabelPriorText[NUMBER_SECRETS];

    // Define anchors
    Vector2 AnchorPrior;

    // Define controls variables
    bool TextBoxPriorEditMode[NUMBER_SECRETS];
    char TextBoxPriorText[NUMBER_SECRETS][CHAR_BUFFER_SIZE];

    // Define controls rectangles
    Rectangle recPanel;
    Rectangle recTitle;
    Rectangle recContent;
    Rectangle recButtonRandom;
    Rectangle recLabel[NUMBER_SECRETS];
    Rectangle recTextBox[NUMBER_SECRETS];

    //------------------------------------------------------------------------------------
    // Methods
    //------------------------------------------------------------------------------------

    // Copy the values of a prior array to another
    static void copyPrior(char origin[NUMBER_SECRETS][CHAR_BUFFER_SIZE], char dest[NUMBER_SECRETS][CHAR_BUFFER_SIZE]){
        for(int i = 0; i < NUMBER_SECRETS; i++){
            strcpy(dest[i], origin[i]);
        }
    }
};

#endif