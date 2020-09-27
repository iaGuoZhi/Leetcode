#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


struct King_Node{
    vector<King_Node*> table; 
    bool alive;
    string name;
    King_Node(string n): name(n), alive(true){}
};
class ThroneInheritance {
    King_Node *root;
    vector<string> inheritance;
    unordered_map<string, King_Node*> mp;
public:
    ThroneInheritance(string kingName) {
        root= new King_Node(kingName);
        mp[kingName]=root;
    }
    
    void birth(string parentName, string childName) {
        King_Node *node=mp[parentName];
        King_Node *child=new King_Node(childName);
        mp[childName]=child;
        node->table.push_back(child);
    }
    
    void death(string name) {
        King_Node *node=mp[name];
        node->alive=false;
    }
    
    void traverse(King_Node *node){
        if(node->alive){
            inheritance.push_back(node->name);
        }
        
        for(auto child: node->table){
            traverse(child);
        }
    }
    vector<string> getInheritanceOrder() {
        inheritance.clear();
        traverse(root);
        return inheritance;
    }
};

int main(){
    ThroneInheritance t= ThroneInheritance("king"); // 继承顺序：king
    t.birth("king", "andy"); // 继承顺序：king > andy
    t.birth("king", "bob"); // 继承顺序：king > andy > bob
    t.birth("king", "catherine"); // 继承顺序：king > andy > bob > catherine
    t.birth("andy", "matthew"); // 继承顺序：king > andy > matthew > bob > catherine
    t.birth("bob", "alex"); // 继承顺序：king > andy > matthew > bob > alex > catherine
    t.birth("bob", "asha"); // 继承顺序：king > andy > matthew > bob > alex > asha > catherine
    t.getInheritanceOrder(); // 返回 ["king", "andy", "matthew", "bob", "alex", "asha", "catherine"]
    t.death("bob"); // 继承顺序：king > andy > matthew > bob（已经去世）> alex > asha > catherine
    t.getInheritanceOrder(); // 返回 ["king", "andy", "matthew", "alex", "asha", "catherine"]
}
