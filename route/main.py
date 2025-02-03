import copy
from enum import Enum
from operator import itemgetter

class Loc(Enum):
    COLTER = 1
    ISABELLA = 2
    WAPITI = 3
    BRANDWINE = 4
    BUCCHUS = 5
    OCREAGB = 6
    ANNESBURG = 7
    PRONGHORN = 8
    WALLACE = 9
    VALENTINE = 10
    OIL_FIELD = 11
    EMERALD = 12
    BUTCHER = 13
    VAN_HORN = 14
    OWANJILA = 15
    STRAWBERRY = 16
    RIGGS = 17
    FLATNECK = 18
    HEARTLAND = 19
    LAGRAS = 20
    PRISON = 21
    BEECHER = 22
    BLACKWATER = 23
    RHODES = 24
    ST_DENIS = 25
    COUJAR = 26
    TUMNBLEWEED = 27
    BENEDICT = 28
    MERCER = 29
    DON_JILA = 30
    ARMADILLO = 31
    MACFARLANE = 32
    THIEVES = 33
    DAKOTA = 34
    CALIGA = 35

    def __lt__(self, other):
        return self.value < other.value

class Node:
    def __init__(self, name):
        self.name = name
        self.neighborList = dict()
        self.parent = 0
        self.distance = 100000
    
    def __gt__(self, other):
        return self.distance > other.distance
    
    def __lt__(self, other):
        return self.distance < other.distance
    
    def __eq__(self, other):
        return self.distance == other.distance


route_list = []
route_list.append((Loc.COLTER, Loc.ISABELLA, 2))
route_list.append((Loc.COLTER, Loc.DAKOTA, 4))
route_list.append((Loc.ISABELLA, Loc.DAKOTA, 3))
route_list.append((Loc.ISABELLA, Loc.WALLACE, 4))
route_list.append((Loc.ISABELLA, Loc.PRONGHORN, 4))
route_list.append((Loc.WAPITI, Loc.DAKOTA, 5))
route_list.append((Loc.WAPITI, Loc.BUCCHUS, 1))
route_list.append((Loc.WAPITI, Loc.BRANDWINE, 6))
route_list.append((Loc.BUCCHUS, Loc.DAKOTA, 4))
route_list.append((Loc.BUCCHUS, Loc.OIL_FIELD, 3))
route_list.append((Loc.BUCCHUS, Loc.OCREAGB, 3))
route_list.append((Loc.BRANDWINE, Loc.OCREAGB, 3))
route_list.append((Loc.BRANDWINE, Loc.ANNESBURG, 3))
route_list.append((Loc.OCREAGB, Loc.OIL_FIELD, 5))
route_list.append((Loc.OCREAGB, Loc.ANNESBURG, 4))
route_list.append((Loc.OCREAGB, Loc.BUTCHER, 3))
route_list.append((Loc.ANNESBURG, Loc.VAN_HORN, 2))
route_list.append((Loc.PRONGHORN, Loc.WALLACE, 3))
route_list.append((Loc.PRONGHORN, Loc.OWANJILA, 3))
route_list.append((Loc.WALLACE, Loc.DAKOTA, 3))
route_list.append((Loc.WALLACE, Loc.VALENTINE, 3))
route_list.append((Loc.WALLACE, Loc.RIGGS, 3))
route_list.append((Loc.VALENTINE, Loc.DAKOTA, 2))
route_list.append((Loc.VALENTINE, Loc.OIL_FIELD, 2))
route_list.append((Loc.VALENTINE, Loc.HEARTLAND, 3))
route_list.append((Loc.VALENTINE, Loc.FLATNECK, 3))
route_list.append((Loc.OIL_FIELD, Loc.EMERALD, 3))
route_list.append((Loc.OIL_FIELD, Loc.HEARTLAND, 2))
route_list.append((Loc.EMERALD, Loc.HEARTLAND, 3))
route_list.append((Loc.EMERALD, Loc.CALIGA, 4))
route_list.append((Loc.EMERALD, Loc.LAGRAS, 3))
route_list.append((Loc.EMERALD, Loc.BUTCHER, 4))
route_list.append((Loc.BUTCHER, Loc.VAN_HORN, 1))
route_list.append((Loc.VAN_HORN, Loc.PRISON, 4))
route_list.append((Loc.VAN_HORN, Loc.ST_DENIS, 5))
route_list.append((Loc.OWANJILA, Loc.STRAWBERRY, 1))
route_list.append((Loc.OWANJILA, Loc.BEECHER, 3))
route_list.append((Loc.OWANJILA, Loc.MACFARLANE, 4))
route_list.append((Loc.STRAWBERRY, Loc.RIGGS, 2))
route_list.append((Loc.STRAWBERRY, Loc.BEECHER, 3))
route_list.append((Loc.RIGGS, Loc.FLATNECK, 2))
route_list.append((Loc.RIGGS, Loc.BLACKWATER, 2))
route_list.append((Loc.FLATNECK, Loc.HEARTLAND, 3))
route_list.append((Loc.FLATNECK, Loc.RHODES, 5))
route_list.append((Loc.HEARTLAND, Loc.RHODES, 4))
route_list.append((Loc.LAGRAS, Loc.CALIGA, 2))
route_list.append((Loc.LAGRAS, Loc.ST_DENIS, 3))
route_list.append((Loc.PRISON, Loc.ST_DENIS, 3))
route_list.append((Loc.BEECHER, Loc.BLACKWATER, 1))
route_list.append((Loc.BEECHER, Loc.MACFARLANE, 3))
route_list.append((Loc.BLACKWATER, Loc.RHODES, 6))
route_list.append((Loc.BLACKWATER, Loc.THIEVES, 3))
route_list.append((Loc.RHODES, Loc.ST_DENIS, 4))
route_list.append((Loc.RHODES, Loc.CALIGA, 2))
route_list.append((Loc.ST_DENIS, Loc.CALIGA, 2))
route_list.append((Loc.ST_DENIS, Loc.THIEVES, 8))
route_list.append((Loc.COUJAR, Loc.TUMNBLEWEED, 2))
route_list.append((Loc.COUJAR, Loc.BENEDICT, 2))
route_list.append((Loc.TUMNBLEWEED, Loc.BENEDICT, 3))
route_list.append((Loc.TUMNBLEWEED, Loc.MERCER, 4))
route_list.append((Loc.BENEDICT, Loc.MERCER, 3))
route_list.append((Loc.BENEDICT, Loc.DON_JILA, 4))
route_list.append((Loc.MERCER, Loc.DON_JILA, 2))
route_list.append((Loc.MERCER, Loc.ARMADILLO, 3))
route_list.append((Loc.DON_JILA, Loc.ARMADILLO, 2))
route_list.append((Loc.DON_JILA, Loc.MACFARLANE, 3))
route_list.append((Loc.DON_JILA, Loc.THIEVES, 4))
route_list.append((Loc.ARMADILLO, Loc.MACFARLANE, 3))
route_list.append((Loc.MACFARLANE, Loc.THIEVES, 2))

all_loc = []
for loc in Loc:
    all_loc.append(loc)

minimum_distance = dict()
game_map = dict()
for loc in Loc:
    game_map[loc] = Node(loc)

# construct node's neighbor information
for road in route_list:
    game_map[road[0]].neighborList[road[1]] = road[2]
    game_map[road[1]].neighborList[road[0]] = road[2]

def BuildMinimumDistance():
    for loc in Loc:
        minimum_distance[loc] = dict()

def Dijkstra(src):
    # make a copy of game map
    visited_nodes = set()
    distance_map = dict()

    for key, value in game_map.items():
        distance_map[key] = value.distance
    distance_map[src] = 0

    # for key, value in cost_map:
    #     value.parent = 0
    #     value.distance = 100000

    # start from farther map
    for dst in reversed(Loc):
        if dst == src:
            # don't have to go through src node
            continue

        if dst in minimum_distance[src]:
            # a path is constructed already
            continue

        distance_map_copy = copy.deepcopy(distance_map)
        game_map_copy = copy.deepcopy(game_map)
        game_map_copy[src].distance = 0

        # now we found a destination without shortest path
        # make a copy of cost map
        while len(distance_map_copy) != 0:
            visited_nodes.clear()
            current_node = min(distance_map_copy, key=distance_map_copy.get)
            if current_node == dst:
                break

            for key, value in game_map_copy[current_node].neighborList.items():
                # go through all neighbors
                if (key not in visited_nodes) and (game_map_copy[current_node].distance + value < game_map_copy[key].distance):
                    game_map_copy[key].distance = game_map_copy[current_node].distance + value
                    game_map_copy[key].parent = current_node
                    distance_map_copy[key] = game_map_copy[key].distance
            
            visited_nodes.add(current_node)
            del distance_map_copy[current_node]
        
        path = []
        tail = dst

        while tail != 0:
            path.append(tail)
            tail = game_map_copy[tail].parent
        
        if src == Loc.BRANDWINE and dst == Loc.BENEDICT:
            print(path)
        
        for node in path:
            if (node != src):
                (minimum_distance[src])[node] = game_map_copy[node].distance
                (minimum_distance[node])[src] = game_map_copy[node].distance


BuildMinimumDistance()
for loc in Loc:
    Dijkstra(loc)

ticket_list = []

for src, dstList in minimum_distance.items():
    for dst, distance in dstList.items():
        if src < dst and dst not in game_map[src].neighborList:
            ticket_list.append((src, dst, distance))

# sort by distance
ticket_list.sort(key=itemgetter(2))

file_to_write = open("ticket_rdr2.csv", "w")

file_to_write.write("station1,station2,cost\n")

for (src, dst, distance) in ticket_list:
    file_to_write.write(f"{src.name},{dst.name},{distance}\n")

file_to_write.close()

print("\n")