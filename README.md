# Plazza

## The Reception

The reception must be started using the command line the following way:
```bash
./plazza <cooking_time> <cooks> <refill_time>
```

- The first parameter is a multiplier for the cooking time of the pizzas. It is used to examine your program
  more easily, so it must **INEVITABLY** be implemented. Otherwise it will not be possible to grade you.
  Moreover this parameter **MUST** be able to accept numbers with value in between 0 to 1 to obtain a
  divisor of the pizzas cooking time... _Cooking time is detailed later_
- The second parameter is the number of cooks per kitchen. **Cook definition is detailed later**
- The third parameter is the time in milliseconds, used by the kitchen stock to replace ingredients.
  **Ingredient definition is detailed later.**
