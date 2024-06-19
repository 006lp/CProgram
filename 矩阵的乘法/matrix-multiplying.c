#include<stdio.h>
int main()
{
    int m,n,o,p;
    printf("请输入A的行数与列数。\n例如:3 5\n");
    scanf("%d %d",&m,&n);
    printf("请输入B的行数与列数。\n例如:5 3\n");
    scanf("%d %d",&o,&p);
    if(n != o)
    {
        printf("A与B无法进行乘法运算。\n");
        return 0;
    }
    double a[m][n],b[o][p],c[m][p];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<p;j++)
        {
            c[i][j]=0;
        }
    }
    printf("请输入A中元素，按行顺序输入。\n例如:\n    a11 a12\n    a21 a22\n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%lf",&a[i][j]);
        }
    }
    printf("请输入B中元素，按行顺序输入。\n例如:\n    a11 a12\n    a21 a22\n");
    for(int i=0;i<o;i++)
    {
        for(int j=0;j<p;j++)
        {
            scanf("%lf",&b[i][j]);
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<p;j++)
        {
            for(int k=0;k<n;k++)
            {
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
        
    }
    printf("C = \n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<p;j++)
        {
            printf("%lf\t",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}