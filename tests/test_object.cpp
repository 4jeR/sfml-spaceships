
#include <gtest/gtest.h>
#include <cmath>
#include "enemy.h"


TEST(ObjectTest, get_x_copy) { 
    Enemy e(20.0f, 30.0f);
    EXPECT_FLOAT_EQ(e.X(), 20.0f);
    EXPECT_TRUE(e.X() == 20.0f);
    EXPECT_FALSE(e.X() == 20.0002f);
}


TEST(ObjectTest, get_y_copy) { 
    Enemy e(120.0f, 35.0f);
    EXPECT_EQ(e.Y(), 35.0f);
    EXPECT_TRUE(e.Y() == 35.0f);
    EXPECT_FALSE(e.Y() == 34.99998f);
}


TEST(ObjectTest, get_x_ref) { 
    Enemy e(120.0f, 35.0f);
    e.GetX() = 60.0f;
    EXPECT_EQ(e.GetX(), 60.0f);
    EXPECT_TRUE(e.GetX() == 60.0f);
    EXPECT_FALSE(e.GetX() == 120.0f);
}


TEST(ObjectTest, get_y_ref) { 
    Enemy e(120.0f, 333.0f);
    e.GetY() = 260.0f;
    EXPECT_FLOAT_EQ(e.GetY(), 260.0f);
    EXPECT_TRUE(e.GetY() == 260.0f);
    EXPECT_FALSE(e.GetY() == 333.0f);
}

TEST(ObjectTest, get_window_ptr) { 
    sf::RenderWindow w(sf::VideoMode(800, 600), "Test");
    Enemy e(20.0f, 25.0f, &w);
    EXPECT_TRUE(e.Window() != nullptr);
}


TEST(ObjectTest, get_currentspeed_copy){
    Enemy e(0.0f, 10.0f);
    EXPECT_FLOAT_EQ(e.CurrentSpeed(), 200.0f);
}


TEST(ObjectTest, get_currentspeed_ref){
    Enemy e(0.0f, 10.0f);
    e.GetCurrentSpeed() = 250.0f;
    EXPECT_FLOAT_EQ(e.GetCurrentSpeed(), 250.0f);
}


TEST(ObjectTest, get_destroystate_copy){
    Enemy e(0.0f, 10.0f);
    EXPECT_TRUE(!e.IsDestroyed());
    EXPECT_FALSE(e.IsDestroyed());
}


TEST(ObjectTest, get_destroystate_ref){
    Enemy e(0.0f, 10.0f);
    EXPECT_TRUE(!e.GetDestroyState());
    e.GetDestroyState() = true;
    EXPECT_TRUE(e.GetDestroyState());
}


TEST(ObjectTest, calc_angular_velocity){
    Enemy e(0.0f, 10.0f);
    e.GetCurrentSpeed() = 75.0f;
    float expected = e.CalcAngularVelocity(e.CurrentSpeed());
    ASSERT_FLOAT_EQ(0.01f, expected);

    e.GetCurrentSpeed() = 450.0f;
    expected = e.CalcAngularVelocity(e.CurrentSpeed());
    ASSERT_FLOAT_EQ(0.017320508f, expected);

    e.GetCurrentSpeed() = 700.0f;
    expected = e.CalcAngularVelocity(e.CurrentSpeed());
    ASSERT_FLOAT_EQ(0.213853532f, expected);
}


TEST(ObjectTest, calc_acceleration){
    Enemy e(40.0f, 180.0f);
    EXPECT_FLOAT_EQ(1.5f, e.CalcAcceleration(100.0f, true));
    EXPECT_FLOAT_EQ(2.0f, e.CalcAcceleration(300.0f, true));
    EXPECT_FLOAT_EQ(0.5f, e.CalcAcceleration(800.0f, true));

    EXPECT_FLOAT_EQ(-1.0f, e.CalcAcceleration(100.0f, false));
    EXPECT_FLOAT_EQ(-3.0f, e.CalcAcceleration(300.0f, false));   

    EXPECT_FLOAT_EQ(-3.0f, e.CalcAcceleration(1000.0f, false));  
    EXPECT_FLOAT_EQ(0.0f, e.CalcAcceleration(1000.0f, true));  
    EXPECT_FLOAT_EQ(1.5f, e.CalcAcceleration(-1000.0f, true));  
    EXPECT_FLOAT_EQ(0.0f, e.CalcAcceleration(-5200.0f, false));  
}


