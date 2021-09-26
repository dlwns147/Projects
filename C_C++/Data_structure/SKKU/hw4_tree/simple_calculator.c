#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "binary_tree.h"
#include "stack.h"

#define EXPRESSION_SIZE 128

/* you can define any function you need */

int GetPriority(char oper) {
    if (oper == '(') return 4;
    else if (oper == '*' || oper == '/') return 3;
    else if (oper == '+' || oper == '-') return 2;
    else if (oper == '@' || oper == '#') return 1;
    else return 0;
}

int ComparePriority(char oper1, char oper2) {
    if (GetPriority(oper1) >= GetPriority(oper2)) return true;
    else return false;
};

int main()
{
    /* write your own code here. */
    int iExp_num;
    int iPost_len;
    int iInorder_len;
    char infix[EXPRESSION_SIZE + 1] = { 0, };
    char postfix[EXPRESSION_SIZE + 1] = { 0, };

    Stack operator_stack;
    InitStack(&operator_stack);

    scanf("%d", &iExp_num);
    printf("%d\n", iExp_num);

    for (int i = 0; i < iExp_num; i++) {
        scanf("%s", infix);
        iPost_len = 0;
        iInorder_len = strlen(infix);
        for (int j = 0; j < iInorder_len; j++) {

            // When a character in the infix expression is an operator(a number).
            if (infix[j] >= '0' && infix[j] <= '9') postfix[iPost_len++] = infix[j]; // Put an operator to posffix expression.

            // When a character in the infix expression is an operand.
            else {
                // Put the operands(which is in stack) whose priority is less than the character into the string sequencially 
                while (!IsEmpty(&operator_stack) && ComparePriority(PeekData(&operator_stack), infix[j]) && PeekData(&operator_stack) != '(') {
                    postfix[iPost_len++] = PeekData(&operator_stack);
                    Pop(&operator_stack);
                }
                if (!IsEmpty(&operator_stack) && PeekData(&operator_stack) == '(') Pop(&operator_stack); // When the top element of stack is '(', delete it.
                if (infix[j] != ')') PushData(&operator_stack, infix[j]); // Push the operand into stack except ')'.
            }
            infix[j] = 0;
        }
        // Put the operands left in the stack.
        while (!IsEmpty(&operator_stack)) {
            postfix[iPost_len++] = PeekData(&operator_stack);
            Pop(&operator_stack);    
        }

        BTreeNode *root = MakeExpTree(postfix, iPost_len);
        printf("\t%s\t%d\n", postfix, CalculateExpTree(root));
        DestroyExpTree(root);
        for (int i = 0; i < iPost_len; i++) postfix[i] = 0;
    }
    return 0;
}