//
//  SqliteConnection2Tests.cpp
//  sqlite2
//
//  Created by manuel on 8/5/18.
//  Copyright © 2018 manuel. All rights reserved.
//

#include "catch.hpp"
#include "db_connection/SqliteConnection2.hpp"
#include <memory>

TEST_CASE("Called without args --> return db")
{
    SqliteConnection2::uniqueDbPtr dbPtr = SqliteConnection2::getDb();
    
    CHECK(dbPtr != nullptr);
    
}
