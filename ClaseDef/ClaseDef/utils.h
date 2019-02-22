//utils.h -> interfaz para operaciones de grafos

//PROGRAMA PARA LEER GRAFOS

struct graph {
	//bool adj[100][100];
	bool** adj; //matriz de adyacencias
	int NV; //Número de vértices
};

bool** allocate_matrix(int N, int M);
void free_matrix(bool** m, int N);
void print_matrix(bool** m, int N, int M);

graph* init_graph(int NV);
void free_graph(graph* pg);
void print_header(graph* pg);
void print_edges(graph* pg);
int addEdge(graph* pg, int v, int w);
bool isEdge(graph* pg, int v, int w);

graph* read_graph(const char* filename);