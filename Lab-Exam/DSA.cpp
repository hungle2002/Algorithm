#include <iostream>
#include <list>
#include<stack>
#include<queue>
#include<sstream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
class Node
                    {
                    private:
                        int freq;
                        char character;
                        Node *pLeft, *pRight;
                        friend class Comparison;
                        friend class HuffmanCode;
                    
                    public:
					void print(Node* root){
						if(root==NULL){
							return;
						}
						cout << root->character<<" "<<root->freq<<endl;
						print(root->pLeft);
						print(root->pRight);
					}
                        Node(){};
                        Node(int freq, char character) : freq(freq), character(character), pLeft(NULL), pRight(NULL){};
                        Node(int freq, char character, Node *pLeft, Node *pRight) : freq(freq), character(character), pLeft(pLeft), pRight(pRight){};
                    };
class Comparison
                    {
                    public:
                        bool operator()(Node *a, Node *b)
                        {
                            return a->freq > b->freq;
                        }
                    };
class HuffmanCode
                    {
                    private:
                        map<char, int> freqTable;
                        map<char, string> hashTable;

                    public:
                        Node *constructTree();
                        void encodeCharacter(Node *root, string prefix);

			void constructFreqTable(string s)
                        {
                            for (int i = 0; i < s.size(); i++)
                            {
                                freqTable[s[i]]++;
                            }
                        }
                        
                        string encode(string s)
                        {
                            string result = "";
                            for (int i = 0; i < s.size(); i++)
                            {
                                result += hashTable[s[i]];
                            }
                            return result;
                        }

                        void printFreqTable()
                        {
                            for (auto const &i : freqTable)
                            {
                                cout << i.first << " - " << i.second << endl;
                            }
                        }
                        
                        void printHashTable()
                        {
                            for (auto const &i : hashTable)
                            {
                                cout << i.first << " - " << i.second << endl;
                            }
                        }

                        void deleteTree(Node *root)
                        {
                            if (!root)
                            {
                                return;
                            }
                            deleteTree(root->pLeft);
                            deleteTree(root->pRight);
                            delete root;
                        }
                    };
// Function for step 2
Node *HuffmanCode::constructTree(){
	vector<Node*> vec;
	for(char i ='A'; i<='Z'; i++){
		if(freqTable[i] >0){
			Node* tmp = new Node(freqTable[i], i);
			vec.push_back(tmp);
		}
	}
	sort(vec.begin(), vec.end(), Comparison());
	Node* head1=NULL;Node* head2=NULL;
	while(!vec.empty()){
		Node* head;
		if(vec.size()>1){
			Node* trai = vec.back();
			vec.pop_back();
			Node* phai = vec.back();
			vec.pop_back();
			head= new Node(trai->freq + phai->freq, 'a');
			if(trai->freq != phai->freq){
			head->pLeft = trai;
			head->pRight = phai;
			}
			else{
				if(trai->character>phai->character){
				head->pLeft = phai;
				head->pRight = trai;
				}
				else{
				head->pLeft = trai;
				head->pRight = phai;			
				}
			}
		}
		else if(vec.size()==1){
			head = new Node(vec.front()->freq, vec.front()->character);
			vec.pop_back();
		}
		if(head1==NULL && head2==NULL){
			head1= head;
		}
		else if(head1 != NULL){
			head2 = head;
		}

		if(head1 != NULL && head2 != NULL){
			Node* headd= new Node(head1->freq+head2->freq, 'a');
			if(head1->freq > head2->freq){
				headd->pLeft = head2;
				headd->pRight = head1;
			}
			else{
				headd->pLeft = head1;
				headd->pRight = head2;
			}
			head1=headd;
			head2=NULL;
		}
	}
	return head1;
}
// Function for step 3

void HuffmanCode::encodeCharacter(Node *root, string prefix){
	if(root==NULL){
		return;
	}
	this->hashTable[root->character] = prefix;
	encodeCharacter(root->pLeft, prefix+'0');
	encodeCharacter(root->pRight, prefix+'1');
	return;
}
int main(){
    string s = "ABC";
    HuffmanCode myCode;
    myCode.constructFreqTable(s);
    Node *tree = myCode.constructTree();
	Node* tmp=tree;
	tree->print(tmp);
    myCode.encodeCharacter(tree, "");
    string encodedString = myCode.encode(s);
    cout << "Encoded string: " << encodedString;
    myCode.deleteTree(tree);
	cout << endl;
	myCode.printHashTable();
}