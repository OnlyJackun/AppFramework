#pragma once
#ifndef IMODULE_H
    #define IMODULE_H

    #include<memory>
    #include<IService.h>
    #include<IServiceRegistry.h>
    // IModule只涵盖对外提供的方法, 自初始化&模版函数由基类实现
    class IModule
    {
        public:
            virtual ~IModule() = default;
            // module生命周期
            virtual void Init() = 0;
            virtual void Shutdown() = 0;
            // 服务
            virtual IServiceRegistry* GetServiceRegistry() = 0;
    };
    
#endif