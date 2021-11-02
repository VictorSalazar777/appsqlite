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

int ClienteDaoImpl::beginTransaction() {
    return sqlite3_exec(db.get(), "BEGIN TRANSACTION;", NULL, NULL, NULL);
}
int ClienteDaoImpl::endTransaction() {
    return sqlite3_exec(db.get(), "END TRANSACTION;", NULL, NULL, NULL);
}

void *ClienteDaoImpl::execUpdateHook(
                                     void(*callback)(void *arg, int opType, const char* dbName,
                                                     const char* tableName, long long rowid), void *arg) {
    return sqlite3_update_hook(
                               db.get(),
                               callback,
                               arg
                               );
}

int ClienteDaoImpl::qry(list<unique_ptr<ClienteEntry>> &clientes) {
    int res = -1;
    const string sql = "SELECT * FROM cliente";
    DatabaseUtils::uniqueStmtPtr stmt = DatabaseUtils::getStmt(db, sql);
    
    cout << "dao qry: "<< sqlite3_sql(stmt.get()) << endl;
    
    while(1) {
        int rc = sqlite3_step(stmt.get());
        if (rc == SQLITE_DONE) {
            res = 0;
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

int ClienteDaoImpl::ins(unique_ptr<ClienteEntry> &cliente) {
    int res = -1;
    const string sql = "INSERT INTO cliente2(nombres, apellidos, dni) VALUES(?, ?, ?)";
    DatabaseUtils::uniqueStmtPtr stmt = DatabaseUtils::getStmt(db, sql);
    
    if (int rc = sqlite3_bind_text(stmt.get(), 1, cliente->nombres.c_str(),
                                   static_cast<int>(cliente->nombres.size()),
                                   SQLITE_STATIC) != SQLITE_OK) {
        cerr << "bind error code: " << sqlite3_errstr(rc) << endl;
        cerr <<"file: " << __FILE__ << ", line: " << __LINE__ << endl;
        DatabaseUtils::printDbMsgError(db, "bind error");
        
        return res;
    }
    
    if (int rc = sqlite3_bind_text(stmt.get(), 2, cliente->apellidos.c_str(),
                                   static_cast<int>(cliente->apellidos.size()),
                                   SQLITE_STATIC) != SQLITE_OK) {
        cerr << "bind error code: " << sqlite3_errstr(rc) << endl;
        DatabaseUtils::printDbMsgError(db, "bind error");
        cerr <<"file: " << __FILE__ << ", line: " << __LINE__ << endl;
        return res;
    }
    
    if (int rc = sqlite3_bind_text(stmt.get(), 3, cliente->dni.c_str(),
                                   static_cast<int>(cliente->dni.size()),
                                   SQLITE_STATIC) != SQLITE_OK) {
        cerr << "bind error code: " << sqlite3_errstr(rc) << endl;
        DatabaseUtils::printDbMsgError(db, "bind error");
        cerr <<"file: " << __FILE__ << ", line: " << __LINE__ << endl;
        return res;
    }
    
    //cout << "dao ins: "<< sqlite3_expanded_sql(stmt.get()) << endl;

    if (int rc = sqlite3_step(stmt.get()) != SQLITE_DONE) {
        cerr << "step error code: " << sqlite3_errstr(rc) << endl;
        DatabaseUtils::printDbMsgError(db, "step error");
        cerr <<"file: " << __FILE__ << ", line: " << __LINE__ << endl;
        return res;
    }
    
    res = 0;
    
    return res;
}

int ClienteDaoImpl::get(long long id, unique_ptr<ClienteEntry> &cliente) {
    int res = -1;
    const string sql = "SELECT * FROM `cliente` WHERE `id`=?";
    DatabaseUtils::uniqueStmtPtr stmt = DatabaseUtils::getStmt(db, sql);
    
    if (int rc = sqlite3_bind_int64(stmt.get(), 1, id) != SQLITE_OK) {
        cerr << "bind error code: " << sqlite3_errstr(rc) << endl;
        DatabaseUtils::printDbMsgError(db, "bind error");
        return res;
    }
    
    cout << "dao get: "<< sqlite3_expanded_sql(stmt.get()) << endl;
    
    while(1) {
        int rc = sqlite3_step(stmt.get());
        if (rc == SQLITE_DONE) {
            res = 0;
            break;
        }
        if (rc != SQLITE_ROW) {
            DatabaseUtils::printDbMsgError(db, "step error");
            break;
        }
        
        cliente->id = sqlite3_column_int64(stmt.get(), 0);
        cliente->nombres = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt.get(), 1)));
        cliente->apellidos = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt.get(), 2)));
        cliente->dni = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt.get(), 3)));
    }
    
    return res;
}

int ClienteDaoImpl::upd(unique_ptr<ClienteEntry> &cliente) {
    int res = -1;
    const string sql = "UPDATE cliente SET nombres=?, apellidos=?, dni=? WHERE id=?";
    DatabaseUtils::uniqueStmtPtr stmt = DatabaseUtils::getStmt(db, sql);
    
    if (int rc = sqlite3_bind_text(stmt.get(), 1, cliente->nombres.c_str(),
                                   static_cast<int>(cliente->nombres.size()),
                                   SQLITE_STATIC) != SQLITE_OK) {
        cerr << "bind error code: " << sqlite3_errstr(rc) << endl;
        cerr <<"file: " << __FILE__ << ", line: " << __LINE__ << endl;
        DatabaseUtils::printDbMsgError(db, "bind error");
        
        return res;
    }
    
    if (int rc = sqlite3_bind_text(stmt.get(), 2, cliente->apellidos.c_str(),
                                   static_cast<int>(cliente->apellidos.size()),
                                   SQLITE_STATIC) != SQLITE_OK) {
        cerr << "bind error code: " << sqlite3_errstr(rc) << endl;
        DatabaseUtils::printDbMsgError(db, "bind error");
        cerr <<"file: " << __FILE__ << ", line: " << __LINE__ << endl;
        return res;
    }
    
    if (int rc = sqlite3_bind_text(stmt.get(), 3, cliente->dni.c_str(),
                                   static_cast<int>(cliente->dni.size()),
                                   SQLITE_STATIC) != SQLITE_OK) {
        cerr << "bind error code: " << sqlite3_errstr(rc) << endl;
        DatabaseUtils::printDbMsgError(db, "bind error");
        cerr <<"file: " << __FILE__ << ", line: " << __LINE__ << endl;
        return res;
    }
    
    if (int rc = sqlite3_bind_int64(stmt.get(), 4, cliente->id) != SQLITE_OK) {
        cerr << "bind error code: " << sqlite3_errstr(rc) << endl;
        DatabaseUtils::printDbMsgError(db, "bind error");
        cerr <<"file: " << __FILE__ << ", line: " << __LINE__ << endl;
        return res;
    }
    
    cout << "dao upd: "<< sqlite3_expanded_sql(stmt.get()) << endl;
    
    if (int rc = sqlite3_step(stmt.get()) != SQLITE_DONE) {
        cerr << "step error code: " << sqlite3_errstr(rc) << endl;
        DatabaseUtils::printDbMsgError(db, "step error");
        cerr <<"file: " << __FILE__ << ", line: " << __LINE__ << endl;
        return res;
    }
    
    res = 0;
    return res;
}

int ClienteDaoImpl::del(list<long long> &ids) {
    int res = -1;
    const string sql = "DELETE FROM cliente WHERE id=?";
    DatabaseUtils::uniqueStmtPtr stmt = DatabaseUtils::getStmt(db, sql);
    
    for (long long id : ids) {
        if (int rc = sqlite3_bind_int64(stmt.get(), 1, id) != SQLITE_OK) {
            cerr << "bind error code: " << sqlite3_errstr(rc) << endl;
            DatabaseUtils::printDbMsgError(db, "bind error");
            return res;
        }
        
        cout << "dao del: "<< sqlite3_expanded_sql(stmt.get()) << endl;
        
        if (int rc = sqlite3_step(stmt.get()) != SQLITE_DONE) {
            cerr << "step error code: " << sqlite3_errstr(rc) << endl;
            DatabaseUtils::printDbMsgError(db, "step error");
            return rc;
        }
        
        if (int rc = sqlite3_reset(stmt.get()) != SQLITE_OK) {
            cerr << "reset error code: " << sqlite3_errstr(rc) << endl;
            DatabaseUtils::printDbMsgError(db, "reset error");
            return rc;
        }
        
        if (int rc = sqlite3_clear_bindings(stmt.get()) != SQLITE_OK) {
            cerr << "clear binding error code: " << sqlite3_errstr(rc) << endl;
            DatabaseUtils::printDbMsgError(db, "clear binding error");
            return rc;
        }
    }
    
    res = 0;
    
    return res;
}
