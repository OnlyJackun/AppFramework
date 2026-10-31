#pragma once
#ifndef ISERVICEREGISTRY_H
#define ISERVICEREGISTRY_H
#include<IService.h>
#include<memory>
class IServiceRegistry
{
    public:
        // virtual void RegisterService(IService* s) = 0;
        // 注册服务需用模版, 由基类实现
        virtual std::shared_ptr<IService> GetService(char name) = 0;
};
#endif