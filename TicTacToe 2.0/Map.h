//
//  Map.h
//  TicTacToe 2.0
//
//  Created by Developer on 22.03.13.
//  Copyright (c) 2013 Developer. All rights reserved.
//

#ifndef TicTacToe_2_0_MAP_H
#define TicTacToe_2_0_MAP_H

typedef struct field {
    char            fieldValue;
    
    struct field*   next;
    struct field*   previous;
    
} Field;

typedef struct point {
    int x;
    int y;

} Point;


#define TTT_FieldDown(current) ((Field*)current->next->next->next)

Field* firstElement = NULL;

void addFieldElement (char fieldValue) {
    Field* current = firstElement;
    Field* currentPrevious;
    
    while (current != NULL) {
        currentPrevious = current;
        current = current->next;
    }
    
    current = malloc(sizeof(Field));
    current->fieldValue = fieldValue;
    
    if (currentPrevious != NULL) {
        currentPrevious->next = current;
    }
    
    current->previous = currentPrevious;
    
    if (firstElement == NULL) {
        firstElement = current;
    }
}

Point enterCoordiantes () {
    Point point;
    printf("Spalte(1-3):");
    scanf("%d\n", &point.x);
    printf("Zeile(1-3):");
    scanf("%d\n", &point.y);

    point.x--;
    point.y--;
    
    return point;
}

Field* fieldCoordinates (Point point, Field* current) {

    for (int x = point.x; x > 1; x--) {
        for (int y = point.y; y > 1; y--) {
            current = TTT_FieldDown(current);
        }
        current = current->next;
    }
    
    return current;
}

void printMap () {
    int i = 0;
    Field* current = firstElement;
    
    while (current != NULL) {
        printf("%c ", current->fieldValue);
        current = current->next;
        
        i++;
        if (i % 3 == 0) {
            printf("\n");
        }
    }
}





#endif
