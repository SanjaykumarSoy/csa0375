   #include <stdio.h>

#define ROW 3
#define COL 3

int main() {
    int matrix[ROW][COL] = {{1, 2, 3},
                             {4, 5, 6},
                             {7, 8, 9}};
    
    int max = matrix[0][0];
    
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }
    
    printf("The largest element in the matrix is: %d\n", max);
    
    return 0;
}

