#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d", &n);
    int l[n + 1];
    int f, r = 0;

    for (int i = 0; i < n; i++){
        char s[100] = { 0, };
        char s2[5] = { 0, };
        int p;
        scanf(" %[^\n]", s);
	    sscanf(s, "%s %d", s2, &p);

        if (strstr(s, "size"))
            printf("%d\n", (r - f + n) % n);
        
        else if (strstr(s, "empty")){
            if (f == r)
                printf("1\n");
            else
                printf("0\n");
        }

        else if (strstr(s, "front")){
            if (f == r)
                printf("-1\n");
            else
                printf("%d\n", l[f]);
        }

        else if (strstr(s,"back")){
            if (f == r)
                printf("-1\n");
            else
                printf("%d\n", l[(r + n - 1) % n]);
        }

        else if (strstr(s, "pop")){
            if (f == r)
                printf("-1\n");

            else {
                printf("%d\n", l[f]);
                f = (f + 1) % n;
            }
        }

        else if (strstr(s2, "push")){
            l[r] = p;
            r = (r + 1) % n;
        }
    }

    return 0;
}