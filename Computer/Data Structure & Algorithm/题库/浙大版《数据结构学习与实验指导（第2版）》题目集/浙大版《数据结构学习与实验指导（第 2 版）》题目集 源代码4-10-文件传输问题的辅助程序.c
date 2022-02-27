void Input_connection(SetType S) {
  ElementType u, v;
  SetName Root1, Root2;

  scanf("%d %d\n", &u, &v);
  Root1 = Find(S, u - 1);
  Root2 = Find(S, v - 1);
  if (Root1 != Root2) Union(S, Root1, Root2);
}

void Check_connection(SetType S) {
  ElementType u, v;
  SetName Root1, Root2;

  scanf("%d %d\n", &u, &v);
  Root1 = Find(S, u - 1);
  Root2 = Find(S, v - 1);
  if (Root1 == Root2)
    printf("yes\n");
  else
    printf("no\n");
}

void Check_network(SetType S, int n) {
  int i, counter = 0;

  for (i = 0; i < n; i++) {
    if (S[i] < 0) counter++;
  }
  if (counter == 1)
    printf("The network is connected.\n");
  else
    printf("There are %d components.\n", counter);
}
