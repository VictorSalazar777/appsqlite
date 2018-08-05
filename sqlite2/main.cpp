//
//  main.cpp
//  sqlite2
//
//  Created by manuel on 8/3/18.
//  Copyright © 2018 manuel. All rights reserved.
//

#include "db_connection/SqliteConnection.hpp"
#include "utils/FileSystemUtils.hpp"
#include <iostream>
#include <list>
#include "dao/ClienteDao.hpp"
#include "dao/impl/ClienteDaoImpl.hpp"
#include "dto/ClienteEntry.hpp"

using namespace std;


int main(int argc, const char * argv[]) {
    cout << "Starting app..." << " cpp version: "<< __cplusplus << endl;
    cout << "Working dir: " << FileSystemUtils::getCurrentDirectory() << endl;

    list<unique_ptr<ClienteEntry>> clientes;
    unique_ptr<ClienteDao> dao = make_unique<ClienteDaoImpl>();
    dao->qry(clientes);
    for (auto it = clientes.begin(); it != clientes.end(); ++it) {
        (*it)->print();
    }
    unique_ptr<ClienteEntry> cliente = make_unique<ClienteEntry>();
    dao->get(2LL, cliente);
    cliente->print();
    
    cliente->nombres = "Marco Aurelio";
    cliente->apellidos = "Denegri";
    cliente->dni = "123134213";
    dao->ins(cliente);
    
    cliente->id = 3LL;
    cliente->nombres = "Felipe";
    cliente->apellidos = "Salazar";
    cliente->dni = "412343145";
    dao->upd(cliente);
    
    list<long long> ids;
    ids.push_back(4LL);
    ids.push_back(5LL);
    dao->del(ids);
    
    cout << "Closing..." << endl;
}
