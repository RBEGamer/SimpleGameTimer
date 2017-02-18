//
//  FRM_timer.hpp
//  optimiser
//
//  Created by Marcel Ochsendorf on 28.05.16.
//  Copyright © 2016 Marcel Ochsendorf. All rights reserved.
//

#ifndef frm_timer_hpp
#define frm_timer_hpp

#include <stdio.h>
#include <chrono>
#endif /* FRM_timer_hpp */





namespace FRM {
    class timer{
    public:
        //FUNCS
        ~timer();
        static timer* getInstance();
        float deltaTime();
        float smoothDeltaTime();
        float getTimeScale();
        void  setTimeScale(float _scale);
        float unscaledDeltaTime();
        void TickUpdate();
    private:
        timer();
        void create_duration();
         //typedefs
        typedef std::chrono::high_resolution_clock Time;
        typedef std::chrono::milliseconds ms;
        typedef std::chrono::duration<float> fsec;
        typedef std::chrono::steady_clock::time_point timepoint;
        
        timepoint time_after_update;
        timepoint time_before_update;
        fsec time_update_duration;
        ms duration_in_milliseconds;
        
        
        float curr_delattime;
        float curr_smooth_delattime;
        float time_scale;
        static timer* instance;



        
        
       
    
    
    
    
    
    };
}
