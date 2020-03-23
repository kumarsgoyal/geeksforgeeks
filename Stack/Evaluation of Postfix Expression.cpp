#include <stdlib.h>

typedef struct Stack {
    int data;
    struct Stack *next;
}node;

void push(node **a, int b) {
    node *temp = (node *)malloc(sizeof(node));
    temp->data = b;
    temp->next = *a;
    *a = temp;
}

int pop(node **a) {
    int res = 0;
    node *temp = *a;
    
    res = temp->data;
    *a = (*a)->next;
    free(temp);
    return res;
}

void func(char *a) {
    node *n = NULL;
    int temp = 0;
    int num1 = 0;
    int num2 = 0;
    int sum = 0;
    int i = 0;
    while(a[i] != '\0') {
        temp = (int)(a[i] - '0');
        if(temp >= 0 && temp <= 9) {
            push(&n, temp);
        }
        else {
            num1 = pop(&n);
            num2 = pop(&n);
            switch(a[i]) {
                case '-' : sum = num2 - num1;
                    break;
                case '+' : sum = num2 + num1;
                    break;
                case '*' : sum = num2 * num1;
                    break;
                case '/' : sum = num2 / num1;
                    break;
            }
            push(&n, sum);
        }
        i++;
    }
    int res = pop(&n);
    printf("%d\n", res);
}

int main() {
	//code
	int t = 0;
	scanf("%d", &t);
	
	while(t--) {
	    char a[101];
	    scanf("%s", a);
	    func(&a);
	}
	return 0;
}
