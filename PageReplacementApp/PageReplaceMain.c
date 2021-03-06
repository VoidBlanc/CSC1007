//
// Created by LIM KEI YIANG on 20/2/22.
//

#include "string.h"
#include "FIFOPageReplacement.h"
#include "OptimalPageReplacement.h"
#include "LRUPageReplacement.h"

#define MAX 200

int main();

int main() {
    char size[MAX] = "";
    char *refStr = size;
    int options = 0, no_of_frames = 0, i;

    // Allocate Memory for Reference LinkedList
    LinkedList *refll = malloc(sizeof(LinkedList));
    printf("Please choose a Page Replacement Algorithm\n");
    printf("Options: \n");
    printf("\t1. First in first out (FIFO) page replacement algorithm\n");
    printf("\t2. Optimal page replacement algorithm\n");
    printf("\t3. Least recently used (LRU) page replacement algorithm\n");
    printf("Enter the options (1, 2 or 3): ");
    refll->head = NULL;
    scanf("%d", &options);
    fflush(stdin);

    printf("Enter the number of Frames : ");
    scanf("%d", &no_of_frames);
    fflush(stdin);

    printf("Enter the reference list : ");
    fgets(refStr, MAX, stdin);

    for (i = 0; i < strlen(refStr); i++) {
        if (*(refStr + i) >= 48 && *(refStr + i) <= 57) {
            insert(refll, (int) (*(refStr + i) - '0'));
        }
    }
    if (options == 1) {
        FIFOPageReplacement(refll, no_of_frames);
    } else if (options == 2) {
        OptimalPageReplacement(refll, no_of_frames);
    } else if (options == 3) {
        LRUPageReplacement(refll, no_of_frames);
    }

    EmptyList(refll);
    free(refll);

    // To prevent non-persistent console from exiting the program immediately
    printf("\nPress ENTER key to end\n");
    getchar();
    return 0;
}
