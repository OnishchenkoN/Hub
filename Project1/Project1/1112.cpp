#include <windows.h> // Библиотека для работы с WIN API-функциями    1, 21
#include <iostream>
#include  <fstream>
#include  <string>
#include <iostream>
// объявление функции обработки сообщений ОС

using namespace std;
int *arr = new int;
int *yrr = new int;
ifstream fin("perem.txt"); // открыли файл для чтения
///////////////////////////////
        LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
        char szClassName[] = "CG_WAPI_Template"; //объявление символьной строки
        int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
			LPSTR lpCmdLine, int nCmdShow)
		{
			// объявляем переменные - объекты
			HWND hWnd;  // основное окно приложения
			MSG lpMsg;  // сообщение
			WNDCLASS wc; // собственно окно

						 // Заполняем структуру класса окна
			wc.style = CS_HREDRAW | CS_VREDRAW;
			wc.lpfnWndProc = WndProc;
			wc.cbClsExtra = 0;
			wc.cbWndExtra = 0;
			wc.hInstance = hInstance;
			wc.hIcon = NULL;
			wc.hCursor = LoadCursor(NULL, IDC_ARROW);
			wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
			wc.lpszMenuName = NULL;
			wc.lpszClassName = szClassName;
            // Регистрируем класс окна
			if (!RegisterClass(&wc)) // если ошибка
			{
				MessageBox(NULL, "Не могу зарегистрировать класс окна!", "Ошибка", MB_OK);
				return 0;
			}
            // Создаем основное окно приложения
			hWnd = CreateWindow(
				szClassName,                // Имя класса
				" lab11-гр319-в05-Онищенко Н.", // Текст заголовка 
				WS_OVERLAPPEDWINDOW,        // Стиль окна
				50, 50,                   // Позиция левого верхнего угла
				600, 600,                  // Ширина и высота окна
				(HWND)NULL,                // Указатель на родительское окно NULL
				(HMENU)NULL,               // Используется меню класса окна
				(HINSTANCE)hInstance,       // Указатель на текущее приложение
				NULL);         // Передается в качестве lParam в событие WM_CREATE
			if (!hWnd) // если ошибка
			{
				MessageBox(NULL, "Не удается создать главное окно!", "Ошибка", MB_OK);
				return 0;
			}
            // Показываем наше окно
			ShowWindow(hWnd, nCmdShow);
			UpdateWindow(hWnd);
            // Выполняем цикл обработки сообщений до закрытия приложения
			while (GetMessage(&lpMsg, NULL, 0, 0))
			{
				TranslateMessage(&lpMsg);
				DispatchMessage(&lpMsg);
			}
			return (lpMsg.wParam);
		}
        LRESULT CALLBACK WndProc(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam)
		{
			// Необходимые объявления 
			PAINTSTRUCT ps;
			HDC hdc;
			static RECT Rect; //область рисования
			static HBITMAP hBmp;
			HBRUSH brush;
		    static int xc, yc; //центр области рисования
			static int w, h; //ширина, высота об.рис.
			//обьявление координат
            int x1 = 20, y1 = 10; 
			int x2 = 20, y2 = 540;

			int x01 = 10, y01 = 280;
			int x02 = 570, y02 = 280;

			int xt1, yt1;
			int xt2, yt2;
			//обьявление переменных
			int u = 0;
			int r = 1;
			int a = 0;
			int b = 0;
			// ОБРАБОТКА СООБЩЕНИЙ ОС
			switch (messg)
			{
			case WM_CREATE:
				hBmp = (HBITMAP)LoadImage(NULL, "desktop.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
				break;
			case WM_SIZE:
				GetClientRect(hWnd, &Rect);
				w = Rect.right - Rect.left;
				h = Rect.bottom - Rect.top;
				xc = Rect.left + w / 2;
				yc = Rect.top + h / 2;
				break;
			case WM_PAINT: // ПЕРЕРИСОВКА ОКНА
				hdc = BeginPaint(hWnd, &ps);
                brush = CreatePatternBrush(hBmp);
                FillRect(hdc, &Rect, brush);
				/////////////////////
				//Оси координат
				//Ось Y
                POINT pt;
				MoveToEx(hdc, x1+5, y1, &pt);
				LineTo(hdc, x2+5, y2);
				TextOut(hdc, x1, y1, "Y", 1);
				//Ось Y
				MoveToEx(hdc, x01, y01, &pt);
				LineTo(hdc, x02, y02);
				TextOut(hdc, x02, y02, "K", 4);
				/////////////////////
				POINT aa;//метки на оси Y
				MoveToEx(hdc, 15, 80, &aa);
				LineTo(hdc, 35, 80);
                
				MoveToEx(hdc, 15, 130, &aa);
				LineTo(hdc, 35, 130);

				MoveToEx(hdc, 15, 180, &aa);
				LineTo(hdc, 35, 180);

				MoveToEx(hdc, 15, 230, &aa);
				LineTo(hdc, 35, 230);
				
                MoveToEx(hdc, 15, 330, &aa);
				LineTo(hdc, 35, 330);

				MoveToEx(hdc, 15, 380, &aa);
				LineTo(hdc, 35, 380);

				MoveToEx(hdc, 15, 430, &aa);
				LineTo(hdc, 35, 430);

				MoveToEx(hdc, 15, 480, &aa);
				LineTo(hdc, 35, 480);
				//аргумент
				TextOut(hdc, x02-495, y02+10, "1", 1); 
				TextOut(hdc, x02-440, y02 + 10, "2", 1);
				TextOut(hdc, x02-385, y02 + 10, "3", 1);
				TextOut(hdc, x02-330, y02 + 10, "4", 1);
				TextOut(hdc, x02-275, y02 + 10, "5", 1);
				TextOut(hdc, x02-220, y02 + 10, "6", 1);
				TextOut(hdc, x02-170, y02 + 10, "7", 1);
				TextOut(hdc, x02-115, y02 + 10, "8", 1);
				TextOut(hdc, x02 - 60, y02 + 10, "9", 1);
				//TextOut(hdc, x02-65, y02 + 10, "10", 2);
				//функция
				TextOut(hdc, 5 , y02 -67, "50", 2);
				TextOut(hdc, 1 , y02 -117, "100", 3);
				TextOut(hdc, 1, y02 - 167, "150", 3);
				TextOut(hdc, 1 , y02 -217, "200", 3);
				TextOut(hdc, 5, y02 + 10, "0", 1);
				TextOut(hdc, 5, y02+33 , "50", 2);
				TextOut(hdc, 0, y02 +83, "100", 3);
				TextOut(hdc, 0, y02+133 , "150", 3);
				TextOut(hdc, 0, y02 + 183, "200", 3);

				do {                   //цикл do while 
					if (r % 2 == 0) {  // использование if
                        fin >> arr[a]; //Y
                        a++;
					}
					else               // использование else 
					{
                        fin >> yrr[b]; //K
						b++;
					}
					r++;
				} while (r < 21);
			    fin.close();
				xt1 = 25;
				xt2 = 80;
				//рисование разметки по оси аргумента
				do {                   //цикл do while 
					yt2 = 280- arr[u+1];
					yt1 = 280 -arr[u ];
                    POINT pee;
					MoveToEx(hdc, xt1, yt1, &pee);
					LineTo(hdc, xt2, yt2);
					xt1 = xt1 + 55;
					xt2 = xt2 + 55;
					u++;
					MoveToEx(hdc, xt1, 270, &pt);
					LineTo(hdc, xt1, 290);
				} while (u < 9);
			
				EndPaint(hWnd, &ps);
				break;
             case WM_DESTROY: // ЗАКРЫТИЕ ОКНА
				PostQuitMessage(0);
				break;
             default: // ДРУГИЕ СООБЩЕНИЯ
				return (DefWindowProc(hWnd, messg, wParam, lParam));
			}
			return (0);
		}
	

	

