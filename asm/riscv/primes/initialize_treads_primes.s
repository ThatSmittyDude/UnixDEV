# Define constants for number of threads and input range size
    .set nthreads, 4
    .set range_size, 1024

# Initialize stack frame for each thread ( dummy values )
    .globl threads
    threads:
        # Thread ID: 0-3
        .quad 0
        # Saved PC (program counter)
        .quad 1
        # Saved RA (return address) - Not used in this example
        # Saved SP (stack pointer)
        .quad 2

# Define thread initialization function
    .globl init_thread
init_thread:
    # Save current thread ID in t0
    mvl s0, t0, threads[t0]   # Load thread ID from memory
    csrw t0, s0               # Store thread ID in register

    # Perform some initial setup here (e.g., allocate shared memory)
    # For now, let's just return with the initial values
    mvl a0, 10                 # Set up dummy result variable
    jalr x0, x1                # Return to main function

# Define main entry point for prime sieve program
main:
    # Initialize input range [start, end]
    .globl start_range
start_range:
    # Input range size: 1024 (example value)
    mvl t1, range_size         # Load range size into register

    # Calculate thread ID based on current address
    # For simplicity, let's use the least significant byte of the PC as the thread ID
    mvl t2, x0                 # Set up dummy PC to get address bits
    andi t2, t2, 255           # Mask out upper bytes ( leave only lower 8 bits )
    csrw t3, t2                # Store thread ID in register

    # Call init_thread function for each worker thread
    mvl t4, nthreads           # Load number of threads into register
loop_threads:
    # Loop through each thread and call init_thread function
    addi t5, x0, 1             # Increment thread counter ( dummy loop )
    csrw x0, t3                # Save current thread ID in x0
    jal init_thread            # Call init_thread function for this thread

    # Wait for all threads to complete (dummy implementation)
    mvl s4, 10000              # Set up dummy sleep time ( example value )
loop_wait:
    addi t5, s4, -1            # Decrement wait counter
    bnez t5, loop_wait         # Continue waiting if not yet done

    # Return to main program
    mvl a0, 0                 # Dummy return value ( example )
    jalr x0, x1                # Return to main function
