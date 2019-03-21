/*************************************************************************
	> File Name: chatRob.cpp
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年03月17日 星期日 14时16分23秒
 ************************************************************************/
#include <time.h>
#include <stdlib.h>
#include <stdarg.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <regex>
#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

unordered_map<string,string> dataW;

//  从file里读取问答的模板 该函数是一个泛型函数
//  输入：文件名 要读入到哪儿 如何划分 如何处理
//  输出：-1 错误 0 正确
template<typename T>
int transToT(const string &file,vector<T> &pairs,unordered_map<char,int>flags,void(*delFunc)(int,string,vector<T>&)){
    // 打开文件
    ifstream inFile;
    inFile.open(file,ios::in);
    if(!inFile){
        cout << "when open " <<file << strerror(errno);
        return -1;
    }
    // 逐行读取文件
    string line;
    int flag = -1;
    while(getline(inFile,line)){
        if(line[0] == '/'){
            // 以// 开头的是注释
            continue;
        }
        // 取得标记
        if(line[0] == '@'){
            auto i = flags.find(line[1]);
            if(i == flags.end()){
                printf("Wrong key ,can not find flags[%c]\n",line[1]); 
                return -1;
            }else{
                flag = i->second;
                continue;
            }
        }
        // 调用接口函数处理
        delFunc(flag,line,pairs);
    }
    return 0;
}

vector<string> regexSplit(const string& input,const string S){
    regex re(S);

    sregex_token_iterator p(input.begin(),input.end(),re,-1);
    sregex_token_iterator end;
    vector<string>vec;
    while(p != end){
        vec.emplace_back(*p++);
    }

    return vec;
}

class flower{
    public:
    string name;// 花名
    string flowerLanguage;//花语
    vector<string>scenes;// 适合的场景
    flower(string Name,string FL,vector<string>S){
        name = Name;
        flowerLanguage = FL;
        scenes = vector<string>(S.begin(),S.end());
    }
    flower(string name){
        this->name = name;
    }
    bool isSuitable(string S){
        for(auto i : scenes){
            if(i == S){
                return true;
            }
        }
        return false;
    }
    void setFlowerLang(string L){
        flowerLanguage = L;
    }
    void insertScene(string s){
        scenes.push_back(s);
    }
};

class flowers{
    private:
    vector<flower>items;
    public:
    flowers(){

    }
    flowers(vector<flower>*f){
        items = *f;
    }
    vector<flower> getFlowers(){
        return items;
    }

    void coutSuitFlower(string scenes){
        int ii = 0;
        for(auto i : items){
            if(i.isSuitable(scenes)){
                ii = 1;
                cout <<"* " << i.name << endl;
                cout <<"-- " << i.flowerLanguage<<endl;
            }
        }
        if(ii == 0){
            cout << "no suitable \n";
        }else{
            cout << "That is all\n";
        }
    }
};

// 注意 Q 代表用户
//      A 代表程序
class QA{

private:
    // 问题的模板
    regex pattern;
    // 该问题的回答
    vector<string> anses;
    // 该问题的意图
    string mind;
public:
    QA(string Q){
        pattern = regex(Q);
    }
    void setMind(string M){
        mind = M;
    }
    void insertA(string A){
        anses.push_back(A);
    }
    bool QA_match(string str,smatch &result){
        return regex_match(str,result,pattern);
    }
    string random_ans(){
        int index = rand() % anses.size();
        return anses[index];
    }
    string getMind(){
        return mind;
    }
};

// 用来处理解析QA的函数
void delQA(int flag,string line,vector<QA>&QAs){
    switch(flag){
        // 意味着读到了一个 question
        case 0:{
            QA* tmp = new QA(line);
            QAs.push_back(*tmp);
        }break;
        // 意味着读到了一个 answer
        case 1:{
            QAs.back().insertA(line);
        }break;
        // 意味着读到了一个 mind
        case 2:{
            QAs.back().setMind(line);
        }
    }
}

// 用来解析花朵的
void delFlower(int flag,string line,vector<flower>&FS){
    switch(flag){
        case 0:{
            flower* f = new flower(line); 
            FS.push_back(*f);
        }break;
        case 1:{
           FS.back().setFlowerLang(line); 
        }break;
        case 2:{
            for(auto i : regexSplit(line,",")){
                FS.back().insertScene(i);
            }
        }break; 
    }
}
// 工作函数的函数指针
typedef void* (*job)(void*);

class simpleQAs{

private:
    // 我的姓名
    string name;
    // 问答模板
    vector<QA> QAs;

    QA answerQA(string input,string &args){
        smatch res;
        for(auto item : QAs){
            if(item.QA_match(input,res)){
                args = res.str(1);
                return item; 
            }
        }
    }

    QA answerQA(string input){
        smatch result;
        for(auto item : QAs){
            if(item.QA_match(input,result)){
                return item; 
            }
        }
    }
public:
    simpleQAs(){
        
    }

    simpleQAs(string &file,unordered_map<char,int>*flags,void(*delQA)(int,string,vector<QA>&)){
        transToT(file,QAs,*flags,delQA);
    }

    // 根据输入判断意图
    string listen(string input,string& args){
        QA item = answerQA(input,args);
        return item.getMind();
    }

    string answer(string input,string & mind){
        QA item = answerQA(input);
        mind = item.getMind();
        return item.random_ans(); 
    }
    // 用来回答输入的
    string answer(string input){
        return answerQA(input).random_ans(); 
    }

    // 由外界函数调用的一个 
    void chatAndAnswer(){
        string input = ""; 
        cout << ">:";
        while(getline(cin,input)){
            cout << name <<"   " << answer(input)<<endl;
            cout << ">:";
        }
    }
};

// 该类是用来解析配置文件的
class config{
    public:
    string type;
    string name;
    unordered_map<char,int>flags;
    string filePath;
    friend ostream & operator<<(ostream &out, config &obj){
        out << "type:" << obj.type << endl
            << "name:" << obj.name << endl
            << "path:" << obj.filePath << endl;
        return out;
    }
    config(string type){
        this->type = type;
    }

    void setPath(string P){
        filePath = P;
    }

    void setName(string N){
        name = N;
    }

    void insertFlag(char C,int V){
        flags[C] = V;
    }


    void* solveConfig(){
        if(type == "flowers"){
            vector<flower>* F = new vector<flower>();
            transToT(filePath,*F,flags,delFlower);
            return F;
        }else if(type == "topics"){
            simpleQAs* qas = new simpleQAs(filePath,&flags,delQA);
            return qas;
        }
    }
};



// 用来解析配置文件的回调接口
void delConfig(int flag,string line,vector<config>&configs){
    switch(flag){
        case 0:{
            vector<string>res = regexSplit(line,":");
            config* temp = new config(res[0]);
            temp->setName(res[1]);
            configs.push_back(*temp);
        }break;
        case 1:{
            vector<string>res = regexSplit(line,":");
            configs.back().insertFlag(res[0][0],atoi(res[1].c_str()));
        }break;
        case 2:{
            configs.back().setPath(line);
        }break;
    }

}

// 用来解析config 文件，来简化接下来的类的初始化的任务
void initConfigs(string path,vector<config>&configs){
    unordered_map<char,int>flags;
    flags['T'] = 0;
    flags['F'] = 1;
    flags['P'] = 2;
    transToT(path,configs,flags,delConfig);
}

class simpleBuyFlowerRob{
    private:
    // 机器人的名字
    string name;
    // 结束词语
    string end;
    // 可以谈论的话题名与对应的类
    unordered_map<string,simpleQAs> topics;
    // 干活的函数们
    map<string,job> jobs;
    // 花朵们
    flowers* myFlowers;
    public:
    simpleBuyFlowerRob(string end){
        this->end = end;
    }

    void setMyFlowers(flowers* F){
        myFlowers = F;
    }

    void setName(string name){
        this->name = name;
    }

    void addTopic(string name,simpleQAs* qa){
       topics[name] = *qa; 
    }
    
    simpleQAs* getTopic(string name){
       return &topics.find(name)->second; 
    }

    // 调用话题来回应
    string listen(string topic,string input,string  &args){
        return getTopic(topic)->listen(input,args);
    }

    void saySomething(string topic,string input,string&mind){
        cout << name << " " << getTopic(topic)->answer(input,mind) << endl;
    }

    void saySomething(string topic,string input){
        cout << name << " " << getTopic(topic)->answer(input) << endl;
    }

    void saySomething(string ans){
        cout << name << " " << ans << endl;
    }

    // 状态转移定义
    string think(string curTopic,string mind,string &input){
        if(curTopic == "welcome"){
            if(mind == "YES"){
                input = "ASK_SCENCE";
                return "choice";
            }else if(mind == "UNKNOW"){
                return "welcome";
            }else 
                return "welcome";
        }else if(curTopic == "choice"){
            if(mind == "YES"){
                input = "ASK_SHOP";
                return "shop";
            }
            return "choice";
        }else if(curTopic == "shop"){
            if(mind == "BACK"){
                input = "SAY_WELCOME";
                return "welcome";
            }
            return "shop";
        }
        return "welcome";
    }

    void doJob(string topic,string mind,string  &args){
        if(topic == "choice"){
            if(mind == "GET_SCENCE"){
                myFlowers->coutSuitFlower(args);
            }
        }
        if(topic == "shop"){
            if(mind == "GET_SHOP"){
                for(auto i : dataW){
                    cout <<"shop :" <<i.first<<"\nurl:" << i.second << endl;
                }
            }
        }
    }

    void startChat(){
        string mind;
        string input;
        string ans;
        string args;
        string curTopic = "welcome";
        // 输出欢迎信息
        saySomething("welcome","SAY_WELCOME");
        while(getline(cin,input)){
            if(input == end){
                // 输出结束信息
                saySomething("welcome","BYE");
                break;
            } 
            // 获得意图
            mind = listen(curTopic,input,args);
            // 获得下个话题和修改input
            curTopic = think(curTopic,mind,input);
            // 输出相应的话语
            saySomething(curTopic,input);
            // 干点事情
            doJob(curTopic,mind,args);
        }
    }
};

int main(){

    dataW["Forget Me Nots"]="forgetmenotsreading.co.uk";
    dataW["Sonning Flower"]="sonningflowers.com";
    dataW["The home of Dreams Flower Studio"]="thehomeofdreams.com";
    dataW["7 Flower & Tea"]="7-flowers.co.uk";

    // 聊天控制类
    simpleBuyFlowerRob GINTAMA("quit");
    GINTAMA.setName(":)");

    // 设置随机数种子
    srand(time(NULL));

    // 初始化全局配置
    string configPath = "conf";
    vector<config> configs;
    initConfigs(configPath,configs);

    // 初始化花朵的配置
    flowers myFlowers;
    for(auto i : configs){
        if(i.type == "flowers"){
            myFlowers = flowers((vector<flower>*)i.solveConfig());
            break;
        }
    }
    GINTAMA. setMyFlowers(&myFlowers);

    // 添加话题到控制类
    for(auto i : configs){
        if(i.type == "topics"){
            GINTAMA.addTopic(i.name, (simpleQAs*)i.solveConfig());
        }
    } 

    // 开始聊天
    GINTAMA.startChat();

    return 0;
}
