#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    vector<string> cro = {"c=","c-","dz=","d-","lj","nj","s=","z="};
    int idx;
    string a; cin >> a;
    for(int i = 0; i < cro.size(); i++)
    {
        while(true){
            idx = a.find(cro[i]);
            if(idx == string::npos)
                break;
            a.replace(idx,cro[i].length(),"#");
        }
    }
    cout << a.length() << endl;
}