#define EVENTSIZE 976
#define MAX_CONNECTION 48
#define HEADERLEN 2
#define IPADDRLEN 4
#define EVTNOLEN 4

#include <stdio.h>
#include <stdlib.h>//EXIT_FAILURE
#include <fstream>//filestream(file I/O)
#include <iostream> //cout

using namespace std;
int main(int argc,char **argv)
{
  printf("Hello world\n");
  FILE *fp;
  char filename[128];
  sprintf(filename,argv[1]);
  int nRB=atoi(argv[2]);
  printf("%s\n",filename);
  if((fp=fopen(filename,"r"))==NULL)
  {
    printf("file open error!\n");
    exit(EXIT_FAILURE);
  }

  unsigned int *p_Ntrg[MAX_CONNECTION];
  unsigned int *p_Nevt[MAX_CONNECTION];
  unsigned long Ntrg[MAX_CONNECTION]={0};
  unsigned long Nevt[MAX_CONNECTION]={0}; 

  char event[EVENTSIZE];
  int i=0;
  unsigned long nData=0;
  while(fread(event,EVENTSIZE,1,fp)!=0)
  {
    p_Nevt[i]=(unsigned int*)&event[HEADERLEN+IPADDRLEN];
    p_Ntrg[i]=(unsigned int*)&event[HEADERLEN+IPADDRLEN+EVTNOLEN];
    Nevt[i]=(unsigned long)*p_Nevt[i];
    Ntrg[i]=(unsigned long)*p_Ntrg[i];
    

    // printf("%d",event[3]);
    i++;
    if(i==nRB)
    {
      // cout<<nData<<" ";
      // cout<<Ntrg[0];
      for(int j=0;j<nRB;j++)
      {
	if(j!=0)
	{
	  if(Ntrg[j]!=Ntrg[j-1])
	  {
	    cout<<Ntrg[0];
	    cout<<"<--Ntrg invalid "
		<<j-1<<":"<<Ntrg[j-1]<<","
		<<j  <<":"<<Ntrg[j];
	  }
	}
      }
      // cout<<endl;
      i=0;
      nData++;
    }
  }
  cout<<nData<<"data read."<<endl;
  fclose(fp);
  return 0;
}
