//
//  main.cpp
//  test-google
//
//  Created by manuel on 8/7/18.
//  Copyright © 2018 manuel. All rights reserved.
//

#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "dao/ClienteDao.hpp"
#include "dao/impl/ClienteDaoImpl.hpp"
#include "dto/ClienteEntry.hpp"
#include <memory>

int main(int argc, char *argv[]) {
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(ClienteDaoTest, Insert)
{
    unique_ptr<ClienteDao> dao = make_unique<ClienteDaoImpl>();
    unique_ptr<ClienteEntry> cliente = make_unique<ClienteEntry>();
    cliente->nombres = "Felipe";
    cliente->apellidos = "Pinglo Alva";
    cliente->dni = "89081232";
    auto result = dao->ins(cliente);
    ASSERT_EQ(result, 0);
}

TEST(ClienteDaoTest, Update)
{
    unique_ptr<ClienteDao> dao = make_unique<ClienteDaoImpl>();
    unique_ptr<ClienteEntry> cliente = make_unique<ClienteEntry>();
    cliente->id = 15LL;
    cliente->nombres = "Carlos";
    cliente->apellidos = "Alcantara";
    cliente->dni = "89081232";
    auto result = dao->upd(cliente);
    ASSERT_EQ(result, 0);
}
