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
         This function returns the number of credits inserted
         by the user.
         @return The number of credits in.
         */
        int getCreditsInCounter();
        
        /**
         This function returns the number of credits removed
         by the user.
         @return The number of credits out.
         */
        int getCreditsOutCounter();
        
        /**
         This function returns the number of credits available.
         This function should return the (creditsIn - creditsOut - playedCounter)
         @return The number of credits available.
         */
        int getCreditsAvailableCounter();
        
        /**
         This function returns the number of plays that have happened.
         @return The number of credits finished plays.
         */
        int getPlayedCounter();
        
        /**
         This function add credits to this player.
         @param num The number of credits to add.
         */
        void addCredits(int num);
        
        /**
         This function remove credits to this player.
         @param num The number of credits to add.
         */
        void removeCredits(int num);
        
        /**
         This function removes all credits available.
         @return num The number of credits removed.
         */
        int removeAllCredits();
        
        /**
         This function adds plays to this player.
         @param num The number of plays to add.
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
