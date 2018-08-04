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
    //virtual ~ClienteDaoImpl();
    ClienteDaoImpl();
    virtual int qry(const list<ClienteEntry> &clientes) override;
    virtual int ins(const ClienteEntry &cliente) override;
    virtual int get(long id, const ClienteEntry &cliente) override;
};

#endif /* ClienteDaoImpl_hpp */
