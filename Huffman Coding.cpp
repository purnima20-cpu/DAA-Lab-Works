#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    char data;
    unsigned freq;
    Node *left, *right;
};

struct MinHeap {
    unsigned size;
    unsigned capacity;
    Node** array;
};

Node* newNode(char data, unsigned freq) {
    Node* temp = new Node();
    temp->data = data;
    temp->freq = freq;
    temp->left = temp->right = nullptr;
    return temp;
}

MinHeap* createMinHeap(unsigned capacity) {
    MinHeap* minHeap = new MinHeap();
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = new Node*[capacity];
    return minHeap;
}

void swapNode(Node** a, Node** b) {
    Node* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

Node* extractMin(MinHeap* minHeap) {
    Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(MinHeap* minHeap, Node* node) {
    minHeap->size++;
    int i = minHeap->size - 1;
    while (i && node->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}

void buildMinHeap(MinHeap* minHeap) {
    for (int i = (minHeap->size - 2) / 2; i >= 0; i--)
        minHeapify(minHeap, i);
}

MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) {
    MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; i++)
        minHeap->array[i] = newNode(data[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

Node* buildHuffmanTree(char data[], int freq[], int size) {
    Node *left, *right, *top;
    MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

    while (minHeap->size > 1) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

void printCodes(Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (!root->left && !root->right) {
        cout << root->data << ": ";
        for (int i = 0; i < top; i++)
            cout << arr[i];
        cout << "\n";
    }
}

void HuffmanCodes(char data[], int freq[], int size) {
    Node* root = buildHuffmanTree(data, freq, size);
    int arr[100], top = 0;
    printCodes(root, arr, top);
}

int main() {
    int size;
    cout << "Enter number of characters: ";
    cin >> size;

    char* data = new char[size];
    int* freq = new int[size];

    cout << "Enter characters and their frequencies:\n";
    for (int i = 0; i < size; i++)
        cin >> data[i] >> freq[i];

    cout << "\nHuffman Codes:\n";
    HuffmanCodes(data, freq, size);

    delete[] data;
    delete[] freq;
    return 0;
}
