#!/bin/python

from turtle import Screen, Turtle
from random import randint, choice
from functools import partial
from time import sleep

INFECTION_DISTANCE = 30
PERSON_RADIUS = 8
WIDTH, HEIGHT = 500, 500
CURSOR_SIZE = 20

possessed = 0

class Person(Turtle):
    population = []

    def __init__(self):
        super().__init__(shape='circle')

        self.moves_left = 100
        self.shapesize(PERSON_RADIUS / CURSOR_SIZE)
        self.penup()
        self.setpos(randint(-int(WIDTH/2), int(WIDTH/2)), randint(-int(HEIGHT/2), int(HEIGHT/2)))

        Person.population.append(self)

    @classmethod
    def all_infected(cls):
        return [person for person in cls.population if person.infected()]

    def infect(self):
        self.color('red')

    def infected(self):
        return self.pencolor() == 'red'

    def die(self):
        self.color('gray')
        if self in Person.population:
            Person.population.remove(self)

    def dead(self):
        return self.pencolor() == 'gray'

    @classmethod
    def all_healthy(cls):
        return [person for person in cls.population if not person.infected()]

    def possess(self):
        self.color('green')

    def possessed(self):
        return self.pencolor() == 'green'

    def random_move(self):
        if self.moves_left <= 0:
            self.die()
        else:
            if self.infected:
                print(self.moves_left)
            self.right(randint(-90, 90))
            self.forward(randint(0, 10))

        x, y = self.position()

        if not (PERSON_RADIUS - WIDTH/2 < x < WIDTH/2 - PERSON_RADIUS and PERSON_RADIUS - HEIGHT/2 < y < HEIGHT/2 - PERSON_RADIUS):
            self.undo()

def make_population(amount):
    for _ in range(amount):
        Person()

def possess_random():
    possessed = None

    healthy = Person.all_healthy()

    if healthy:
        possessed = choice(healthy)
        possessed.possess()

        screen.onkey(partial(move_up, possessed), 'k')
        screen.onkey(partial(move_down, possessed), 'j')
        screen.onkey(partial(move_right, possessed), 'l')
        screen.onkey(partial(move_left, possessed), 'h')

    return possessed

def infect_random():
    person = None

    healthy = Person.all_healthy()

    if healthy:
        person = choice(healthy)
        person.infect()

    return person

def check_infection(person):
    for infected in Person.all_infected():
        if person.distance(infected) < INFECTION_DISTANCE:
            is_possessed = person.possessed()

            person.infect()

            if is_possessed:
                possess_random()

def simulation(amount, moves, interval):
    make_population(amount)

    infect_random()
    possess_random()
    screen.update()

    for _ in range(moves):
        for person in Person.population:
            if person.infected() and not person.dead():
                person.moves_left = person.moves_left - 1
            if not person.possessed() and not person.dead():
                person.random_move()

            if not person.infected() and not person.dead():
                check_infection(person)

        screen.update()
        sleep(interval)

def move_up(possessed):
    y = possessed.ycor() + 10

    if y < HEIGHT/2 - PERSON_RADIUS:
        possessed.sety(y)
        check_infection(possessed)

def move_down(possessed):
    y = possessed.ycor() - 10

    if y > PERSON_RADIUS - HEIGHT/2:
        possessed.sety(y)
        check_infection(possessed)

def move_right(possessed):
    x = possessed.xcor() + 10

    if x < WIDTH/2 - PERSON_RADIUS:
        possessed.setx(x)
        check_infection(possessed)

def move_left(possessed):
    x = possessed.xcor() - 10

    if x > PERSON_RADIUS - WIDTH/2:
        possessed.setx(x)
        check_infection(possessed)

amount = int(input("Enter amount of people within the area: "))
moves = int(input("Enter the amount of moves these people will do: "))
interval = float(input("Enter refresh rate in seconds: "))

screen = Screen()
screen.bgcolor("white")
screen.title("Virus")
screen.setup(WIDTH, HEIGHT)

virus = Turtle()
virus.hideturtle()
a=0
b=0
virus.speed(0)
virus.pencolor("lightgray")
virus.penup()
virus.goto(0,200)
virus.pendown()
for i in range(197):
    virus.forward(a)
    virus.right(b)
    a+=3
    b+=1

screen.listen()
screen.tracer(False)

simulation(amount, moves, interval)

screen.tracer(True)
screen.exitonclick()
