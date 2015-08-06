#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

#define MAX 128

struct Node{
    char data;
    int freq;
    Node *left, *right;
};

Node* Heap[MAX];
int Size = 0;
int freq[MAX] = {0};
string code[MAX];

void Swap(Node* &x, Node* &y)
{
    Node* temp;
    temp = x;
    x = y;
    y = temp;
}

Node* createNode(int data, int value, Node* n1, Node* n2)
{
    Node* temp = new Node;
    temp->data = (char)data;
    temp->freq = value;
    temp->left = n1;
    temp->right = n2;

    if(value == 0)
        temp->freq = n1->freq + n2->freq;

    return temp;
}

void Add(Node* t)
{
    Size++;
    int i = Size;

    while(i/2 > 0)
    {
        if(t->freq >= Heap[i/2]->freq)
            break;
        Heap[i] = Heap[i/2];
        i = i/2;
    }

    Heap[i] = t;
}

Node* Remove()
{
    int i = 1;
    Node* temp;
    temp = Heap[1];

    Heap[1] = Heap[Size];
    Size--;

    while(i*2 <= Size)
    {
        if(Heap[i]->freq <= Heap[i*2]->freq)
        {
            if(i*2+1 <= Size)
            {
                if(Heap[i]->freq <= Heap[i*2+1]->freq)
                    break;
                else
                {
                    Swap(Heap[i], Heap[i*2+1]);
                    i = i*2+1;
                }
            }
            else
                break;
        }
        else
        {
            if(i*2+1 <= Size && Heap[i*2+1]->freq <= Heap[i*2]->freq)
            {
                Swap(Heap[i], Heap[i*2+1]);
                i = i*2+1;
            }
            else
            {
                Swap(Heap[i], Heap[i*2]);
                i = i*2;
            }
        }
    }

    return temp;
}

void buildCode(Node* t, string s)
{
    if(t->left != NULL)
        buildCode(t->left, s+'0');
    else
    {
        code[(int)t->data] = s;
        return ;
    }

    if(t->right != NULL)
        buildCode(t->right, s+'1');
}

void huffman()
{
    for(int i = 0; i < MAX; i++)
    {
        if(freq[i] > 0)
        {
            Add( createNode(i, freq[i], NULL, NULL) );
        }
    }

    if(Size == 1)
    {
        Heap[1]->left = createNode(Heap[1]->data, Heap[1]->freq, NULL, NULL);
    }

    while(Size >= 2)
    {
        Add( createNode(0, 0, Remove(), Remove()) );
    }

    buildCode(Heap[1], "");
}

void init_freq_array(string str)
{
    int len = str.size();

    for(int i = 0; i < len; i++)
    {
        freq[ str[i] ]++;
    }
}

void printCode()
{
    for(int i = 0; i < MAX; i++)
    {
        if( !code[i].empty() )
        {
            cout << (char)i << ": " << code[i] << "\n";
        }
    }
    cout << endl;
}

string encode(string str)
{
    string t = "";
    int len = str.size();

    for(int i = 0; i < len; i++)
    {
        if( !code[ str[i] ].empty() )
        {
            t += code[str[i]];
        }
        else
        {
            cout << "Invalid Input" << endl;
            return "";
        }
    }

    cout << "Encoded: " << t << endl;

    return t;
}

void decode(string str)
{
    string s = "";
    int len = str.size();
    Node* t;
    t = Heap[1];

    for(int i = 0; i < len; i++)
    {
        if(str[i] == '0')
            t = t->left;
        else
            t = t->right;

        if(t->left == NULL && t->right == NULL)
        {
            s += t->data;
            t = Heap[1];
        }
    }

    cout << "Decoded: " << s << endl;
}

int main()
{
    string str, t;

    getline(cin, str);

    init_freq_array(str);
    huffman();
    printCode();
    t = encode(str);
    decode(t);

    return 0;
}
