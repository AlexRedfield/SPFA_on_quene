/*
 * spfa.cpp
 *
 *  Created on: 2017年4月1日
 *      Author: Administrator
 */
#include<iostream>
#include<stdio.h>
#define maxnum 100
#define maxint 9999
using namespace std;

typedef struct Edge{
    int u, v;    // 起点，终点
    int weight;  // 边的权值
}Edge;

Edge edge[maxnum];     // 保存边的值
int  dis[maxnum]; 	   // 结点到源点最小距离
int  vis[maxnum],q[maxnum],path[maxnum];
int nodenum, edgenum, source;    // 结点数，边数，源点
int a[maxnum][maxnum];
int flag=0;//设置这个全局变量只是为了路径的最后不输出-
//int b[maxnum][maxnum];
// 初始化图
void init()
{
    // 输入结点数，边数，源点
    cin >> nodenum >> edgenum >> source;
    for(int i=1; i<=nodenum; ++i)
        dis[i] = maxint;
    dis[source] = 0;

    for(int i=1; i<=edgenum; ++i)
    {
        cin >> edge[i].u >> edge[i].v >> edge[i].weight;
        a[edge[i].u][edge[i].v]=edge[i].weight;

        if(edge[i].u == source)          //注意这里设置初始情况
            dis[edge[i].v] = edge[i].weight;

    }
}


void spfa(int s){
	for(int i=0; i<=nodenum; i++) dis[i]=maxint; //初始化每点i到s的距离
	dis[s]=0; vis[s]=1; q[1]=s;  //队列初始化,s为起点
	int i, v, head=0, tail=1;
	while (head<tail){   //队列非空
		head++;
		v=q[head];  //取队首元素
		vis[v]=0;   //释放队首结点，因为这节点可能下次用来松弛其它节点，重新入队
		for(i=0; i<=nodenum; i++)  //对所有顶点
		   if (a[v][i]>0 && dis[i]>dis[v]+a[v][i]){
				dis[i] = dis[v]+a[v][i];   //修改最短路
				path[i]=v;
				if (vis[i]==0){ // 如果扩展结点i不在队列中，入队
					tail++;
					q[tail]=i;
					vis[i]=1;
				}
		   }
		}
	}
void printpath(int k){//递归输出路径

		if (path[k]!=0)
			{
			flag++;
			printpath(path[k]);
			}
		if(flag==0)
		{
		cout << k;
		}
		else
		{
		cout << k << '-';
		flag--;
		}
	}
int main()
{
	freopen("input.txt", "r", stdin);
	init();
	spfa(source);

	for(int i = 1 ;i <= nodenum; i++)
	{
		cout <<"the shortest path length from source to "<<i<<" is "<< dis[i]<<" ,the path is ";
		printpath(i);
		cout<<endl;
	}
	return 0;
}

