#include <stdio.h>
#include <stdlib.h>

/*
 * This stores the total number of books in each shelf.
 */
int* total_number_of_books;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
int** total_number_of_pages;
int main() {
    int total_number_of_shelves;
    if (scanf("%d", &total_number_of_shelves) != 1) return 1;
    
    int total_number_of_queries;
    if (scanf("%d", &total_number_of_queries) != 1) return 1;
    
    // Allocate memory for tracking books on each shelf and initialize to 0
    total_number_of_books = (int*)calloc(total_number_of_shelves, sizeof(int));
    
    // Allocate memory for array of pointers representing pages on each shelf
    total_number_of_pages = (int**)malloc(total_number_of_shelves * sizeof(int*));
    for (int i = 0; i < total_number_of_shelves; i++) {
        *(total_number_of_pages + i) = NULL;
    }
    
    while (total_number_of_queries--) {
        int type_of_query;
        if (scanf("%d", &type_of_query) != 1) break;
        
        if (type_of_query == 1) {
            int x, y;
            if (scanf("%d %d", &x, &y) != 2) break;
            
            // Increment the count of books on shelf x using pointer arithmetic
            *(total_number_of_books + x) += 1;
            
            // Reallocate memory for shelf x to accommodate the new book
            *(total_number_of_pages + x) = (int*)realloc(*(total_number_of_pages + x), *(total_number_of_books + x) * sizeof(int));
            
            // Insert the number of pages 'y' at the end of shelf x
            *(*(total_number_of_pages + x) + (*(total_number_of_books + x) - 1)) = y;


        } else if (type_of_query == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        } else {
            int x;
            scanf("%d", &x);
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    if (total_number_of_books) {
        free(total_number_of_books);
    }
    
    for (int i = 0; i < total_number_of_shelves; i++) {
        if (*(total_number_of_pages + i)) {
            free(*(total_number_of_pages + i));
        }
    }
    
    if (total_number_of_pages) {
        free(total_number_of_pages);
    }
    
    return 0;
}
