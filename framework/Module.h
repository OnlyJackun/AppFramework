#include<contracts/core/IModule.h>
#include<ServiceRegistry.h>

#include<memory>
#include<vector>


class Module: public IModule
{
    public:
        // 由parent调用, 初始化/销毁自身及子节点
        void Init(IServiceRegistry* r) final override{
            OnInit(r);
            auto s = servicesRegistry_.get();
            for(auto &mod : mods_)
            {
                mod->Init(s);
            }
            OnReady();
        }

        void Shutdown() final override{
            for(auto it=mods_.rbegin();it != mods_.rend();++it)
            {
                (*it)->Shutdown();
            }
            OnShutdown();
            mods_.clear();
        }        

        template<typename T, typename...Args>
        T* RegisterModule(Args...args){
            static_assert(std::is_base_of(Module, T))
            auto mod = std::make_unique<T>(std::forwards<Args>(args))
            mod->parent_ = this;
            T* raw = mod.get();
            mods_.push_back(std::move(mod));
            return raw;
        }


        
    protected:
        // 自身的初始化与销毁, 及子节点就绪后的回调
        virtual void OnInit(IServiceRegistry* r) = 0;
        virtual void OnReady() = 0;
        virtual void OnShutdown() = 0;

    private:
        Module* parent = nullptr;
        std::vector<std::unique_ptr<Module>> mods_;
        std::unique_ptr<IServiceRegistry> servicesRegistry_;
};