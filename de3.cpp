#include<stdio.h>
#include<stdlib.h>

// Dinh nghia cau truc node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Dinh nghia cau truc stack
typedef struct Stack {
    Node* top;
    int size;
} Stack;

// Khoi tao ngan xep
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

// Tao mot node moi
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Them phan tu vao ngan xep
void push(Stack* stack, int value) {
    Node* newNode = createNode(value);
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
    printf("Da them %d vao ngan xep.\n", value);
}

// Lay phan tu khoi ngan xep
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Ngan xep rong, khong the lay phan tu.\n");
        return -1;
    }
    Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    printf("Da lay %d khoi ngan xep.\n", poppedValue);
    return poppedValue;
}

// Kiem tra phan tu tren cung ngan xep
int peek(Stack* stack) {
    if (stack->top == NULL) {
        printf("Ngan xep rong.\n");
        return -1;
    }
    return stack->top->data;
}

// Kiem tra ngan xep co rong khong
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Lay kich thuoc ngan xep
int size(Stack* stack) {
    return stack->size;
}

// In toan bo ngan xep
void display(Stack* stack) {
    if (stack->top == NULL) {
        printf("Ngan xep rong.\n");
        return;
    }
    Node* current = stack->top;
    printf("Cac phan tu trong ngan xep: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Xoa phan tu ngan xep
void clear(Stack* stack) {
    while (stack->top != NULL) {
        pop(stack);
    }
    printf("Da xoa toan bo ngan xep.\n");
}

// In cac phan tu theo thu tu nguoc lai
void reverse(Stack* stack) {
    if (stack->top == NULL) {
        printf("Ngan xep rong.\n");
        return;
    }
    Node* current = stack->top;
    Node* prev = NULL;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    stack->top = prev;
    printf("Da dao nguoc ngan xep.\n");
    display(stack);
}

int main() {
    Stack* stack = createStack();
    int choice, value;

    do {
        printf("==================MENU=================\n");
	    printf("1. Them phan tu vao ngan xep\n");
	    printf("2. Lay phan tu khoi ngan xep\n");
	    printf("3. Kiem tra phan tu tren cung ngan xep\n");
	    printf("4. Kiem tra ngan xep co rong khong\n");
	    printf("5. Lay kich thuoc ngan xep\n");
	    printf("6. In toan bo ngan xep\n");
	    printf("7. Xoa toan bo ngan xep\n");
	    printf("8. In cac phan tu theo thu tu nguoc lai\n");
	    printf("9. Thoat\n");
	    printf("========================================\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri muon them: ");
                scanf("%d", &value);
                push(stack, value);
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                value = peek(stack);
                if (value != -1) {
                    printf("Phan tu tren cung la: %d\n", value);
                }
                break;
            case 4:
                printf("Ngan xep %s.\n", isEmpty(stack) ? "rong" : "khong rong");
                break;
            case 5:
                printf("Kich thuoc ngan xep: %d\n", size(stack));
                break;
            case 6:
                display(stack);
                break;
            case 7:
                clear(stack);
                break;
            case 8:
                reverse(stack);
                break;
            case 9:
                printf("Da thoat chuong trinh.\n");
                exit (0);
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (1 == 1);

    return 0;
}
