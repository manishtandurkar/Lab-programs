#include<stdio.h>
#include<stdlib.h>
 
void heapify(int a[10], int n) { 
    int i, k, v, j, flag = 0; 
    for(i=n/2; i>=1; i--) { 
        k = i; 
        v = a[k]; 
        while(!flag && 2*k <= n) { 
            j = 2*k; 
            if(j < n) 
                if(a[j] < a[j+1]) 
                    j++;
            else if(v >= a[j]) 
                flag = 1; 
            else { 
                a[k] = a[j]; 
                k = j; 
            } 
        } 
        a[k] = v; 
        flag = 0; 
    } 
} 
 
int main() { 
    int n, i, a[10], ch; 
    for(;;) { 
        printf("\n1. Create Heap"); 
        printf("\n2. Extract max"); 
        printf("\n3. Exit"); 
        printf("\nRead Choice :"); 
        scanf("%d", &ch); 
        switch(ch) { 
            case 1:
                printf("\nRead no of elements :"); 
                scanf("%d", &n); 
                printf("\nRead Elements\n"); 
                for(i=1; i<=n; i++) 
                    scanf("%d", &a[i]); 
                heapify(a, n); 
                printf("\nElements after heap\n"); 
                for(i=1; i<=n; i++) 
                    printf("%d\t", a[i]); 
                break; 
            case 2:
                if(n>=1) { 
                    printf("\nElement deleted is %d\n", a[1]); 
                    a[1] = a[n]; 
                    n--;
                    heapify(a, n); 
                    if(n != 0) { 
                        printf("\nElements after reconstructing heap\n"); 
                        for(i=1; i<=n; i++) 
                            printf("%d\t", a[i]); 
                    } 
                } 
                else 
                    printf("\nNo element to delete"); 
                break; 
            default:exit(0); 
        } 
    } 
}