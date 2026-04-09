#include "ns3/core-module.h" 
#include "ns3/network-module.h" 
#include "ns3/internet-module.h" 
#include "ns3/point-to-point-module.h" 
#include "ns3/netanim-module.h" 
 
using namespace ns3; 
 
int main(int argc, char *argv[]) 
{ 
    Time::SetResolution(Time::NS); 
 
    const uint32_t nNodes = 16;     NodeContainer nodes;     nodes.Create(nNodes); 
 
    InternetStackHelper internet;     internet.Install(nodes); 
 
    PointToPointHelper p2p;     p2p.SetDeviceAttribute("DataRate", StringValue("10Mbps"));     p2p.SetChannelAttribute("Delay", StringValue("5ms")); 
 
    // Connect nodes in a ring     for (uint32_t i = 0; i < nNodes; i++) 
    { 
        NodeContainer pair(nodes.Get(i), nodes.Get((i + 1) % nNodes));         p2p.Install(pair); 
    } 
 
    AnimationInterface anim("ring-topology.xml"); 
 
    // Arrange nodes in a circle 
    double radius = 50.0;     for (uint32_t i = 0; i < nNodes; i++) 
    { 
        double angle = 2 * M_PI * i / nNodes;         double x = radius * cos(angle) + 100;         double y = radius * sin(angle) + 100;         anim.SetConstantPosition(nodes.Get(i), x, y); 
    } 
 
    Simulator::Stop(Seconds(10.0)); 
    Simulator::Run();     Simulator::Destroy();     return 0; 
} 