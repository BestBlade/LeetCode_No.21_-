/*----------------------------------------------------------------------|
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个|
链表的所有节点组成的。 													|
																		|
 																		|
																		|
示例：																	|
																		|
输入：1->2->4, 1->3->4													|
输出：1->1->2->3->4->4													|
																		|
来源：力扣（LeetCode）													|
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists			|
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。	|
-----------------------------------------------------------------------*/

/*	双指针法
*
*	执行用时：12 ms, 在所有 C++ 提交中击败了50.40%的用户
*	内存消耗：14.3 MB, 在所有 C++ 提交中击败了63.23%的用户
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
	ListNode* result = new ListNode(0);

	ListNode* result_Head = result;

	while (l1 && l2)														/*	应该以移动后的l1，l2来判断，而不应该判断l1->next是否为空，因为此时指针还在链表最后一位，没有走完	*/
	{
		if (l1->val <= l2->val)
		{
			result->next = l1;
			l1 = l1->next;
		}
		else if (l1->val > l2->val)
		{
			result->next = l2;
			l2 = l2->next;
		}
		result = result->next;
	}

	result->next = (l1 == NULL) ? l2 : l1;

	return result_Head->next;
}

int main()
{
	ListNode *l1 = new ListNode(1);
	ListNode *l1_Head = l1;
	l1->next = new ListNode(2);
	l1 = l1->next;
	l1->next = new ListNode(4);

	ListNode* l2 = new ListNode(1);
	ListNode* l2_Head = l2;
	l2->next = new ListNode(3);
	l2 = l2->next;
	l2->next = new ListNode(4);


}