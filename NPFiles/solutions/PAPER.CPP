#include <stdio.h>
#include <conio.h>

#define max(_A,_B) ( (_A)<(_B) ? (_A) : (_B) )
#define min(_A,_B) ( (_A)<(_B) ? (_A) : (_B) )

int N;
int count;
int W; // X
int L; // Y
int s[1000][4];
int w[1000];
int ans=0;

void check(int i, int j)
{
  static int k;

  static int lx1=s[i][0];
  static int mx1=s[i][2];
  static int ly1=s[i][1];
  static int my1=s[i][3];

  static int lx2=s[j][0];
  static int mx2=s[j][2];
  static int ly2=s[j][1];
  static int my2=s[j][3];

  static int canadd=0;

  if (lx2<mx1 && lx1<lx2 || lx1==lx2)
  {
    s[count][0]=lx2;
    s[count][2]=min(mx1, mx2);
    canadd=1;
  }
  if (lx1<mx2 && lx2<lx1 || lx1==lx2)
  {
    s[N][0]=lx1;
    s[N][2]=min(mx1, mx2);
    canadd=1;
  }

  if ( (ly1<my2 && ly2<ly1 || ly1==ly2) && canadd)
  {
    s[count][1]=ly1;
    s[count][3]=min(my1, my2);
  }
  else
    if ( (ly2<my1 && ly1<ly2 || ly1==ly2) && canadd)
    {
      s[count][1]=ly2;
      s[count][3]=min(my1, my2);

    }
    else
      return;


  for (k=0; k<4; k++)
    if (s[i][k]!=s[count][k])
      break;
  if (k==4)
  {

    for (k=0; k<4; k++)
    if (s[j][k]!=s[count][k])
      break;
    if (k==4)
    {
      w[j]=1;
      return;
    }

    w[i]=1;
    return;
  }

  count++;
  w[i]=1;
  w[j]=1;
}

void findX(int l, int r)
{
  int i,j;

  for (i=l; i<r; i++)
    for (j=i+1; j<r; j++)
      check(i, j);
  if (count==r)
    return;
  findX(r, count);
}

int main()
{
  int i, j;

  scanf("%d", &N);
  scanf("%d %d", &L, &W);

  count=N;
  for (i=0; i<N; i++)
  {
    scanf("%d %d", &s[i][0], &s[i][1]);
    s[i][2]=s[i][0]+W;
    s[i][3]=s[i][1]+L;
  }

  findX(0, N);

  for (i=0; i<count; i++)
    if (!w[i])
      ans++;

  printf("%d\n", ans);

  for (i=0; i<count; i++)
    if (!w[i])
      printf("%.1f %.1f\n", (float)(s[i][0]+0.5), (float)(s[i][1]+0.5));
  getch();
  return 0;
}