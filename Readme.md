# NetVision Test Program

Данный репозиторий содержит исходный код программы тестового задания на позицию C++ Junior компании NetVision.

Программа вычисляет пересечание заданных отрезков с фигурой в двумерном пространстве.

## Getting Started

### Dependencies

* GTest

### Installing Dependencies

## Ubuntu
```
sudo apt-get install libgtest-dev
```
## ArchLinux
```
sudo pacman -S gtest
```
## Nix Flake (Recommended)
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
Результат будет записан в файл results.txt

## Author

ex. [Aleksey (Faumaray) Selihov](faumaray@gmail.com)

