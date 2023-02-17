#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename,vector<string> names, vector<int> scores, vector<char> grades){
    ifstream data;
    data.open(filename);
    char format[] = "%[^:] : %d %d %d";
    int sum;
    string textline;
    while(getline(data,textline)){
        char name[100];
        int a,b,c;
        sscanf(textline.c_str(),format,&name,&a,&b,&c);
        names.push_back(name);
        sum = a + b + c;
        scores.push_back(sum);
        char g = score2grade(sum);
        grades.push_back(g);
    }
    
}

void getCommand(string &command,string &key){
    string text;
    char kkk[100],mmm[100];
    char format[] = "%s %[^\n] ";
    cout << "Please input your command: ";
    getline(cin,text);
    sscanf(text.c_str(),format,kkk,mmm);

    command = kkk;
    key = mmm;
    
}


void searchName(vector<string> names, vector<int> scores, vector<char> grades,string key){
    int index;
    for(int i = 0; i < names.size(); i++){
        if(names[i] == key){
            index = i;
        }
    }
    cout << "---------------------------------\n";
    cout << names[index] << "'s score = " << scores[index];                      
    cout << names[index] << "'s grade = " << grades[index];                      
    cout << "\n---------------------------------\n";
    
}

void searchGrade(vector<string> names, vector<int> scores, vector<char> grades,string key){
    cout << "---------------------------------\n";
    char k = key[0];
    for(int i = 0; i < names.size() ; i++ ){
        if(grades[i] == k) cout << names[i] << " (" << scores[i] << ")" << endl; 
    }
    cout << "---------------------------------\n";
}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        cout << "\n" << command << " \n" << key ; 
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
