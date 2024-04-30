import random
from datetime import datetime
import pandas as pd


class Field:
    def __init__(self, n=0, m=0, per=0):
        self.matrix = None
        self.n = n
        self.m = m
        self.per = per

    def generate(self):
        self.matrix = [[0] * self.m for i in range(self.n)]
        for i in range(len(self.matrix)):
            for j in range(len(self.matrix[i])):
                rand = random.randint(0, 100)
                life_all = int((self.n * self.m * self.per) / 100)
                life_curr=life(self.matrix)
                if (self.per >= rand) and life_all >= life_curr :
                    self.matrix[i][j] = '*'
                else:
                    self.matrix[i][j] = '_'

    def __str__(self):
        format_field = pd.DataFrame(self.matrix)
        return format_field

    def __repr__(self):
        return f'Field(n={self.n}, m={self.m}, per={self.per})'


def empty(a):
    count = 0
    for i in range(len(a)):
        for j in range(len(a[i])):
            if a[i][j] == '_':
                count += 1
    return count


def life(a):
    count = 0
    for i in range(len(a)):
        for j in range(len(a[i])):
            if a[i][j] == '*':
                count += 1
    return count


p = Field(10, 10, 33)
p.generate()
print(f"empty= {empty(p.matrix)}")
print(f"life= {life(p.matrix)}")
print(p.__str__())
print(p.__repr__())
