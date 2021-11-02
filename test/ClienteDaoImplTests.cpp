//
//  ClienteDaoImplTests.cpp
//  test
//
//  Created by manuel on 8/6/18.
//  Copyright © 2018 manuel. All rights reserved.
//

#include "catch.hpp"
#include "dao/ClienteDao.hpp"
#include "dao/impl/ClienteDaoImpl.hpp"
#include "dto/ClienteEntry.hpp"
#include <memory>

SCENARIO("If client unique_ptr is inserted it will return 0")
{
    GIVEN("A Cliente dao")
    {
        unique_ptr<ClienteDao> dao = make_unique<ClienteDaoImpl>();
        //ClienteDao *dao = new ClienteDaoImpl();

        WHEN("a cliente with correct data is inserted")
        {
            unique_ptr<ClienteEntry> cliente = make_unique<ClienteEntry>();
            cliente->nombres = "Felipe";
            cliente->apellidos = "Pinglo Alva";
            cliente->dni = "89081232";

            THEN("It returns 0")
            {
                auto result = dao->ins(cliente);
                //delete dao;
                REQUIRE(result == 0);
            }
        }
    }
}

// TODO: Why is this buggy???
SCENARIO("If a list of clients is queried it will return 0")
{
    GIVEN("A Cliente dao")
    {
        //unique_ptr<ClienteDao> dao = make_unique<ClienteDaoImpl>();
        list<unique_ptr<ClienteEntry>> clientes;

        WHEN("some clients are requested")
        {
            ClienteDao *dao = new ClienteDaoImpl();
            dao->qry(clientes);
            for (auto it = clientes.begin(); it != clientes.end(); ++it) {
                (*it)->print();
            }
            unique_ptr<ClienteEntry> cliente = make_unique<ClienteEntry>();

            THEN("It returns 0")
            {
                auto result = dao->get(2LL, cliente);
                cliente->print();

                REQUIRE(result == 0);
                delete dao;
            }
        }
    }
}



