#include <stdlib.h>

typedef struct Stack {
    char data;
    struct Stack *next;
}node;

void push(node **top, char data) {
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = *top;
    *top = temp;
}

char pop(node **top) {
    char res;
    node *temp = *top;
    res = temp->data;
    *top = (*top)->next;
    free(temp);
    return res;
}

int prec(char a) {
    if(a == '+' || a == '-')
        return 1;
    else if(a == '/' || a == '*')
        return 2;
    else if(a == '^')
        return 3;
    else 
        return 0;
}

char peek(node *a) {
    return a->data;
}

void func(char *a) {
    
    node *s = NULL; 
    int i = 0; 
    while(a[i] != '\0') {
        if((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z')) {
            printf("%c", a[i]);
        }
        else if(a[i] == '(') {
            push(&s, a[i]);
        }
        else if(a[i] == ')') {
            while(s != NULL && peek(s) != '(') {
                printf("%c", pop(&s));
            }
            if(s != NULL && peek(s) == '(')
                pop(&s);
            
        }
        else {
            while( s != NULL && ( prec(a[i]) <= prec(peek(s)) ) )
            {
                printf("%c", pop(&s));
            }
            push(&s, a[i]);
        }
        i++;
    }
    while(s) {
        printf("%c", pop(&s));
    }
    
    printf("\n");
}

int main() {
	int t = 0;
	scanf("%d",&t);
	while(t--) {
	    
	    char a[1001];
	    scanf("%s", a);
	    func(a);
	}
	return 0;
}
