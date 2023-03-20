#include<iostream>
#include<map>
#include<fstream>
#include<vector>
using namespace std;

ifstream filedata("hw2_data.txt"); //讀入檔案
string box[1000]; //每一個名字放的陣列
map<string,int> counter; 
int lines = 0; 

int readfile();
void counting();
void output();

int main(){
    readfile();   //讀檔
    counting();   //數次數 
    output();     //輸出
    return 0;
}

int readfile(){
    if(filedata.fail()){
        cout << "file failed to open." << endl; //看file有沒有打開
        return 1;
    }
    while(!filedata.eof()){
        getline(filedata, box[lines]); //每一個名字放在陣列裡面
        lines++;
    }
    filedata.close(); //關閉檔案
}
void counting(){
    for(int i=0; i< lines; i++){
        string labeltype;
        labeltype = box[i]; //製造key
        counter[labeltype]++; //key對應的數字增加
    }
}
void output(){
    cout << "總共有多少個不重複的英文字：" << counter.size() << endl;
    for(auto itr= counter.begin(); itr !=counter.end(); itr++){
        cout << itr->first << "\t";
        cout << itr->second << endl;
    }
}