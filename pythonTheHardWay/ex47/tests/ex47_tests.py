from nose import *
from ex47.game import Room

def testRoom():
    gold = Room("GoldRoom",
            """This room has gold in it you can grab. There's a 
            door to the north.""")
    assert_equal(gold.name, "GoldName")
    assert_equal(gold.paths, {})

def testRoomPaths():
    center = Room("Center", "Test room in the center.")
    north = Room("North", "Test room in the north.")
    south = Room("South", "Test room in the south.")

    center.addPaths({'north' : north, 'south' : south})

    assert_equal(center.go('north'), north)
    assert_equal(center.go('south'), south)

def testMap():
    start = Room("Start", "You can go west and down a hole.")
    west = Room("Trees", "There are trees here you can go east.")
    down = Room("Dungeon", "It's dark down here, you can go up.")

    start.addPaths({'west' : west, 'down' : down})
    west.addPaths({'east' : start})
    down.addPaths({'up' : start})

    assert_equal(start.go('west'), west)
    assert_equal(start.go('west').go('east'), start)
    assert_equal(start.go('down').go('up'), start)
    
