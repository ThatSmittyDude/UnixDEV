# Define constants for thread local storage (TLS)
    .set TLS_SIZE, 256

# Define helper function to check if a number is prime
prime_check:
    # Input: x0 = number to check
    mvl t1, x0               # Save input number in register
    mvl s2, t1                # Duplicate input number for later use
    csrw s3, s2               # Store duplicate number in shared memory

    # Calculate square root of the input number
    mvl t4, 15               # Load initial estimate of sqrt(x0)
loop_sqrt:
    mvl t5, x0               # Load input number into register
    mulw t6, t5, t4          # Compute (sqrt(x0) * sqrt(x0))
    csrw s7, t6               # Store intermediate result in shared memory

    # Check if square root is exact
    mvl t8, s7                # Load intermediate result into register
    subw t9, x0, t8           # Compute (x0 - sqrt(x0) * sqrt(x0))
    bnez t9, loop_sqrt       # Repeat until square root is exact

    # Initialize divisor check counter
    mvl t10, 2               # Set up initial divisor value
loop_divisor:
    # Check if input number is divisible by current divisor
    mvl s11, x0              # Load input number into register
    subw s12, s11, s3        # Compute (x0 - shared memory value)
    mvl t13, s12             # Duplicate result for later use
    csrw s14, t13             # Store intermediate result in shared memory

    # Check if divisor is greater than input number's square root
    mvl t15, x0              # Load input number into register
    mulw t16, t10, t9        # Compute (divisor * sqrt(x0))
    subw s17, s11, s16       # Compute (x0 - divisor * sqrt(x0))
    bnez s17, loop_divisor   # Repeat until divisor exceeds square root

    # Return 1 if input number is prime
    mvl a0, 1                # Set up return value (1) if prime
    jalr x0, x1               # Return to main function with result
    j exit_prime_check        # Exit early if not prime

# Update thread initialization function to use prime_check helper function
init_thread:
    # Save current thread ID in t0
    mvl s18, t0              # Store thread ID in shared memory
    csrw s19, s18             # Store thread ID in register

    # Perform some initial setup here (e.g., allocate shared memory)
    # For now, let's just return with the initial values
    mvl a0, 10                 # Set up dummy result variable
    jalr x0, x1                # Return to main function

exit_prime_check:
