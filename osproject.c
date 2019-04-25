/* CPU schedule N processes which arrive at different time intervals and each process is allocated the cpu for a specific user input
time unit, processes are scheduled using a preemptive round robin scheduling algorithm . each processes must be assigned a numerical priority with
a higher number indicating a higher relative priority.in addition to the processes one task has priority 0. the length of a time quantum T units where 
T is the custom time considered as time quantum for processing. if a process is preempted by a higher priority process the preempted process is placed
at the end of the queue.
Design a scheduler so that the task with priority 0 does not starve for resources and gets the cpu at some time unit to execute.also compute waiting time
and turn around time
********************************************************************************************************************************************************
we use formula for 
1. turn around time=Exit time - arriaval time
2. waiting time = turn arround time - burst time
*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
  int n,i,j,pt[10],pr[10],temp1,wt[10];
  char p[10][5],temp[10];
  printf("\t\t\t\t\tenter no of processes:\n");
  printf("\t\t\t\t####################################\n");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
  printf("\t\t\t\t\tenter process%d name:\n",i+1);
  printf("\t\t\t\t####################################\n");
  scanf("%s",&p[i]);
  printf("\t\t\t\t\tenter process time:\n");
  printf("\t\t\t\t####################################\n");
  scanf("%d",&pt[i]);
  printf("\t\t\t\t\tenter priority:\n");
  printf("\t\t\t\t####################################\n");
  scanf("%d",&pr[i]);
  }
  for(i=0;i<n-1;i++)
  {
     for(j=i+1;j<n;j++)
      {
        if(pr[i]<pr[j])
        {
          temp1=pr[i];
          pr[i]=pr[j];
          pr[j]=temp1;
          temp1=pt[i];
          pt[i]=pt[j];
          pt[j]=temp1;
          strcpy(temp,p[i]);
          strcpy(p[i],p[j]);
          strcpy(p[j],temp);
        }
      }
  }
  printf("process-name\t process_time\t\t priority\n");
  for(i=0;i<n;i++)  
  {
   printf("%s\t\t\t %d\t\t %d\n" ,p[i],pt[i],pr[i]);
  }
  printf("#############################################################################################################\n");
  printf("Waiting time and Turn arround time of processes\n");
  wt[0]=0;
  for(i=1;i<n;i++)
  {
   wt[i]=wt[i-1]+pt[i-1];
   //printf("%d\n",wt[i]);
  }
  printf("process-name\t process_time\t\t priority\t waiting-time\n");
  for(i=0;i<n;i++)  
  {
   printf("%s\t\t\t %d\t\t %d\t\t %d\n" ,p[i],pt[i],pr[i],wt[i]);
  }
   getch();
}
