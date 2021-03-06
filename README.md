# lem-in school21

Цель проекта найти самый быстрый путь для n числа муравьёв, чтобы провести их через лабиринт. Лабиринт состоит из комнат и связей между комнатами. В каждой комнате может находить одновременно только один муравей (кроме начальной и конечной комнаты), так что нужно избежать пробок. В итоге колония муравьев должна переместится из начало в конец за наименьшее количество ходов. Для решения задачи был использован алгоритм поиск в ширину (BFS).

Программа получает данные из файла (карта) следующим образом “./lem-in < map”.
Карта состоит из:
1.	Количество муравьев.
2.	Начало лабиринта - Start room.
3.	Другие комнаты.
4.	Конец лабиринта - End room.
5.	Связи со всеми комнатами, которые у нас есть. 

_Примеры карт можно найти в директории maps._

Карту необходимо проверить на валидность, иначе выдать ошибку:
1.	Количество муравьев должно быть больше 0;
2.	Карта должна иметь начальную и конечную комнату;
3.	Не должно быть одинаковое название комнат. Название комнат может быть и строкой и номером.
4.	Название комнат не может начинаться с L или #;
5.	Не должно быть одинаковых координат, координаты всегда цифры;
6.	Карта должна иметь одну или более связей:
7.	Связи обязательно должны привести с начальной в конечную комнату;
8.	Пример связи room1-room2. Комнаты обязательно должны существовать;
9.	Не должно быть дубликатов связей  
так  
room1-room2  
room1-room2  
или так  
room1-room2  
room2-room1  
нельзя.  
10.	В карте могут быть комментарии, которые начинаются с символа #;
11.	 Карта может иметь команды, которые начинаются с “##”. Команды ##start и ##end символизирует о начальной и конечной комнате. Все остальные команды нужно игнорировать;
12.	Не должно быть пустых строк. 


_Подробнее о проекте можно почитать в [Subject](https://github.com/Timur17/lem-in/blob/master/subject_lem-in.en.pdf)_
