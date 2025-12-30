#ifndef SIMULATION_MODEL_H
#define SIMULATION_MODEL_H

#include <map>

enum Simulation_State{
    START_MENU,
    START_MENU_2,
    SETTINGS,
    SIMULATION,
    ADD_PLANET_MENU,
    DELETE_PLANET_MENU,
    PAUSE,
    EXIT
};

class Simulation_Model{
    private:
    Simulation_State simulation_state;
    bool start_sim;
    bool exit;
    bool settings;
    bool solar_system;
    bool free_mode;
    bool go_back;
    bool add_planet;
    bool delete_planet;
    bool pause;
    bool save_file;
    bool read_file;

    public:
    Simulation_Model();

    ~Simulation_Model();

    Simulation_State getState() const;

    void setState(Simulation_State);

    bool getStartSim() const;

    void setStartSim(const bool);

    bool getExit() const;

    void setExit(const bool);

    bool getSettings() const;

    void setSettings(const bool);

    bool getSolarSystem() const;

    void setSolarSystem(const bool);

    bool getFreeMode() const;

    void setFreeMode(const bool);

    bool getGoBack() const;

    void setGoBack(const bool);

    bool getAddPlanet() const;

    void setAddPlanet(const bool);

    bool getDeletePlanet() const;

    void setDeletePlanet(const bool);

    bool getPause() const;

    void setPause(const bool);

    bool getSaveFile() const;

    void setSaveFile(const bool);

    bool getReadFile() const;

    void setReadFile(const bool);
};

#endif