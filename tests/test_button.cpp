#include <gtest/gtest.h>
#include <cmath>
#include "button.h"

TEST(Button, default_width){
    Button b(550.0f, 150.0f, "test-button1");
    
    EXPECT_FLOAT_EQ(270.0f, b.GetShape()->getSize().x);
}


TEST(Button, default_height){
    Button b(550.0f, 150.0f, "test-button2");
    
    EXPECT_FLOAT_EQ(50.0f, b.GetShape()->getSize().y);
}


TEST(Button, get_pos_x){
    Button b(100.0f, 200.0f, "test-button3");
    
    EXPECT_FLOAT_EQ(100.0f, b.GetShape()->getPosition().x);
}


TEST(Button,  get_pos_y){
    Button b(100.0f, 250.0f, "test-button4");
    
    EXPECT_FLOAT_EQ(250.0f, b.GetShape()->getPosition().y);
}


TEST(Button,  get_text_str){
    Button b(125.0f, 250.0f, "test-button5");
    
    EXPECT_EQ("test-button5", b.GetText()->getString());
}



//   Button(float x, float y, sf::String string);
//     ~Button();
//     sf::RectangleShape* GetShape()noexcept;
//     sf::Text* GetText()noexcept;
//     sf::Font GetFont()noexcept;
// private:
//     sf::RectangleShape* _shape;
//     sf::Text* _text;

//     sf::Font _font;
