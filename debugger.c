#include "lib/pre.h"
#include "lib/gui.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_mouse.h>
#include <SDL2/SDL_render.h>
#include <math.h>
#include <stdio.h>

int main(){
    board test;
    test.pieces[0]=0;
    test.pieces[1]=0;

    SDL_Renderer* renderer = init_Board_GUI();
    
    int running =1;
    int m=0;
    while (running!=0){
        
        SDL_Event e;
        SDL_PumpEvents(); 


                while(SDL_PollEvent(&e)){
                    if(e.type==SDL_QUIT){
                        running =0 ;


                    }
                    else if(e.type==SDL_MOUSEBUTTONDOWN){
                            int r,c;
                            ui64 move;
                            r = 7-(e.button.x)/100;
                                c =7-(e.button.y)/100;
                                move = (ui64) pow(2, c*8+r);
                            if(e.button.button==SDL_BUTTON_LEFT){

                            
                                if((move&(test.pieces[0]|test.pieces[1]))==0){
                                test.pieces[m]|=move;}
                            }
                            
                            else if(e.button.button==SDL_BUTTON_RIGHT){
                            
                                test.pieces[m]&=~move;
                            }

                                
                                
                        }
                    else if(e.type==SDL_KEYDOWN){

                    if (e.key.keysym.sym == SDLK_BACKSPACE) {
                                      
                               test.pieces[0]=0;
                               test.pieces[1]=0;
                    }   else if (e.key.keysym.sym == SDLK_SPACE) {
                        m= (m==0)?1:0;
                    }   else if (e.key.keysym.sym == SDLK_RETURN) {
                        printf("WHITE %llu  BLACK %llu  \n",test.pieces[0],test.pieces[1]);
                    }else if(e.key.keysym.sym == SDLK_LEFT){
                        test.pieces[m]<<=1;
                    }else if(e.key.keysym.sym==SDLK_RIGHT){
                     test.pieces[m]>>=1;
        }

                    }
                
                

        make_board(renderer, &test );

    }}

    return 0;
}
