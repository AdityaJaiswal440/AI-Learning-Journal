
import multiprocessing
import time

def square_numbers():
    for i in range(5):
        time.sleep(1.5)
        print(f"Square : {i**2}")
        
def cube_numbers():
    for i in range(5):
        time.sleep(5)
        print(f"Cube : {i**3}")

if __name__ == "__main__":
    p1 = multiprocessing.Process(target=square_numbers)
    p2 = multiprocessing.Process(target=cube_numbers)
    t = time.time()

    p1.start()
    p2.start()

    p1.join()
    p2.join()
    
    finished_time = time.time() - t
    print(finished_time)