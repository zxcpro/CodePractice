#include <cstdlib>
#include <iostream>

using namespace std;


int minimum(int a,int b,int c){
	int tmp = a>b?b:a;
	return tmp>c?c:tmp;
}

int distOfString(char* str1,char* begin1,char* end1,char* str2,char* begin2,char* end2){
	if(begin1 == end1){
		return end2 - begin2;
	}else if(begin2 == end2){
		return end1 - begin1;
	}
	if(*begin1 == *begin2){
		return distOfString(str1,begin1+1,end1,str2,begin2+1,end2);
	}else{
		int dis1 = distOfString(str1,begin1+1,end1,str2,begin2,end2)+1;
		int dis2 = distOfString(str1,begin1,end1,str2,begin2+1,end2)+1;
		int dis3 = distOfString(str1,begin1+1,end1,str2,begin2+1,end2)+1;
		return minimum(dis1,dis2,dis3);
	}
}


int main(){

char* str1 = "abc";
char* str2 = "abcd";
char* begin1 = str1;
char* end1 = str1 + strlen(str1);
char* begin2 = str2;
char* end2 = str2 + strlen(str2);
cout<<distOfString(str1,begin1,end1,str2,begin2,end2);
system("pause");

}
