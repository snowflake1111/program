#include <stdio.h>
#include <stdint.h>

int main(){
    int32_t level = 0;
    double atk = 0;
    int32_t status = 0;
    double status_effect = 1;
    int32_t move_power = 0;
    int32_t move_type = 0;
    int32_t move_category = 0;
    double def = 0;
    int32_t atk_type = 0;
    int32_t target_type = 0;
    double type_effect = 1;
    int32_t weather = 0;
    double weather_effect = 1;
    int32_t terrain = 0;
    double terrain_effect = 1;
    int32_t damage = 0;
    double factor = 0;
    int32_t stab = 1;
    
    printf("Attacker\n");

    printf("    level: ");
    scanf("%d", &level);
    
    printf("    atk: ");
    scanf("%lf", &atk);
    
    printf("    type: ");
    scanf("%d", &atk_type);
    
    printf("    status: ");
    scanf("%d", &status);
    
    printf("    move power: ");
    scanf("%d", &move_power);
    
    printf("    move type: ");
    scanf("%d", &move_type);
    
    printf("    move category: ");
    scanf("%d", &move_category);
    
    printf("Target\n");
    
    printf("    def: ");
    scanf("%lf", &def);
    
    printf("    type: ");
    scanf("%d", &target_type);
    
    printf("Environment\n");

    printf("    weather: ");
    scanf("%d", &weather);

    printf("    terrain: ");
    scanf("%d", &terrain);
    
    if(level < 1 || level > 100 || move_power < 1 || status < 0 || status > 2 || move_type < 0 || move_type > 7 || (move_category != 0 && move_category != 1) || atk_type < 0 || atk_type > 7 || target_type < 0 || target_type > 7 || weather < 0 || weather > 5 || terrain < 0 || terrain > 3){
        printf("Error\n");
        
        return 0;
    }
    
    //判斷weather effective
    if(weather == 1){
        if(move_type == 0){
            weather_effect = 0.5;
        }
        else if(move_type == 1){
            weather_effect = 2;
        }
    }
    else if(weather == 2){
        if(move_type == 0){
            weather_effect = 2;
        }
        else if(move_type == 1){
            weather_effect = 0.5;
        }
    }
    
    //判斷stab
    if(move_type == atk_type){
        stab = 2;
    }
    
    //判斷type effective
    if(move_type == 0){
        if(target_type == 0 || target_type == 2 || target_type == 7){
            type_effect = 0.5;
        }
        else if(target_type == 1 || target_type == 4 || target_type == 5){
            type_effect = 2;
        }
    }
    else if(move_type == 1){
        if(target_type == 0 || target_type == 1 || target_type == 4 || target_type == 7){
            type_effect = 0.5;
        }
        else if(target_type == 2){
            type_effect = 2;
        }
    }
    else if(move_type == 2){
        if(target_type == 1 || target_type == 2 || target_type == 3 || target_type == 7){
            type_effect = 0.5;
        }
        else if(target_type == 0 || target_type == 4 || target_type == 5){
            type_effect = 2;
        }
    }
    else if(move_type == 3){
        if(target_type == 4 || target_type == 6){
            type_effect = 0.5;
        }
        else if(target_type == 2){
            type_effect = 2;
        }
    }
    else if(move_type == 4){
        if(target_type == 5){
            type_effect = 0.5;
        }
        else if(target_type == 1 || target_type == 3){
            type_effect = 2;
        }
    }
    else if(move_type == 5){
        if(target_type == 3){
            type_effect = 0;
        }
        else if(target_type == 1 || target_type == 4 || target_type == 6){
            type_effect = 2;
        }
    }
    else if(move_type == 6){
        if(target_type == 5){
            type_effect = 0;
        }
        else if(target_type == 2 || target_type == 6 || target_type == 7){
            type_effect = 0.5;
        }
        else if(target_type == 0 || target_type == 3){
            type_effect = 2;
        }
    }
    else if(move_type == 7){
        if(target_type == 7){
            type_effect = 2;
        }
    }
    
    //判斷status effective
    if(status == 1 && move_category == 0){
        status_effect = 0.5;
    }
    else if(status == 2 && move_category == 1){
        status_effect = 0.5;
    }
    
    //判斷terrain effective
    if(terrain == 1 && move_type == 2){
        terrain_effect = 2;
    }
    else if(terrain == 2 && move_type == 6){
        terrain_effect = 2;
    }
    else if(terrain == 3 && move_type == 7){
        terrain_effect = 0.5;
    }

    //特殊規則1
    if(weather == 5 && target_type == 4){
        def = def * 2;
    }
    else if(weather == 2 && target_type == 5){
        def = def / 2;
    }
    else if(weather == 3 && atk_type == 2){
        atk = atk / 2;
    }
    else if(weather == 4 && atk_type == 3){
        atk = atk * 2;
    }
    
    factor = weather_effect * stab * type_effect * status_effect * terrain_effect;
    
    damage = (int) (((int) ((double) (((level * 2) + 10) * atk * move_power) / 250 / def) + 2) * factor);
    
    //特殊規則2
    if(damage == 0 && factor != 0){
        damage = 1;
    }
    
    printf("Damage --> %d\n", damage);
    
    return 0;
}
