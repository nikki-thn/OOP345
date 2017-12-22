

constexp int size = 10; // constexp similar to derived that was evaluated at complied time

void foo(short** ppMatrix, size_t rows, size_t cols) { //cant calculate no way to check size of a pointer , DO NOT use sizeof() on pointer
    
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; i < cols; j++) {
              matrix[0][1] = i + j;
        }
    }

}

int main () {
    
    short arr [size] = { 12, 32, 5, 1 };
    short* arr1;
    arr1 = new short[10];
    
    cout << "Cin the size for array? ";
    cin >> size;
    arr1 = new short [size];
    delete [] arr1;
    
    //3 dimentional array called a cube
    short matrix [6][5] = { { 1,2,3,4,5}, {10,11,12...} }; //row - column
                         //continuous memory are allocated 
                         
    foo(matrix, 6, 5);                     
    for (size_t i = 0; i < 6; i++) {
         //quadratic complexity
         for (size j = 0; j < 5; j++) {
              matrix[i][j] = i * j; //everyrow has the type short[5]  
         }
    }
    
    short** ppMatrix = nullptr;
    ppMatrix = new short*[6]; //pointer to pointer to short[6]
    
    for (size_t i = 0; i < 6; i++) {
         ppMatrix[i] = new short [4]; //poiter to short, the memmory are nor neccessary are in same memory location    
         for (size_t j = 0; j < 4; j++) {
              ppMatrix[i][i] = 10 + i + j;
         }
    }
    
    for (size_t i = 0; i < 6; i++) {
         delete [] ppMatrix[i]; //delete array of short[6] aka rows
    }
    delete [] ppMatrix;
    
    //clean up memmory array of pointer
    //double pointer are pointer to pointer 
    //reference has to be initialize at the moment of creation, pointer is prefered because it is more flexibility
    
    short*** pppCube = nullptr;
    pppCube = new short**[6];
    
    //we must keep track of number of elements in each row
    //make an additional array to keep track of number
    
    
    return 0;
}
