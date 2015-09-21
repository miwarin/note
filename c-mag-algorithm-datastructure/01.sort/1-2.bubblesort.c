#include <stdio.h>
#include <stdlib.h>

#define N 3

int sort[ N ] = { 2, 1, 3 };

void BubbleSort( void )
{
  int i, j, k, flag;
  k = 0;
  do
  {
    flag = 0;
    for( i = 0; i < N - 1 - k; i++ )
    {
      if( sort[ i ] > sort[ i + 1 ] )
      {
        flag = 1;
        j = sort[ i ];
        sort[ i ] = sort[ i + 1 ];
        sort[ i + 1 ] = j;
      }
    }
    k++;
  } while ( flag == 1 );
}

int main( int ac, char** av )
{
  //int i;
  //srand( ( unsigned int )time( NULL ) );
  
  //printf("ソート準備\n");
  //for( i = 0; i < N; i++ )
  //{
  //  sort[ i ] = rand();
  //  printf("%d\n", sort[ i ]);
  //}
  printf("\nソート開始\n");
  BubbleSort();

  printf("\nソート終了\n");
  for( i = 0; i < N; i++ )
  {
    printf("%d\n", sort[ i ]);
  }
  return 0;
}
