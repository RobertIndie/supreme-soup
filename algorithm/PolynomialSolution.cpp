#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef double data_type;

int compute(const data_type *p,const int p_count,const data_type input){
    data_type result=0;
    for(int i=p_count-1,t=0;i>=0;i--,t++){
        result += p[i]*pow(input,t);
    }
    return result;
}

vector<data_type>* conversion(data_type data,data_type p){
    vector<data_type> *result = new vector<data_type>;
    int c=0,m=0;
    int _data = (int)data;
    int _p = (int)p;
    while(_data!=0){
        c=fmod(_data,_p);
        _data=_data/_p;
        result->push_back(c);
    }
    return result;
}

int main(){
    int p_count = 0;
    cout << "输入多项式项数：";
    cin >> p_count;
    cout << "输入多项式系数，从高到低：";
    data_type* p=new data_type[p_count];
    for(int i=0;i<p_count;i++){
        cin >> p[i];
    }
    data_type r = compute(p,p_count,1);
    cout << "代入 1 得到的值：" << r << endl;
    data_type r2 = compute(p,p_count,r+1);
    cout << "代入 " << r+1 << " 得到的值：" << r2 << endl;
    vector<data_type> *result = conversion(r2,r+1);
    int t =result->size()-1;
    cout << "解得结果：";
    for(vector<data_type>::reverse_iterator iter=result->rbegin();iter!=result->rend();++iter,--t){
        static bool first = true;
        if(*iter==0)continue;
        if(!first){
            cout << " + ";
        }else{
            first = false;
        }
        cout << *iter;
        if(t==1){
            cout << "x";
        }
        else if(t!=0){
            cout << "x^" << t;
        }
    }
    delete [] p;
    delete result;
    return 0;
}
