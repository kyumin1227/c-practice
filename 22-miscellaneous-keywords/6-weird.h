#ifndef WEIRED_H
#define WEIRED_H
struct Weird {
    char arr[2];
    int i;
};
#endif

// 중복 선언되는 것을 막기 위해서 선언 여부를 확인, 위와 아래의 역할은 동일하며 아래가 현대식으로 조금 더 빠름

#pragma once
struct Weird {
    char arr[2];
    int i;
};