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
    virtual int ins(ClienteEntry &cliente) = 0;
    virtual int get(long long id, ClienteEntry &cliente) = 0;
};

#endif /* ClienteDao_hpp */
