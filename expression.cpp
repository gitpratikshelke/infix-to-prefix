#include<iostream>
#include<string.h>

#include"Stack.cpp"
class exp
{
char inf[10],post[10],pref[10];
    public :
    void inf2post();
    void inf2pref();
    int posteval();
    int preeval();


};
int icp(char x)
    {
        if(x=='+'||x=='-')
        return 1;
        else if(x=='*'||x=='/')
        return 2;
        else if(x=='^')
        return 3;
        else if(x==')')
        return 4;
        else
            return 5;
    }

    int isp(char x)
    {
        if(x=='+'||x=='-')
        return 1;
        else if(x=='*'||x=='/')
        return 2;
        else if(x=='^')
        return 3;
        else if(x=='(')
        return 0;
        else
            return 4;
    }


void exp::inf2post()
{
    stack s;
    int i,j=0;
    cout<<"enter infix expression: ";
    cin>>inf;
    for(int i=0;inf[i]!='\0';i++)
    {
        int x;
        x=inf[i];
        if(isalnum(x))
        post[j++]=x;
        else if(x=='(')
        s.push(x);
        else if(x==')')
        {
            while(x=s.pop()!='(')
            post[j++]=x;
        }
        else{
            while(!s.isEmpty()&&icp(x)<=isp(s.showTop()))
            {
                post[j++]=s.pop();
            }
            s.push(x);
            }

    }

            while(!s.isEmpty())
                post[j++]=s.pop();
            post[j]='\0';
            cout<<"postfix="<<post;

        }



void strrev(char inf[10])
{
    int i, j;
    char temp;
    j==strlen(inf)-1;
    while(i<j)
    {
        temp=inf[i];
        inf[i]=inf[j];
        inf[j]=temp;
        i++;
        j--;
    }
}
void exp::inf2pref()
{
    stack s;char x;int i,j=0;
    cout<<"enter infix expression:";
    cin>>inf;
    strrev(inf);
    for( int i=0;inf[i]!='\0';i++)
    {
        x=inf[i];
        if((isalnum(x)))
        pref[j++]==x;
        else if(x=='(')
        s.push(x);
        else if(x==')')
        {
            while(x==s.pop()!='(')
            pref[j++]=x;
        }
        else{
            while(!s.isEmpty()&&icp(x)<isp(s.showTop()))
            {
            pref[j++]=s.pop();
            }
            s.push(x);
        }

        while(!s.isEmpty())
        {
            pref[j++]=s.pop();
        }
        pref[j]='\0';
        strrev(pref);
        cout<<pref;
    }

}

int main()
  {
    int ch;
    exp e;
    do{

         cout<<"---menu---";
         cout<<"\n1.inf2post\n2.inf2prefix:";
         cout<<"\nenter your choice:";
         cin>>ch;
         switch(ch)
         {
            case 1:
            e.inf2post();
            break;

            case 2:
            e.inf2pref();
            break;

         }
    }while(1);
         return 0;




  }

