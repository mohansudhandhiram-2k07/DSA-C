#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int dest;
    int weight;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
} List;

typedef struct Graph {
    int V;
    List* array;
} Graph;

Node* new_node(int dest, int weight) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->dest = dest;
    n->weight = weight;
    n->next = NULL;
    return n;
}

Graph* init_graph(int V) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->V = V;
    g->array = (List*)malloc(V * sizeof(List));
    for (int i = 0; i < V; ++i)
        g->array[i].head = NULL;
    return g;
}

void add_edge(Graph* g, int src, int dest, int weight) {
    Node* n = new_node(dest, weight);
    n->next = g->array[src].head;
    g->array[src].head = n;

    n = new_node(src, weight);
    n->next = g->array[dest].head;
    g->array[dest].head = n;
}

typedef struct HeapNode {
    int v;
    int key;
} HeapNode;

typedef struct MinHeap {
    int size;
    int capacity;
    int* pos;
    HeapNode** array;
} MinHeap;

HeapNode* new_heap_node(int v, int key) {
    HeapNode* n = (HeapNode*)malloc(sizeof(HeapNode));
    n->v = v;
    n->key = key;
    return n;
}

MinHeap* init_heap(int capacity) {
    MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));
    h->pos = (int*)malloc(capacity * sizeof(int));
    h->size = 0;
    h->capacity = capacity;
    h->array = (HeapNode**)malloc(capacity * sizeof(HeapNode*));
    return h;
}

void swap_nodes(HeapNode** a, HeapNode** b) {
    HeapNode* t = *a;
    *a = *b;
    *b = t;
}

void heapify(MinHeap* h, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < h->size && h->array[left]->key < h->array[smallest]->key)
        smallest = left;

    if (right < h->size && h->array[right]->key < h->array[smallest]->key)
        smallest = right;

    if (smallest != idx) {
        HeapNode* s_node = h->array[smallest];
        HeapNode* i_node = h->array[idx];

        h->pos[s_node->v] = idx;
        h->pos[i_node->v] = smallest;

        swap_nodes(&h->array[smallest], &h->array[idx]);
        heapify(h, smallest);
    }
}

bool is_empty(MinHeap* h) {
    return h->size == 0;
}

HeapNode* pop_min(MinHeap* h) {
    if (is_empty(h))
        return NULL;

    HeapNode* root = h->array[0];
    HeapNode* last = h->array[h->size - 1];

    h->array[0] = last;
    h->pos[root->v] = h->size - 1;
    h->pos[last->v] = 0;

    --h->size;
    heapify(h, 0);

    return root;
}

void update_key(MinHeap* h, int v, int key) {
    int i = h->pos[v];
    h->array[i]->key = key;

    while (i && h->array[i]->key < h->array[(i - 1) / 2]->key) {
        h->pos[h->array[i]->v] = (i - 1) / 2;
        h->pos[h->array[(i - 1) / 2]->v] = i;
        swap_nodes(&h->array[i], &h->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

bool in_heap(MinHeap* h, int v) {
    return h->pos[v] < h->size;
}

void print_mst(int parent[], int n) {
    printf("Edge     Weight\n");
    for (int i = 1; i < n; ++i)
        printf("%d - %d\n", parent[i], i);
}

void prim(Graph* g) {
    int V = g->V;
    int parent[V];
    int key[V];
    MinHeap* h = init_heap(V);

    for (int v = 1; v < V; ++v) {
        parent[v] = -1;
        key[v] = INT_MAX;
        h->array[v] = new_heap_node(v, key[v]);
        h->pos[v] = v;
    }

    key[0] = 0;
    h->array[0] = new_heap_node(0, key[0]);
    h->pos[0] = 0;
    h->size = V;

    while (!is_empty(h)) {
        HeapNode* min_node = pop_min(h);
        int u = min_node->v;

        Node* crawl = g->array[u].head;
        while (crawl != NULL) {
            int v = crawl->dest;
            if (in_heap(h, v) && crawl->weight < key[v]) {
                key[v] = crawl->weight;
                parent[v] = u;
                update_key(h, v, key[v]);
            }
            crawl = crawl->next;
        }
        free(min_node);
    }
    print_mst(parent, V);
}

int main() {
    int V = 9;
    Graph* g = init_graph(V);
    
    add_edge(g, 0, 1, 4);
    add_edge(g, 0, 7, 8);
    add_edge(g, 1, 2, 8);
    add_edge(g, 1, 7, 11);
    add_edge(g, 2, 3, 7);
    add_edge(g, 2, 8, 2);
    add_edge(g, 2, 5, 4);
    add_edge(g, 3, 4, 9);
    add_edge(g, 3, 5, 14);
    add_edge(g, 4, 5, 10);
    add_edge(g, 5, 6, 2);
    add_edge(g, 6, 7, 1);
    add_edge(g, 6, 8, 6);
    add_edge(g, 7, 8, 7);

    prim(g);

    return 0;
}