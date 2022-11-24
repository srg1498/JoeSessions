#include<iostream>

class Node{
   public:
      char data;
	  bool hasReachedEnd;
	  Node* arr[26];
	  
	  Node(char data) : data(data), hasReachedEnd(false){
	      for(int i=0;i<26;i++){
		      arr[i] = NULL;
		  }
	  };
	  
	  ~Node(){
	      // delete
	  }
};

class Trie{
    public:
	    Node* root;
		
	    Trie(){
		    root = new Node('$');
		}
		
		void insertWord(std::string word){
		    Node* curr = root;
			for(int i=0;i<word.size();i++){
			    int pos = word[i] - 97;
				if(curr->arr[pos]){
				    curr = curr->arr[pos];        
				}else{
				    Node* p = new Node(word[i]);
					curr->arr[pos] = p;
					curr = curr->arr[pos];
				}
			}	
			curr->hasReachedEnd = true;
		}
		
		
		bool searchWord(std::string word){
		    Node* curr = root;
			for(int i=0;i<word.size();i++){
			    int pos = word[i] - 97;
				if(curr->arr[pos]){
				    curr = curr->arr[pos];
				}else{
				    return false;
				}
			}
			return curr->hasReachedEnd;
		}

        void deleteWord(std::string word){
		    Node* curr = root;
			for(int i=0;i<word.size();i++){
			    int pos = word[i] - 97;
				if(curr->arr[pos]){
				    curr = curr->arr[pos];        
				}else{
                    return;
				}
			}	
			curr->hasReachedEnd = false;
		}
};


int main(){
    Trie trie = Trie();

    trie.insertWord("bat");
    trie.insertWord("ball");
    trie.insertWord("bull");
    trie.insertWord("cat");
    trie.insertWord("cab");
    trie.insertWord("dog");

    std::cout<<"dog "<<trie.searchWord("dog")<<"\n";
    std::cout<<"cab "<<trie.searchWord("cab")<<"\n";
    std::cout<<"cool "<<trie.searchWord("cool")<<"\n";

    trie.deleteWord("dog");
    std::cout<<"after delete, dog "<<trie.searchWord("dog")<<"\n";

    return 0;
}