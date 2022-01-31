#include <stdio.h>
#include<string.h>
#include <Ctype.h>
#include <math.h>

void push(int);
int pop();
void display();
 
 int ch,top=-1;
 int s[25]={0};

        void main(){

        char postfix [25]={'\0'};
        int i=0,num1,num2,ch,ele,ans;

        printf("enter postfix expression:\n");
        scanf("%s",&postfix);

        printf("the postfix expression is:%s",postfix);
        
        while (i<=strlen(postfix)-1)
        {
               ele = postfix [i];
               if (isdigit(ele))
               {
                      push(ele-'0');
               }
               else{
                      num1=pop();
                      num2=pop();
                             switch (ele)
                            {
                            case '^':
                            ans=pow(num2,num1);
                                   
                                   break;
                            case '*':
                            ans=num2*num1;
                                   
                                   break;
                            case '/':
                            ans=num2/num1;
                                   
                                   break;
                            case '+':
                            ans=num2+num1;
                                   
                                   break;
                            case '-':
                            ans=num2-num1;
                                   
                                   break; 
                            
                            }
                            push(ans);
               } 
               display();
               i++;
        }
               printf("\nAnswer=%d",pop());

        }
              void push(int ele){
               if(top==24){
                      printf("staack is full");
               }
               else{
                      top++;
                      s[top]=ele;
               }
        }
              int pop(){
               if(top==-1){
                      printf("\nstack is empty");
               }
               else{
                      ch=s[top];
                      top--;

               }
               return ch;
        }
                     void display(){
                     printf("\noutput  stack=");
                     for (int i = 0; i <= top; i++)
                     {
                      printf("|%d",s[i]);
                     }
               
        }

 