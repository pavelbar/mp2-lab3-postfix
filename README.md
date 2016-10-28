﻿# Методы программирования 2: Вычисление арифметических выражений

![Build Status](https://travis-ci.org/alvls/mp2-lab3-postfix.svg)

<!-- TODO
  -
-->

## Цели и задачи

__Цель данной работы__  — разработка структуры данных Стек и ее использование для расчета арифметических выражений с использованием обратной польской записи (постфиксной формы).

Выполнение работы предполагает решение следующих задач:

  1. Разработка интерфейса шаблонного класса `TStack`.
  1. Реализация методов шаблонного класса `TStack`.
  1. Разработка интерфейса класса `TPostfix` для работы с постфиксной формой.
  1. Реализация методов класса `TPostfix`.
  1. Разработка и реализация тестов для классов `TStack` и `TPostfix` на базе Google Test.
  1. Публикация исходных кодов в личном репозитории на GitHub.

## Используемые инструменты

  - Система контроля версий [Git][git]. Рекомендуется использовать один из
    следующих клиентов на выбор студента:
    - [Git](https://git-scm.com/downloads)
    - [GitHub Desktop](https://desktop.github.com)
  - Фреймворк для написания автоматических тестов [Google Test][gtest]. Не
    требует установки, идет вместе с проектом-шаблоном.
  - Среда разработки Microsoft Visual Studio (2010 или старше).

## Общая структура проекта

Структура проекта:

  - `gtest` — библиотека Google Test.
  - `base` — каталог с основным проектом ЛР.
  - `base_test` — каталог с проектом с модульными тестами.
  - `README.md` — информация о проекте, которую вы сейчас читаете.
  - `mp2-lab3-postfix.sln` - файл с решением (solution) для Microsoft Visual Studio 2010.
  - Служебные файлы
    - `.gitignore` — перечень расширений файлов, игнорируемых Git при добавлении файлов в репозиторий.

## Инструкция по выполнению работы

  1. Создание форка данного проекта-шаблона.
  1. Клонирование форка из своего личного пространства на GitHub к себе на рабочую машину.
  1. __Смена имени папки верхнего уровня на свою фамилию (на русском языке).__
  1. Разработка тестов для классов `TStack` и `TPostfix`
  1. Разработка классов `TStack` и `TPostfix`.
  1. Доработка консольной программы для работы с арифмитическими выражениями.

<!-- LINKS -->

[git]:         https://git-scm.com/book/ru/v2
[gtest]:       https://github.com/google/googletest
[git-guide]:   https://github.com/UNN-VMK-Software/mp2-lab1-set/blob/master/docs/part1-git.md
[gtest-guide]: https://github.com/UNN-VMK-Software/mp2-lab1-set/blob/master/docs/part2-google-test.md
