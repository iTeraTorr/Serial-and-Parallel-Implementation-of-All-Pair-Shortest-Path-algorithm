#include <bits/stdc++.h>
#include <omp.h>
using namespace std;
#define NUM_THREADS 8
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
	cerr<<"Time taken by:\n";
	for(int num_threads=1;num_threads<=10;num_threads++){
	omp_set_num_threads(num_threads);
	double start=omp_get_wtime();

	for (int k = 0; k < V; k++)
	{
        #pragma omp parallel for
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
                graph[i][j] = min(graph[i][k] + graph[k][j],graph[i][j]);
			}
		}
	}

	double end=omp_get_wtime();
	cerr<<num_threads<<" threads: "<<end-start<<" with Speedup: "<<3.6853e-05/(end-start)<<"\n";
	}
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
	return 0;
}
