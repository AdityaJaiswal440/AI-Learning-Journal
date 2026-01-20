from concurrent.futures import ProcessPoolExecutor
import time

def print_numbers(number):
    time.sleep(1)
    return f"Number : {number}"

if __name__ == "__main__":
    numbers = [1,2,3,4,5,6,7,8,9]

    t = time.time()

    with ProcessPoolExecutor(max_workers=3) as executor:
        results = executor.map(print_numbers,numbers)
    
    for result in results:
        print(result)
    
    finished_time = time.time() - t
    print(finished_time)