import numpy as np
import matplotlib.pyplot as plt
import random

def polynomial_function(x, coefficients):
    """Evaluate a polynomial function at x with given coefficients."""
    return sum(coef * (x ** (len(coefficients) - 1 - i)) for i, coef in enumerate(coefficients))

def find_initial_interval(f, max_attempts=1000, search_range=10):
    """Find an initial interval [a, b] where f(a) * f(b) < 0 using random probing."""
    for _ in range(max_attempts):
        a = random.uniform(-search_range, search_range)
        b = random.uniform(a, a + search_range/5)  
        
        fa = f(a)
        fb = f(b)
        
        if fa * fb < 0:
            return a, b, fa, fb
        
    return find_initial_interval(f, max_attempts, search_range * 2)

def bisection_method(f, a, b, fa, fb, tol=1e-6, max_iter=100):
    """
    Bisection method to find root of function f in interval [a, b].
    Returns:
        - The approximate root
        - Array of all iterations data [a, b, c, f(c)]
    """
    if fa * fb >= 0:
        raise ValueError("Function must have opposite signs at interval endpoints")
    
    # Initialize array to store all iterations
    iterations = np.zeros((max_iter, 4))  # [a, b, c, f(c)]
    
    for i in range(max_iter):
        c = (a + b) / 2  # Midpoint
        fc = f(c)
        
        # Store iteration data
        iterations[i] = [a, b, c, fc]
        
        # Check if we've found the root or reached desired tolerance
        if abs(fc) < tol or (b - a) / 2 < tol:
            # Trim unused rows in iterations array
            return c, iterations[:i+1]
        
        # Update interval
        if fa * fc < 0:
            b, fb = c, fc
        else:
            a, fa = c, fc
            
    # Return the best approximation so far
    return c, iterations[:max_iter]

def plot_bisection_process(f, iterations, polynomial_coeffs):
    """Visualize the bisection method process."""
    # Extract data from iterations
    a_values = iterations[:, 0]
    b_values = iterations[:, 1]
    c_values = iterations[:, 2]
    fc_values = iterations[:, 3]
    
    # Create figure with two subplots
    fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(10, 10))
    
    # Plot 1: Function and root approximations
    x_range = max(b_values[0] - a_values[0], 5)
    x = np.linspace(min(a_values[0], c_values[-1]) - x_range/3, 
                  max(b_values[0], c_values[-1]) + x_range/3, 1000)
    y = np.array([f(xi) for xi in x])
    
    ax1.plot(x, y, 'b-', label='f(x)')
    ax1.axhline(y=0, color='k', linestyle='-', alpha=0.3)
    
    # Plot midpoints progression
    for i, c in enumerate(c_values):
        alpha = 0.2 + 0.8 * (i / len(c_values)) if i < len(c_values) - 1 else 1.0
        ax1.plot(c, f(c), 'ro', alpha=alpha, markersize=4)
    
    ax1.plot(c_values[-1], f(c_values[-1]), 'go', markersize=8, label='Final approximation')
    ax1.set_title('Function and Root Approximations')
    
    # Format polynomial for display
    poly_str = "f(x) = "
    degree = len(polynomial_coeffs) - 1
    for i, coef in enumerate(polynomial_coeffs):
        power = degree - i
        if coef != 0:
            if i > 0 and coef > 0:
                poly_str += " + "
            elif coef < 0:
                poly_str += " - "
                coef = abs(coef)
            
            if power == 0:
                poly_str += f"{coef}"
            elif power == 1:
                poly_str += f"{coef}x"
            else:
                poly_str += f"{coef}x^{power}"
    ax1.set_xlabel(f'x\n{poly_str}')
    ax1.set_ylabel('f(x)')
    ax1.grid(True)
    ax1.legend()
    
    # Plot 2: Convergence of the interval
    iterations_nums = np.arange(1, len(iterations) + 1)
    
    ax2.plot(iterations_nums, a_values, 'b-', label='a values')
    ax2.plot(iterations_nums, b_values, 'r-', label='b values')
    ax2.plot(iterations_nums, c_values, 'g-', label='midpoint values')
    
    ax2.set_title('Interval Convergence and Residual')
    ax2.set_xlabel('Iteration')
    ax2.set_ylabel('Value')
    ax2.grid(True)
    ax2.legend(loc='upper left')
    
    # Residual plot on secondary y-axis
    ax3 = ax2.twinx()
    ax3.semilogy(iterations_nums, np.abs(fc_values), 'm--', label='|f(c)|')
    ax3.set_ylabel('Absolute Residual', color='m')
    ax3.tick_params(axis='y', labelcolor='m')
    ax3.legend(loc='upper right')
    
    plt.tight_layout()
    plt.show()

def main():
    # Get polynomial coefficients from user
    print("Enter the coefficients of the polynomial in descending order of power")
    print("Example: For x^3 - 2x^2 - 5, enter: 1 -2 0 -5")
    
    try:
        coeffs = list(map(float, input("Enter coefficients: ").strip().split()))
        if not coeffs:
            raise ValueError("No coefficients provided")
    except ValueError as e:
        print(f"Error: {e}")
        print("Using default polynomial: x^3 - 2x^2 - 5 (coefficients: 1 -2 0 -5)")
        coeffs = [1, -2, 0, -5]
    
    # Define the polynomial function using the coefficients
    f = lambda x: polynomial_function(x, coeffs)
    
    # Find initial interval
    print("Searching for initial interval...")
    a, b, fa, fb = find_initial_interval(f)
    print(f"Found interval: [{a:.6f}, {b:.6f}] with f(a) = {fa:.6f}, f(b) = {fb:.6f}")
    
    # Apply bisection method
    print("Applying bisection method...")
    root, iterations = bisection_method(f, a, b, fa, fb)
    print(f"Found root: {root:.10f} with {len(iterations)} iterations")
    print(f"Function value at root: {f(root):.10e}")
    
    # Plot the process
    plot_bisection_process(f, iterations, coeffs)

if __name__ == "__main__":
    main()