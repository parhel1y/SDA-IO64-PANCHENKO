Міністерство освіти і науки України
Національний технічний університет України
«Київський політехнічний інститут імені Ігоря Сікорського»
Факультет інформатики та обчислювальної техніки
Кафедра обчислювальної техніки
Лабороторна робота №1
з дисципліни «Структури даних і алгоритми»
Виконав
Студент групи: ІО-64
Панченко Ілля Ігорович
номер у списку групи: 15

Перевірив
Русінов Володимир Володимирович

Київ 2026
Завдання
Задаєтся дійсне число х, визначити значення х ща варіантом кусково неперервної функції y(x), якщо вона існує.\

         f1(x) ,  x ∈ D1
y(x) =
         f2(x) ,  x ∈ D2
Розв'язати задачу двома способами:

Умови першого способу:
Варіант 15
f1(x), x ∈ D1
x³ – 6, x ∈ (–10,–5] ∪ (5,15]
f2(x), x ∈ D2
2x³ – 3x + 2, x ∈ [25, +∞)

У програмі дозволяється використовувати тільки одиничні операції порівняння (=, <>, <, <=, >, >=) і не дозволяється використовувати булеві (логічні) операції (not, and, or тощо);
<img width="459" height="930" alt="image" src="https://github.com/user-attachments/assets/0b347da4-4906-47d6-89ef-43ed794fb027" />
#include <stdio.h>

int main() {
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
<img width="1094" height="76" alt="image" src="https://github.com/user-attachments/assets/845d098b-d69b-46d5-8873-25519aaab271" />
<img width="1107" height="96" alt="image" src="https://github.com/user-attachments/assets/0b8fcb99-589f-4125-9f17-1b5a282c802d" />
<img width="1102" height="88" alt="image" src="https://github.com/user-attachments/assets/1920ac45-1b57-42f8-88a5-4ab301df6c02" />
<img width="1108" height="106" alt="image" src="https://github.com/user-attachments/assets/7ef51cab-31e0-4953-b4a6-28c1eb567dc7" />
<img width="1110" height="92" alt="image" src="https://github.com/user-attachments/assets/bd27f298-48f8-4ec9-875d-69deba79115e" />
Умови другого способу:
Варіант 15
f1(x), x ∈ D1
x³ – 6, x ∈ (–10,–5] ∪ (5,15]
f2(x), x ∈ D2
2x³ – 3x + 2, x ∈ [25, +∞)

2. У програмі необхідно обов'язково використати булеві (логічні) операції (not, and, or тощо); використання булевих операцій не повинно бути надлишковим.
<img width="529" height="933" alt="image" src="https://github.com/user-attachments/assets/63cfc3ef-7890-43ba-8762-a8789f87b5ed" />
#include <stdio.h>

int main() {
    double x, y = 0;
    int defined = 0;

    printf("Input x: ");
    if (scanf("%lf", &x) != 1) {
        printf("Error: invalid input\n");
        return 1;
    }

    if ((x > -10 && x <= -5) || (x > 5 && x <= 15)) {
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
<img width="1077" height="51" alt="image" src="https://github.com/user-attachments/assets/32640bd2-a189-49ab-be4e-f80dcd4a4667" />
<img width="1094" height="80" alt="image" src="https://github.com/user-attachments/assets/aa6ebbe3-ebeb-4d14-b3ed-51b8a274e6da" />
<img width="1105" height="83" alt="image" src="https://github.com/user-attachments/assets/f4464b06-0e50-41d7-bb44-2fd9f7669a5f" />
<img width="1133" height="79" alt="image" src="https://github.com/user-attachments/assets/4dba6dc6-5fcf-42f1-a4a3-1adf9e5863cb" />
<img width="1106" height="99" alt="image" src="https://github.com/user-attachments/assets/e489aca8-0957-4748-b789-ab264cea06ef" />










