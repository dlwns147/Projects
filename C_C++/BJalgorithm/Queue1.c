#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *s1, const void *s2){
    return -(strcmp((char*)s1, (char*)s2));
}

int main(){
    int n;
    scanf("%d", &n);
    char l[n][6];
    memset(l, 0, n * 6);
    for (int i = 0; i < n; i++)
    {
        char name[6] = { 0, };
        char inout[6] = { 0, };
        scanf("%s %s", name, inout);

        if (!strcmp(inout, "enter"))
            strncpy(l[i], name, 5);

        else if (!strcmp(inout, "leave")){
            for (int j = 0; j < n; j++){
                if (!strcmp(l[j], name)){
                    memset(l[j], 0 , 6);
                    break;
                }
            }
        }
    }

    qsort(l, n, 6, compare);

    for (int i = 0; i < n; i++)
        if (*l[i])
            printf("%s\n", l[i]);

    return 0;
}