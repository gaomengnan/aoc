class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


# 打印链表
def print_linked_list(head):
    current = head
    while current:
        print(current.data, end=" -> ")
        current = current.next
    print("None")


# 生成链表（从一个列表）
def create_linked_list(values):
    if not values:
        return None
    head = Node(values[0])
    current = head
    for v in values[1:]:
        current.next = Node(v)
        current = current.next
    return head


# 生成回环链表
def create_cyclic_linked_list(values, pos):
    """
    values: 节点数据列表
    pos: 尾节点要指向的下标（-1 表示不形成环）
    """
    if not values:
        return None

    head = Node(values[0])
    current = head
    nodes = [head]  # 用来保存节点引用

    # 依次生成链表
    for v in values[1:]:
        new_node = Node(v)
        current.next = new_node
        current = new_node
        nodes.append(new_node)

    # 如果 pos 有效，则尾节点指向对应位置的节点
    if pos != -1 and 0 <= pos < len(nodes):
        current.next = nodes[pos]

    return head
