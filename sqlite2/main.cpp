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
#include "utils/timeUtilitiesCpp.hpp"
#include <sqlite3.h>

using namespace std;
using myclock = chrono::system_clock;


int main(int argc, const char * argv[]) {
    cout << "Starting app..." << " cpp version: "<< __cplusplus << endl;
    cout << "Working dir: " << FileSystemUtils::getCurrentDirectory() << endl;
    
    list<unique_ptr<ClienteEntry>> clientes;
    unique_ptr<ClienteDao> dao = make_unique<ClienteDaoImpl>();
    unique_ptr<ClienteEntry> cliente = make_unique<ClienteEntry>();
    
    struct argt {
        unique_ptr<ClienteDao> dao;
        unique_ptr<ClienteEntry> cliente;
    } arg;
    arg.dao = move(dao);
    arg.cliente = move(cliente);
    time_of_execution_with_chrono_cpp<myclock>([](void* args){
        for (int i = 0; i < 1000; i++) {
            ((argt*)(args))->cliente->nombres = "Marco Aurelio";
            ((argt*)(args))->cliente->apellidos = "Denegri";
            ((argt*)(args))->cliente->dni = "123134213";
            ((argt*)(args))->dao->ins(((argt*)(args))->cliente);
        }
    }, &arg);
    time_of_execution_with_chrono_cpp<myclock>([](void* args){
        ((argt*)(args))->dao->beginTransaction();
        for (int i = 0; i < 1000; i++) {
            ((argt*)(args))->cliente->nombres = "Marco Aurelio";
            ((argt*)(args))->cliente->apellidos = "Denegri";
            ((argt*)(args))->cliente->dni = "123134213";
            ((argt*)(args))->dao->ins(((argt*)(args))->cliente);
        }
        ((argt*)(args))->dao->endTransaction();
    }, &arg);
    
    dao = make_unique<ClienteDaoImpl>();
    cliente = make_unique<ClienteEntry>();
    
    dao->execUpdateHook([](void* arg, int opType, const char* dbName, const char* tableName, long long rowid){
        cout << opType << endl;
        cout << dbName << endl;
        cout << tableName << endl;
        cout << rowid << endl;
    });

    cliente->nombres = "Marco Aurelio";
    cliente->apellidos = "Denegri";
    cliente->dni = "123134213";
    dao->ins(cliente);
    
    //getchar();
    cout << "Closing..." << endl;
}
