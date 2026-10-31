#include<contracts/core/IServiceRegistry.h>
#include<contracts/core/IService.h>

#include<memory>
#include<unordered_map>


class ServiceRegistry: public IServiceRegistry
{
    public:
        std::shared_ptr<IService> GetService(char name) final override{
            std::shared_ptr<IService> s = services_.find(name)->second.lock();
            if(!s)
            {
                services_.erase(name);
            }
            return s;
        }

        void RegisterService(std::shared_ptr<IService> s){
            services_[s->GetName()] = s;
        }

    private:
        std::unordered_map<char, std::weak_ptr<IService>> services_;
};