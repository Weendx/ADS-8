// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

class Train {
 private:
    struct Cage {
        Cage() {
            light = false;
            next = nullptr;
            prev = nullptr;
        }
        bool light; // состояние лампочки
        Cage *next;
        Cage *prev;
    };
    Cage* first; // точка входа в поезд (первый вагон)
    Cage* last; // указатель на последний вагон
    int countOp; // счетчик шагов (число переходов из вагона в вагон)
    int countCages; // счетчик вагонов
    Cage* createCage(const bool& lampState);
 public:
    Train();
    ~Train();
    void addCage(bool light); // добавить вагон с начальным состоянием лампочки
    int getLength();          // вычислить длину поезда
    int getOpCount();         // вернуть число переходов (из вагона в вагон)
};
#endif  // INCLUDE_TRAIN_H_
