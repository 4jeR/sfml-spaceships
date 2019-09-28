
#include <gtest/gtest.h>
#include <cmath>
#include "enemy.h"


TEST(Object, get_x_copy) { 
    Enemy enemy(20.0f, 30.0f);
    Object* ptr = &enemy;
    EXPECT_FLOAT_EQ(ptr->X(), 20.0f);
    EXPECT_TRUE(ptr->X() == 20.0f);
    EXPECT_FALSE(ptr->X() == 20.0002f);
}

TEST(Object, get_y_copy) { 
    Enemy enemy(120.0f, 35.0f);
    Object* ptr = &enemy;
    EXPECT_EQ(ptr->Y(), 35.0f);
    EXPECT_TRUE(ptr->Y() == 35.0f);
    EXPECT_FALSE(ptr->Y() == 34.99998f);
}

TEST(Object, get_x_ref) { 
    Enemy enemy(120.0f, 35.0f);
    Object* ptr = &enemy;
    ptr->GetX() = 60.0f;
    EXPECT_EQ(ptr->GetX(), 60.0f);
    EXPECT_TRUE(ptr->GetX() == 60.0f);
    EXPECT_FALSE(ptr->GetX() == 120.0f);
}


TEST(Object, get_y_ref) { 
    Enemy enemy(120.0f, 333.0f);
    Object* ptr = &enemy;
    ptr->GetY() = 260.0f;
    EXPECT_FLOAT_EQ(ptr->GetY(), 260.0f);
    EXPECT_TRUE(ptr->GetY() == 260.0f);
    EXPECT_FALSE(ptr->GetY() == 333.0f);
}

TEST(Object, get_currentspeed_copy){
    Enemy e(0.0f, 10.0f);
    Object* ptr = &e;
    EXPECT_FLOAT_EQ(ptr->CurrentSpeed(), 200.0f);
}

TEST(Object, get_currentspeed_ref){
    Enemy e(0.0f, 10.0f);
    Object* ptr = &e;
    ptr->GetCurrentSpeed() = 250.0f;
    EXPECT_FLOAT_EQ(ptr->GetCurrentSpeed(), 250.0f);
}

TEST(Object, get_destroystate_copy){
    Enemy e(0.0f, 10.0f);
    Object* ptr = &e;
    EXPECT_TRUE(!ptr->IsDestroyed());
    EXPECT_FALSE(ptr->IsDestroyed());
}

TEST(Object, get_destroystate_ref){
    Enemy e(0.0f, 10.0f);
    Object* ptr = &e;
    EXPECT_TRUE(!ptr->GetDestroyState());
    ptr->GetDestroyState() = true;
    EXPECT_TRUE(ptr->GetDestroyState());
}

TEST(Object, calc_angular_velocity){
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





/**
 * float CalcAngularVelocity(float current_speed)const noexcept;
    float CalcAcceleration(float current_speed, bool add)const noexcept;
*/

/**
 * 

float Object::CalcAngularVelocity(float current_speed)const noexcept{
    float abs_speed = std::abs(current_speed);
    if(abs_speed <= 200.0f){
        return 0.002f * std::sqrt(abs_speed / 3.0f);
    }
    else if(200.0f < abs_speed&& abs_speed <= 600.0f){
        return 0.001f * std::sqrt(2.0f * abs_speed / 3.0f);
    }
    else if(600.0f < abs_speed){
        return 0.007f * std::sqrt(4.0f * abs_speed / 3.0f);
    }
    else return 0.0f;
}

float Object::CalcAcceleration(float current_speed, bool add)const noexcept{
    float value = 0.0f;
    if(add){
        if(current_speed <= 200.0f){
            value = 1.5f;
        }
        else if(200.0f < current_speed && current_speed <= 600.0f){
            value  = 2.0f;
        }
        else if(600.0f < current_speed && current_speed <= 894.5f){
            value  = 0.5f;
        }
    }
    else if(!add){
        if(1.0f <= current_speed && current_speed <= 200.0f){
            value = -1.0f;
        }
        else if(200.0f <= current_speed){
            value = -3.0f;
        }
    }
    return value;
}
*/