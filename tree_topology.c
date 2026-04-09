#include "ns3/core-module.h" 
#include "ns3/network-module.h" 
#include "ns3/internet-module.h" 
#include "ns3/point-to-point-module.h" 
#include "ns3/netanim-module.h" 
 
using namespace ns3; 
 
int main(int argc, char *argv[]) 
{ 
    Time::SetResolution(Time::NS); 
 
    const uint32_t nNodes = 15;     NodeContainer nodes;     nodes.Create(nNodes); 
 
    InternetStackHelper internet;     internet.Install(nodes); 
 
    PointToPointHelper p2p;     p2p.SetDeviceAttribute("DataRate", StringValue("10Mbps"));     p2p.SetChannelAttribute("Delay", StringValue("2ms")); 
 
    // Tree connections 
    // Level 0 (root): 0 
    // Level 1: 1, 2     // Level 2: 3–6 
    // Level 3: 7–14 
 
    p2p.Install(NodeContainer(nodes.Get(0), nodes.Get(1)));     p2p.Install(NodeContainer(nodes.Get(0), nodes.Get(2))); 
 
    for (uint32_t i = 1; i <= 2; i++) 
    { 
        for (uint32_t j = 1; j <= 2; j++) 
        { 
            uint32_t child = i * 2 + j; 

            p2p.Install(NodeContainer(nodes.Get(i), nodes.Get(child))); 
        } 
    } 
 
    for (uint32_t i = 3; i <= 6; i++) 
    { 
        for (uint32_t j = 1; j <= 2; j++) 
        { 
            uint32_t child = i * 2 + j;             if (child < nNodes)                 p2p.Install(NodeContainer(nodes.Get(i), nodes.Get(child))); 
        } 
    } 
 
    AnimationInterface anim("tree-topology.xml"); 
 
    // Position nodes level-wise     anim.SetConstantPosition(nodes.Get(0), 200, 50); 
 
    anim.SetConstantPosition(nodes.Get(1), 100, 150);     anim.SetConstantPosition(nodes.Get(2), 300, 150); 
 
    double xLevel2[4] = {50, 150, 250, 350};     for (uint32_t i = 3; i <= 6; i++) 
    { 
        anim.SetConstantPosition(nodes.Get(i), xLevel2[i - 3], 250); 
    } 
 
    double xLevel3[8] = {25, 75, 125, 175, 225, 275, 325, 375}; 
    for (uint32_t i = 7; i <= 14; i++) 
    { 
        anim.SetConstantPosition(nodes.Get(i), xLevel3[i - 7], 350); 
    } 
 
    Simulator::Stop(Seconds(10.0)); 
    Simulator::Run();     Simulator::Destroy();     return 0; 
} 
