int fact(int no, int out) {
  if (no > 1) out *= fact(no - 1, out) * no;
  return out;
}

int factorial(int no) {
  return fact(no, 1);
}

int sumOfFactorials(int no, int out) {
  if (no > 1) out += sumOfFactorials(no - 1, out) + factorial(no);
}

int sumFacts(int no) {
  return sumOfFactorials(no, 0);
}