#include<stdio.h>
#include<stdlib.h>

void heapify(int a[], int n) {
    int i, k, v, j, flag;
    for(i = n/2 - 1; i >= 0; i--) {
        k = i;
        v = a[k];
        flag = 0;
        while(!flag && 2*k + 1 < n) {
            j = 2*k + 1;
            if(j+1 < n && a[j] < a[j+1])
                j++;
            if(v >= a[j])
                flag = 1;
            else {
                a[k] = a[j];
                k = j;
            }
        }
        a[k] = v;
    }
}

int main() {
    int n, i, a[10], ch;
    for(;;) {
        printf("\n1. Create Heap");
        printf("\n2. Extract max");
        printf("\n3. Exit");
        printf("\nRead Choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("\nRead no of elements: ");
                scanf("%d", &n);
                printf("\nRead Elements\n");
                for(i = 0; i < n; i++)
                    scanf("%d", &a[i]);
                heapify(a, n);
                printf("\nElements after heap\n");
                for(i = 0; i < n; i++)
                    printf("%d ", a[i]);
                break;
            case 2:
                if(n >= 1) {
                    printf("\nElement deleted is %d\n", a[0]);
                    a[0] = a[n - 1];
                    n--;
                    heapify(a, n);
                    if(n != 0) {
                        printf("\nElements after reconstructing heap\n");
                        for(i = 0; i < n; i++)
                            printf("%d ", a[i]);
                    }
                }
                else
                    printf("\nNo element to delete");
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    }
}