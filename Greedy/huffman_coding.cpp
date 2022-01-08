#include <bits/stdc++.h>
using namespace std;
//Huffman coding using STL
/*
Steps to build Huffman Tree
Input is an array of unique characters along with their frequency of occurrences and output is Huffman Tree. 

1.Create a leaf node for each unique character and build a min heap of all leaf nodes
    (Min Heap is used as a priority queue. 
    The value of frequency field is used to compare two nodes in min heap. 
    Initially, the least frequent character is at root)
2.Extract two nodes with the minimum frequency from the min heap.
3.Create a new internal node with a frequency equal to the sum of the two nodes frequencies. 
    Make the first extracted node as its left child and the other extracted node as its right child. 
    Add this node to the min heap.
4.Repeat steps#2 and #3 until the heap contains only one node. The remaining node is the root node 
    and the tree is complete.
*/
// A Huffman tree node
struct MinHeapNode
{

    // One of the input characters
    char data;

    // Frequency of the character
    unsigned freq;

    // Left and right child
    MinHeapNode *left, *right;

    MinHeapNode(char data, unsigned freq)

    {

        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

// For comparison of two heap nodes (needed in min heap), we will need a custom comparator which will return larger frequency node first
struct compare
{

    bool operator()(MinHeapNode *l, MinHeapNode *r)

    {
        return (l->freq > r->freq);
    }
};

// Prints huffman codes from the root of Huffman Tree. using DFS or preOrder traversal of tree
void printCodes(struct MinHeapNode *root, string str)
{

    if (!root)
        return;
    //as we have assigned '$' character to all the intermediate node and as we will be printing only the leaf nodes
    //we first check if its a leaf node we print its character and respective string otherwise we build the string
    if (root->data != '$')
        cout << root->data << ": " << str << "\n";
    //according to the huffman coding algo if we go left append a 0, if we go to the right we append a 1
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

// The main function that builds a Huffman Tree and  print codes by traversing the built Huffman Tree
void HuffmanCodes(char data[], int freq[], int size)
{
    struct MinHeapNode *left, *right, *top;
    // Create a min heap & inserts all characters of data[]
    //a priority queue with a custom comparator
    priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;
    //first of all we will be storing all the characters and their respective frequencies in the minHeap
    //to get the character with mininmum frequency always at the top
    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));

    // Iterate while size of heap doesn't become 1
    while (minHeap.size() != 1)
    {
        // Extract the two minimum freq items from min heap
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        // Create a new internal node with frequency equal to the sum of the two nodes frequencies.
        // Make the two extracted node as left and right children  of this new node.
        // Add this node to the min heap '$' is a special value for internal nodes, not used
        top = new MinHeapNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;
        //after creating the intermediate nodes we push this into the priority queue again
        minHeap.push(top);
    }

    // Print Huffman codes using the Huffman tree built above
    printCodes(minHeap.top(), "");
}

// Driver Code
int main()
{

    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    int size = sizeof(arr) / sizeof(arr[0]);

    HuffmanCodes(arr, freq, size);

    return 0;
}