#include <iostream>
using namespace std;

struct classname{
    const char *name;
    int cap;
};
int main(){
    classname *p = new classname;
    char a[] = "helloaaa";
    p->name = a;
    cout<<p->name<<endl;
    return 0;
}
    
