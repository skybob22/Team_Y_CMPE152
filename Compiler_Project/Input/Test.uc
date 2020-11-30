//Test seperate declaration and definition
int fib(int in);
void printList(int[] list,int len);
void printMatrix(int[][] matrix,int dim1, int dim2);


void main(void){
    //Test for array access
    int arr[10];
    arr[0] = 5;
    for(int k=0;k<10;k++){
        arr[k] = k*2;
    }
    printList(arr,10);

    int arr2[2][2];
    for(int a=0;a<2;a++){
        for(int b=0;b<2;b++){
            arr2[a][b] =  (a+1) + ((b+1)*2);
        }
    }
    printMatrix(arr2,2,2);

    //Test for loops, recursive function call
    println();
    int i;
    do{
        print("Please Enter Number:");
        read(i);

        int fib_n;
        if(i >= 0){
            fib_n = fib(i);
            println("The ",i,"th fibbonachi number is: ",fib_n);
        }
    }while(i!=-1);
}


void printList(int[] list,int len){
    print("[");
    for(int k=0;k<len;k++){
        print(list[k]);
        if(k < len-1){
            print(",");
        }
    }
    println("]");
    return;
}

void printMatrix(int[][] matrix,int dim1,int dim2){
    for(int i=0;i<dim1;i++){
        print("[");
        for(int j=0;j<dim2;j++){
            print(matrix[i][j]);
            if(j < dim2-1){
                print(",");
            }
        }
        println("]");
    }
}


int fib(int in){
    if(in == 0){
        return 0;
    }
    else if(in == 1){
        return 1;
    }
    else{
        return fib(in-2) + fib(in-1);
    }
}
