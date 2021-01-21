
//习题整理:
//1. 原地移除数组中所有的元素val，要求时间复杂度为O(N)，空间复杂度为O(1)。
int removeElement(int* nums, int numsSize, int val){
	// int idx=0;
	// for (int i=0;i<numsSize;i++) {
	//     if ( nums[i] != val) {
	//         nums[idx++]=nums[i];
	//     }
	// }
	// return idx;
	int idx = 0;
	int* newArrar = (int*)malloc(sizeof(int)*numsSize);
	for (int i = 0; i<numsSize; i++) {
		if (nums[i] != val) {
			newArrar[idx++] = nums[i];
		}
	}
	memcpy(nums, newArrar, sizeof(int)*idx);
	return idx;
}
//2. 删除排序数组中的重复项。
int removeDuplicates(int* nums, int numsSize){
	int idx = 0;
	int i = 0;
	int j = 1;
	while (j<numsSize) {

		nums[idx++] = nums[i];
		if (nums[i] != nums[j]) {
			++i;
			++j;
		}
		else {
			while (j < numsSize && nums[i] == nums[j]) {
				++j;
			}
			i = j;
			++j;
		}
	}
	if (i<numsSize) //假如最后一个元素恰好不重复的情况
		nums[idx++] = nums[i];
	return idx;
}
//3. 合并两个有序数组。
// void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
// int idx=0;
// int n1=0;
// int n2=0;
// int* newArr=(int*)malloc(sizeof(int)*(m+n));
// while (n1 < m  && n2 < n ) {
//     if(nums1[n1] <= nums2[n2]) {
//     newArr[idx++]=nums1[n1++];   
//     }else {
//         newArr[idx++]=nums2[n2++]; 
//     } 
//   }
// if (n1 < m)
//     memcpy(newArr+idx,nums1+n1,sizeof(int)*(m-n1));
// if (n2 < n)
//     memcpy(newArr+idx,nums2+n2,sizeof(int)*(n-n2));
// memcpy(nums1,newArr,sizeof(int)*(m+n));
// free(newArr);
// }

//方法2:不用开辟新的空间,直接将元素保存到nums1中,此时一定是从后向前进行存放,不然会存在元素会被覆盖的情况
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	//从后向前依次将数据放入到nums数组中
	int idx = m + n - 1;
	while (m > 0 && n > 0) {
		if (nums1[m - 1] >= nums2[n - 1]) {
			nums1[idx--] = nums1[m - 1];
			--m;
		}
		else{
			nums1[idx--] = nums2[n - 1];
			--n;
		}
	}
	//nums2中有剩余元素-----直接将剩余的元素进行拷贝到nums1数组中
	if (n > 0)
		memcpy(nums1, nums2, sizeof(int)*n);

}
//4. 旋转数组。
//封装一个依次逆转的函数
void Rever(int* nums, int left, int right) {
	// while (left<right) {
	//        int tep=nums[left];
	//        nums[left]=nums[right];
	//        nums[right]=tep;
	//        --right;
	//        ++left;
	// }
	for (; left<right;) {
		int tep = nums[left];
		nums[left] = nums[right];
		nums[right] = tep;
		--right;
		++left;
	}
}

void rotate(int* nums, int numsSize, int k){
	//方法:三次旋转法
	k %= numsSize;  //假如旋转的次数大于数组的长度,此时就避免了进行多次重复的操作
	Rever(nums, 0, numsSize - k - 1); //通过旋转的次数k将数组进行分成两部分进行
	Rever(nums, numsSize - k, numsSize - 1);
	Rever(nums, 0, numsSize - 1);//最后依次进行整体的旋转
}


