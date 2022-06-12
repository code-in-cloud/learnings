def test_WHEN_generator_is_called_THEN_it_returns_a_generator():
    from generator import get_random_list
    t = get_random_list(10)
    assert t is not None and len(t) == 10