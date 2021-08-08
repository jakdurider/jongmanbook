#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int total;
void picnic(vector<int>& students, vector<vector<int>>& pairs){
    if(students.size()==0) ++total;
    else{
        int friend0 = students[0];
        for(int i=0;i<pairs.size();++i){
            if(pairs[i][0]==friend0){
                int friend1 = pairs[i][1];
                vector<int>::iterator it = find(students.begin(),students.end(),friend1);
                if(it!=students.end()){
                    students.erase(it);
                    students.erase(students.begin());
                    picnic(students,pairs);
                    students.insert(students.begin(),friend0);
                    students.insert(it,friend1);
                }
            }
            else if(pairs[i][1]==friend0){
                int friend1 = pairs[i][0];
                vector<int>::iterator it = find(students.begin(),students.end(),friend1);
                if(it!=students.end()){
                    students.erase(it);
                    students.erase(students.begin());
                    picnic(students,pairs);
                    students.insert(students.begin(),friend0);
                    students.insert(it,friend1);
                }
            }
        }
    }
}

int main()
{

    int C;
    int student_num, pair_num;
    cin >> C;
    for(int i=0;i<C;++i){
        total = 0;
        cin >> student_num >> pair_num;
        vector<int> students(student_num);
        for(int i=0;i<student_num;++i){
            students[i] = i;
        }
        vector<vector<int>> pairs(pair_num);
        for(int i=0;i<pair_num;++i){
            int friend0, friend1;
            cin >> friend0 >> friend1;
            pairs[i].push_back(friend0);
            pairs[i].push_back(friend1);
        }
        picnic(students,pairs);
        cout<<total<<endl;
    }
    return 0;
}