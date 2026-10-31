#pragma once
#ifndef IMODULE_H
#define IMODULE_H
#include<IServiceRegistry.h>
// IModule只负责跨DLL加载模块时parent调用的方法的链接地址, 其余服务&自初始化等方法归Module负责
class IModule
{
    public:
        virtual ~IModule() = default;
        virtual void Init(IServiceRegistry* r) = 0;
        virtual void Shutdown() = 0;
};
#endif