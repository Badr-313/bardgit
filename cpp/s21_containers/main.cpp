// circles.cpp
// круги в качестве Объектов
#include "msoftcon.h"
// для функций консольной графики
//////////////////////////////////////////////////////////
class circle
// графический Объект "круг"
{
protected:
int xCo, yCo;
// координаты центра
int radius;
color fillcolor;
// цвет
fstyle fillstyle;
// стиль заполнения
public:
// установка атрибутов круга
void set(int x, int y, int r, color fc, fstyle fs)
{
yCo = y;
radius = r;
fillcolor = fc;
fillstyle = fs;
}
void draw()
// рисование круга
{
set_color(fillcolor);
// установка цвета и
set_fill_style(fillstyle);
// стиля заполнения
draw_circle(xCo, yCo, radius);// рисование круга
}
};
//////////////////////////////////////////////////////////
int main()
{
init_graphics();
// инициализация графики
circle c1;
// создание кругов
circle c2;
circle c3;
// установка атрибутов кругов
c1.set(15, 7, 5, cBLUE, X_FILL);
c2.set(41, 12, 7, cRED, O_FILL);
c3.set(65, 18, 4, cGREEN, MEDIUM_FILL);
c1.draw();
// рисование кругов
c2.draw();
c3.draw();
set_cursor_pos(1, 25);
// нижний левый угол
return 0;
}