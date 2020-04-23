# decorator is a function that takes a functino and returns a function

def make_desirable(func):
  def inner(s):
    letters = list( map (lambda x : chr(ord('A') + x) , range(26)) ) + \
        list( map (lambda x : chr(ord('a') + x) , range(26)) )
    new_str = ''.join(list(filter(lambda c : c in letters, s)))
    return func(new_str.lower())
  return inner

@make_desirable
def check_palin(s):
  return "YES" if s == s[::-1] else "NO"

def main():
  s = input()
  print(check_palin(s))

if __name__ == '__main__':
  main()