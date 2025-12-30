#ifndef SLIDER_TEXTFIELD_MENU_MODEL_H
#define SLIDER_TEXTFIELD_MENU_MODEL_H

class Slider_Textfield_Menu_Model{
    private:
    float slider_result;
    float slider_min;
    float slider_max;

    public:
    Slider_Textfield_Menu_Model(const float, const float);

    ~Slider_Textfield_Menu_Model();

    const float getSliderMin() const;

    const float getSliderMax() const;

    const float getSliderResult() const;

    float* getSliderResultPointer();

    void setDirectValue(const float);

    void updateNextFrame(const float);
};

#endif