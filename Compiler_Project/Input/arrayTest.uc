int test[10];

void doArrayStuff(int[] arr,int len);

void main(){
	for(int i=0;i<10;i++){
		test[i] = i;
	}

	doArrayStuff(test,10);
	println();
	println("Now values are:");
	for(i=0;i<10;i++){
		println(test[i]);
	}
	return;
}


void doArrayStuff(int[] arr,int len){
	println("Started");
	println("len: ",len);
	for(int j=0;j<len;j++){
		println("Was: ",arr[j]);
		arr[j] = 100+j;
		println("Now: ",arr[j]);
	}
}
