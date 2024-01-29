all:
	gcc Main.c handlers/EventHandler.c Render.c handlers/UIHandler.c objects/Block.c objects/Button.c objects/Frame.c handlers/ColorHandler.c -ISDL2\include\SDL2 -LSDL2\lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -o bootlegpaint
