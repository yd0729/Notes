double dist(double h, double p) {
  double sum = h;
  h *= p;
  while (h >= TOL) {
    sum += 2 * h;
    h *= p;
  }
  return sum;
}