int GLOBALA;
int GLOBALB = 7;

int add(int in);
bool not(bool in);

void main(){
  for(int i=0;i<10;i++){
    if(i > 5){
      println("fizz");
    }
    println(i);
  }
}

int add(int in){
  return in+1;
}

bool not(bool in){
  return !in;
}
