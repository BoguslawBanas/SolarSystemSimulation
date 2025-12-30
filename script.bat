@set count=0

@for %%A in (%*) do (
    @set /A count+=1
)

@echo %count%

@REM compiling every single .cpp file and linking them together.
@if %count%==0 (
    @REM g++ source_files/main.cpp ^
    @REM  source_files/planet.cpp ^
    @REM  source_files/gravitational_grid_2d.cpp ^
    @REM  source_files/add_planet_menu.cpp ^
    @REM  source_files/delete_planet_menu.cpp ^
    @REM  source_files/universe.cpp ^
    @REM  source_files/simulation.cpp ^
    @REM  source_files/slider_textfield_menu.cpp ^
    @REM  source_files/clicked_planet_menu.cpp ^
    @REM  source_files/pause_menu.cpp ^
    @REM  source_files/file_saver.cpp ^
    @REM  source_files/file_reader.cpp ^
    @REM  source_files/main_menu.cpp ^
    @REM -lraylib -lgdi32 -lwinmm -lcomdlg32

    g++ main.cpp Simulation/*.cpp ^
        Universe/*.cpp ^
        Planet/*.cpp ^
        Main_Menu/*.cpp ^
        Slider_Textfield_Menu/*.cpp ^
        Gravitational_Grid_2D/*.cpp ^
        Add_Planet_Menu/*.cpp ^
        Start_Menu/*.cpp ^
    -pthread -lraylib -lgdi32 -lwinmm -lcomdlg32
)

@REM compiling given .cpp files and linking it to already compiled files.
@if %count% GEQ 1 (
    @echo Piwo
)

@if %count% GEQ 2 (
    @echo Piwo2
)

@if %count% GEQ 3 (
    @echo Piwo3
)

@if %count% GEQ 4 (
    @echo Piwo4
)

@if %count% GEQ 5 (
    @echo Piwo5
)


@REM @if "%~2"=="" (@echo There is not a second argument.) else @echo Second argument exists.