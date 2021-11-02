//
//  ClienteDaoImpl.hpp
//  sqlite2
//
//  Created by manuel on 8/3/18.
//  Copyright © 2018 manuel. All rights reserved.
//

#ifndef ClienteDaoImpl_hpp
#define ClienteDaoImpl_hpp

#include "dao/ClienteDao.hpp"
#include "utils/DatabaseUtils.hpp"
#include <sqlite3.h>

class ClienteDaoImpl : public ClienteDao {
    DatabaseUtils::uniqueDbPtr db;
public:
//    virtual ~ClienteDaoImpl() override {
//        cout << "dao: bye!" << endl;
//    }
    ClienteDaoImpl();
    virtual int qry(list<unique_ptr<ClienteEntry>> &clientes) override;
    virtual int ins(unique_ptr<ClienteEntry> &cliente) override;
    virtual int get(long long id, unique_ptr<ClienteEntry> &cliente) override;
    virtual int upd(unique_ptr<ClienteEntry> &cliente) override;
    virtual int del(list<long long> &ids) override;
    virtual int beginTransaction() override;
    virtual int endTransaction() override;
    virtual void* execUpdateHook(
                                 void(*callback)(void *arg, int opType, const char* dbName,
                                                 const char* tableName, long long rowid), void *arg = nullptr) override;
};

#endif /* ClienteDaoImpl_hpp */
