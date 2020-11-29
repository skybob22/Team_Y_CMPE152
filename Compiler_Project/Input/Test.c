int GLOBALA;
int GLOBALB = 7;

int add(int in);
bool not(bool in);
void p(int in);

void main(){
  int j;
  for(int i=0;i<10;i++){
    if(i == 1){
      println("f1");
    }
    else if(i == 2){
       println("f2");
    }
    else if(i == 3){
      println("f3");
    }
    else if(i == 4){
      println("f4");
    }
    else if(i == 5){
      println("f5");
    }
    else if(i == 6){
      println("f6");
    }
    else{
      j = add(i);
      //println(i);
    }
  }
}

void p(int in){
  println("In: ",in);
  return;
}

int add(int in){
  return in+1;
}

bool not(bool in){
  return !in;
}
