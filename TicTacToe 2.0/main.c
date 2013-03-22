//
//  main.c
//  TicTacToe 2.0
//
//  Created by Developer on 18.03.13.
//  Copyright (c) 2013 Developer. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Map.h"



void startMap () {
    for (int i=0; i < 9; i++) {
        addFieldElement('-');
    }
}


int main(int argc, const char * argv[]) {
    startMap();

    printMap();

    return EXIT_SUCCESS;
}
