#pragma once
//Explain access specifier and classes
class Light
{
    private:
        bool activated;
        int brightness;
    public:
        Light();
        Light(bool active, int bright);
        void Brighten();
        void Dim();
        void ShowStatus();
};
