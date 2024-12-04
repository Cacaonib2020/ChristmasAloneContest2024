import os
import random

def generate_random_input(max_n=200000, max_q=200000, max_time=10**18):
    """
    Generate random input for the problem.
    Args:
        max_n (int): Maximum number of couples (N).
        max_q (int): Maximum number of queries (Q).
        max_time (int): Maximum possible value for time.
    
    Returns:
        str: The generated input as a single string.
    """
    # Random number of couples (N) and queries (Q)
    N = random.randint(1, max_n)
    Q = random.randint(1, max_q)
    
    # Generate random events for couples
    events = []
    for _ in range(N):
        T_in = random.randint(0, max_time - 1)
        T_out = random.randint(T_in + 1, max_time)
        events.append((T_in, T_out))
    
    # Generate unique query times
    query_times = set()
    while len(query_times) < Q:
        T_j = random.randint(0, max_time)
        # Ensure T_j is not equal to any T_in or T_out
        if all(T_j != T_in and T_j != T_out for T_in, T_out in events):
            query_times.add(T_j)
    # query_times = sorted(query_times)  # Sort for easier debugging
    
    # Create input as a string
    input_data = []
    input_data.append(f"{N}")
    for T_in, T_out in events:
        input_data.append(f"{T_in} {T_out}")
    input_data.append(f"{Q}")
    for T_j in query_times:
        input_data.append(f"{T_j}")
    
    return "\n".join(input_data)

def save_test_cases(case_count=35, startnum=0,output_dir="./in", max_n=200000, max_q=200000, max_time=10**18):
    """
    Generate and save multiple test cases to files.
    Args:
        case_count (int): Number of test cases to generate.
        output_dir (str): Directory to save the test cases.
        max_n (int): Maximum number of couples (N) for each test case.
        max_q (int): Maximum number of queries (Q) for each test case.
        max_time (int): Maximum possible value for time.
    """
    # Ensure the output directory exists
    os.makedirs(output_dir, exist_ok=True)
    
    for i in range(0, case_count + 0):
        # Generate test case
        test_case = generate_random_input(max_n=max_n, max_q=max_q, max_time=max_time)
        # Save to file
        file_path = os.path.join(output_dir, f"testcase-{(i+startnum):02d}.txt")
        with open(file_path, "w") as f:
            f.write(test_case)
        print(f"Generated {file_path}")

# Generate and save test cases
if __name__ == "__main__":
    save_test_cases(case_count=7, startnum=21,output_dir="./in", max_n=2*10**5, max_q=2*10**5, max_time=10**18)  # Small-scale example
