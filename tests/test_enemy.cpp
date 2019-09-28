#include <gtest/gtest.h>
#include <cmath>
#include "enemy.h"


TEST(Enemy, constructor){
    Enemy enemy(20.0f, 30.0f);
    ASSERT_TRUE(enemy.GetShape() != nullptr);
    EXPECT_FLOAT_EQ(enemy.Radius(), 12.0f);
    EXPECT_FLOAT_EQ(enemy.CurrentSpeed(), 200.0f);
}

TEST(Enemy, InstantiateEnemy){
    Enemy* e = Enemy::InstantiateEnemy(20.0f, 30.0f);
    ASSERT_TRUE(e != nullptr);
    ASSERT_TRUE(e->GetShape() != nullptr);
    
    EXPECT_FLOAT_EQ(e->Radius(), 12.0f);
    EXPECT_FLOAT_EQ(e->CurrentSpeed(), 200.0f);
    delete e;
}

TEST(Enemy, get_name_copy){
    Enemy e(0.0f, 0.0f);
    EXPECT_EQ(e.Name(), "enemy");
}