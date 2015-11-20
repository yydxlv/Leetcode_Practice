//Description:
//Given a sorted array, remove the duplicates in place such that each element appear only once
//and return the new length.
//Do not allocate extra space for another array, you must do this in place with constant memory.
//For example, Given input array A = [1, 1, 2],
//Your function should return length = 2, and A is now[1, 2].
class solution1 {
	int removeDuplicates(int A[], int n)
	{
		if (n == 0)
			return 0;
		int index = 0;
		for (int i = 1; i < n; i++)
		{
			if (A[index] != A[i])
				A[++index] = A[i];
		}
		return index + 1;
	}
};
//Description:
//Follow up for ¡±Remove Duplicates¡± : What if duplicates are allowed at most twice ?
//For example, Given sorted array A = [1, 1, 1, 2, 2, 3],
//Your function should return length = 5, and A is now[1, 1, 2, 2, 3]
class solution2 {
public:
	int removeDuplicates(int A[], int n) {
		if (n <= 2) return n;
		int index = 2;
		for (int i = 2; i < n; i++) {
			if (A[i] != A[index - 2])
				A[index++] = A[i];
		}
		return index;
	}
};