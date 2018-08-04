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

class ClienteDao {
public:
    virtual ~ClienteDao(){};
    virtual int qry(const list<ClienteEntry> &clientes) = 0;
    virtual int ins(const ClienteEntry &cliente) = 0;
    virtual int get(long id, const ClienteEntry &cliente) = 0;
};

#endif /* ClienteDao_hpp */
