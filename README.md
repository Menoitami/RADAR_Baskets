# BasketChance

## Описание проекта

**BasketChance** — программа, моделирующая вероятности событий с шарами в двух корзинах. Проект реализован на основе фреймворка **Qt 5.x** и предоставляет минимальный графический интерфейс для управления моделью. Программа выполняет следующие действия:

1. Перекладывает случайный шар из первой корзины во вторую.
2. Перекладывает случайный шар из второй корзины в первую.
3. Извлекает два шара случайным образом (оба из одной корзины или по одному из каждой). В этом случае общее количество шаров в корзинах уменьшается на 2.

Вероятности действий и их результаты рассчитываются с использованием генератора случайных чисел.

---

## Основные функции

**Расчет вероятностей**:
   - Вероятность извлечения шара того или иного цвета из каждой корзины.
   - Вероятность извлечения:
     - двух синих шаров,
     - двух красных шаров,
     - одного синего и одного красного шара при извлечении двух шаров.



## Установка и запуск

### Сборка проекта
1. Убедитесь, что у вас установлен **Qt 5.x**, **Qt Creator**, **gcc**(на других компиляторах не тестировалось).
2. Склонируйте репозиторий:
```bash
   git clone https://github.com/username/BasketChance.git
```
3. откройте и соберите проект:
```bash
   mkdir build
   cd build
   cmake ..
   cmake --build .
```
