//
//  frm_timer_unit_test.cpp
//  
//
//  Created by Marcel Ochsendorf on 28.06.16.
//Copyright © 2016 Marcel Ochsendorf. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "frm_timer.hp"



int timer_unit_test(int argc, const char * argv[]) {
    
    FRM::timer* timer = new MO::timer();
    
    timer->setTimeScale(0.5f);
    
    
    bool frun = true;
    while (true) {
        timer->TickUpdate();
        if(frun){
            frun = false;
            
            int test = (int)timer->deltaTimer();
            int test_noscale = (int)timer->unscaledDeltaTime();
            std::cout << "TIME :" << test << std::endl;
    
            if(test == 500 && test_noscale == 1000){
                std::cout << "TEST SUCCESS" << std::endl;
                break;
            }
            
        }
        sleep(1);
    }
    delete  timer;
    timer = nullptr;
    return 0;
}
