/*
�����㷨�������Ժ��ַ�ʽ�ﵽ24��һ����һ�����������������
ö��һ�������������㣬ö��һ������λ�ã�Ȼ����������ߺ��ұ��ټ�����
�����߻����ұ��в�ֹһ�����֣���ô��Ҫ�������
1.���ȣ�ͨ��ö�٣������ĸ�������һ���Ĵ����ź�
  ��һ���ַ����������ѣ�һ��ʼ���ַ���Ϊ��1234����ʾ���ĸ���ŵ����֣��м�û�������
2.Ȼ�󣬿�ʼ���ѡ���dfs(i,j,c)��ʾ�ڵ�i������j����֮�䣬��Ҫ��������,�����Ϊc 
  ��1�� Ūһ��k����ʾ�ڵ�k�����͵�k+1����֮����Ҫһ�����������k��i��j-1ö��
  ��2���Ҷ�һ��λ�ú󣬰��Լ������ַ�����Ȼ����һ���Լ�����ж��ٸ����֣������������1����ô�Ӹ����ţ�Ȼ�������
       �����������1����ôʲôҲ����
  ��3���ұ��Դ�����
3.ͨ���������ǵõ���һ�����ʽ��Ȼ�����ñ��ʽ����󷨣���������ǲ���24������ǣ�������ʽ��������ǣ��������

1.0�浮����1.����һ��ΰ���ʱ�� 
2.0����£�1.�㷨��ģ��޸����ųɵ�bug 
2.5����£�1.ȥ���˺ܶ��ظ��Ĵ�2.�������۸���ȫ�棬����©��3.������������4.����ͳ�ƴ�����5.����ʾ��
2.7����£�1.ȥ�����ظ������ţ�����һ������£� 2.ǿ���޸���˫������ʽĩβĪ����������ţ��Ӷ�ȥ�������ظ��� 
2.9����£�1.�����������źʹ����� 2.������ĳЩ����ɾ������ 
3.1����£�1.רҵ����ǿ��֢�����д𰸰����ȴ�С����
3.5����£�1.�޸���������ɫ 2.������ʽ������ϵͳ 3.����������� 
3.6����£�1.���������ԣ��޸��˴��ڲ�ƥ���bug,�����������Ի� 
4.6����£�1.��������ģʽ 2.�����޸ģ�����˴𰸽϶�ʱ����Ĵ𰸿�������bug 
4.7����£�1.�޸��˳���ģʽ���޷��б������ظ������ֶ����bug 
4.8����£�1.�޸��˳���ģʽ��ĳЩ��ȷ�Ĵ𰸱����е�bug 2.�޸��˳���ģʽ���޷��ж��ĸ������Ƿ񶼱�ʹ�����bug 
4.9����£�1.����ģʽ�����Ʒ�ϵͳ 2.����ģʽ������ʾ�𰸵��Ѷȣ���Ȼ˵���Ѷȵ��жϲ����Ǻ��Ͻ��� 
5.1����£�1.����ģʽ����ѡ���Ѷ� 2.���ֽ������� 
5.2����£�1.�޸���һ���й����ŵ�bug 2.�޸��˳���ģʽһ���йؿո��bug 3.�Ѷ�����
5.3����£�1.����ģʽ���Լ�¼ʱ�䲢��ʾƽ����ʱ 
*/ 
#include<bits/stdc++.h>
#include<windows.h>
using namespace std;				
int a[5],data[5];//data���ĸ�����a��ö��״̬��4���� 
char d[501][101],b[101];  //d��ĿǰΪֹ�Ĵ𰸣���ֹ�ظ�(dnumΪ���ɱ��ʽ�е����֣�,b�����ɵı��ʽ 
string ans;
int topd=0,topb=0,dnum[501][5],dlength[501];
void gaikuohao(){//�޸�������ʽ 
	//�����ܼ򵥣����岻˵��
	for(int i=0;i<=topb;i++)
	  if(b[i]=='('){
	  	  int rpair,anotherpair=0,otherpair=0;
	  	  for(rpair=i+1;rpair<=topb;rpair++){
	  	  	  if(b[rpair]=='(') anotherpair++;
	  	  	  if(b[rpair]==')') anotherpair--;
	  	  	  otherpair=max(otherpair,anotherpair);
	  	  	  if(anotherpair<0) break;
	  	  }
	  	  if(otherpair==1) b[i]='[',b[rpair]=']';
	  	  if(otherpair>=2) b[i]='{',b[rpair]='}';
	  }
	return;
}
void qukuohao(){//ȥ�����Ų��� 
	/*����һ�������ж�ô���ӣ�������һ��ֻ����������ֶ�����1.һ�������  2.�������
	����������һ������ֻ��һ�����������Ҫô����ǰ�棬Ҫô��������
	�������ڵ��������������ĵȼ����жԱȣ����������ĵȼ�С�ڵ��������ڵģ��Ϳ��԰��������ɾ��*/
	int rk[200];
	rk['+']=rk['-']=1;
	rk['*']=rk['/']=2;
	for(int i=0;i<=topb;i++)//ע�⣺һ��Ҫ��ɾ��ߵ�������ɾ�ұߵ����ţ���Ȼ�ᵼ�»��� 
	  if(b[i]=='('){
	  	  int rpair,anotherpair=0;//rpair��¼�������������ƥ��������ŵ�λ��,anotherpair���Է�ֹ������ŵ�Ӱ�� 
	  	  for(rpair=i+1;rpair<=topb;rpair++){
	  	  	  if(b[rpair]=='(') anotherpair++;
	  	  	  if(b[rpair]==')') anotherpair--;
			  if(anotherpair<0) break;
	  	  }
	  	  int symout,symin;//�ֱ��¼���������ķ��� 
	  	  if(i>0 && (b[i-1]=='+' || b[i-1]=='-' || b[i-1]=='*' || b[i-1]=='/')) symout=i-1;
	  	  if(rpair<topb && (b[rpair+1]=='+' || b[rpair+1]=='-' || b[rpair+1]=='*' || b[rpair+1]=='/')) symout=rpair+1;
	  	  anotherpair=0;
	  	  for(symin=i+1;symin<rpair;symin++){
	  	  	  if(b[symin]=='(') anotherpair++;
	  	  	  if(b[symin]==')') anotherpair--;
	  	  	  if(anotherpair==0 &&(b[symin]=='+' || b[symin]=='-' || b[symin]=='*' || b[symin]=='/')) break;
	  	  }
	  	  if(rk[b[symin]]>=rk[b[symout]] && !(symout<i && (b[symout]=='/' || b[symout]=='-' && b[symin]!='*')))
	  	  	b[i]=' ',b[rpair]=' '; 
	  }
	for(int i=0;i<=topb;i++)
	  while(b[i]==' '){
	  	for(int j=i;j<99;j++) b[j]=b[j+1];
	  	    topb--;
	  	    if(i>topb) break;
	  }
	return;
}
double calc(double x,double y,char z){
		if(z=='+') return x+y;
		if(z=='-') return x-y;
		if(z=='*') return x*y;
		if(z=='/') return x/y;
}
void jisuan(){//���ʽ����󷨣�˳��㶨����� 
	double num[5];//����ջ 
	char sym[1001];//����ջ 
	int topnum=0,topsym=0;
	int rk[200];//��������ĵȼ�
	rk['+']=rk['-']=1;
	rk['*']=rk['/']=2;
	rk['(']=0;
	memset(num,0,sizeof(num));
	memset(sym,0,sizeof(sym));//�ز����ٵĳ�ʼ�� 
	for(int i=0;i<=topb;i++){
		if(b[i]>='1' && b[i]<='4') num[++topnum]=(double)a[b[i]-48];
			else{
			    if(b[i]=='(') sym[++topsym]=b[i];//������ֱ����ջ 
			    else if(b[i]==')'){//������һֱ���������� 
				    while(topnum && topsym && sym[topsym]!='('){
				    	num[topnum-1]=calc(num[topnum-1],num[topnum],sym[topsym]);
					    topnum--,topsym--;
				    } 
				    topsym--;//��������Ҳ���� 
			    }
			         else{
			     	      while(topnum && topsym && rk[b[i]]<=rk[sym[topsym]]){
			     	          num[topnum-1]=calc(num[topnum-1],num[topnum],sym[topsym]);
			     	          topnum--,topsym--;
			     	      }
			     	     sym[++topsym]=b[i];
			         }
		    }
	}
	while(topsym){
		num[topnum-1]=calc(num[topnum-1],num[topnum],sym[topsym]);
		topnum--,topsym--;
	}
	if(abs(num[1]-24)<0.000001){//���ӵ�������� 
	    qukuohao();//ȥ�����������
	    gaikuohao();//�޸�������ʽ 
		//��������ȥ�ػ��� 
		topd++;
		for(int i=1;i<=4;i++) dnum[topd][i]=a[i];
		for(int i=0;i<=100;i++) d[topd][i]=b[i];
		dlength[topd]=topb;
		bool f=false;
		for(int i=1;i<topd;i++){
			if(f) break;
			for(int j=0;j<=100;j++){
				if(d[i][j]>='1' && d[i][j]<='4' && b[j]>='1' && b[j]<='4'){
					if(dnum[i][d[i][j]-48]!=a[b[j]-48]) break; 
				}
		  	    else if(d[i][j]!=b[j]) break;
		  	    if(j==100){
		  	  	    f=true;
		  	  	    topd--;
		  	    }
		    }
		}
		if(f) return;
    }
	return;
}
bool jisuan2(){//����ģʽ���𰸵ı��ʽ���� 
    ans=ans+')';
    ans='('+ans;
    int len=ans.size();
    double num[5];//����ջ 
	char sym[1001];//����ջ 
	int topnum=0,topsym=0;
	int rk[200];//��������ĵȼ�
	rk['+']=rk['-']=1;
	rk['*']=rk['/']=2;
	rk['(']=0;
	memset(num,0,sizeof(num));
	memset(sym,0,sizeof(sym));//�ز����ٵĳ�ʼ�� 
	double k=0;
	bool vis[5]={0};
	for(int i=0;i<len;i++){
	    if(ans[i]>='0' && ans[i]<='9') k=k*10+(ans[i]-48); 
	    else{
	        if(i>0 && ans[i-1]>='0' && ans[i-1]<='9') num[++topnum]=k;
	        if(i>0 && ans[i-1]>='0' && ans[i-1]<='9'){
	        	bool cant=true;
	            for(int j=1;j<=4;j++){
	        	    if(k==data[j] && !vis[j]){
	          		    cant=false;
	          			vis[j]=true;
	          			break;
	          		}
	       		}
	       		if(cant) return false;
	        }
            k=0;
            if(ans[i]=='(') sym[++topsym]=ans[i];//������ֱ����ջ 
	        else if(ans[i]==')'){//������һֱ���������� 
	            while(topnum && topsym && sym[topsym]!='('){
    	            num[topnum-1]=calc(num[topnum-1],num[topnum],sym[topsym]);
	                topnum--,topsym--;
                } 
                topsym--;//��������Ҳ���� 
	        }
            else{
                while(topnum && topsym && rk[ans[i]]<=rk[sym[topsym]]){
 	                num[topnum-1]=calc(num[topnum-1],num[topnum],sym[topsym]);
	                topnum--,topsym--;
     	        }
   	            sym[++topsym]=ans[i];
            }
        }
    }
    while(topsym){
		num[topnum-1]=calc(num[topnum-1],num[topnum],sym[topsym]);
		topnum--,topsym--;
	}
	for(int i=1;i<=4;i++) if(!vis[i]) return false; 
    if(abs(num[1]-24)<0.000001) return true;
    return false;
}
void dfs(int x,int y,char c){
	//��ʼѰ�������Ӧ�÷ŵ�λ�� 
	for(int k=x;k<=y-1;k++){//e[k]+1Ϊ��ǰ��Ҫ�ӷ��ŵ�λ�� 
	   int e[5];
	   for(int i=x;i<=y;i++)
	     for(int j=0;j<=topb;j++)
	       if(b[j]==i+48){//Ѱ�Ҵ�x��y���б�ŵ�����λ�� 
	    	   e[i]=j;
	           break;
	       }
	    char g[101];
	    for(int i=0;i<=100;i++) g[i]=b[i];//���˻�����ʱ����и�ԭ
	    int topg=topb;
		//������� 
	    topb++;
	    for(int i=topb;i>=e[k]+2;i--) b[i]=b[i-1];//����һ��λ�����������
		b[e[k]+1]=c;
		for(int i=y;i>k;i--) e[i]++;//��Ϊ����һ���������ȥ�����Ժ��������λ��Ҫ�䶯 
		if(k-x+1>1){//�����߻��еĶ�
		    //��������һ������ 
			topb++;
			for(int i=topb;i>=e[x]+1;i--) b[i]=b[i-1];
			b[e[x]]='(';
			for(int i=x;i<=y;i++) e[i]++;//��Ϊ����һ�������Ž�ȥ�����Դ�ҵ�λ�ö�Ҫ�䶯�� 
			topb++;
			for(int i=topb;i>=e[k]+2;i--) b[i]=b[i-1];
			b[e[k]+1]=')';
			for(int i=k+1;i<=y;i++) e[i]++;
			int g2[100];
			for(int i=0;i<=100;i++) g2[i]=b[i];
			int topg2=topb;
			for(char p='*';p<='/';p++){//ö�����Ӧ������������������+-*/�ĸ������У�*��ascii��С��/��� 
				if(!(p=='+' || p=='-' || p=='*' || p=='/')) continue;//���ĸ�����������������ģ��м仹���˺ܶ������Ӱ˵ķ��� 
				dfs(x,k,p);
				if(y-k>1){//���������еĶ������£��ұ�Ҳ�еĶ� 
					for(int i=x;i<=y;i++)
				      for(int j=0;j<=topb;j++)
				        if(b[j]==i+48) e[i]=j;//������ǰ���dfs�����еĶ�����Ҫ�䶯
				    //���ұ����һ������  ע�⣺�����Ѿ��������ӹ�һ�����ţ����Դ�ʱ�������λ����e[k]+2 
				    topb++;
			        for(int i=topb;i>=e[k]+4;i--) b[i]=b[i-1];
			        b[e[k]+3]='(';
			        for(int i=k+1;i<=y;i++) e[i]++;
			        topb++;
			        for(int i=topb;i>=e[y]+2;i--) b[i]=b[i-1];
			        b[e[y]+1]=')';
			        int g3[100];
			        for(int i=0;i<=100;i++) g3[i]=b[i];
			        int topg3=topb;
			        for(char p2='*';p2<='/';p2++){
			        	if(!(p2=='+' || p2=='-' || p2=='*' || p2=='/')) continue;
			        	b[100]=0;//����Ϊ��ǿ�ƴ����Ǹ�Ī�������bug 
			        	dfs(k+1,y,p2);
			        	for(int i=0;i<=100;i++) b[i]=g3[i];
						topb=topg3;//��ԭ��׼����һ��ѭ�� 
			        }
				}
				for(int i=0;i<=100;i++) b[i]=g2[i];
				topb=topg2;//��ԭ��׼����һ��ѭ��	 
			}
		} 
		if(y-k>1){//��������ұ��еĶ� 
		    //���ұ����һ������ 
			topb++;
			for(int i=topb;i>=e[k]+3;i--) b[i]=b[i-1];
			b[e[k]+2]='(';
			for(int i=k+1;i<=y;i++) e[i]++;
			topb++;
			for(int i=topb;i>=e[y]+2;i--) b[i]=b[i-1];
			b[e[y]+1]=')';
			char g2[100];
			for(int i=0;i<=100;i++) g2[i]=b[i];
			int topg2=topb;
			for(char p='*';p<='/';p++){
				if(!(p=='+' || p=='-' || p=='*' || p=='/')) continue;
				dfs(k+1,y,p);
				for(int i=0;i<=100;i++) b[i]=g2[i];
				topb=topg2;//��ԭ 
			}
		}
	    if(k-x+1==1 && y-k==1){//����������߶�û�ö࣬��ô˵�������Ѿ���һ�����ʽ�ɹ������� 
	    	bool really=true;//�ж����ǲ�������б��ʽ���ɵ����ݣ�ÿ������֮���Ƿ��Ѿ���������� 
	    	for(int i=1;i<=4;i++)//��εð�ȫ�������ֵ�λ�ö������ 
	    	  for(int j=0;j<=topb;j++)
	    	    if(b[j]==i+48){
	    	    	e[i]=j;
	    	    	break;
	    	    }
	    	for(int i=1;i<4;i++){
	    		bool really2=false;
	    		for(int j=e[i];j<=e[i+1];j++)
	    			if(b[j]=='+' || b[j]=='-' || b[j]=='*' || b[j]=='/'){
	    	      	  really2=true;
	    	      	  break;
	    		    }
	    	    if(really2==false) really=false;
	    	}
	    	if(really) jisuan();//��24��ȥ� 
	    }
	    if(k-x+1>1 || y-k>1){//����ֻ��һ����ʱ���ø�ԭ 
	    	for(int i=0;i<=100;i++) b[i]=g[i];
	        topb=topg;//��ԭ��׼����һ��ѭ�� 
	    }
	}
}
void px(){//��ָ�ӹ� 
	memset(b,0,sizeof(b));
	b[0]='1',b[1]='2',b[2]='3',b[3]='4',topb=3;//����Ϊ���������������Ǽ������� 
	dfs(1,4,'+');
	memset(b,0,sizeof(b));
	b[0]='1',b[1]='2',b[2]='3',b[3]='4',topb=3;
	dfs(1,4,'-');
	memset(b,0,sizeof(b));
	b[0]='1',b[1]='2',b[2]='3',b[3]='4',topb=3;
	dfs(1,4,'*');
	memset(b,0,sizeof(b));
	b[0]='1',b[1]='2',b[2]='3',b[3]='4',topb=3;
	dfs(1,4,'/');
}
bool check(string s){
	for(int i=0;i<s.size();i++) 
	  if(s[i]<'0' || s[i]>'9') return false;
	return true;
}
bool checkans(){//����ģʽ�м������Ĵ𰸵ĸ�ʽ 
    for(int i=0;i<ans.size();i++){
        if(ans[i]=='[' || ans[i]=='{') ans[i]='(';//����������ͳһ����С���� 
        if(ans[i]==']' || ans[i]=='}') ans[i]=')';
        if(ans[i]==' '){  
            if(i>0 && i<ans.size()-1 && ans[i-1]>='0' && ans[i-1]<='9' && ans[i+1]>='0' && ans[i-1]<='9') return false;//�����������м���ֿո� 
	 	    ans.erase(i,1);i--;//ɾ���ո� 
	    }
    }
    for(int i=0;i<ans.size();i++){
        if((ans[i]<'0' || ans[i]>'9') && ans[i]!='+' && ans[i]!='-' && ans[i]!='*' && ans[i]!='/' && ans[i]!='(' && ans[i]!=')') return false;//�����Ӱ˵��ַ�
        if(ans[i]=='0' && (i==0 || ans[i-1]<'0' || ans[i-1]>'9') && i<ans.size()-1 && ans[i+1]>='0' && ans[i+1]<='9') return false;//ǰ���� 
        if((ans[i]=='+' || ans[i]=='-' || ans[i]=='*' || ans[i]=='/') && (i==0 || ans[i-1]=='+' || ans[i-1]=='-' || ans[i-1]=='*' || ans[i-1]=='/')) return false;//�����ظ�
        if(i>0 && ans[i]=='(' && ans[i-1]==')') return false;//��ѧ���� 
        if(i<ans.size()-1 && ans[i]=='(' && (ans[i+1]=='+' || ans[i+1]=='-' || ans[i+1]=='*' || ans[i+1]=='/')) return false;//�����ŵ��ұ�������� 
        if(i>0 && ans[i]==')' && (ans[i-1]=='+' || ans[i-1]=='-' || ans[i-1]=='*' || ans[i-1]=='/')) return false;//�����ŵ����������� 
    }
    int top=0;
    for(int i=0;i<ans.size();i++){//��������Ƿ�ƥ�� 
        if(ans[i]=='(') top++;
        if(ans[i]==')'){
            if(top>0) top--;
            else return false;
        }
	}
	if(top) return false;
    return true;
}
int zh(string s){
	int sum=0;
	for(int i=0;i<s.size();i++)
	  sum=(sum<<1)+(sum<<3)+(s[i]^48);
	return sum;
}
int main(){
	About_first:
	char CH;
	goto first_page;
	About:
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	system("cls");
	puts("24_Points Calculator was first invented by Wang Zhijian on 2018.10.20.");
	puts("");
	puts("Name:                     24-Points Calculator STD-5.3");
	puts(""); 
	puts("Main functions:           Questioning and calculating");
	puts("");
	puts("Developers:               Wang Zhijian and Xu Xing");
	puts("");
    puts("Developing environment:   Dev-C++ 5.6.1  g++ 4.9.8  Windows 10");
    puts("");
	puts("Visions:                  STD-1.0 STD-2.0 STD-2.5 STD-2.7 STD-2.9 STD-3.1 STD-3.5 STD-3.6 SIM-3.6");
    puts("                          STD-4.6 STD-4.7 STD-4.8 STD-4.9 STD-5.1 STD-5.2 STD-5.3");
    puts(""); 
    puts("Suggested processor:      Intel Core i5-6200U CPU @ 2.30GHZ 2.40GHZ, 64-bit");
    puts("");
    puts("Suggested memory(RAM):    >=4.00GB");
    puts("");
    puts("Suggested display size:   1366*768");
    puts("");
    puts("Suggested system:         Windows 10");
	puts("");
	puts("");
	puts("copyright(c) 2018 Wang Zhijian Xu Xing. All rights reserved.");
	puts(""); 
	puts("");
	puts("");
    puts("Press Enter to continue:");
    CH=getchar();
    while(CH!='\n') CH=getchar();
	first_page:
	system("cls");
	system("mode con cols=120 lines=45");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    puts("Ver:STD-5.3");
	puts("  ____________                                                                                                        ");
	puts("            ||   ||        ||         	  ||======                                                                    ");
	puts("            ||   ||        ||             ||      ==                                                                  ");
	puts("            ||   ||        ||             ||       ==        ====          ==                                         ");
	puts("            ||   ||        ||             ||        ==     ==    ==        ==                         ||              ");
	puts("            ||   ||        ||             ||       ==     ==      ==                ==========     ========    =====  ");
	puts(" ____________    ___________              ||      ==     ==        ==      ||       ||      ||        ||      ||      ");
	puts(" ||                        ||   =======   ||======      ==          ==     ||       ||      ||        ||      ||      ");
	puts(" ||                        ||      	  ||             ==        ==      ||       ||      ||        ||      ======  ");
	puts(" ||                        ||             ||              ==      ==       ||       ||      ||        ||           || ");
	puts(" ||                        ||             ||               ==    ==        ||       ||      ||        ||           || ");
	puts(" ____________              ||             ||                 ====          ||       ||      ||        ||      ======  ");
	puts("");
	puts("");
	puts("                                             ");
	puts("");
	puts("");
	puts("");
	puts("   									-------Developed by Wang Zhijian & Xu Xing");
	puts("");
	puts("");
	puts("");
	puts("");
	puts("");
	puts("");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	puts("You can input 'About' to view the information about the software.");
	puts("You can also input 's' to start your game.");
	first_input:
    string input_first;
    getline(cin,input_first,'\n');
    if(input_first=="s") goto pat;
    else if(input_first=="About") goto About;
    else goto first_input;
	pat:
    system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	puts("Which pattern would you like to play?");
	puts("Please input 'a' for problem set pattern, and 'c' for calculating pattern");
	format:
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	string pattern;
	getline(cin,pattern,'\n');
	while(pattern=="") getline(cin,pattern,'\n');
	if(pattern=="return") goto first_page;
	if(pattern!="c" && pattern!="a"){
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED);
	    puts("Format Error! Please input again!");
	    goto format;
    }
    if(pattern=="c")
        while(1){
        	system("cls");
        	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_GREEN);
        	cout<<"Input your four numbers:"<<endl;
        	puts("(If you don't want to calculate, you can input 'return' to choose the pattern again)");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
        	topd=0,topb=0;
        	string s1,s2,s3,s4;
        	cin>>s1;
        	if(s1=="return") goto pat;
        	cin>>s2;
        	if(s2=="return") goto pat;
        	cin>>s3;
        	if(s3=="return") goto pat;
        	cin>>s4;
        	if(s4=="return") goto pat;
        	if(!check(s1) || !check(s2) || !check(s3) || !check(s4)){
        		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED);
        		puts("Format Error! Please input again!");
        		Sleep(1500);
        		continue;
        	}
        	data[1]=zh(s1),data[2]=zh(s2),data[3]=zh(s3),data[4]=zh(s4);
            for(int i=1;i<=4;i++)
              for(int j=1;j<=4;j++)
                for(int k=1;k<=4;k++)
                  for(int t=1;t<=4;t++)
                    if(i!=j && i!=k && i!=t && j!=k && j!=t && k!=t){
                    	a[1]=data[i],a[2]=data[j],a[3]=data[k],a[4]=data[t];
                	    px();
                    }
            if(!topd){
            	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED);
            	cout<<"No Answer"<<endl<<endl;
            }
            else{
          	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            	cout<<endl;
            	for(int i=1;i<topd;i++)
            	  for(int j=i+1;j<=topd;j++)
            	    if(dlength[i]>dlength[j]){
            	    	swap(d[i],d[j]);//swap����ֱ�ӽ������飬�ǳ�ǿ�� 
    					swap(dnum[i],dnum[j]);
            	    	swap(dlength[i],dlength[j]);
            	    }
    	        int t=0;
    			for(int i=1;i<=topd;i++){
    			    t++;
    				for(int j=0;j<=20;j++)
    			  	  if(d[i][j]>='1' && d[i][j]<='4') cout<<dnum[i][d[i][j]-48];
    			      else cout<<d[i][j];
    			    cout<<" ";
    			    if(t%4==0) cout<<endl;
    			}
   			    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_BLUE);
                cout<<endl<<"There are "<<topd<<" answers."<<endl<<endl;
    			if(topd>=100){
    				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    				cout<<"That's awful!"<<endl<<endl;
    			}
            }
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_GREEN);
            puts("Press Enter to continue...");
            char c=getchar();
            c=getchar();
    		while(c!='\n') c=getchar();
        }
        else{
            srand(time(0));
            input_difficulty_again:
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_GREEN);
            puts("Are you ready? The computer is going to challenge you...");
            puts("(If you don't want to play, please input 'return' to choose the pattern again.)");
            puts("");
            puts("");
            puts("Please input your difficulty: (Simple/Medium/Hard/Random)");
            input_difficulty:
            int ac=0,wa=0,giveup=0,sum=0;
            double totaltime=0;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_GREEN);
            string difficulty;
            getline(cin,difficulty,'\n');
            if(difficulty=="return") goto pat;
            if(difficulty!="Simple" && difficulty!="Medium" && difficulty!="Hard" && difficulty!="Random"){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED);
                puts("Format Error! Please input again:");
                goto input_difficulty;
            }
            while(1){
                system("cls");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_GREEN);
                problem:
                data[1]=rand()%13+1,data[2]=rand()%13+1,data[3]=rand()%13+1,data[4]=rand()%13+1;
                memset(d,0,sizeof(d));
                memset(b,0,sizeof(b));
                memset(a,0,sizeof(a));
                topd=0;
                for(int i=1;i<=4;i++)
                  for(int j=1;j<=4;j++)
                    for(int k=1;k<=4;k++)
                      for(int t=1;t<=4;t++)
                        if(i!=j && i!=k && i!=t && j!=k && j!=t && k!=t){
                    	    a[1]=data[i],a[2]=data[j],a[3]=data[k],a[4]=data[t];
                	        px();
                        }
                if(!topd) goto problem;
                input:
				clock_t start=clock();
				input_without_stop:
                system("cls");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                string tdifficulty;
                if(topd<=5) tdifficulty="Hard";
                else if(topd<=20) tdifficulty="Medium";
                else tdifficulty="Simple";
                if(data[1]+data[2]+data[3]+data[4]==24) tdifficulty="Simple";
                if(tdifficulty!=difficulty && difficulty!="Random") goto problem;
                sum++;
                printf("%d %d %d %d\n",data[1],data[2],data[3],data[4]);
                cout<<"Difficulty:"<<tdifficulty<<endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_GREEN);
                printf("Please calculate and input your answer:                                            Correct:%d  Wrong:%d\n",ac,wa);
                printf("You can input 'I failed' to view the answers.                                               Give up:%d\n",giveup);
                if(totaltime==0) printf("You can input 'return' to choose the difficulty again.                                 Average time:N/A\n");
                else printf("You can input 'return' to choose the difficulty again.                                 Average time:%.2lfs\n",totaltime/(double)(sum-1));
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
                getline(cin,ans,'\n');
                if(ans=="return") goto input_difficulty_again;
                if(ans=="I failed"){
                	 giveup++;sum--;
                     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
               	     cout<<endl;
               	     for(int i=1;i<topd;i++)
            	       for(int j=i+1;j<=topd;j++)
            	         if(dlength[i]>dlength[j]){
    	    	             swap(d[i],d[j]);//swap����ֱ�ӽ������飬�ǳ�ǿ�� 
    					     swap(dnum[i],dnum[j]);
            	    	     swap(dlength[i],dlength[j]);
            	         }
               	     int t=0;
    			     for(int i=1;i<=topd;i++){
			             t++;
    				     for(int j=0;j<=20;j++)
                           if(d[i][j]>='1' && d[i][j]<='4') cout<<dnum[i][d[i][j]-48];
    			           else cout<<d[i][j];
    			         cout<<" ";
    			         if(t%4==0) cout<<endl;
    			     }
   			        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_BLUE);
                    cout<<endl<<"There are "<<topd<<" answers."<<endl<<endl;
    			    if(topd>=100){
    				    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    				    cout<<"That's awful!"<<endl<<endl;
    			    }
          			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_GREEN);
          			puts("Make persistent efforts!");
          			puts("Press enter to continue...");
          			char c=getchar();
          			while(c!='\n') c=getchar();
          			goto problem;
                }
                if(!checkans()){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED);
            		puts("Format Error! Please input again!");
            		Sleep(1500);
            		goto input_without_stop;
                }
                if(jisuan2()){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_GREEN);
                    puts("Congratulations! The answer is correct.");
                    double time=(clock()-start)*1000.0/CLOCKS_PER_SEC/1000.0;
                    printf("\ntime: %.2lfs\n",time);
                    if(time<=10) puts("So fast!");
                    puts("");
                    ac++;totaltime+=time;
                    puts("Press anykey to continue...");
                    char ch=getchar();
                }
                else{
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED);
                    puts("Wrang answer! Please input again!");
                    wa++;
                    Sleep(1500);
                    goto input_without_stop;
                }
            }
        }	
    return 0;
} 
