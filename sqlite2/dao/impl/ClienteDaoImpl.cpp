//
//  ClienteDaoImpl.cpp
//  sqlite2
//
//  Created by manuel on 8/3/18.
//  Copyright © 2018 manuel. All rights reserved.
//

#include "ClienteDaoImpl.hpp"
#include "dto/ClienteEntry.hpp"
#include <iostream>

using namespace std;

ClienteDaoImpl::ClienteDaoImpl() {
    db = DatabaseUtils::getDb();
}

int ClienteDaoImpl::qry(list<unique_ptr<ClienteEntry>> &clientes) {
    const string sql = "SELECT * FROM cliente";
    int res = -1;
    
    DatabaseUtils::uniqueStmtPtr stmt = DatabaseUtils::getStmt(db, sql);
    
    cout << "dao: "<< sqlite3_sql(stmt.get()) << endl;
    
    while(1) {
        int rc = sqlite3_step(stmt.get());
        if (rc == SQLITE_DONE) {
            break;
        }
        if (rc != SQLITE_ROW) {
            DatabaseUtils::printDbMsgError(db, "step error");
            break;
        }
        unique_ptr<ClienteEntry> clientePtr = make_unique<ClienteEntry>();
        clientePtr->id = sqlite3_column_int64(stmt.get(), 0);
        clientePtr->nombres = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt.get(), 1)));
        clientePtr->apellidos = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt.get(), 2)));
        clientePtr->dni = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt.get(), 3)));
        clientes.push_back(std::move(clientePtr));
    }
    return res;
}

int ClienteDaoImpl::ins(ClienteEntry &cliente) {
    int rc;
    return rc;
}

int ClienteDaoImpl::get(long long id, ClienteEntry &cliente) {
    int rc;
    return rc;
}
