bool check(int mid, int array[], int n, int K)
{
    int count = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
 
        // If individual element is greater
        // maximum possible sum
        if (array[i] > mid)
            return false;
 
        // Increase sum of current sub - array
        sum += array[i];
 
        // If the sum is greater than
        // mid increase count
        if (sum > mid) {
            count++;
            sum = array[i];
        }
    }
    count++;
 
    // Check condition
    if (count <= K)
        return true;
    return false;
}
 int splitArray(int array[] ,int n, int k) {
        int* max = max_element(array, array + n);
    int start = *max; //Max subarray sum, considering subarray of length 1
    int end = 0;
 
    for (int i = 0; i < n; i++) {
        end += array[i]; //Max subarray sum, considering subarray of length n
    }
 
    // Answer stores possible
    // maximum sub array sum
    int answer = 0;
    while (start <= end) {
        int mid = (start + end) / 2;
 
        // If mid is possible solution
        // Put answer = mid;
        if (check(mid, array, n, k)) {
            answer = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
 
    return answer;
}
 