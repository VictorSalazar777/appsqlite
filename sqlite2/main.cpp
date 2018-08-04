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
    cout << "Closing..." << endl;
}
