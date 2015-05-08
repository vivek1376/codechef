//the white knight

#include <stdio.h>
#include <string.h>

long int maxPawn(int i,int j,int n);
long int max(long int,long int,long int,long int);

long int p1=0,p2=0,p3=0,p4=0;
int board[1000][1000]={0};

int knt_x,knt_y;

int main()
{
    int t,n,i,j,index;
    
    //printf("%d",board[10][10]);
    
    /*
     * TEST
     * 
     * char line[1000]="000000012",l[]="2";
    line[50]='2';
    char *pchar;//="1";
    pchar=strstr(line,l);
    if(pchar)
    printf("%s\n",pchar);
    else
    printf("not found\n");*/
    
    char line[1001],*pchar ,*pch_temp;
    
    scanf ("%d", &t);
    while (t--)
    {
        scanf("%d",&n);        //board size
        for(i=0;i<n;i++)
        {
            scanf("%s",line);
            
            pchar=strstr(line,(char *)"K");   //search for knight
            if(pchar!=NULL)
            {
                index=(int)(pchar-line);
                //printf("K position %d\n",index);
                board[i][index]=1;
                knt_x=i;
                knt_y=index;
                //printf("board %d\n",board[i][index]);
            }
            
            //now pawn
            pchar=strstr(line,(char *)"P");
            pch_temp=line;
            index=0;        //reset index
            while(pchar!=NULL)
            {
                index+=((int)(pchar-pch_temp));
                //printf("P position %d\n",index);
                board[i][index]=2;
                //printf("P in board %d\n",board[i][index]);
                pch_temp=pchar;
                pchar=strstr(++pchar,(char *)"P");
            }
        }
        
        
        for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                printf("%d ",board[i][j]);
                
                printf("\n");
            }
        
    }
    
    //maxPawn(knt_x,knt_y,n);
    
    printf("max pawns %ld\n",maxPawn(knt_x,knt_y,n));
    return 0;
    
    
    }
    
long int maxPawn(int x, int y,int n)
{
    if(x>=(n-1))
    return 0;
    
    //n is board size can be upto 1000
    
    long int a=0,b=0,c=0,d=0;
    
    if(y>=2 && (board[x+1][y-2]==2))
    {
        //board[x+1][y-2]=3;
        a=maxPawn(x+1,y-2,n);
        a=a+1;
    }
    if(y>=1 && (board[x+2][y-1]==2))
    {
        //board[x+2][y-1]=3;
        b=maxPawn(x+2,y-1,n);
        b=b+1;
    }
    if(y<=(n-2) && (board[x+2][y+1]==2))
    {
        //board[x+2][y+1]=3;
        c=maxPawn(x+2,y+1,n);
        c=c+1;
    }
    if(y<=(n-3) && (board[x+1][y+2]==2))
    {
        //board[x+1][y+2]=3;
        d=maxPawn(x+1,y+2,n);
        d=d+1;
    }
    
    return max(a,b,c,d);
}

long int max(long int a,long int b,long int c,long int d)
{
    long int max;
    
    max=(a>=b?a:b);
    max=(c>=max?c:max);
    max=(d>=max?d:max);
    
    return max;    
}
