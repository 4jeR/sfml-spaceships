#include <gtest/gtest.h>
#include <cmath>
#include "button.h"

TEST(ButtonTest, default_width){
    Button b(550.0f, 150.0f, "test-button1");
    
    EXPECT_FLOAT_EQ(270.0f, b.GetShape()->getSize().x);
}


TEST(ButtonTest, default_height){
    Button b(550.0f, 150.0f, "test-button2");
    
    EXPECT_FLOAT_EQ(50.0f, b.GetShape()->getSize().y);
}


TEST(ButtonTest, get_pos_x){
    Button b(100.0f, 200.0f, "test-button3");
    
    EXPECT_FLOAT_EQ(100.0f, b.GetShape()->getPosition().x);
}


TEST(ButtonTest,  get_pos_y){
    Button b(100.0f, 250.0f, "test-button4");
    
    EXPECT_FLOAT_EQ(250.0f, b.GetShape()->getPosition().y);
}


TEST(ButtonTest,  get_text_str){
    Button b(125.0f, 250.0f, "test-button5");
    
    EXPECT_EQ("test-button5", b.GetText()->getString());
}