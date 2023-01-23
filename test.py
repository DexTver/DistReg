import os

gen = "gen"
good = "good"
bad = "bad"
iters = 100

for i in range(1, int(iters) + 1):
    print('Test', i, end=': ')
    os.system(f'{gen} > input.txt ' + str(i))
    os.system(f'{good} < input.txt > good.txt')
    os.system(f'{bad} < input.txt > bad.txt')
    good_answer = open('good.txt').read()
    bad_answer = open('bad.txt').read()
    if good_answer != bad_answer:
        print('GG')
        print(open('input.txt').read())
        print(f'Output of {good}:')
        print(good_answer)
        print(f'Output of {bad}:')
        print(bad_answer)
        break
    else:
        print("OK")
    print()
