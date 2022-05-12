from threading import *

def m1():
	print("Current thread:",current_thread().name)
	print("Good morning")

def m2():
	print("Good evening")
	
def m3():
	print("Good night")
	
print("Finding current thread")

t1 = Thread(target=m1, name="thread1")
t2 = Thread(target=m2, name="thread2")
t3 = Thread(target=m3, name="thread3")

t1.start()
t2.start()
t3.start()
