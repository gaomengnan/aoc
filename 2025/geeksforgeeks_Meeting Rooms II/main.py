class Solution:
    def minMeetingRooms(self, start, end):
        events = []
        for s, e in zip(start, end):
            events.append((s, "start"))  # 记录开始事件
            events.append((e, "end"))  # 记录结束事件

        # 按时间排序，若时间相同，则结束事件优先
        events.sort(key=lambda x: (x[0], x[1] == "start"))

        rooms = 0
        ongoing_meetings = 0
        for event in events:
            if event[1] == "start":
                ongoing_meetings += 1
                rooms = max(rooms, ongoing_meetings)
            else:
                ongoing_meetings -= 1

        return rooms


# print(Solution().minMeetingRooms([1, 2, 1, 4], [3, 3, 7, 5]))

# print(Solution().minMeetingRooms([1, 10, 7], [4, 15, 10]))

# print(Solution().minMeetingRooms([2, 9, 6], [4, 12, 10]))
print(
    Solution().minMeetingRooms([25, 0, 14, 24, 18, 3, 17], [29, 25, 24, 26, 25, 23, 18])
)
