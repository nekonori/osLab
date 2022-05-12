from threading import *
from time import sleep

def m1():
	for i in range(3):
		print("Good morning")
		sleep(2)

def m2():
	for i in range(3):
		print("Good evening")
		
def m3():
	for i in range(3):
		print("Good night")
		
print("Daemon thread")
t1 = Thread(target=m1, daemon=True)
t2 = Thread(target=m2, daemon=True)
t3 = Thread(target=m3, daemon=True)

t1.start()
t2.start()
t3.start()
