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
        
        int getCreditsInCounter();
        int getCreditsOutCounter();
        int getCreditsAvailableCounter();
        int getPlayedCounter();
        
        void addCredits(int num);
        void removeCredits(int num);
        int removeAllCredits();
        void addPlayed(int num);
        
    private:
        int _creditsInCounter;
        int _creditsOutCounter;
        int _creditsAvailableCounter;
        int _playedCounter;
    };
}

#endif /* Player_hpp */
