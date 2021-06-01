#include <bits/stdc++.h>
using namespace std;
class Trie
{
private:
    vector<Trie *> links;
    int n;
    int offset;
    bool end;
public:
    Trie(int n = 256,int offset=0)
    {
        this->n=n;
        this->offset=offset;
        end=false;
        links = vector<Trie *>(n, nullptr);
    }
    void set(int index){
        if(links[index-offset]==nullptr)links[index-offset]=new Trie(n,offset);
    }
    Trie* get(int index){
        return links[index-offset];
    }
    bool has(int index){
        return links[index-offset]!=nullptr;
    }
    bool eof(){
        return end;
    }
    void insert(const string &str){
        Trie* temp = this;
        int i=0;
        while(i<str.size()){
            temp->set(str[i]);
            temp=temp->get(str[i]);
            i++;
        }
        temp->end=true;
    }
    bool find(const string &target){
        Trie* temp = this;
        int i=0;
        while(i<target.size()&&temp->has(target[i])){
            temp=temp->get(target[i]);
            i++;
        }
        return i==target.size()&&temp->eof();
    }
    static void getAll(Trie* root, vector<string> &res, string cur=""){
        if(root->eof()){
            res.push_back(cur);
        }
        for(int i=0;i<root->n;i++){
            if(root->has(i+root->offset)){
                getAll(root->get(i+root->offset), res, cur+char(i+root->offset));
            }
        }
    }
    vector<string> findAll(const string &prefix){
        Trie* temp = this;
        int i=0;
        while(i<prefix.size()&&temp->has(prefix[i])){
            temp=temp->get(prefix[i]);
            i++;
        }
        vector<string> result;
        if(i==prefix.size()){
            Trie::getAll(temp, result, prefix);
        }
        return result;
    }
    bool exist(const string &target){
        Trie* temp = this;
        int i=0;
        while(i<target.size()&&temp->has(target[i])){
            temp=temp->get(target[i]);
            i++;
        }
        return i==target.size();
    }
};

int main(){
    Trie* root = new Trie(26,'a');
    root->insert("ashish");
    root->insert("ashley");
    root->insert("asful");
    vector<string> all = root->findAll("as");
    for(string s:all)cout<<s<<" ";
    cout<<endl;
    cout<<"prefix \"ash\" is present in the tree -> "<<root->exist("ash")<<endl;
    cout<<"word \"ash\" is present in the tree -> "<<root->find("ash")<<endl;
    cout<<"word \"ashish\" is present in the tree -> "<<root->find("ashish")<<endl;
}