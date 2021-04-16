#include<windows.h>
#include<stdio.h>
int function();
int main()
{	
	function();
}
int function()
{
	system("color 0a");
	char name[]={};
	char a[200] = {};
	unsigned cycle;
	printf("输入窗口名称:  ");
	scanf("%s",name);
	HWND window;
	window = FindWindow(NULL,name);
	if(window==0)
	{
		printf("\n请打开目标窗口！！！\n\n");
		for(int i=0;i<4;i++)
		{
			system("color 04");
			Sleep(200);
			system("color 0a");
			Sleep(200);
		}	
	}
	else
	{	
		system("color 0b");
		printf("\n\n输入轰炸内容："); 
		scanf("%s",a);
		printf("\n\n轰炸多少遍？");
		scanf("%d",&cycle);
		for(int i=0;i<cycle;i++)
		{	
			for(int i=0;i<strlen(a);i++)
			SendMessage(window,WM_CHAR,a[i]&0xff,0);
			SendMessage(window,WM_KEYDOWN,VK_RETURN,0);
			SendMessage(window,WM_KEYUP,VK_RETURN,0);
			Sleep(50); 
		}
		printf("\n已完成\n\n\n\n\n");
		system("color 0e");
		Sleep(3000);
	}	
	function();
 }
