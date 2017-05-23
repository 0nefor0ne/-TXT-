#include <stdio.h>
typedef struct Student{
	int id;
	char name[20];
	float score;
	}Student;
int  main()
{
	int i,j,k,n = 0;
	int c;
	char ch;
    struct Student *stu = NULL;
	FILE* fp1=fopen("stuin.txt","r");
	FILE* fp2 = fopen("stuout.txt","w");
	while ((!feof(fp1))) if((ch=fgetc(fp1))=='\n') {n++;}//计算行数
    n+=1;
	fclose(fp1);
	FILE* fp3 = fopen("stuin.txt","r");
	stu  = (struct Student*)malloc(sizeof(*stu)*n);
	if(fp3==NULL)

	{
		printf("无文件");
		return -1;
	}
		for(j=0;j<n;j++)
		{
			fscanf(fp3,"%d%s%f",&stu[j].id,&stu[j].name,&stu[j].score);
		}
    Max_Score(stu,n,fp2);
    Average_Date(stu,n,fp2);
    Score_Levels(stu,n,fp2);
	fclose(fp2);
    fclose(fp3);
    printf(" Information in stuout.txt");
	return 0;
}


void Max_Score( Student *stu1,int n,FILE* fp2)//排序算法 冒泡
{
    int j, i,k;
    for( j = 0 ; j< n -1 ; j++){
        for( i = 0 ; i< n-1-j ; i++){
            if(stu1[i].score > stu1[i+1].score){
                Student temp = stu1[i];
                stu1[i]= stu1[i+1];
                stu1[i+1] = temp;
            }
        }
    }
    for(j = 0; j <n-1 ; j++){
        if(stu1[j].score==stu1[n-1].score){
            fprintf(fp2,"成绩最高的人的学号为%d  名字是%s  成绩为 = %f \n",stu1[j].id,stu1[j].name,stu1[j].score);//现在的输出只用于测试

        }
    }
            fprintf(fp2,"成绩最高的人的学号为%d  名字是%s  成绩为 = %f \n",stu1[n-1].id,stu1[n-1].name,stu1[n-1].score);//现在的输出只用于测试
}
 float Average_Score(Student *stu1,int n)//成绩的平均值
 {      int i;
     float Score_sum,Average_score;
     Score_sum = 0;
     for(i = 0 ; i<n ; i++){
     Score_sum += stu1[i].score;
     }
     Average_score = Score_sum/n;
     return Average_score;
 }
 void Average_Date(Student *stu1,int n,FILE* fp2)//已经排序过的数组 显示与平均数相比的各个阶层人数
 {
     int i,high,low,and;
     high = 0;
     low = 0;
     and = 0;
     float Aver_Score;
     Aver_Score  =  Average_Score(stu1, n);
     for(i = 0 ; i < n ;i++ ){
       if( stu1[i].score > Aver_Score){
            high++;
       }
      else if(stu1[i].score == Aver_Score){
            and++;
            printf("%d and = %d\n",i,and);
            printf("stu = %f aver = %f",stu1[i].score,Aver_Score);
        }
        else if(stu1[i].score < Aver_Score){
        low++;
        }
     }
        fprintf(fp2,"平均成绩超过的%d人\n",high);
        fprintf(fp2,"平均成绩等于的%d人\n",and);
        fprintf(fp2,"平均成绩低于的%d人\n",low);
 }
 void Score_Levels(Student *stu1, int n,FILE* fp2 )//打印各阶层的人数及其所占总人数的百分比
 {
     int i;
     float fine,good,medium,pass,fail;
     float percentage;
     fine = 0;
     good = 0;
     medium = 0;
     pass = 0;
     fail = 0;
     for(i=0 ; i<n ; i++){
        if(stu1[i].score>=90.0){
        fine++;
        }
        else if(stu1[i].score>=80&&stu1[i].score<90){
            good++;
        }
        else if(stu1[i].score>=70&&stu1[i].score<80){
            medium++;
        }
        else if(stu1[i].score>=60&&stu1[i].score<70){
            pass++;
        }
        else if(stu1[i].score<59){
            fail++;
        }

     }
        percentage = (fine/n)*100;
        fprintf(fp2,"优秀的人数为%f人 占比为百分之%f\n",fine,percentage);
        percentage = (good/n)*100;
        fprintf(fp2,"良好的人数为%f人 占比为百分之%f\n",good,percentage);
        percentage= medium/n*100;
        fprintf(fp2,"中等的人数为%f人 占比为百分之%f\n",medium,percentage);
        percentage = (pass/n)*100;
        fprintf(fp2,"及格的人数为%f人 占比为百分之%f\n",pass,percentage);
        percentage = (fail/n)*100;
        fprintf(fp2,"不及格的人数为%f人 占比为百分之%f\n",fail,percentage);
 }
