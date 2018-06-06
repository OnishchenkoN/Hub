#include <windows.h> // Библиотека для работы с WIN API-функциями    1, 21

// объявление функции обработки сообщений ОС
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

char szClassName[] = "CG_WAPI_Template"; //объявление символьной строки

										 //ОСНОВНАЯ ФУНКЦИЯ  ~main
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
		"Шаблон WinAPI приложения", // Текст заголовка 
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

//реализация функции обработки сообщений ОС
LRESULT CALLBACK WndProc(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam)
{
	// Необходимые объявления 
	PAINTSTRUCT ps;
	HDC hdc;
	static RECT Rect; //область рисования
	static HBITMAP hBmp;
	HBRUSH brush, hBrush;
	HFONT hFont;
	HPEN hPen; //создаём перо

	static int xc, yc; //центр области рисования
	static int w, h; //ширина, высота об.рис.
	int a = 450;
	int x0 = 320, y0 = 150;
	int b = 450;
	int x1 = 370, y1 = 200;
	int c = 450;
	int x2 =420, y2 = 250;

/////////////////////////
	int nxTL=50; // координата x верхнего левого угла
		int nyTL=50; // координата y верхнего левого угла
	int nxBR=550; // координата x правого нижнего угла
	int nyBR=500;// координата y правого нижнего угла
	int nxEllipse=50; // ширина эллипса
		int nyEllipse=50; // высота эллипса

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

		
		

		// Здесь РИСУЕМ на контексте hDC 
		/////////////////////////////////////
		//cub
		
		RoundRect(hdc, nxTL,nyTL, nxBR, nyBR, nxEllipse, nyEllipse);
		
		
		
		RECT r; //объявляем экземпляр структуры
				//RECT - координаты прямоугольника
		r.left = y0+120; //левый верхний угол
		r.top = x0-60;
		r.bottom = 150;//правый нижний
		r.right = x0 - a / 2;

		//Заполняем прямоугольник
		FillRect(hdc, &r,(HBRUSH)CreateSolidBrush(RGB(255, 0, 0)));
	
		TextOut(hdc, x0 -200, y0 + 10, "red", 3);///
		/////////////////////////////////////////////////
		
		
		RECT e; //объявляем экземпляр структуры
				//RECT - координаты прямоугольника
		e.left = y1+120; //левый верхний угол
		e.top = x1-60;
		e.right =  x1 - b / 2;
		e.bottom = 200;
		//Заполняем прямоугольник
		FillRect(hdc, &e,(HBRUSH)CreateSolidBrush(RGB(0, 255, 0)));
		
		TextOut(hdc, x1 -200, y1 + 10, "green", 5);////////
		///////////////////////////////////////////////////////////
		
        
		
		RECT w; //объявляем экземпляр структуры
				//RECT - координаты прямоугольника
		w.left = x2-50; //левый верхний угол
		w.top = x2-57;
		w.right =  x2 - c / 2;
		w.bottom = 250;

		//Заполняем прямоугольник
		FillRect(hdc, &w,(HBRUSH)CreateSolidBrush(RGB(0, 0, 255)));
		TextOut(hdc, x2-200, y2 + 10, "blue", 4);/////
		
		
		
		/////////////////////////////////////					      

		// Удаляем ненужные системные объекты
		//DeleteObject(hFont);
		//DeleteObject(hBrush);
		//DeleteObject(brush);

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




// Закраска фоновым цветом
//brush = CreateSolidBrush(RGB(200, 200, 200));
//FillRect(hdc, &Rect, brush);
//hBmp = (HBITMAP)LoadImage(NULL, "desktop.bmp", IMAGE_BITMAP, 0, 0,
//LR_LOADFROMFILE | LR_CREATEDIBSECTION)