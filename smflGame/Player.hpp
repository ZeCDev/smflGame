//
//  Player.hpp
//  smflGame
//
//  Copyright © 2019 ZeCDev. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>

namespace SMFLGame
{
    class Player {
    public:
        Player();
        virtual ~Player();
        
        /**
         This function return the number of the credits inserted
         by the user.
         
         @return The number of credits in.
         */
        int getCreditsInCounter();
        
        /**
         This function return the number of the credits removed
         by the user.
         
         @return The number of credits out.
         */
        int getCreditsOutCounter();
        
        /**
         This function return the number of the credits available.
         This function should return the (creditsIn - creditsOut - playedCounter)
         
         @return The number of credits available.
         */
        int getCreditsAvailableCounter();
        
        /**
         This function return the number of the plays that have happened.
         
         @return The number of credits finished plays.
         */
        int getPlayedCounter();
        
        /**
         This function add credits to this player.
         
         @param num The number of the credits to add.
         */
        void addCredits(int num);
        
        /**
         This function remove credits to this player.
         
         @param num The number of the credits to add.
         */
        void removeCredits(int num);
        
        /**
         This function remove all credits available.
         
         @return num The number of the credits removed.
         */
        int removeAllCredits();
        
        /**
         This function add plays to this player.
         
         @param num The number of the plays to add.
         */
        void addPlayed(int num);
        
    private:
        int _creditsInCounter;
        int _creditsOutCounter;
        int _creditsAvailableCounter;
        int _playedCounter;
    };
}

#endif /* Player_hpp */
