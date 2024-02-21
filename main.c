#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Fill_Matrix(FILE *infile,int years[], int quantity[][4]);
void Print_Matrix(int years[], int quantity[][4]);
void compute_sum(int years[], int quantity[][4], float years_sum[]);
void Sort(int years[], int quantity[][4], float years_sum[]);
void Print_Average(int years[], int quantity[][4], float years_sum[]);

int main()
{

    FILE *infile;
    infile = fopen("rains.txt", "r");

    int i;
    int years[10];
    int quantity[10][4];
    float years_sum[10];

    Fill_Matrix(infile, years, quantity);
    Print_Matrix(years, quantity);
    compute_sum(years, quantity, years_sum);
    Sort(years, quantity, years_sum);
    printf("\n");
    printf("         years           The 4 months readings          The 4 months Sum \n         ----            ---------------------          ----------------\n ");
    Print_Average(years,quantity, years_sum);


    return 0;
}

void Fill_Matrix(FILE *infile,int years[], int quantity[][4])
{
    int i,j;
    for(i=0; i<10 ; i++)
    {
        fscanf(infile,"%d",&years[i]);

        for( j=0; j<4; j++)
        {
            fscanf(infile,"%d",&quantity[i][j]);
        }
    }

}

void Print_Matrix(int years[], int quantity[][4])
{
    int i,j;
    for(i = 0 ; i < 10 ; i++)
    {
        printf("%d  ", years[i]);

        for( j=0 ; j<4 ; j++)
        {
            printf("%d ", quantity[i][j]);
        }

        printf("\n");
    }


}

void compute_sum(int years[], int quantity[][4], float years_sum[])
{
    int i;
    int j;
    for(i=0 ; i<10 ; i++)
    {
        years_sum[i]=0;
        for(j=0 ; j<4 ; j++)
        {
            years_sum[i]+= quantity[i][j];
        }
    }

}
void Sort(int years[], int quantity[][4], float years_sum[])
{
    int i;
    int j;
    int k;
    float temp1;
    int temp2;
    int temp3;

    for(i=0 ; i<10 ; i++)
    {
        for(j=0 ; j<10 ; j++)
        {
            if (years_sum[j]<years_sum[j+1])
            {
                temp1 = years_sum[j];
                years_sum[j] = years_sum[j+1];
                years_sum[j+1] = temp1;

                temp2 = years[j];
                years[j] = years[j+1];
                years[j+1] = temp2;

                for(k=0 ; k<4 ; k++)
                {
                    temp3 = quantity[j][k];
                    quantity[j][k] = quantity[j+1][k];
                    quantity[j+1][k]= temp3;
                }
            }
        }
    }

}

void Print_Average(int years[], int quantity[][4], float years_sum[])
{
    int i;
    for(i=0 ; i<10 ; i++)
    {
        printf(" \t %d     \t %d   %d   %d   %d\t\t %0.2f\n",years[i],quantity[i][0], quantity[i][1], quantity[i][2], quantity[i][3], years_sum[i]);
    }

}

