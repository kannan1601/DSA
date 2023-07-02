int f(int ind, int target, vector<int> arr){
  if(ind == 0){
    if(target == 0 && arr[0] == 0) return 2;
    if(target == 0 || a[0] == target == 0) return 1;
    return 0;
  }
  int notpick = f(ind - 1, target, arr);
  int pick = 0;
  if(arr[ind] <= target){
    pick = f(ind - 1, target - arr[ind], arr);
  }
  return pick || notpick;
}