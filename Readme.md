# NetVision Test Program

Данный репозиторий содержит исходный код программы тестового задания на позицию C++ разработчик компании NetVision.

Программа вычисляет пересечание заданных отрезков с фигурой в двумерном пространстве.

## Getting Started

### Dependencies

* GTest only for tests via -DBUILD_TESTS=true

### Installing Dependencies

#### Ubuntu
```
sudo apt-get install libgtest-dev cmake ninja-build
```
#### ArchLinux
```
sudo pacman -S gtest cmake ninja
```
#### Nix Flake (Recommended)
```
nix build
```

### Executing program

Для запуска программы необходимо 2 файла
- polys.txt
Содержит список точек фигуры в формате:
```
x1,y1 x2,y2 x3,y3 x4,y4 ... xn,yn
```
- lines.txt
Содержит список отрезков в формате:
```
x1,y1 x2,y2
x1,y1 x2,y2
...
x1,y1 x2,y2
```
Результат будет записан в файл results.txt где каждная строка будет соответствовать каждому отрезку
0 - отрезок внутри четырёхугольника (обе точки вписаны в четырёхугольник
1 - отрезок пересекает четырёхугольник (обе точки находятся вне четырёхугольника)
2 - отрезок частично пересекает четырёхугольник(одна из точек вписана четырёхугольник,
вторая нет)
3 - отрезок не имеет ничего общего с прямоугольником (обе точки вне четырёхугольника).

## Author

ex. [Aleksey (Faumaray) Selihov](faumaray@gmail.com)

