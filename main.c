#include "Renderer.h"

int SDL_main(int c, char *T[]) {
    TrainigList *list = createTrainigList();
    Model* model=createModel(1,1);

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("error initializing SDL: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_Window *win = SDL_CreateWindow("LINEAR REGRESSION",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       SCALE, SCALE, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderSetLogicalSize(renderer, SCALE, SCALE);

    SDL_bool succ = SDL_FALSE;
    while (!succ)
    {
        minimizeError(model,list);

        SDL_Event event;

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        float scale = 5.0;
        int i;
        Point *p;
        SDL_Point points[list->size];
        for (i = 0, p = list->first; p != NULL; p = p->next, i++)
        {
            int x = p->x;
            int y = SCALE - p->y;
            points[i].x = x / scale;
            points[i].y = y / scale;
        }
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderSetScale(renderer, scale, scale);
        SDL_RenderDrawPoints(renderer, points, list->size);

        render(model, renderer);

        SDL_RenderPresent(renderer);

        SDL_RenderSetScale(renderer, 1.0, 1.0);
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                succ = SDL_TRUE;
            }
            else if (event.type == SDL_MOUSEBUTTONUP)
            {
                SDL_MouseButtonEvent button = event.button;
                int x = button.x;
                int y = SCALE - button.y;
                addPt(list, x, y);
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    SDL_Quit();

    free(model);
    deleteTrainigList(list);
    return 0;
}
