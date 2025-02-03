from datatype import *

route_list = CreateRoute()

game_map, minimum_distance = ConstructGameMap(route_list)

ticket_list = FindShortestPath(game_map, minimum_distance)

file_to_write = open("ticket_rdr2.csv", "w")

file_to_write.write("station1,station2,cost\n")

for (src, dst, distance) in ticket_list:
    file_to_write.write(f"{src.name},{dst.name},{distance}\n")

file_to_write.close()

print("\n")