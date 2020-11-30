void main(){
	int j;

	do{
		print("Enter Number: ");
		read(j);
		switch(j){
			case 1:{
				println("The value is 1");
			}
			case 2:{
				println("The value is 2");
			}
			case 3:{
				println("The value is 3");
			}
			case 4:{
				println("The value is 4");
			}
			case 5:{
				println("The value is 5");
			}
			case 6:{
				println("The value is 6");
			}
			default:{
				println("You entered: ",j);
			}
		}
	}while(j > 0);
}
