#include <bits/stdc++.h>
#include <omp.h>
using namespace std;
#define INF 20005
int V;
int main()
{
	int e;
	scanf("%d %d",&V,&e);

	cerr<<"Number of nodes: "<<V<<"\nNumber of edges: "<<e<<"\n";
	int **graph=(int **)malloc(V*sizeof(int*));
	for(int i=0;i<V;i++){
		graph[i]=(int*)malloc(V*sizeof(int));
	}

	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			if(i==j)
			graph[i][j]=0;
			else
			graph[i][j]=INF;
		}
	}

	for(int i=0;i<e;i++){
		int from,to,w;
		scanf("%d %d %d",&from,&to,&w);
		graph[from][to]=w;
	}
	double start=omp_get_wtime();

	for (int k = 0; k < V; k++)
	{
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				if (graph[i][k] + graph[k][j] < graph[i][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}


	double end=omp_get_wtime();
	//print final matrix
	// for (int i = 0; i < V; i++)
	// {
	// 	for (int j = 0; j < V; j++)
	// 	{
	// 		if (graph[i][j] == INF)
	// 			cout<<"INF"<<"  ";
	// 		else
	// 			cout<<graph[i][j]<<"  ";
	// 	}
	// 	cout<<endl;
	// }
	cerr<<"Time taken by Serial code: "<<end-start<<"\n";
	return 0;
}
