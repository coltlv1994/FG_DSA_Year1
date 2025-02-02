from enum import Enum


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
route_list.append((Loc.MERCER, Loc.DON_JILA, 2))
route_list.append((Loc.MERCER, Loc.ARMADILLO, 3))
route_list.append((Loc.DON_JILA, Loc.ARMADILLO, 2))
route_list.append((Loc.DON_JILA, Loc.MACFARLANE, 3))
route_list.append((Loc.DON_JILA, Loc.THIEVES, 4))
route_list.append((Loc.ARMADILLO, Loc.MACFARLANE, 3))
route_list.append((Loc.MACFARLANE, Loc.THIEVES, 2))

connection_map = dict()

def build_connection_map(start_loc):
    dict_to_add = dict()
    for road in route_list:
        if road[0] == start_loc:
            dict_to_add[road[1]] = road[2]
        
        if road[1] == start_loc:
            dict_to_add[road[0]] = road[2]
    
    connection_map[start_loc] = dict_to_add

