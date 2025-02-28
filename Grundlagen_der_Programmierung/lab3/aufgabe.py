import turtle
t=turtle.Turtle()
#RECHTECK
def rechteck():
     t.penup()
     t.goto(-100,-30)
     t.pendown()
     t.color("black","green")
     t.begin_fill()
     for i in range(3):
         t.forward(200)
         t.left(90)
         t.forward(100)
         t.left(90)
     t.end_fill()
     t.penup()
     t.goto(29,32)
     t.pendown()
     t.color("black","purple")
     t.begin_fill()
     for i in range(3):
         t.forward(50)
         t.left(90)
         t.forward(25)
         t.left(90)
     t.end_fill()





#HERZ
def herz():
    t.penup()
    t.goto(0,-100)
    t.pendown()
    t.color("red","dark red")
    t.begin_fill()
    t.left(50)
    t.forward(200)
    t.circle(75,200)
    t.right(140)
    t.circle(75,200)
    t.forward(200)
    t.end_fill()




#Hauser
def hauser():
    #haus1
    t.penup()
    t.goto(-300, -130)
    t.pendown()
    t.color("black", "orange")
    t.begin_fill()
    for i in range(4):
        t.forward(200)
        t.left(90)
    t.end_fill()

    #dach
    t.penup()
    t.goto(-313, 70)
    t.pendown()
    t.color( "black","brown")
    t.begin_fill()
    for i in range(3):
        t.forward(225)
        t.left(120)
    t.end_fill()

    #fenster
    t.penup()
    t.goto(-230,100)
    t.pendown()
    t.color("black","skyblue")
    t.begin_fill()
    for i in range(5):
        t.forward(60)
        t.left(120)
    t.end_fill()


    #tur
    t.penup()
    t.goto(-260,-128)
    t.pendown()
    t.color("black","red")
    t.begin_fill()
    for i in range(2):
         t.left(120)
         t.forward(120)
    t.end_fill()

    #clanta
    t.penup()
    t.goto(-218,-80)
    t.pendown()
    t.color("black","dark red")
    t.begin_fill()
    t.circle(5)
    t.end_fill()

    #chimney
    t.penup()
    t.goto(-134,150)
    t.pendown()
    t.color('black','firebrick')
    t.begin_fill()
    t.right(32)
    t.forward(80)
    t.left(90)
    t.forward(50)
    t.end_fill()


    #haus2
    t.penup()
    t.goto(270, -135)
    t.pendown()
    t.color("black","grey")
    t.begin_fill()
    t.left(2)
    for i in range(4):
         t.forward(200)
         t.right(90)
    t.end_fill()

    #dach
    t.penup()
    t.goto(280, 65)
    t.pendown()
    t.color("black","brown")
    t.begin_fill()

    for i in range(3):
          t.forward(225)
          t.right(120)
    t.end_fill()

    #chimney
    t.penup()
    t.goto(231,150)
    t.pendown()
    t.color('black','firebrick')
    t.begin_fill()
    t.right(90)
    t.forward(80)
    t.left(90)
    t.forward(48)
    t.end_fill()

    #fenster1
    t.penup()
    t.goto(253,-10)
    t.pendown()
    t.color("black","skyblue")
    t.begin_fill()
    for i in range(3):
        t.forward(60)
        t.right(120)
    t.end_fill()

    #fesnster2
    t.penup()
    t.goto(150,-10)
    t.pendown()
    t.color("black","skyblue")
    t.begin_fill()
    for i in range(3):
        t.forward(60)
        t.right(120)
    t.end_fill()

    #tur
    t.penup()
    t.goto(223,-135)
    t.pendown()
    t.color("black","dark blue")
    t.begin_fill()
    for i in range(3):
        t.forward(100)
        t.right(120)
    t.end_fill()

    #clanta
    t.penup()
    t.goto(150,-97)
    t.pendown()
    t.color("black")
    t.begin_fill()
    t.circle(5)
    t.end_fill()





def menu():
    return '''
        1--Rechteck
        2--Herz
        3--Hauser    

    '''


def main():
     import turtle

     print(menu())
     opt = int(input("opt= "))
     if opt == 1:
       print(rechteck())
       turtle.done()
     if opt == 2:
        print(herz())
        turtle.done()
     if opt == 3:
        print(hauser())
        turtle.done()
main()