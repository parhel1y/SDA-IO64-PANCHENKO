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
        {6,
