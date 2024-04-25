total_resources = [7, 2, 6]
available = [7, 2, 6]
allocation = [[0, 1, 0], [2, 0, 0], [3, 0, 3], [2, 1, 1], [0, 0, 2]]
request = [0, 0, 1]

# Calculate maximum demand based on the provided formulas
max_demand = [[allocation[i][j] + request[j] for j in range(3)] for i in range(5)]

# Calculating need
need = [[max_demand[i][j] - allocation[i][j] for j in range(3)] for i in range(5)]

def print_state():
    print("Allocation:", allocation)
    print("Need:", need)
    print("Available:", available)

def request_resources(thread_id, request):
    global available
    print(f"\nThread {thread_id} requesting: {request}")
    for i in range(3):
        if request[i] > need[thread_id][i]:
            print("Error: Exceeding maximum claim.")
            return False
        if request[i] > available[i]:
            print("Resources not available.")
            return False

    for i in range(3):
        available[i] -= request[i]
        allocation[thread_id][i] += request[i]
        need[thread_id][i] -= request[i]

    if not check_safety():
        print("Unsafe state detected. Rolling back.")
        for i in range(3):
            available[i] += request[i]
            allocation[thread_id][i] -= request[i]
            need[thread_id][i] += request[i]
        return False
    print("Request granted.")
    return True

def check_safety():
    work = available[:]
    finish = [False] * 5
    safe_sequence = []

    while len(safe_sequence) < 5:
        made_progress = False
        for i in range(5):
            if not finish[i] and all(need[i][j] <= work[j] for j in range(3)):
                for j in range(3):
                    work[j] += allocation[i][j]
                finish[i] = True
                safe_sequence.append(f"T{i}")
                made_progress = True
                break
        if not made_progress:
            return False
    print("System is in a safe state.")
    print("Safe sequence:", " -> ".join(safe_sequence))
    return True

def run_menu():
    while True:
        print("\nChoose the algorithm:")
        print("1. Banker's Algorithm")
        print("2. Detection Algorithm")
        print("3. Exit")
        choice = input("Enter your choice (1/2/3): ")

        if choice == "1":
            banker_algorithm()
        elif choice == "2":
            detection_algorithm()
        elif choice == "3":
            print("Exiting...")
            break
        else:
            print("Invalid choice. Please choose again.")

def banker_algorithm():
    print("\nBanker's Algorithm")
    if check_safety():
        print("System is in a safe state using Banker's Algorithm.")
    else:
        print("System is in an unsafe state using Banker's Algorithm.")

def detection_algorithm():
    print("\nDetection Algorithm")
    if check_safety():
        print("System is in a safe state using Detection Algorithm.")
    else:
        print("System is in an unsafe state using Detection Algorithm.")

if __name__ == "__main__":
    print("Initial state:")
    print_state()

    run_menu()

    print("\nFinal state:")
    print_state()
