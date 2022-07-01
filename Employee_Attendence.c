#include <stdio.h>
#include<string.h>
///////////////////  EMPLOYEE STRUCTURE  ///////////////////////
struct employee{
    char name[100];
    char dob[100];
    char from[100];
    char to[100];
    char mno[100];
    char address[100];
    char role[100];
    int salary;
    char reason[100];
    char status;
    char psd[100];
    char gender[100];
    int count;//no of days present
    int taken;//withdrawed till now
    int amtdatecount;
    struct withdrawamt// to store amt withdraw date
    {
        char date[100];
        int amt;
    }amtdate[100];
    struct present{
        char date[100];
    }present[100];
}emp[100];
int employee_count=1;
/////////////////// ADMIN STTRUCTURE  //////////////
struct admindata
{
    char name[100];
    char no[100];
    char date[100];
    int given;
    int totalgiven;
}ad[100];
int adcount=0;
////////////////////  ADD EMPLOYEE  ///////////////////
void add_employee()
{
    int n;
    printf("\nEnter no of employees to be addded :");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\nEnter Employee name :");
        scanf("%s",emp[employee_count].name);
        printf("\nEnter Date of Birth :");
        scanf("%s",emp[employee_count].dob);
        printf("\nEnter current date :");
        scanf("%s",emp[employee_count].from);
        printf("\nEnter Moblie no :");
        scanf("%s",emp[employee_count].mno);
        printf("\nEnter your Gender :");
        scanf("%s",emp[employee_count].gender);
        printf("\nEnter Address :");
        scanf("%s",emp[employee_count].address);
        printf("\nEnter your Role :");
        scanf("%s",emp[employee_count].role);
        printf("\nEnter your password :");
        scanf("%s",emp[employee_count].psd);
        printf("\nEnter your salary :");
        scanf("%d",&emp[employee_count].salary);
        employee_count=employee_count+1;
        
    }
    
}
//////////////////  DISPLAY EMPLOYEE  ///////////////
void display_employee()
{
    if(employee_count!=1)
    {
        printf("\n\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\t Employees\t<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
        printf("\nName\tDOB\tMobileno\tGender\tAddress\tRole\tSalary");
        for(int i=1;i<employee_count;i++)
        {
            if(emp[i].status!='i'){
                 printf("\n%s\t%s\t%s\t\t%s\t%s\t%s\t%d",emp[i].name,emp[i].dob,emp[i].mno,emp[i].gender,emp[i].address,emp[i].role,emp[i].salary);
            }    
        }
    }
    else
    {
        printf("\n\t\tSorry!!! No Employees found.......");
    }
}
//////////////////  DELETE EMPLOYEE  ///////////////
void delete_employee()
{
    char no[100];
    int t=0;
    if(employee_count!=1)
    {
        display_employee();
        printf("\n Enter Employee mno to be deleted : ");
        scanf("%s",no);
        for(int i=1;i<employee_count;i++)
        {
            if(strcmp(emp[i].mno,no)==0)
            {
                printf("\nEnter current date : ");
                scanf("%s",emp[i].to);
                printf("\nEnter reason for quiting : ");
                scanf("%s",emp[i].reason);
                t=1;
                emp[i].status='i';
            }
        }
        if(t==0)
        {
            printf("\nSorry!!! Enter valid no......... ");
        }
    }
    else
    {
        printf("\n\t\tSorry!!! No Employees found.......");
    }
}
//////////////////  DISPLAY EX EMPLOYEE  ///////////////
void ex_display_employee()
{
    if(employee_count!=1)
    {
        printf("\n\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\t Employees\t<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
        printf("\nName\tDOB\tMobileno\tGender\tAddress\tRole\tSalary");
        for(int i=1;i<employee_count;i++)
        {
            if(emp[i].status=='i'){
                 printf("\n%s\t%s\t%s\t\t%s\t%s\t%s\t%d",emp[i].name,emp[i].dob,emp[i].mno,emp[i].gender,emp[i].address,emp[i].role,emp[i].salary);
                 printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
                 printf("\n>>\tFrom : %s\tTo : %s\tReason : %s",emp[i].from,emp[i].to,emp[i].reason);
                 printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
            }    
        }
    }
    else
    {
        printf("\n\t\tSorry!!! No Employees found.......");
    }
}
///////////////////  EMPLOYEE LOGIN  ////////////////////
void employee_login()
{
    int t=0,c;
    char emp_no[100];
    char emp_psd[100];
    char date[100],timee[100];
    printf("\n******************************************************************************************************");
    printf("\n\n\t*******************************\tLogin\t**************************************\n\n");
    printf("\n******************************************************************************************************");
    printf("\n\t\tUsrename : ");
    scanf("%s",emp_no);
    printf("\n\t\tPassword : ");
    scanf("%s",emp_psd);
    for(int i=1;i<employee_count;i++)
    {
        if(strcmp(emp[i].mno,emp_no)==0&&strcmp(emp[i].psd,emp_psd)==0&&emp[i].status!='i')
        {
            emp[i].count=emp[i].count+1;
            c=emp[i].count;
            printf("\nEnter date : ");
            scanf("%s",emp[i].present[c].date);
            t=1;
        }
    }
    if(t==0)
    {
        printf("\nEnter valid details.......");
    }
}
//////////////////  EMPLOYEE WORKED DAYS  ///////////////
void employee_present_days()
{
    char id[100];
    int c=0;
    printf("\n Enter Employee id");
    scanf("%s",id);
    printf("\n\t\t\tEmployee mno : %s",id);
    printf("\n******************************************************************************************************");
    for(int i=1;i<employee_count;i++)
    {
        if(strcmp(emp[i].mno,id)==0)
        {
            for(int j=1;j<=emp[i].count;j++)
            {
                printf("\n\t\t%d\t%s",j,emp[i].present[j].date);
                c++;
            }
        }
    }
    if(c>0){
        printf("\n******************************************************************************************************");
        printf("\n\t\t Total Days present : %d",c);
        printf("\n******************************************************************************************************");
    }
    else{
        printf("\n\t\tSorry!! No data found....");
    }
}
//////////////////  EMPLOYEE SALARY  ///////////////
void employee_salary()
{
    if(employee_count==1)
    {
        printf("\n\n\tSorry!!! No Data Found.............");
    }
    else{
    printf("\n******************************************************************************************************");
    printf("\n\t\t************************\tSALARY\t******************************");
    printf("\n******************************************************************************************************");
    printf("\nSNO\tNAME\tSALARY");
    for(int i=1;i<employee_count;i++)
    {
        if(emp[i].status!='i'){
            printf("\n%d\t%s\t%d",i,emp[i].name,emp[i].salary);
        }
    }
    }
}
//////////////////  EX EMPLOYEE SALARY  ///////////////
void ex_employee_salary()
{
    if(employee_count==1)
    {
        printf("\n\n\tSorry!!! No Data Found.............");
    }
    else{
    printf("\n******************************************************************************************************");
    printf("\n\t\t************************\tSALARY\t******************************");
    printf("\n******************************************************************************************************");
    printf("\nSNO\tNAME\tSALARY");
    for(int i=1;i<employee_count;i++)
    {
        if(emp[i].status=='i'){
            printf("\n%d\t%s\t%d",i,emp[i].name,emp[i].salary);
        }
    }
    }
}
////////////////  EMPLOYEE CHOICE /////////////
void employee_table()
{
    int choice2;
    printf("\n******************************************************************************************************");
    printf("\n\n\t\t*************************\tEMPLOYEE LIST\t***************************\n\n");
    printf("\n******************************************************************************************************");
    printf("\n\t1.Add Employee.....\n\t2.Delete Employee....\n\t3.Employee Details....\n\t4.Employee present days\n\t5.Salary Details");
    printf("\n******************************************************************************************************");
    printf("\n Enter your choice : ");
    scanf("%d",&choice2);
    switch(choice2)
    {
        case 1:
           add_employee();
            break;
        case 2:
            delete_employee();
            break;
        case 3:
            display_employee();
             break;
        case 4:
            employee_present_days();
            break;
        case 5:
            employee_salary();
            break;
    }
}
////////////////////  EX EMPLOYEE CHOICE  /////////////
void ex_employee_table()
{
    int choice2;
    printf("\n******************************************************************************************************");
    printf("\n\n\t\t*************************\tEX EMPLOYEE LIST\t***************************\n\n");
    printf("\n******************************************************************************************************");
    printf("\n\t1.Employee Details....\n\t2.Employee present days\n\t3.Salary Details");
    printf("\n******************************************************************************************************");
    printf("\n Enter your choice : ");
    scanf("%d",&choice2);
    switch(choice2)
    {
        case 1:
            ex_display_employee();
            break;
        case 2:
            employee_present_days();
            break; 
        case 3:
            ex_employee_salary();
            break;    
    }
}
//////////////////  EMPLOYEE WITHDRAW AMOUNT  ///////////////
void employee_withdraw()
{
    char emp_no[100],name[100];
    char emp_psd[100];
    char date[100];
    int balance,t=0,id,amt;
    printf("\n\t\tUsrename : ");
    scanf("%s",emp_no);
    printf("\n\t\tPassword : ");
    scanf("%s",emp_psd);
    for(int i=1;i<employee_count;i++)
    {
        if(strcmp(emp[i].mno,emp_no)==0&&strcmp(emp[i].psd,emp_psd)==0)
        {
            balance=(emp[i].count*emp[i].salary)-emp[i].taken;
            strcpy(name,emp[i].name);
            t=1;
            id=i;
        }
    }
    if(t==0)
    {
        printf("\nEnter valid details........");
    }
    else{
    printf("\n\tAvailable balance : %d",balance);
    if(balance==0)
    {
        printf("\nSorry!!! Balance Unsufficient......");
    }
    else{
    printf("\n\tEnter the amount u want : ");
    scanf("%d",&amt);
    if(amt>balance)
    {
        printf("\nEnter valid amount........");
    }
    else{
        printf("\nEnter current date : ");
        scanf("%s",date);
        adcount++;
        strcpy(ad[adcount].date,date);
        ad[adcount].given=amt;
        ad[adcount].totalgiven=ad[adcount].totalgiven+1;
        strcpy(ad[adcount].no,emp_no);
        strcpy(ad[adcount].name,name);
        emp[id].amtdatecount=emp[id].amtdatecount+1;
        strcpy(emp[id].amtdate[emp[id].amtdatecount].date,date);
        emp[id].amtdate[emp[id].amtdatecount].amt=amt;
        emp[id].taken=emp[id].taken+amt;
    }
    }
    }
}
//////////////////  EMPLOYEE TRANSACTION HISTROY  ///////////////
void employee_histroy()
{
    char emp_no[100];
    char emp_psd[100];
    int t=0,id,t2=0;;
    printf("\n\t\tUsrename : ");
    scanf("%s",emp_no);
    printf("\n\t\tPassword : ");
    scanf("%s",emp_psd);
    for(int i=1;i<employee_count;i++)
    {
        if(strcmp(emp[i].mno,emp_no)==0 && strcmp(emp[i].psd,emp_psd)==0)
        {
            id=i;
            t2=1;
            for(int j=1;j<=emp[id].amtdatecount;j++)
            {
                t=1;
            }
        }
    }
    if(t==1)
    {
        printf("\n\tSno\tDate\tAmount");
        for(int j=1;j<=emp[id].amtdatecount;j++)
        {
            printf("\n\t%d\t%s\t%d",j,emp[id].amtdate[j].date,emp[id].amtdate[j].amt);
        }
    }
    else{
        if(t2==0)
        {
            printf("\n Sorry!!! No Employee Found");
        }
        else{
            printf("\n\t No Transaction found......");
        }
    }
}
/////////////////// ADMIN AMOUNT DATA ////////////
void ad_amt()
{
    int total=0;
    if(adcount==0)
    {
        printf("\n No Transaction Found......");
    }
    else{
        printf("\nSno\tName\tMobile no\tDate\tAmount");
        for(int i=1;i<=adcount;i++)
        {
            printf("\n%d\t%s\t%s\t\t%s\t\t%d",i,ad[i].name,ad[i].no,ad[i].date,ad[i].given);
            total=total+ad[i].given;
        }
        printf("\n**********************************************************************************");
        printf("\n\t\t\t\tTotal : %d",total);
        printf("\n**********************************************************************************");
        }
}
///////////////////  MAIN FUNCTION  //////////////
int main()
{
    int choice1,choice2,n=1;
    printf("\n\t*********************************\t SENTHIL AGRO FARM\t***********************");
    do{
        printf("\n\t1.Admin....\n\t2.Employee....\n\t3.Ex Employee....");
        printf("\n Enter your choice : ");
        scanf("%d",&choice1);
        switch(choice1)
        {
            case 1:
                printf("\n******************************************************************************************************");
                printf("\n\n\t\t*************************\tADMIN\t***************************\n\n");
                printf("\n******************************************************************************************************");
                printf("\n\t1.Employee Details.....\n\t2.Ex Employee Details....\n\t3.Transaction....");
                printf("\n******************************************************************************************************");
                printf("\n Enter your choice : ");
                scanf("%d",&choice2);
                switch(choice2)
                {
                    case 1:
                        employee_table();
                        break;
                    case 2:
                        ex_employee_table();
                        break;
                    case 3:
                        ad_amt();
                        break;
                }
                break;
            case 2: 
                printf("\n******************************************************************************************************");
                printf("\n\n\t\t*************************\tEMPLOYEE\t***************************\n\n");
                printf("\n******************************************************************************************************");
                printf("\n\t1.Login.....\n\t2.Withdraw....\n\t3.Histroy....");
                printf("\n******************************************************************************************************");
                printf("\n Enter your choice : ");
                scanf("%d",&choice2);
                switch(choice2)
                {
                    case 1:
                        employee_login();
                        break;
                    case 2:
                        employee_withdraw();
                        break;
                    case 3:    
                        employee_histroy();
                        break;
                }
                break;
            case 3:
                printf("\n******************************************************************************************************");
                printf("\n\n\t\t*************************\tEX EMPLOYEE\t***************************\n\n");
                printf("\n******************************************************************************************************");
                printf("\n\t1.Worked Days.....\n\t2.Withdraw....\n\t3.Histroy....");
                printf("\n******************************************************************************************************");
                printf("\n Enter your choice : ");
                scanf("%d",&choice2);
                switch(choice2)
                {
                    case 1:
                        employee_present_days();
                        break;
                    case 2:
                        employee_withdraw();
                        break;
                    case 3:
                        employee_histroy();
                        break;
                }
                break;
        }
        printf("\nPress 1 to continue main function : ");
        scanf("%d",&n);
    }while(n==1);
    return 0;
}



