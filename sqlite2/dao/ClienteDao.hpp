//
//  ClienteDao.hpp
//  sqlite1
//
//  Created by manuel on 7/27/18.
//  Copyright © 2018 manuel. All rights reserved.
//

#ifndef ClienteDao_hpp
#define ClienteDao_hpp

#include "dto/ClienteEntry.hpp"
#include <list>
#include <memory>
#include <iostream>

class ClienteDao {
public:
    virtual ~ClienteDao(){};
    virtual int qry(list<unique_ptr<ClienteEntry>> &clientes) = 0;
    virtual int ins(unique_ptr<ClienteEntry> &cliente) = 0;
    virtual int get(long long id, unique_ptr<ClienteEntry> &cliente) = 0;
    virtual int upd(unique_ptr<ClienteEntry> &cliente) = 0;
    virtual int del(list<long long> &ids) = 0;
    virtual int beginTransaction() = 0;
    virtual int endTransaction() = 0;
    virtual void* execUpdateHook(
                                 void(*callback)(void *arg, int opType, const char* dbName,
                                                  const char* tableName, long long rowid), void *arg = nullptr) = 0;
};

#endif /* ClienteDao_hpp */
