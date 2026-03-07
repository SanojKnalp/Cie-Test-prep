// Task: Implement these two functions using the 'new' and 'delete' rules

int** createMatrix(int rows, int cols) {
    // 1. Allocate an array of pointers (the rows) 
    int** matrix = new int*[rows];
    // 2. For each row, allocate an array of integers (the columns)
    for(int i=0; i<rows; i++)
    {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; ++j) matrix[i][j] = 0;
    }
    return matrix;
}
void deleteMatrix(int** matrix, int rows)
{
    for(int i=0; i<rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}