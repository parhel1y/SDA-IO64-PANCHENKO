Міністерство освіти і науки України  
Національний технічний університет України  
«Київський політехнічний інститут імені Ігоря Сікорського»  
Факультет інформатики та обчислювальної техніки  
Кафедра обчислювальної техніки  

---

# Лабораторна робота №1

### з дисципліни «Структури даних і алгоритми»

**Виконав:**  
Студент групи: ІО-64  
Панченко Ілля Ігорович  
номер у списку групи: 15  

**Перевірив:**  
Русінов Володимир Володимирович  

Київ 2026

---

## Завдання

Задається дійсне число $x$, визначити значення $x$ за варіантом кусково-неперервної функції $y(x)$, якщо вона існує.

Розв'язати задачу двома способами:

---

## Умови першого способу:

**Варіант 15**

* $f_1(x) = x^3 - 6, \quad x \in (-10, -5] \cup (5, 15]$
* $f_2(x) = 2x^3 - 3x + 2, \quad x \in [25, +\infty)$

1. У програмі дозволяється використовувати тільки одиничні операції порівняння (`=`, `<>`, `<`, `<=`, `>`, `>=`) і **не дозволяється** використовувати булеві (логічні) операції (`not`, `and`, `or` тощо).

<img width="454" height="931" alt="image" src="https://github.com/user-attachments/assets/495b513f-08bb-4564-86b0-65d195702207" />
```c
#include <stdio.h>
int main(void) {
    double x, y = 0;
    int defined = 0;

    printf("Input x: ");
    if (scanf("%lf", &x) != 1) {
        printf("Error: invalid input\n");
        return 1;
    }

    if (x > -10) {
        if (x <= -5) {
            y = x * x * x - 6;
            defined = 1;
        } else if (x > 5) {
            if (x <= 15) {
                y = x * x * x - 6;
                defined = 1;
            } else if (x >= 25) {
                y = 2 * x * x * x - 3 * x + 2;
                defined = 1;
            }
        }
    }

    if (defined == 1) {
        printf("Result: x = %.4f, y = %.4f\n", x, y);
    } else {
        printf("Result: function is undefined for x = %.4f\n", x);
    }

    return 0;
}
#### Скріншоти тестів:
<img width="1094" height="76" alt="image" src="https://github.com/user-attachments/assets/4a296bf0-ad19-42ae-9bbd-20489973928a" />
<img width="1107" height="96" alt="image" src="https://github.com/user-attachments/assets/d0ea5b49-6fd1-45d0-ae16-9e4696bb3064" />
<img width="1102" height="88" alt="image" src="https://github.com/user-attachments/assets/74a1778d-3e1c-41b1-afeb-3cd7ca3c5766" />
<img width="1108" height="106" alt="image" src="https://github.com/user-attachments/assets/155a4360-ebbd-4584-a798-5a6880b8fd6e" />
<img width="1110" height="92" alt="image" src="https://github.com/user-attachments/assets/6bad0fe2-4569-4e0e-9272-d3c760337b0f" />

Умови другого способу:
Варіант 15
$f_1(x) = x^3 - 6, \quad x \in (-10, -5] \cup (5, 15]$$f_2(x) = 2x^3 - 3x + 2, \quad x \in [25, +\infty)$У програмі необхідно обов'язково використати булеві (логічні) операції (not, and, or тощо); використання булевих операцій не повинно бути надлишковим.
<img width="529" height="933" alt="image" src="https://github.com/user-attachments/assets/49756093-49eb-43a3-85b6-6e6fde96c9fe" />
```c
#include <stdio.h>
int main(void) {
    double x, y = 0;
    int defined = 0;

    printf("Input x: ");
    if (scanf("%lf", &x) != 1) {
        printf("Error: invalid input\n");
        return 1;
    }

    if (((x > -10 && x <= -5)) || (x > 5 && x <= 15)) {
        y = x * x * x - 6;
        defined = 1;
    } else if (x >= 25) {
        y = 2 * x * x * x - 3 * x + 2;
        defined = 1;
    }

    if (defined == 1) {
        printf("Result: x = %.4f, y = %.4f\n", x, y);
    } else {
        printf("Result: function is undefined for x = %.4f\n", x);
    }

    return 0;
}
#### Скріншоти тестів:
<img width="1078" height="52" alt="image" src="https://github.com/user-attachments/assets/d08d02eb-6568-40de-836d-e62a6d85d6fc" />
<img width="1094" height="80" alt="image" src="https://github.com/user-attachments/assets/eb9d2376-cf4e-4f7a-906b-bc1c66853ebb" />
<img width="1105" height="83" alt="image" src="https://github.com/user-attachments/assets/e527fdfd-c325-494c-b0d4-fa81fe99ef11" />
<img width="1133" height="79" alt="image" src="https://github.com/user-attachments/assets/ee2166a0-fd4e-433e-9b4d-1c581643a2c9" />
<img width="1106" height="99" alt="image" src="https://github.com/user-attachments/assets/3671a6a2-42d8-4dbf-95b7-3c891402348b" />




