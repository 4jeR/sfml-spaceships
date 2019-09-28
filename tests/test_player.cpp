#include <gtest/gtest.h>
#include <cmath>
#include "player.h"


TEST(Player, instantiate_player){
    Player* p = Player::InstantiatePlayer(200.0f, 100.0f);
    ASSERT_TRUE(p != nullptr);
    EXPECT_FLOAT_EQ(p->X(), 200.0f);
    EXPECT_FLOAT_EQ(p->Y(), 100.0f);
    
    delete p;
}


TEST(Player, get_cooldown_copy){
    Player p(200, 300);
    EXPECT_EQ(0, p.Cooldown());
}


TEST(Player, get_cooldown_ref){
    Player p(100, 300);
    p.GetCooldown() = 12;
    EXPECT_EQ(12, p.GetCooldown());
}


TEST(Player, get_lives_copy){
    Player p(250, 550);
    EXPECT_EQ(3, p.Lives());
}


TEST(Player, get_lives_ref){
    Player p(400, 300);
    p.GetLives() = 2;
    EXPECT_EQ(2, p.Lives());
}


TEST(Player, get_score_copy){
    Player p(250, 450);
    EXPECT_EQ(0, p.Score());
}


TEST(Player, get_score_ref){
    Player p(240, 350);
    p.GetScore() = 20;
    EXPECT_EQ(2, p.Score());
}


TEST(Player, add_score){
    Player p(240, 350);
    p.AddScore(20);
    EXPECT_EQ(20, p.Score());
}



