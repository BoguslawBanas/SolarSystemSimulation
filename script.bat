@set count=0

@for %%A in (%*) do (
    @set /A count+=1
)

@echo Compiling process has started.

@if %count%==0 (
    g++ main.cpp Simulation/*.cpp ^
        Universe/*.cpp ^
        Planet/*.cpp ^
        Main_Menu/*.cpp ^
        Slider_Textfield_Menu/*.cpp ^
        Gravitational_Grid_2D/*.cpp ^
        Add_Planet_Menu/*.cpp ^
        Start_Menu/*.cpp ^
        Options/*.cpp ^
    -pthread -lraylib -lgdi32 -lwinmm -lcomdlg32
)

@if %count% GEQ 1 (
    @echo One argument has been given.
)

@if %count% GEQ 2 (
    @echo Two arguments have been given.
)

@if %count% GEQ 3 (
    @echo Three arguments have been given.
)

@if %count% GEQ 4 (
    @echo Four arguments have been given.
)

@if %count% GEQ 5 (
    @echo Five arguemnts have been given.
)

@echo Compiling process has ended.