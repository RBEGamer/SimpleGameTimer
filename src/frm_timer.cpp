//
//  FRM_timer.cpp
//  optimiser
//
//  Created by Marcel Ochsendorf on 28.05.16.
//  Copyright © 2016 Marcel Ochsendorf. All rights reserved.
//

#include "frm_timer.hpp"

FRM::timer::timer(){
    setTimeScale(1.0f);
    //set time to zero
    time_after_update = Time::now();
    time_before_update = Time::now();
    
    curr_delattime = 0.0f;
    curr_smooth_delattime = 0.0f;
}

FRM::timer::~timer(){

}


FRM::timer* FRM::timer::getInstance(){
    if(!instance){
        instance=new FRM::timer();
    }
    return instance;
}



void FRM::timer::create_duration(){
    time_after_update = Time::now();
    time_update_duration = time_after_update - time_before_update;
    time_before_update = time_after_update;
    curr_delattime = time_update_duration.count();
    curr_smooth_delattime = (curr_smooth_delattime+curr_delattime)/2.0f;
}



void FRM::timer::TickUpdate(){
    create_duration();
}


float FRM::timer::deltaTime(){
    return curr_delattime * time_scale;
}


float FRM::timer::smoothDeltaTime(){
    
    return curr_smooth_delattime * time_scale;
}


float FRM::timer::getTimeScale(){
    return time_scale;
}
void  FRM::timer::setTimeScale(float _scale){
    if(_scale < 0.0f){
        _scale = _scale * -1;
    }
    time_scale = _scale;
}

float FRM::timer::unscaledDeltaTime(){
    return curr_delattime;
}
