#include "mPoll.h"
#include <poll.h>
namespace net{
    class pollpoll:public mPOLL{
        public:
            typedef std::vector<struct pollfd> fdList;
            pollpoll(EventLoop*ev):mPOLL(ev),pollfds(){}
            ~pollpoll() override {}
            void update(Channel *ch)override;
            void remove(Channel *ch)override;
            void POLL(int timeout,ChannelList &activeList)override;
            size_t getPollfdSize(){return pollfds.size();}

        private:
            void fillActiveChannelList(int nReady,ChannelList &activeList);
            fdList pollfds;
            
    };
}