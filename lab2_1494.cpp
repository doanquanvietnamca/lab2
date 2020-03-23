#include <stdio.h>
 
int stack[100001];
int top;
 
int main(){
 
	int numOfBalls;
	scanf("%d", &numOfBalls);
 
	top = 0;
	int ballToPocket = 1;
 
	int i;
	for (i = 1; i <= numOfBalls; i++){
		int ballTakenOut;
		scanf("%d", &ballTakenOut);
 
		while (stack[top] != ballTakenOut && ballToPocket <= numOfBalls){
			stack[++top] = ballToPocket;
			ballToPocket++;
		}
 
		if (top && stack[top] == ballTakenOut)
			top--;
	}
 
	printf("%s\n", top ? "Cheater" : "Not a proof");
	
	return 0;
}
