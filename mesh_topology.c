#include "ns3/core-module.h" 
#include "ns3/network-module.h" 
#include "ns3/internet-module.h" 
#include "ns3/point-to-point-module.h" 
#include "ns3/netanim-module.h" 
#include <cmath> 
 
using namespace ns3; 
 

int main(int argc, char *argv[]) 
{ 
    Time::SetResolution(Time::NS); 
 
    const uint32_t nNodes = 9;     NodeContainer nodes;     nodes.Create(nNodes); 
 
    InternetStackHelper internet;     internet.Install(nodes); 
 
    PointToPointHelper p2p;     p2p.SetDeviceAttribute("DataRate", StringValue("10Mbps"));     p2p.SetChannelAttribute("Delay", StringValue("2ms")); 
 
    // FULL MESH: connect every node to every other node     for (uint32_t i = 0; i < nNodes; i++) 
    { 
        for (uint32_t j = i + 1; j < nNodes; j++) 
        { 
            NodeContainer pair(nodes.Get(i), nodes.Get(j));             p2p.Install(pair); 
        } 
    } 
 
    AnimationInterface anim("mesh-topology.xml"); 
 
    // Arrange nodes in a grid     uint32_t gridSize = 3;     double spacing = 100.0; 
 
    for (uint32_t i = 0; i < nNodes; i++) 
    { 
        double x = (i % gridSize) * spacing + 100;         double y = (i / gridSize) * spacing + 100;         anim.SetConstantPosition(nodes.Get(i), x, y); 
    } 
 
    Simulator::Stop(Seconds(10.0)); 
    Simulator::Run();     Simulator::Destroy();     return 0; 
} 
