//
// Created by Admin on 6/1/2024.
//
#include "ClientInMemory.cpp"
#include <memory>

using std::shared_ptr;

class Controller{
private:
    shared_ptr<ClientInMemoryRepository> repo;
public:
    Controller(shared_ptr<ClientInMemoryRepository> _repo){
        this->repo=_repo;
    }

    Client findById(int id){repo->findOne(id);}

    vector<Client> findByName(string name){
        vector<Client> aux=repo->findAll();
        for(int i=0;i<aux.size();i++){
            if(aux[i].get_name().find(name)==std::string::npos){
                aux.erase(aux.begin()+i);
            }
        }
        return aux;
    }

    void saveClient(Client client){repo->save(client);};
    void deleteClient(int id){repo->del(id);};
};
