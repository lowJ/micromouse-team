def Traverse(maze,mouse):
    pois = []
    mouse.startPos()
    flag = True

    while flag or pois:
        flag = False
        ScanBlock(maze,mouse)
        mouse.moveForward()
        while not wallForward():
            if tickPostion() and not ScanBlock(maze,mouse):
                break
        if mouse.getDistanceMoved() > 15:
            ScanBlock(maze,mouse)
        mouse.setMovement(0)    
        mouse.stop()
        poi = pois.pop()
        goToPoint(poi,maze,mouse)
        
def goToPoint(poi,maze,mouse): #TODO
    pass

def ScanBlock(maze,mouse):
    pos = mouse.position
    
    block = maze.maze[pos[0]][pos[1]]
    if block.mark:
        return False
    block.mark = True

    d = mouse.shiftL[mouse.direction]
    if wallLeft():
         
        block.moves[d] = True
    else:
        move = mouse.moves[d]
        poi.append((pos[0] + move[0],pos[1] + move[1]))

    d = mouse.shiftR[mouse.direction]
    if wallRight():
         
        block.moves[d] = True
    else:
        move = mouse.moves[d]
        poi.append((pos[0] + move[0],pos[1] + move[1]))

    if (pos[0],pos[1]) in poi:
        poi.remove((pos[0],pos[1]))

    return True
