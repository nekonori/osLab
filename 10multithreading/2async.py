from threading import Thread

def m1():
	print("Good morning")
	print("Good morning")
	print("Good morning")

def m2():
	print("Good evening")
	print("Good evening")
	print("Good evening")
	
def m3():
	print("Good night")
	print("Good night")
	print("Good night")
	
print("Multithreading asynchronous")

t1 = Thread(target=m1)
t2 = Thread(target=m2)
t3 = Thread(target=m3)

t1.start()
t2.start()
t3.start()
