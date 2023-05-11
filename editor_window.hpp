#pragma once

class EditorWindow
{
public:
    explicit EditorWindow(std::string title);

    void draw();

protected:
    virtual void draw_layout() = 0;

    std::string _title;
};