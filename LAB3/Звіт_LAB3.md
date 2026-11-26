#### Міністерство освіти і науки України
#### Національний технічний університет України
#### «Київський політехнічний інститут імені Ігоря Сікорського»
#### Факультет інформатики та обчислювальної техніки
#### Кафедра обчислювальної техніки
---
# Лабораторна робота №3
## з дисципліни «Структури даних і алгоритми»

#### Виконав
Студент групи: ІО-64\
Панченко Ілля Ігорович\
Варіант: 15

#### Перевірив
Русінов Володимир Володимирович

#### Київ 2026

---

## Постановка задачі

1. Кожен варіант завдання визначає прикладну задачу та структуру даних, потрібну для її розв'язання.
2. Написати **дві програми**, що реалізують ту саму структуру даних двома способами:
   1. на основі **одновимірного масиву фіксованого розміру** (кільцева черга);
   2. на основі **однозв'язного списку** (динамічне виділення пам'яті: вузол зі значенням і вказівником на наступний вузол).
3. Обидві реалізації мають надавати єдиний узгоджений набір функцій (`init_queue`, `is_empty`, `is_full`, `enqueue`, `dequeue`, `peek_front`, `clear_queue`) зі сталим часом виконання $O(1)$ та однаковою прикладною логікою.

### Завдання для варіанту 15

| № | Завдання |
| --- | --- |
| 15 | Чергою змоделювати обробку викликів у call-центрі: виклики надходять у чергу з відомою тривалістю розмови; визначити **максимальну довжину черги**, що спостерігалася протягом симуляції, і час завершення обробки останнього виклику. |

---

## Код програм

#### Перший спосіб 
```c
#include <stdio.h>

#define MAX_SIZE 50

typedef struct {
    int id;
    int arrival;
    int duration;
} Call;

typedef struct {
    Call data[MAX_SIZE];
    int front;
    int rear;
    int count;
} Queue;

void init_queue(Queue *q) {
    q->front = 0;
    q->rear = 0;
    q->count = 0;
}

int is_empty(const Queue *q) {
    return q->count == 0;
}

int is_full(const Queue *q) {
    return q->count == MAX_SIZE;
}

int enqueue(Queue *q, Call item) {
    if (is_full(q)) {
        return 0;
    }
    q->data[q->rear] = item;
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->count++;
    return 1;
}

int dequeue(Queue *q, Call *out) {
    if (is_empty(q)) {
        return 0;
    }
    if (out != NULL) {
        *out = q->data[q->front];
    }
    q->front = (q->front + 1) % MAX_SIZE;
    q->count--;
    return 1;
}

int peek_front(const Queue *q, Call *out) {
    if (is_empty(q)) {
        return 0;
    }
    if (out != NULL) {
        *out = q->data[q->front];
    }
    return 1;
}

void clear_queue(Queue *q) {
    q->front = 0;
    q->rear = 0;
    q->count = 0;
}

void simulate_calls(const Call calls[], int n) {
    Queue q;
    init_queue(&q);

    int t = 0;
    int i = 0;
    int busy = 0;
    int free_at = 0;
    int max_len = 0;
    Call current = {0, 0, 0};

    printf("Симуляція роботи call-центру:\n");

    while (i < n || !is_empty(&q) || busy) {
        if (busy && i < n) {
            t = (free_at < calls[i].arrival) ? free_at : calls[i].arrival;
        } else if (busy) {
            t = free_at;
        } else {
            t = calls[i].arrival;
        }

        if (busy && t == free_at) {
            printf("t = %2d: завершено виклик #%d\n", t, current.id);
            busy = 0;
        }

        while (i < n && calls[i].arrival == t) {
            if (enqueue(&q, calls[i])) {
                printf("t = %2d: виклик #%d додано в чергу (у черзі: %d)\n",
                       t, calls[i].id, q.count);
            } else {
                printf("t = %2d: черга переповнена, виклик #%d відхилено\n",
                       t, calls[i].id);
            }
            i++;
        }

        if (!busy && !is_empty(&q)) {
            Call next;
            if (peek_front(&q, &next) && dequeue(&q, &current)) {
                busy = 1;
                free_at = t + current.duration;
                printf("t = %2d: оператор прийняв виклик #%d (до t = %d, у черзі: %d)\n",
                       t, current.id, free_at, q.count);
            }
        }

        if (q.count > max_len) {
            max_len = q.count;
        }
    }

    printf("\nМаксимальна довжина черги: %d\n", max_len);
    printf("Час завершення останнього виклику: %d\n\n", free_at);

    clear_queue(&q);
}

void test_limits(void) {
    Queue q;
    Call tmp;
    init_queue(&q);

    printf("Перевірка граничних умов:\n");

    if (!dequeue(&q, &tmp)) {
        printf("Спроба dequeue з порожньої черги: операцію відхилено\n");
    }

    int added = 0;
    for (int k = 1; k <= MAX_SIZE + 3; k++) {
        Call c = {k, 0, 1};
        if (enqueue(&q, c)) {
            added++;
        } else {
            printf("Переповнення черги: елемент #%d не додано (ліміт %d)\n", k, added);
        }
    }

    if (added == MAX_SIZE + 3) {
        printf("Додано %d елементів без обмеження розміру\n", added);
    }

    dequeue(&q, &tmp);
    dequeue(&q, &tmp);
    Call extra1 = {901, 0, 2};
    Call extra2 = {902, 0, 2};
    if (enqueue(&q, extra1) && enqueue(&q, extra2)) {
        printf("Після звільнення 2 місць додано нові елементи (розмір черги: %d)\n", q.count);
    }

    clear_queue(&q);
}

int main(void) {
    Call calls[] = {
        {1,  0, 5},
        {2,  2, 4},
        {3,  3, 6},
        {4,  4, 2},
        {5,  9, 3},
        {6, 15, 5},
        {7, 25, 4},
        {8, 26, 3}
    };
    int n = sizeof(calls) / sizeof(calls[0]);

    simulate_calls(calls, n);
    test_limits();

    return 0;
}
```

#### Другий спосіб 
```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

typedef struct {
    int id;
    int arrival;
    int duration;
} Call;

typedef struct Node {
    Call data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int count;
} Queue;

void init_queue(Queue *q) {
    q->head = NULL;
    q->tail = NULL;
    q->count = 0;
}

int is_empty(const Queue *q) {
    return q->head == NULL;
}

int is_full(const Queue *q) {
    return q == NULL;
}

int enqueue(Queue *q, Call item) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL) {
        return 0;
    }
    node->data = item;
    node->next = NULL;

    if (is_empty(q)) {
        q->head = node;
        q->tail = node;
    } else {
        q->tail->next = node;
        q->tail = node;
    }
    q->count++;
    return 1;
}

int dequeue(Queue *q, Call *out) {
    if (is_empty(q)) {
        return 0;
    }
    Node *tmp = q->head;
    if (out != NULL) {
        *out = tmp->data;
    }
    q->head = q->head->next;
    if (q->head == NULL) {
        q->tail = NULL;
    }
    free(tmp);
    q->count--;
    return 1;
}

int peek_front(const Queue *q, Call *out) {
    if (is_empty(q)) {
        return 0;
    }
    if (out != NULL) {
        *out = q->head->data;
    }
    return 1;
}

void clear_queue(Queue *q) {
    while (!is_empty(q)) {
        Node *tmp = q->head;
        q->head = q->head->next;
        free(tmp);
    }
    q->tail = NULL;
    q->count = 0;
}

void simulate_calls(const Call calls[], int n) {
    Queue q;
    init_queue(&q);

    int t = 0;
    int i = 0;
    int busy = 0;
    int free_at = 0;
    int max_len = 0;
    Call current = {0, 0, 0};

    printf("Симуляція роботи call-центру:\n");

    while (i < n || !is_empty(&q) || busy) {
        if (busy && i < n) {
            t = (free_at < calls[i].arrival) ? free_at : calls[i].arrival;
        } else if (busy) {
            t = free_at;
        } else {
            t = calls[i].arrival;
        }

        if (busy && t == free_at) {
            printf("t = %2d: завершено виклик #%d\n", t, current.id);
            busy = 0;
        }

        while (i < n && calls[i].arrival == t) {
            if (enqueue(&q, calls[i])) {
                printf("t = %2d: виклик #%d додано в чергу (у черзі: %d)\n",
                       t, calls[i].id, q.count);
            } else {
                printf("t = %2d: черга переповнена, виклик #%d відхилено\n",
                       t, calls[i].id);
            }
            i++;
        }

        if (!busy && !is_empty(&q)) {
            Call next;
            if (peek_front(&q, &next) && dequeue(&q, &current)) {
                busy = 1;
                free_at = t + current.duration;
                printf("t = %2d: оператор прийняв виклик #%d (до t = %d, у черзі: %d)\n",
                       t, current.id, free_at, q.count);
            }
        }

        if (q.count > max_len) {
            max_len = q.count;
        }
    }

    printf("\nМаксимальна довжина черги: %d\n", max_len);
    printf("Час завершення останнього виклику: %d\n\n", free_at);

    clear_queue(&q);
}

void test_limits(void) {
    Queue q;
    Call tmp;
    init_queue(&q);

    printf("Перевірка граничних умов:\n");

    if (!dequeue(&q, &tmp)) {
        printf("Спроба dequeue з порожньої черги: операцію відхилено\n");
    }

    int added = 0;
    for (int k = 1; k <= MAX_SIZE + 3; k++) {
        Call c = {k, 0, 1};
        if (enqueue(&q, c)) {
            added++;
        } else {
            printf("Переповнення черги: елемент #%d не додано (ліміт %d)\n", k, added);
        }
    }

    if (added == MAX_SIZE + 3) {
        printf("Додано %d елементів без обмеження розміру\n", added);
    }

    dequeue(&q, &tmp);
    dequeue(&q, &tmp);
    Call extra1 = {901, 0, 2};
    Call extra2 = {902, 0, 2};
    if (enqueue(&q, extra1) && enqueue(&q, extra2)) {
        printf("Після звільнення 2 місць додано нові елементи (розмір черги: %d)\n", q.count);
    }

    clear_queue(&q);
}

int main(void) {
    Call calls[] = {
        {1,  0, 5},
        {2,  2, 4},
        {3,  3, 6},
        {4,  4, 2},
        {5,  9, 3},
        {6, 15, 5},
        {7, 25, 4},
        {8, 26, 3}
    };
    int n = sizeof(calls) / sizeof(calls[0]);

    simulate_calls(calls, n);
    test_limits();

    return 0;
}
```

---

## Скріншоти тестування обох програм

#### Перший спосіб
<img width="1224" height="640" alt="image" src="https://github.com/user-attachments/assets/1487af6c-7583-4602-93ab-335156030216" />



#### Другий спосіб
<img width="1344" height="614" alt="image" src="https://github.com/user-attachments/assets/6e66a9db-fe82-4650-a556-1d3a421d0b4d" />

---

## Висновок
Перевірив обидві реалізації черги на прикладі з 8 викликів: і кільцевий масив, і однозв'язний список показали однаковий результат (максимум 3 виклики в очікуванні та завершення останнього на 32-й хвилині). При спробі дістати елемент із порожньої черги обидві програми коректно відхиляють операцію без збоїв. Масив одразу резервує місце під 50 елементів і працює по колу за $O(1)$, а список дозволяє додавати скільки завгодно викликів, але витрачає пам'ять на вказівники `next`. Тому масив краще брати, коли заздалегідь відомий максимальний розмір черги, а список, коли кількість викликів невідома.
