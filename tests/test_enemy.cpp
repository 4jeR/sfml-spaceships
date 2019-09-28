#include <gtest/gtest.h>
#include <cmath>
#include "enemy.h"


TEST(Enemy, get_x_copy) { 
    Enemy enemy(20.0f, 30.0f);
    EXPECT_FLOAT_EQ(enemy.X(), 20.0f);
    EXPECT_TRUE(enemy.X() == 20.0f);
    EXPECT_FALSE(enemy.X() == 20.0002f);
}

TEST(Enemy, get_y_copy) { 
    Enemy enemy(120.0f, 35.0f);
    EXPECT_EQ(enemy.Y(), 35.0f);
    EXPECT_TRUE(enemy.Y() == 35.0f);
    EXPECT_FALSE(enemy.Y() == 34.99998f);
}

TEST(Enemy, get_x_ref) { 
    Enemy enemy(120.0f, 35.0f);
    enemy.GetX() = 60.0f;
    EXPECT_EQ(enemy.GetX(), 60.0f);
    EXPECT_TRUE(enemy.GetX() == 60.0f);
    EXPECT_FALSE(enemy.GetX() == 120.0f);
}


TEST(Enemy, get_y_ref) { 
    Enemy enemy(120.0f, 333.0f);
    enemy.GetY() = 260.0f;
    EXPECT_FLOAT_EQ(enemy.GetY(), 260.0f);
    EXPECT_TRUE(enemy.GetY() == 260.0f);
    EXPECT_FALSE(enemy.GetY() == 333.0f);
}


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