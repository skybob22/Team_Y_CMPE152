int fib(int in);

void main(void){
  int i=0;
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
