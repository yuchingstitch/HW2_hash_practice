#include<iostream>
#include<map>
#include<fstream>
#include<vector>
using namespace std;

ifstream filedata("hw2_data.txt"); //Ū�J�ɮ�
string box[1000]; //�C�@�ӦW�r�񪺰}�C
map<string,int> counter; 
int lines = 0; 

int readfile();
void counting();
void output();

int main(){
    readfile();   //Ū��
    counting();   //�Ʀ��� 
    output();     //��X
    return 0;
}

int readfile(){
    if(filedata.fail()){
        cout << "file failed to open." << endl; //��file���S�����}
        return 1;
    }
    while(!filedata.eof()){
        getline(filedata, box[lines]); //�C�@�ӦW�r��b�}�C�̭�
        lines++;
    }
    filedata.close(); //�����ɮ�
}
void counting(){
    for(int i=0; i< lines; i++){
        string labeltype;
        labeltype = box[i]; //�s�ykey
        counter[labeltype]++; //key�������Ʀr�W�[
    }
}
void output(){
    cout << "�`�@���h�֭Ӥ����ƪ��^��r�G" << counter.size() << endl;
    for(auto itr= counter.begin(); itr !=counter.end(); itr++){
        cout << itr->first << "\t";
        cout << itr->second << endl;
    }
}