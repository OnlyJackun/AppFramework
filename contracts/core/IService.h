#pragma once
#ifndef ISERVICE_H
#define ISERVICE_H
class IService
{
    public:
        // 自己去ServiceId里找
        virtual char GetName() = 0;
};
#endif