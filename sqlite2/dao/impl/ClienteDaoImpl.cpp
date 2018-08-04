//
//  ClienteDaoImpl.cpp
//  sqlite2
//
//  Created by manuel on 8/3/18.
//  Copyright © 2018 manuel. All rights reserved.
//

#include "ClienteDaoImpl.hpp"
#include "dto/ClienteEntry.hpp"
#include "db_connection/SqliteConnection.hpp"
#include "utils/DatabaseUtils.hpp"
#include <sqlite3.h>
#include <iostream>

using namespace std;

ClienteDaoImpl::ClienteDaoImpl() {
    db = DatabaseUtils::getDb((SqliteConnection::getInstance())->getSqliteConnection());
}

int ClienteDaoImpl::qry(const list<ClienteEntry> &clientes) {
    const string sql = "SELECT * FROM cliente";
    int rc = -1;
    
    DatabaseUtils::uniqueStmtPtr stmt = DatabaseUtils::getStmt(db.get(), sql);
    
    cout << "dao: "<< sqlite3_sql(stmt.get()) << endl;
    
    if (int err = sqlite3_step(stmt.get()) != SQLITE_DONE) {
        cerr << "step error code: " << sqlite3_errstr(err) << endl;
        DatabaseUtils::printDbMsgError(db.get(), "step error");
        return rc;
    }
    
    return rc;
}

int ClienteDaoImpl::ins(const ClienteEntry &cliente) {
    int rc;
    return rc;
}

int ClienteDaoImpl::get(long id, const ClienteEntry &cliente) {
    int rc;
    return rc;
}
