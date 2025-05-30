from time import sleep
def foo():
    sleep(0.1)


for i in range(0,100):
    p = 0
    print("numero",i)
    foo()
    if i > 50:
        print(p)


