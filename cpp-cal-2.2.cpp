#include<iostream>
#include<string.h>
using namespace std;

class opretor
{
    protected :
        long double final;
        int a[100],c=0, cnt=1,j=0 ,y=0, flag=1;
        char s[100] ,num[100];
        char opr[50] ;
    
    public :
        opretor()
        {
            int i;
            strcpy(s," ");
            strcpy(num," ");
            strcpy(opr," ");
            for(i=0;i<100;i++)
            {  a[i]=0;  }
        }
        void sapretor();
        void convert();
        void number(int);
        void calculate();
};
void opretor :: sapretor()
{
    int i, x=0;
    cnt=0;
    for(i=0 ;i<strlen(s); i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            num[j] = s[i];
            j++;
        }
        else
        {
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
            {
                opr[x] = s[i];
                x++;
            }
            else
            {
                flag = 0;
            }
            num[j] = ' ' ;
            j++;
        }
    }
    
}
void opretor :: convert()
{
    int i;
    for (i = 0; i < strlen(num); i++)
    {
        if((num[i]>='0'&&num[i]<='9') || num[i]==' ')
        {
            switch (num[i])
            {
                case '0':
                    number(0);
                    break;

                case '1':
                    number(1);
                    break;
        
                case '2':
                    number(2);
                    break;
        
                case '3':
                    number(3);
                    break;
        
                case '4':
                    number(4);
                    break;
        
                case '5':
                    number(5);
                    break;
        
                case '6':
                    number(6);
                    break;
        
                case '7':
                    number(7);
                    break;
        
                case '8':
                    number(8);
                    break;
        
                case '9':
                    number(9);
                    break;

                case ' ':
                    if(num[0] == ' ')
                    { continue; }
                    else
                    {
                        c++;
                    }
            }
        }
    }
}
void opretor :: number(int n)
{  a[c] = (a[c] * 10) + n;  }

void opretor :: calculate()
{
    int i;
    final= a[0];
    for(i=0; i<strlen(opr); i++)
    {
        if(opr[i] == '+'|| opr[i] == '-'|| opr[i] =='*' || opr[i] =='/' || opr[i] == '^')
        {
            switch(opr[i])
            {
                case '+':
                    final = final + a[i+1];
                	break;
                    
                case '-':
                	final = final - a[i+1];
                	break;
                    	
               case '*':
                    final = final * a[i+1];
                	break;
                    
                case '/':
                	this->final = this->final / (a[i+1]*1.0);
                	break;
                	
                case '^':
                    final = final *final;
                    break;
            }
        }
    }
}
class opretor2 : public opretor
{
    public :
        int scan()
        {
            int f=0;
            cout << "Enter the string to calculate : ";
            cin.getline(this->s,100);
            
            if(strlen(s)==0)
            {
                return(!f);
            }
            else
            {
                return(f);
            }
        }
        void print()
        {
            if(flag==1)
            {
                cout << " = " << this->final << "\n";
            }
            else
            {
                cout << "Invalide opretor!!\nTry again!!!\n";
            }
        }
        void loop()
        {
                sapretor();
                convert();
                calculate();
                print();
        }
};
int main()
{
    opretor2 c[20];
    int i=0, f=0;
    cout<<"This Program is to Calculate the string which will be given by you to addion, subtraction, multipication, division, which represent as + ,- ,* ,/ respectivily. \nexample:-' 1+2-3*4/5 '.\n\n\n";
    do
    {
       
        f= c[i].scan();
        if(f == 0)
        {  c[i].loop();  }
        else
        {  f = 1; cout<<"Exit program"; }
        i++;
    }while(f==0);
    return(0);
}