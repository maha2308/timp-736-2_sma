#include <stdio.h>
#include <stdlib.h>

void filtering(int *a, int outerv, int lowerv)
{
    int maxv, stop = 0;
    while ((outerv * 2 <= lowerv) && (!stop))
    {
        if (outerv * 2 == lowerv) {maxv = outerv * 2;}
            else if (a[outerv * 2] > a[outerv * 2 + 1]) {maxv = outerv * 2;}
            else {maxv = outerv * 2 + 1;}
            if (a[outerv] < a[maxv])
            {
                int tmp = a[outerv];
                a[outerv] = a[maxv];
                a[maxv] = tmp;
                outerv = maxv;
            }
            else  {stop = 1;}
    }
}
void heapsort(int *a, int sizea)
{
    for (int i = (sizea / 2) - 1; i >= 0; i--)
        filtering(a, i, sizea);
    for (int i = sizea - 1; i >= 1; i--)
    {
        int tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;
        filtering(a, 0, i-1);
    }
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
    heapsort(a, n);
    for(i = 0;i < n;i++)
    {
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    }
    return 0;
}
