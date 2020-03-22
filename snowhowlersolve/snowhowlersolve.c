#include <stdio.h>
#include <stdlib.h>


int* books;


int** pages;


int main()
{
    int shelves;
    printf("Enter number of shelves: ");
    scanf("%d", &shelves);

    int queries;
    printf("\nEnter number of queries: ");
    scanf("%d", &queries);

    //Alokacja tablic
    books = malloc(shelves * sizeof(int));

    pages = malloc(shelves * sizeof(int*));

    int a;

    for(a  = 0; a < shelves; a++)
    {
        pages[a] = malloc(1*sizeof(int));
        books[a] = 0;
        pages[a][0] = 0;
    }
    int max = 0;
    while (queries--) {
        int typequery;
        printf("\nWhat you want to do?(type number)\n");
        printf("1)Add book on shelf\n 2)See number of pages\n 3)See number of books\n");
        scanf("%d", &typequery);

        if (typequery == 1) {
            int x, y;
            printf("Enter shelf number(x) and pages of book(y):");
            scanf("%d %d", &x, &y);
            books[x]++;
//Spawdzenie czy ksiazek nie jest wiecej niz max
            if(books[x] > books[max])
            {
              //gdy jest wiecej liczba ksiazek x staj sie maxem
              max = x;
              for(a = 0; a < shelves; a++)
              {
                pages[a] = realloc(pages[a], (books[max]) * sizeof(int));
              }
            }
            printf("\nBook added!\n");

            pages[x][books[x] - 1]  = y;
        } else if (typequery == 2) {
            int x, y;
            printf("\nEnter shelf number(x) and number of pages(y)  ");
            scanf("%d %d", &x, &y);
            printf("\nTotal number of pages is :%d\n", pages[x][y]);
        } else {
            int x;
            printf("\nEnter shelf number(x):");
            scanf("%d", &x);
            printf("\nTotal number of books is %d\n", *(books + x));
        }
    }

    if (books) {
        free(books);
    }

    for (int a = 0; a < shelves; a++) {
        if (*(pages + a)) {
            free(*(pages + a));
        }
    }

    if (pages) {
        free(pages);
    }

    return 0;
}
