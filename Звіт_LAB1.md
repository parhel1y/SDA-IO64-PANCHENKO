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
Задається дійсне число x, визначити значення x за варіантом кусково-неперервної функції y(x), якщо вона існує.\

$$y(x) = \begin{cases} f_1(x), & x \in D_1 \\  f_2(x), & x \in D_2 \end{cases}$$

Розв'язати задачу двома способами:

### Умови першого способу:
##### Варіант 15
$f_1(x), \quad x \in D_1$  
$x^3 - 6, \quad x \in (-10, -5] \cup (5, 15]$  
$f_2(x), \quad x \in D_2$  
$2x^3 - 3x + 2, \quad x \in [25, +\infty)$  

1. У програмі дозволяється використовувати тільки одиничні операції порівняння (`=`, `<>`, `<`, `<=`, `>`, `>=`) і **не дозволяється** використовувати булеві (логічні) операції (`not`, `and`, `or` тощо);

---

<img width="450" height="928" alt="image" src="https://github.com/user-attachments/assets/5cb629aa-4f0a-4ed1-9927-14f08ac3e621" />


---

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
<img width="1094" height="76" alt="image" src="https://github.com/user-attachments/assets/037d98b9-0667-467e-bb2e-999c377aaa88" />
<img width="1107" height="96" alt="image" src="https://github.com/user-attachments/assets/80cf57b6-26e2-419e-b162-6b29f4da8b64" />
<img width="1102" height="88" alt="image" src="https://github.com/user-attachments/assets/94b68c0a-cba3-4977-9976-d4f794afa753" />
<img width="1108" height="106" alt="image" src="https://github.com/user-attachments/assets/e6e1a5d8-1684-447e-bcee-4a010f34cf5f" />
<img width="1110" height="92" alt="image" src="https://github.com/user-attachments/assets/c42d7721-fe3c-4710-991a-68150c3c6b3a" />

### Умови другого способу:
##### Варіант 15
f1(x), x ∈ D1\
x³ - 6, x ∈ (-10,-5] U (5,15]\
f2(x), x ∈ D2\
2x³ - 3x + 2, x ∈ [25, +∞)

2. У програмі необхідно **обов'язково** використати булеві (логічні) операції (`not`, `and`, `or` тощо); використання булевих операцій не повинно бути надлишковим.
---
<img width="528" height="931" alt="image" src="https://github.com/user-attachments/assets/9099be59-c8a2-4c0a-8a70-12d540691c31" />

---
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
<img width="1074" height="55" alt="image" src="https://github.com/user-attachments/assets/c359647e-9aaf-4376-9be9-dd6723012e58" />
<img width="1094" height="80" alt="image" src="https://github.com/user-attachments/assets/c8c4ebf6-8fd5-42ce-83b9-2f596675f056" />
<img width="1105" height="83" alt="image" src="https://github.com/user-attachments/assets/eb3457f0-7e0b-4b9a-a13b-42db4d8859c2" />
<img width="1133" height="79" alt="image" src="https://github.com/user-attachments/assets/d0322e2c-2e9c-4dca-899b-3f3039edd81e" />
<img width="1106" height="99" alt="image" src="https://github.com/user-attachments/assets/63c4aad6-dae9-48d3-94e7-815b6067af21" />




