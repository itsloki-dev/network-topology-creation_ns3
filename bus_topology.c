#include "ns3/core-module.h" 
#include "ns3/network-module.h" 
#include "ns3/internet-module.h" 
#include "ns3/csma-module.h" 
#include "ns3/netanim-module.h" 
 
using namespace ns3; 
 
int main(int argc, char *argv[]) 
{ 
    Time::SetResolution(Time::NS); 
 
    // Create 20 nodes     NodeContainer nodes;     nodes.Create(20); 
 
    // Install Internet stack     InternetStackHelper internet;     internet.Install(nodes); 
 
    // CSMA (Bus) channel     CsmaHelper csma;     csma.SetChannelAttribute("DataRate", StringValue("100Mbps"));     csma.SetChannelAttribute("Delay", TimeValue(MicroSeconds(10))); 
 
    csma.Install(nodes); 
 
    // NetAnim output 
    AnimationInterface anim("bus-topology.xml"); 
 
    // Position nodes in a straight line (bus)     for (uint32_t i = 0; i < nodes.GetN(); i++) 
    { 
        anim.SetConstantPosition(nodes.Get(i), 20 * i, 50); 
    } 

 
    Simulator::Stop(Seconds(10.0)); 
    Simulator::Run();     Simulator::Destroy();     return 0; 
}