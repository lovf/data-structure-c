
//ϰ������:
//1. ԭ���Ƴ����������е�Ԫ��val��Ҫ��ʱ�临�Ӷ�ΪO(N)���ռ临�Ӷ�ΪO(1)��
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
//2. ɾ�����������е��ظ��
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
	if (i<numsSize) //�������һ��Ԫ��ǡ�ò��ظ������
		nums[idx++] = nums[i];
	return idx;
}
//3. �ϲ������������顣
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

//����2:���ÿ����µĿռ�,ֱ�ӽ�Ԫ�ر��浽nums1��,��ʱһ���ǴӺ���ǰ���д��,��Ȼ�����Ԫ�ػᱻ���ǵ����
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	//�Ӻ���ǰ���ν����ݷ��뵽nums������
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
	//nums2����ʣ��Ԫ��-----ֱ�ӽ�ʣ���Ԫ�ؽ��п�����nums1������
	if (n > 0)
		memcpy(nums1, nums2, sizeof(int)*n);

}
//4. ��ת���顣
//��װһ��������ת�ĺ���
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
	//����:������ת��
	k %= numsSize;  //������ת�Ĵ�����������ĳ���,��ʱ�ͱ����˽��ж���ظ��Ĳ���
	Rever(nums, 0, numsSize - k - 1); //ͨ����ת�Ĵ���k��������зֳ������ֽ���
	Rever(nums, numsSize - k, numsSize - 1);
	Rever(nums, 0, numsSize - 1);//������ν����������ת
}


