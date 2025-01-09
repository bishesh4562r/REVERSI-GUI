#ifndef GUI_H
#define GUI_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h>
#include "pre.h"

typedef struct{
    int x,y;
} pair;




void SDL_RenderFillCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius) {
    
    for (int w = 0; w < radius * 2; w++) {
        for (int h = 0; h < radius * 2; h++) {
            int dx = radius - w; 
            int dy = radius - h; 
            if ((dx * dx + dy * dy) <= (radius * radius)) {
                SDL_RenderDrawPoint(renderer, centerX + dx, centerY + dy);
            }
        }
    }
}





void drawGrid(SDL_Renderer* renderer, int cellWidth, int cellHeight, int cols, int rows) {
    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x) {
            SDL_Rect rect = {x * cellWidth, y * cellHeight, cellWidth, cellHeight};
            SDL_RenderDrawRect(renderer, &rect);
        }
    }
}





void drawPiece(SDL_Renderer* renderer, board* bd){

    if(((bd->pieces[0]) & (bd->pieces[1]))==0){
        for(int i=0;i<2;i++){

        ui64 mask=1;

            for(int r=0;r<8;r++){
                            for(int c=0;c<8;c++){
                                if((mask&(bd->pieces[i]))!=0){
                                    int x_coord= 750-c*100;
                                    int y_coord= 750-r*100;
                                    int cwp= 255*(1-i);

                                    SDL_SetRenderDrawColor(renderer, cwp,cwp,cwp, 255);
                                    SDL_RenderFillCircle(renderer, x_coord, y_coord, 40);

                            }
                            mask<<=1;


            }



        }

}}



}
              


      
SDL_Renderer* init_Board_GUI(){

        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;

        SDL_Init(SDL_INIT_EVERYTHING);
        SDL_CreateWindowAndRenderer(800,800,0,&window,&renderer);
        SDL_RenderSetScale(renderer,1,1);
        SDL_SetRenderDrawColor(renderer,55,55,55,255);

        return renderer;



}
void make_board(SDL_Renderer* renderer, board* bd){

        SDL_SetRenderDrawColor(renderer,55,55,55,255);

        SDL_RenderClear(renderer);


        SDL_SetRenderDrawColor(renderer,200,200,200,255);
        drawGrid(renderer,  100,  100, 8, 8);
        SDL_SetRenderDrawColor(renderer, 255 , 255, 255, 255);

        drawPiece(renderer, bd );
        SDL_RenderPresent(renderer);


}



// SDL_SetRenderDrawColor(renderer,255,255,255,255);
// SDL_RenderDrawPoint(renderer,640/2,480/2);

// SDL_Delay(100000);







#endif
