# NS-3 Network Topology Simulations

This repository contains implementations of five different network topologies using the NS-3 network simulator. Each topology is designed and visualized using NetAnim.

## Topologies Implemented

### 1. Bus Topology
- 20 nodes connected using a CSMA channel
- All nodes share a common communication medium
- Nodes are arranged in a straight line for visualization

### 2. Mesh Topology
- 9 nodes connected in a full mesh
- Every node is connected to every other node using point-to-point links
- Nodes are arranged in a grid layout

### 3. Ring Topology
- 16 nodes connected in a circular manner
- Each node connects to exactly two neighbors
- Nodes are positioned in a circular layout

### 4. Star Topology
- 1 central hub node and 15 spoke nodes
- Each spoke node is connected directly to the hub
- Hub is placed at the center, spokes arranged around it

### 5. Tree Topology
- 15 nodes arranged hierarchically
- Multi-level parent-child structure
- Nodes are positioned level-wise to represent hierarchy

## Implementation Details

- All topologies are implemented using NS-3 C++ modules
- Internet stack is installed on all nodes
- Communication links use either:
  - CSMA (for bus topology)
  - Point-to-point connections (for others)
- Simulation time is set to 10 seconds for all cases
- Node positions are explicitly assigned for clear visualization

## Output

Each simulation generates a NetAnim XML file:

- `bus-topology.xml`
- `mesh-topology.xml`
- `ring-topology.xml`
- `star-topology.xml`
- `tree-topology.xml`

These files can be opened in NetAnim to visualize the network structure.

## Files

- `bus_topology.c`
- `mesh_topology.c`
- `ring_topology.c`
- `star_topology.c`
- `tree_topology.c`
