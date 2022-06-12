from random import randint


def get_random_list(size: int) -> list:
    return [randint(0, size+1) for _ in range(size)]