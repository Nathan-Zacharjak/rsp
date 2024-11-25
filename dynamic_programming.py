import math
import sys

def numTrucksRecursive(numCrates, loadSize):
    if numCrates <= loadSize:
        return 1

    return numTrucksRecursive(math.floor(numCrates/2), loadSize) + numTrucksRecursive(math.ceil(numCrates/2), loadSize)

print(numTrucksRecursive(int(sys.argv[1]), int(sys.argv[2])))

def numTrucksDP(numCrates, loadSize):
    dpArray = [ [0]*(numCrates+1) for _ in range(numCrates+1) ]

    for i in range(numCrates+1):
        dpArray[i][1] = i
        for j in range(i, numCrates+1):
            dpArray[i][j] = 1

    for i in range(2, numCrates+1):
        for j in range(2, i):
            dpArray[i][j] = dpArray[math.floor(i/2)][j] + dpArray[math.ceil(i/2)][j]

    for row in dpArray:
        print(row)

    return dpArray[numCrates][loadSize]


print(numTrucksDP(int(sys.argv[1]), int(sys.argv[2])))


def GetHouseCostArray(houses, houseIndex):
    costString = str(houses[houseIndex])
    costArray = list(map(int, costString.split()))

    return costArray

def RGBRecursiveHelper(houses, houseIndex, lastColour):
    if houseIndex == len(houses):
        return 0

    house = GetHouseCostArray(houses, houseIndex)
    minCost = -1

    for colour, cost in enumerate(house):
        if colour == lastColour:
            continue

        totalCost = RGBRecursiveHelper(houses, houseIndex + 1, colour) + cost
        if minCost == -1 or totalCost < minCost:
            minCost = totalCost

    return minCost

def RGBRecursive(houses):
    houseIndex = 0
    if houseIndex >= len(houses):
        return 0

    house = GetHouseCostArray(houses, houseIndex)
    minCost = -1

    for colour, cost in enumerate(house):
        totalCost = RGBRecursiveHelper(houses, houseIndex + 1, colour) + cost
        if minCost == -1 or totalCost < minCost:
            minCost = totalCost

    return minCost

print(RGBRecursive(["71 39 44", "32 83 55", "51 37 63", "89 29 100", "83 58 11", "65 13 15", "47 25 29", "60 66 19"]))

def RGBDP(houses):
    houseNum = len(houses)
    if houseNum == 0:
        return 0
    elif houseNum == 1:
        return min(GetHouseCostArray(houses, 0))

    lastHouseIndex = houseNum - 1
    house = GetHouseCostArray(houses, lastHouseIndex)

    dpArray = [ [-1]*(3) for _ in range(houseNum) ]

    for colour in range(3):
        lastColourHouse = house.copy()
        lastColourHouse.pop(colour)
        dpArray[lastHouseIndex][colour] = min(lastColourHouse)

    for houseIndex in range(lastHouseIndex - 1, -1, -1):
        house = GetHouseCostArray(houses, houseIndex)

        for lastColour in range(3):
            minCost = -1

            for colour, cost in enumerate(house):
                if colour == lastColour:
                    continue

                totalCost = dpArray[houseIndex + 1][colour] + cost
                if minCost == -1 or totalCost < minCost:
                    minCost = totalCost

            dpArray[houseIndex][lastColour] = minCost

    for row in dpArray:
        print(row)

    return min(dpArray[0])

print(RGBDP(["71 39 44", "32 83 55", "51 37 63", "89 29 100", "83 58 11", "65 13 15", "47 25 29", "60 66 19"]))
