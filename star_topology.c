#include "ns3/core-module.h" 
#include "ns3/network-module.h" 
#include "ns3/internet-module.h" 
#include "ns3/point-to-point-module.h" 
 
#include "ns3/netanim-module.h" 
 
using namespace ns3; 
 
int main(int argc, char *argv[]) 
{ 
    Time::SetResolution(Time::NS); 
 
    NodeContainer hub;     hub.Create(1); 
 
    NodeContainer spokes;     spokes.Create(15); 
 
    InternetStackHelper internet;     internet.Install(hub);     internet.Install(spokes); 
 
    PointToPointHelper p2p;     p2p.SetDeviceAttribute("DataRate", StringValue("5Mbps"));     p2p.SetChannelAttribute("Delay", StringValue("2ms")); 
 
    for (uint32_t i = 0; i < spokes.GetN(); i++) 
    { 
        NodeContainer pair(hub.Get(0), spokes.Get(i));         p2p.Install(pair); 
    } 
 
    AnimationInterface anim("star-topology.xml");     anim.SetConstantPosition(hub.Get(0), 50, 50); 
 
    for (uint32_t i = 0; i < spokes.GetN(); i++) 
    { 
        anim.SetConstantPosition(spokes.Get(i), 10 * i, 10); 
    } 
 
    Simulator::Stop(Seconds(10.0)); 
    Simulator::Run();     Simulator::Destroy();     return 0; 
} 
