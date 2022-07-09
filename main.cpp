#include <bits/stdc++.h>
using namespace std;
 

struct HuffmanTreeNode {
 
    char data;
 
    unsigned freq;
 
    // Left and right child
    HuffmanTreeNode *left, *right;
 
     HuffmanTreeNode(char data1, unsigned freq1)
 
    {
 
        left = right = NULL;
        data = data1;
        freq = freq1;
    }
};
 
//to compare two nodes 
struct compare {
 
    bool operator()( HuffmanTreeNode* l, HuffmanTreeNode* r)
 
    {
        return (l->freq > r->freq);
    }
};
 
// print the huffman node
void printCodes(struct  HuffmanTreeNode* root, string str)
{
 
    if (!root)
        return;
 
    if (root->data != ' ')
        cout << root->data << ": " << str << "\n";
 
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}


 
void HuffmanCodes(char data[], int freq[], int size)
{
    struct HuffmanTreeNode *left, *right, *top;
 
    // Create a min heap 
    priority_queue< HuffmanTreeNode*, vector< HuffmanTreeNode*>, compare> pq;
 
    for (int i = 0; i < size; ++i)
        pq.push(new  HuffmanTreeNode(data[i], freq[i]));
 
    
    while ( pq.size() != 1) {
 
      
        left = pq.top();
        pq.pop();
 
        right = pq.top();
        pq.pop();
 
        
        top = new  HuffmanTreeNode(' ', left->freq + right->freq);
 
        top->left = left;
        top->right = right;
 
        pq.push(top);
    }
 
    
    printCodes(pq.top(), "");
}
 
// main function
int main()
{
 
    char arr[] = { 'q', 's', 't', 'u', 'v', 'w' };
    int freq[] = { 2, 8, 23, 45, 50, 59 };
 
    int size = sizeof(arr) / sizeof(arr[0]);
 
    HuffmanCodes(arr, freq, size);
 
    return 0;
}
 
