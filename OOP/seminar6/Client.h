//
// Created by Admin on 6/1/2024.
//

#ifndef SEMINAR6_CLIENT_H
#define SEMINAR6_CLIENT_H

#endif //SEMINAR6_CLIENT_H
#include <string>

using std::string;


class Client{
private:
    int id;
    string name;
    bool company;
public:
    Client(int _id,string _name,bool _company): id(_id),name(_name), company(_company){}
    ~Client(){};
    int get_id(){return id;};
    void set_id(int _id){id=_id;};
    string get_name(){return name;};
    void set_name(string _name){name=_name;};
    bool get_company(){return company;};
    void set_company(bool _company){company=_company;};

};