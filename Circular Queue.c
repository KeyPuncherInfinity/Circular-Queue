#include<stdio.h>
#include<conio.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;


void insert(int data){

	if(!(((front == rear+1) && (front != 0)) || ((rear == SIZE-1) && (front == 0)))){

		if((front == -1) && (rear == -1)){
			front = 0;
			rear = 0;
			queue[rear] = data;
		}
		else if((rear == SIZE-1) && (front != 0)){

			rear = 0;
			queue[rear] = data;
		}
		else{

            rear++;
			queue[rear] = data;
		}


	}
    else
        printf("Queue Full\n");
    
}


int delete1(){

	int data;

	if((front != -1) && (rear != -1)){
		data = queue[front];

		if(front == SIZE-1){
			front = 0;
		}
		else{

			front++;
		}

        if(front == rear+1){
            front = rear = -1;
        }

        return data;

	}
	else{
		printf("Queue is empty\n");
		return NULL;
	}
}

void display(){
	int i;
    printf("front = %d \n",front);
    printf("rear = %d \n",rear);
	for(i=front;(i!=rear);i++){

		if(i == SIZE)
			i = 0;

		printf("%d - %d\n",queue[i],i);

	}

}


int main(){

	int element,choice;

	while(1){
		printf("\nEnter the choice\n");
		printf("1. Enter element\n");
		printf("2. Delete from Queue\n");
		printf("3. Print Queue\n");
		printf("4. Exit\n");

		scanf("%d",&choice);

		switch(choice){
			case 1:
			printf("Enter the element to insert into the q\n");
			scanf("%d",&element);
			insert(element);
			break;

			case 2: element = delete1();
			printf("%d",element);
			break;

			case 3: display();
			break;

			case 4: return 0;
		}

	}
    return 0;

}