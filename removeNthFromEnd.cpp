#include <QCoreApplication>
#include <QtDebug>

/*
Constraints:
The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
*/

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* resHead = head;

        int count = 1;//кол-во элментов (не может быть равным 0)
        ListNode* counter = head;
        while(counter->next != nullptr)
        {
            count++;
            counter = counter->next;
        }

        int toDelIndx = count - n + 1;
        int prevIndx = toDelIndx - 1;
        int i = 1;//текущий индекс элемента
        ListNode *prev = nullptr;
        while((i != toDelIndx) && (i < toDelIndx))//дошли до элемента который нужно удалить
        {
            if(i == prevIndx)
                prev = head;

            i++;
            head = head->next;
        }

        if(toDelIndx < count)//если элемент не последний
        {
            if(prevIndx > 0)// если есть предыдущий
            {
                prev->next = head->next;
            }
        }

        head = nullptr;
        return resHead;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Solution s;

    ListNode *head = new ListNode(0);
    ListNode *list = head;
    for (int i = 1; i < 0; ++i)
    {
        head->next = new ListNode(i);
        head = head->next;
    }

    s.removeNthFromEnd(list, 3);

    while (list != nullptr)
    {
        qDebug() << list->val;
        list = list->next;
    }


    return a.exec();
}
