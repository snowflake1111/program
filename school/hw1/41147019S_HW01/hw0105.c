#include <stdio.h>
#include <stdint.h>

int main(){
    int32_t card1 = 0;
    int32_t card2 = 0;
    int32_t card3 = 0;
    int32_t card4 = 0;
    int32_t card5 = 0;
    int32_t state = 9;
    int32_t card1_num = 0;
    int32_t card2_num = 0;
    int32_t card3_num = 0;
    int32_t card4_num = 0;
    int32_t card5_num = 0;
    int32_t same = 1;
    int32_t spade = 0;
    int32_t heart = 0;
    int32_t diamond = 0;
    int32_t club = 0;
    int32_t A = 0;
    int32_t two = 0;
    int32_t three = 0;
    int32_t four = 0;
    int32_t five = 0;
    int32_t six = 0;
    int32_t seven = 0;
    int32_t eight = 0;
    int32_t nine = 0;
    int32_t ten = 0;
    int32_t J = 0;
    int32_t Q = 0;
    int32_t K = 0;
    int32_t pair = 0;
   
    printf("Please enter 5 cards: ");
    scanf("%d %d %d %d %d", &card1, &card2, &card3, &card4, &card5);

    //判斷錯誤card
    if(card1 < 1 || card1 > 52 ||
         card2 < 1 || card2 > 52 ||
           card3 < 1 || card3 > 52 ||
             card4 < 1 || card4 > 52 ||
               card5 < 1 || card5 > 52){
        state = 0;
    }
    else if(card1 == card2 || card1 == card3 || card1 == card4 || card1 == card5 ||
              card2 == card3 || card2 == card4 || card2 == card5 ||
                card3 == card4 || card3 == card5 ||
                  card4 == card5){
        state = 0;
    }
    
    //計算card數字
    card1_num =  card1 % 13;
    card2_num =  card2 % 13;
    card3_num =  card3 % 13;
    card4_num =  card4 % 13;
    card5_num =  card5 % 13;
    
    //統計card數字數量
    if(card1_num == 1){
        A = A + 1;
    }
    else if(card1_num == 2){
        two = two + 1;
    }
    else if(card1_num == 3){
        three = three + 1;
    }
    else if(card1_num == 4){
        four = four + 1;
    }
    else if(card1_num == 5){
        five = five + 1;
    }
    else if(card1_num == 6){
        six = six + 1;
    }
    else if(card1_num == 7){
        seven = seven + 1;
    }
    else if(card1_num == 8){
        eight = eight + 1;
    }
    else if(card1_num == 9){
        nine = nine + 1;
    }
    else if(card1_num == 10){
        ten = ten + 1;
    }
    else if(card1_num == 11){
        J = J + 1;
    }
    else if(card1_num == 12){
        Q = Q + 1;
    }
    else{
        K = K + 1;
    }
    
    if(card2_num == 1){
        A = A + 1;
    }
    else if(card2_num == 2){
        two = two + 1;
    }
    else if(card2_num == 3){
        three = three + 1;
    }
    else if(card2_num == 4){
        four = four + 1;
    }
    else if(card2_num == 5){
        five = five + 1;
    }
    else if(card2_num == 6){
        six = six + 1;
    }
    else if(card2_num == 7){
        seven = seven + 1;
    }
    else if(card2_num == 8){
        eight = eight + 1;
    }
    else if(card2_num == 9){
        nine = nine + 1;
    }
    else if(card2_num == 10){
        ten = ten + 1;
    }
    else if(card2_num == 11){
        J = J + 1;
    }
    else if(card2_num == 12){
        Q = Q + 1;
    }
    else{
        K = K + 1;
    }
    
    if(card3_num == 1){
        A = A + 1;
    }
    else if(card3_num == 2){
        two = two + 1;
    }
    else if(card3_num == 3){
        three = three + 1;
    }
    else if(card3_num == 4){
        four = four + 1;
    }
    else if(card3_num == 5){
        five = five + 1;
    }
    else if(card3_num == 6){
        six = six + 1;
    }
    else if(card3_num == 7){
        seven = seven + 1;
    }
    else if(card3_num == 8){
        eight = eight + 1;
    }
    else if(card3_num == 9){
        nine = nine + 1;
    }
    else if(card3_num == 10){
        ten = ten + 1;
    }
    else if(card3_num == 11){
        J = J + 1;
    }
    else if(card3_num == 12){
        Q = Q + 1;
    }
    else{
        K = K + 1;
    }
    
    if(card4_num == 1){
        A = A + 1;
    }
    else if(card4_num == 2){
        two = two + 1;
    }
    else if(card4_num == 3){
        three = three + 1;
    }
    else if(card4_num == 4){
        four = four + 1;
    }
    else if(card4_num == 5){
        five = five + 1;
    }
    else if(card4_num == 6){
        six = six + 1;
    }
    else if(card4_num == 7){
        seven = seven + 1;
    }
    else if(card4_num == 8){
        eight = eight + 1;
    }
    else if(card4_num == 9){
        nine = nine + 1;
    }
    else if(card4_num == 10){
        ten = ten + 1;
    }
    else if(card4_num == 11){
        J = J + 1;
    }
    else if(card4_num == 12){
        Q = Q + 1;
    }
    else{
        K = K + 1;
    }
    
    if(card5_num == 1){
        A = A + 1;
    }
    else if(card5_num == 2){
        two = two + 1;
    }
    else if(card5_num == 3){
        three = three + 1;
    }
    else if(card5_num == 4){
        four = four + 1;
    }
    else if(card5_num == 5){
        five = five + 1;
    }
    else if(card5_num == 6){
        six = six + 1;
    }
    else if(card5_num == 7){
        seven = seven + 1;
    }
    else if(card5_num == 8){
        eight = eight + 1;
    }
    else if(card5_num == 9){
        nine = nine + 1;
    }
    else if(card5_num == 10){
        ten = ten + 1;
    }
    else if(card5_num == 11){
        J = J + 1;
    }
    else if(card5_num == 12){
        Q = Q + 1;
    }
    else{
        K = K + 1;
    }

    //計算card花色
    if(card1 >= 40){
        club = club + 1;
    }
    else if(card1 >= 27){
        diamond = diamond + 1;
    }
    else if(card1 >= 14){
        heart = heart + 1;
    }
    else{
        spade = spade + 1;
    }
    
    if(card2 >= 40){
        club = club + 1;
    }
    else if(card2 >= 27){
        diamond = diamond + 1;
    }
    else if(card2 >= 14){
        heart = heart + 1;
    }
    else{
        spade = spade + 1;
    }
    
    if(card3 >= 40){
        club = club + 1;
    }
    else if(card3 >= 27){
        diamond = diamond + 1;
    }
    else if(card3 >= 14){
        heart = heart + 1;
    }
    else{
        spade = spade + 1;
    }
    
    if(card4 >= 40){
        club = club + 1;
    }
    else if(card4 >= 27){
        diamond = diamond + 1;
    }
    else if(card4 >= 14){
        heart = heart + 1;
    }
    else{
        spade = spade + 1;
    }
    
    if(card5 >= 40){
        club = club + 1;
    }
    else if(card5 >= 27){
        diamond = diamond + 1;
    }
    else if(card5 >= 14){
        heart = heart + 1;
    }
    else{
        spade = spade + 1;
    }
    
    //判斷對數
    if(A == 2){
        pair = pair + 1;
    }
    if(two == 2){
        pair = pair + 1;
    }
    if(three == 2){
        pair = pair + 1;
    }
    if(four == 2){
        pair = pair + 1;
    }
    if(five == 2){
        pair = pair + 1;
    }
    if(six == 2){
        pair = pair + 1;
    }
    if(seven == 2){
        pair = pair + 1;
    }
    if(eight == 2){
        pair = pair + 1;
    }
    if(nine == 2){
        pair = pair + 1;
    }
    if(ten == 2){
        pair = pair + 1;
    }
    if(J == 2){
        pair = pair + 1;
    }
    if(Q == 2){
        pair = pair + 1;
    }
    if(K == 2){
        pair = pair + 1;
    }
    
    if(state != 0){
        //同花順與同花
        if(spade == 5 || heart == 5 || diamond == 5 || club == 5){
            if(A == 1){
                if(two == 1 && three == 1 && four == 1 && five == 1){
                    state = 1;
                }
                else if(ten == 1 && J == 1 && Q == 1 & K == 1){
                    state = 1;
                }
                else{
                    state = 4;
                }
            }
            else if(two == 1){
                if(three == 1 && four == 1 && five == 1 && six == 1){
                    state = 1;
                }
                else{
                    state = 4;
                }
            }
            else if(three == 1){
                if(four == 1 && five == 1 && six == 1 && seven == 1){
                    state = 1;
                }
                else{
                    state = 4;
                }
            }
            else if(four == 1){
                if(five == 1 && six == 1 && seven == 1 && eight == 1){
                    state = 1;
                }
                else{
                    state = 4;
                }
            }
            else if(five == 1){
                if(six == 1 && seven == 1 && eight == 1 && nine == 1){
                    state = 1;
                }
                else{
                    state = 4;
                }
            }
            else if(six == 1){
                if(seven == 1 && eight == 1 && nine == 1 && ten == 1){
                    state = 1;
                }
                else{
                    state = 4;
                }
            }
            else if(seven == 1){
                if(eight == 1 && nine == 1 && ten == 1 && J == 1){
                    state = 1;
                }
                else{
                    state = 4;
                }
            }
            else if(eight == 1){
                if(nine == 1 && ten == 1 && J == 1 && Q == 1){
                    state = 1;
                }
                else{
                    state = 4;
                }
            }
            else if(nine == 1){
                if(ten == 1 && J == 1 && Q == 1 && K == 1){
                    state = 1;
                }
                else{
                    state = 4;
                }
            }
        }
        //鐵支
        else if(A == 4 || two == 4 || three == 4 || four == 4 || five == 4 ||
                  six == 4 || seven == 4 || eight == 4 || nine == 4 || ten == 4 ||
                    J == 4 || Q == 4 || K == 4){
            state = 2;
        }
        //三條與葫蘆
        else if(A == 3 || two == 3 || three == 3 || four == 3 || five == 3 ||
             six == 3 || seven == 3 || eight == 3 || nine == 3 || ten == 3 ||
               J == 3 || Q == 3 || K == 3){
            if(A == 2 || two == 2 || three == 2 || four == 2 || five == 2 ||
                 six == 2 || seven == 2 || eight == 2 || nine == 2 || ten == 2 ||
                   J == 2 || Q == 2 || K == 2){
                state = 3;
            }
            else{
                state = 6;
            }
        }
        //兩對
        else if(pair == 2){
            state = 7;
        }
        //一對
        else if(pair == 1){
            state = 8;
        }
        //順子
        else if(A == 1){
            if(two == 1 && three == 1 && four == 1 && five == 1){
                state = 5;
            }
            else if(ten == 1 && J == 1 && Q == 1 && K == 1){
                state = 5;
            }
        }
        else if(two == 1){
            if(three == 1 && four == 1 && five == 1 && six == 1){
                state = 5;
            }
        }
        else if(three == 1){
            if(four == 1 && five == 1 && six == 1 && seven == 1){
                state = 5;
            }
        }
        else if(four == 1){
            if(five == 1 && six == 1 && seven == 1 && eight == 1){
                state = 5;
            }
        }
        else if(five == 1){
            if(six == 1 && seven == 1 && eight == 1 && nine == 1){
                state = 5;
            }
        }
        else if(six == 1){
            if(seven == 1 && eight == 1 && nine == 1 && ten == 1){
                state = 5;
            }
        }
        else if(seven == 1){
            if(eight == 1 && nine == 1 && ten == 1 && J == 1){
                state = 5;
            }
        }
        else if(eight == 1){
            if(nine == 1 && ten == 1 && J == 1 && Q == 1){
                state = 5;
            }
        }
        else if(nine == 1){
            if(ten == 1 && J == 1 && Q == 1 && K == 1){
                state = 5;
            }
        }
        else{
            state = 9;
        }
    }
       
    //判斷牌型種類
    if(state == 1){
        printf("Straight flush\n");
    }
    else if(state == 2){
        printf("Four of a kind\n");
    }
    else if(state == 3){
        printf("Full house\n");
    }
    else if(state == 4){
        printf("Flush\n");
    }
    else if(state == 5){
        printf("Straight\n");
    }
    else if(state == 6){
        printf("Three of a kind\n");
    }
    else if(state == 7){
        printf("Two pair\n");
    }
    else if(state == 8){
        printf("One pair\n");
    }
    else if(state == 9){
        printf("High card\n");
    }
    else if(state == 0){
        printf("Error\n");
    }
    
    return 0;
}
