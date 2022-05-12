from threading import Thread

def welcome():
	print("Welcome")

print("Single thread")
t1 = Thread(target=welcome, name="Thread 1")
t1.start()
