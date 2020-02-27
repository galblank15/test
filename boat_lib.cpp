//{
//! @file boat_lib.cpp
//! @mainpage
//! @brief Библиотека движения кораблика при сияющем солнышке
//!         $Date: 2020-02-27 20:43:39 +0400 $
//! @par  Библиотека Корабль
//! - Рисование кораблика @ref DrawBoat !!!!
//! - Рисование солнышка @ref DrawSun !!!!
//! - Рисование фона @ref DrawBackgraund !!!!
//! - Движение кораблика @ref Boat_up !!!!
//}


#include "TXLib.h"

const COLORREF SEE = RGB (0,   0,   255);
const COLORREF SKY = RGB (157, 163, 244);
const COLORREF BOAT = RGB (0, 0, 0);
const COLORREF SUN = RGB (255, 242, 0);

void DrawSun (int x, int y, int r, int t0);
//{ Рисование солнышка
//! This draws a Sun
//! @param x - x координата центра
//! @param y - y координата центра
//! @param r - радиус солнышка
//! @param t0 - движение лучиков
//}

void DrawBoat (int rightX, int rightY, int scaleX, int scaleY);
//{ Рисование кораблика
//! This draws a Boat
//! @param rightX - x координата правой нижней точки кораблика
//! @param rightY - y координата правой нижней точки кораблика
//! @param scaleX - масштабирование кораблика по x
//! @param scaleY - масштабирование кораблика по y
//}


void DrawBackgraund (int startX, int startY, int waveHeight, int t);
//{ Рисование фона
//! @param startX -
//! @param startY -
//! @param waveHeight -
//! @param t -
//}

void Boat_up (int x);
//{ Движение кораблика
//! This motion a Boat
//!@param x - изменение x координаты кораблика
//}

void DrawBackgraund (int startX, int startY, int waveHeight, int t)
    {
    txSetColor (SEE);
    txSetFillColor (SEE);
    txCircle (startX+abs(t%4-2), startY, waveHeight);
    }

void DrawSun (int x, int y, int r, int t0)
    {
    txCircle (x, y, r);
    int n = 30;
    for (int i = 0; i<n; i++)
        {
        float alfa = 360/n*i;
        float t = txPI/180*alfa;
        txLine (x+sin(t+t0)*r*2, y+cos(t+t0)*r*2, x+sin(t+t0)*r*5, y+cos(t+t0)*r*5);
        }
    }

void DrawBoat (int rightX, int rightY, int scaleX, int scaleY)
    {
    txSetColor (BOAT);
    txSetFillColor (TX_LIGHTGRAY);
    POINT korp[6] = {{rightX-14*scaleX, rightY-2*scaleY}, {rightX-14*scaleX, rightY},
    {rightX, rightY}, {rightX+3*scaleX, rightY-3*scaleY}, {rightX-3*scaleX, rightY-3*scaleY},
    {rightX-4*scaleX, rightY-2*scaleY}};
    txPolygon (korp, 6);
    txRectangle (rightX-13*scaleX, rightY-3*scaleY, rightX-12*scaleX, rightY-2*scaleY);
    POINT ser[7] = {{rightX-11*scaleX, rightY-2*scaleY}, {rightX-4*scaleX, rightY-2*scaleY},
    {rightX-3*scaleX, rightY-3*scaleY}, {rightX, rightY-3*scaleY}, {rightX, rightY-4*scaleY},
    {rightX-9*scaleX, rightY-4*scaleY}, {rightX-10*scaleX, rightY-3*scaleY}};
    txPolygon (ser, 7);
    txRectangle (rightX-9*scaleX, rightY-5*scaleY, rightX-7*scaleX, rightY-4*scaleY);
    txRectangle (rightX-7*scaleX, rightY-7*scaleY, rightX-6*scaleX, rightY-4*scaleY);
    txRectangle (rightX-6*scaleX, rightY-5*scaleY, rightX-3*scaleX, rightY-4*scaleY);
    }

void Boat_up (int x)
    {
    txBegin();
    for (int i = 0; i<1100; i++)
        {
        txClear();
        txSetColor (SEE);
        txSetFillColor (SEE);
        txRectangle (0, 200, 800, 600);
        DrawBoat (i*2, 300, 10, 5);
        DrawBoat (i, 550, 10*2, 5*3);
        txSetColor (SKY);
        txSetFillColor (SKY);
        txRectangle (0, 0, 800, 200);
        int t = 0;
        while (t <= 800)
            {
            DrawBackgraund (0+t, 200, 30, 0);
            t+=50;
            }
        txSetColor (SUN);
        txSetFillColor (SUN);
        DrawSun (500, 100, 20, i);
        txSleep (20);
        }
        txEnd();
    }


