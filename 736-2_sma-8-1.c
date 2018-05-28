#include <stdlib.h>
#include <stdio.h>

void quicksort(int a[], int lborder, int rborder) {
      int i = lborder, j = rborder;
      int tmp;
      int pivot = a[(lborder + rborder) / 2];
      while (i <= j) {
            while (a[i] < pivot)
                  i++;
            while (a[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = a[i];
                  a[i] = a[j];
                  a[j] = tmp;
                  i++;
                  j--;
            }
      };
      if (lborder < j)
            quicksort(a, lborder, j);
      if (i < rborder)
            quicksort(a, i, rborder);
}

int main ()
{
    int n, i;
    int *a;
    scanf("%d", &n);
    a  =  (int *)calloc(n, sizeof(int));
    for (i = 0;i< n;i++)
    {
        scanf("%d", &a[i]);
    }
    quicksort(a, 0, n-1);
    for(i = 0;i < n;i++)
    {
        printf("%d ", (a[i]));
    }
    printf("\n");
    return 0;
}
