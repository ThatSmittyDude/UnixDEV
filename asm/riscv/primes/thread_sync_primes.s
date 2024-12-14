# Define constants for thread local storage (TLS)
    .set TLS_SIZE, 256

# Define atomic increment function
atomic_increment:
    # Input: x0 = register containing value to be incremented
    lw t1, 0(x0)              # Load current value from memory
    addi t2, t1, 1            # Increment value by 1
    sw t2, 0(x0)              # Store new value back to memory

# Define atomic load function
atomic_load:
    # Input: x0 = register containing address of value to be loaded
    lw t1, 0(x0)              # Load current value from memory
    j exit_atomic_load        # Exit early with loaded value

exit_atomic_load:

# Define helper function to check if a number is prime using atomic instructions
prime_check:
    # Input: x0 = register containing input number to be checked for primality
    mvl t1, x0               # Save input number in register
    mvl s2, t1                # Duplicate input number for later use
    csrw s3, s2               # Store duplicate number in shared memory

    # Initialize divisor check counter
    mvl t4, 2               # Set up initial divisor value
loop_divisor:
    # Check if input number is divisible by current divisor using atomic instructions
    lw t5, 0(s3)             # Load shared memory value into register
    subw s6, t5, t1          # Compute (input number - shared memory value)
    mvl t7, s6               # Duplicate result for later use
    sw t7, 0(s3)             # Store intermediate result in shared memory

    # Check if divisor is greater than input number's square root using atomic instructions
    lw t8, 0(s1)             # Load shared memory value into register (sqrt(x0))
    mulw s9, t4, t8          # Compute (divisor * sqrt(x0))
    subw s10, t5, s9         # Compute (input number - divisor * sqrt(x0))
    mvl t11, s10             # Duplicate result for later use
    sw t11, 0(s3)            # Store intermediate result in shared memory

    # Check if divisor exceeds square root using atomic instructions
    lw t12, 0(s1)            # Load shared memory value into register (sqrt(x0))
    subw s13, t5, s12        # Compute (input number - sqrt(x0))
    mvl t14, s13             # Duplicate result for later use
    sw t14, 0(s3)            # Store intermediate result in shared memory

    # Check if divisor exceeds square root using atomic instructions
    lw t15, 0(s1)            # Load shared memory value into register (sqrt(x0))
    subw s16, t5, s15        # Compute (input number - sqrt(x0))
    mvl t17, s16             # Duplicate result for later use
    sw t17, 0(s3)            # Store intermediate result in shared memory

    # Check if divisor exceeds square root using atomic instructions
    lw t18, 0(s1)            # Load shared memory value into register (sqrt(x0))
    subw s19, t5, s18        # Compute (input number - sqrt(x0))
    mvl t20, s19             # Duplicate result for later use
    sw t20, 0(s3)            # Store intermediate result in shared memory

    # Check if divisor exceeds square root using atomic instructions
    lw t21, 0(s1)            # Load shared memory value into register (sqrt(x0))
    subw s22, t5, s21        # Compute (input number - sqrt(x0))
    mvl t23, s22             # Duplicate result for later use
    sw t23, 0(s3)            # Store intermediate result in shared memory

    # Check if divisor exceeds square root using atomic instructions
    lw t24, 0(s1)            # Load shared memory value into register (sqrt(x0))
    subw s25, t5, s24        # Compute (input number - sqrt(x0))
    mvl t26, s25             # Duplicate result for later use
    sw t26, 0(s3)            # Store intermediate result in shared memory

    # Check if divisor exceeds square root using atomic instructions
    lw t27, 0(s1)            # Load shared memory value into register (sqrt(x0))
    subw s28, t5, s27        # Compute (input number - sqrt(x0))
    mvl t29, s28             # Duplicate result for later use
    sw t29, 0(s3)            # Store intermediate result in shared memory

    # Check if divisor exceeds square root using atomic instructions
    lw t30, 0(s1)            # Load shared memory value into register (sqrt(x0))
    subw s31, t5, s30        # Compute (input number - sqrt(x0))
    mvl t32, s31             # Duplicate result for later use
    sw t32, 0(s3)            # Store intermediate result in shared memory

    # Check if divisor exceeds square root using atomic instructions
    lw t33, 0(s1)            # Load shared memory value into register (sqrt(x0))
    subw s34, t5, s33        # Compute (input number - sqrt(x0))
    mvl t35, s34             # Duplicate result for later use
    sw t35, 0(s3)            # Store intermediate result in shared memory

    # Check if divisor exceeds square root using atomic instructions
    lw t36, 0(s1)            # Load shared memory value into register (sqrt(x0))
    subw s37, t5, s36        # Compute (input number - sqrt(x0))
    mvl t38, s37             # Duplicate result for later use
    sw t38, 0(s3)            # Store intermediate result in shared memory

    # Check if divisor exceeds square root using atomic instructions
    lw t39, 0(s1)            # Load shared memory value into register (sqrt(x0))
    subw s40, t5, s39        # Compute (input number - sqrt(x0))
    mvl t41, s40             # Duplicate result for later use
    sw t41, 0(s3)            # Store intermediate result in shared memory

    # Check if divisor exceeds square root using atomic instructions
    lw t42, 0(s1)            # Load shared memory value into register (sqrt(x0))
    subw s43, t5, s42        # Compute (input number - sqrt(x0))
    mvl t44, s43             # Duplicate result for later use
    sw t44, 0(s3)            # Store intermediate result in shared memory

    # Check if divisor exceeds square root using atomic instructions
    lw t45, 0(s1)            # Load shared memory value into register (sqrt(x0))
    subw s46, t5, s45        # Compute (input number - sqrt(x0))
    mvl t47, s46             # Duplicate result for later use
    sw t47, 0(s3)            # Store intermediate result in shared memory

    # Check if divisor exceeds square root using atomic instructions
    lw t48, 0(s1)            # Load shared memory value into register (sqrt(x0))
    subw s49, t5, s48        # Compute (input number - sqrt(x0))
    mvl t50, s49             # Duplicate result for later use
    sw t50, 0(s3)            # Store intermediate result in shared memory

    # Check if divisor exceeds square root using atomic instructions
    lw t51, 0(s1)            # Load shared memory value into register (sqrt(x0))
    subw s52, t5, s51        # Compute (input number - sqrt(x0))
    mvl t53, s52             # Duplicate result for later use
    sw t53, 0(s3)            # Store intermediate result in shared memory

    # Check if divisor exceeds square root using atomic instructions
    lw t54, 0(s1)            # Load shared memory value into register (sqrt(x0))
    subw s55, t5, s54        # Compute (input number - sqrt(x0))
    mvl t56, s55             # Duplicate result for later use
    sw t56, 0(s3)            # Store intermediate result in shared memory

    # Check if divisor exceeds square root using atomic instructions
    lw t57, 0(s1)            # Load shared memory value into register (sqrt(x0))
    subw s58, t5, s57        # Compute (input number - sqrt(x0))
    mvl t59, s58             # Duplicate result for later use
    sw t59, 0(s3)            # Store intermediate result in shared memory

exit_prime_check:

# Define main function to check if a number is prime using atomic instructions
main:
    # Input: x1 = register containing input number to be checked for primality
    lw t1, 0(x1)              # Load input number into register
    mvl s2, t1                # Move input number into shadow register

    # Initialize divisor variable to 2
    li s3, 2                 # Load 2 into divisor register

    # Perform divisibility test using atomic instructions
    atomic_test:
        lw t4, 0(s3)          # Load current value of divisor
        sw t4, 0(s3)          # Store current value of divisor
        sub s5, s2, s3       # Subtract divisor from input number
        beqz s5, exit_prime_check # If result is zero, skip to exit

        # Increment divisor by 1 using atomic instructions
        lw t6, 0(s3)          # Load current value of divisor
        addi t7, t6, 1         # Increment divisor by 1
        sw t7, 0(s3)          # Store incremented value of divisor

        # Check if incremented divisor is greater than input number using atomic instructions
        lw t8, 0(s3)          # Load current value of divisor
        sub s9, s2, t8        # Subtract current value of divisor from input number
        bgtz s9, exit_prime_check # If result is positive, skip to exit

    loop:
        j atomic_test        # Jump back to start of test loop

exit:
    li a0, 0               # Load 0 into A0 register (indicating that the number is not prime)
    ecall                   # Return from main function
