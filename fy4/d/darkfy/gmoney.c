inherit ROOM;
#include <room.h>
void create()
{
        set("short", "�ھ��˷�");
        set("long", @LONG
�����ǽ�ʨ�ھֳ����������˷��������������ɼ�Ӳ�Ļ���ʯ���ɵġ���Ψһ��һ
��С���϶�����Ĵָ��ϸ�ĸ������ݽ���С��������������ͷ�����ŵ�����ҹ���ء���
����ˣ����л��л�ͭ���壬����һ�죬�ھֻ���Ǿͻ��ӵ������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"ghall",
]));
        set("objects", ([
        __DIR__"npc/xiansheng" : 1,
                        ]) );
        set("coor/x",20);
        set("coor/y",50);
        set("coor/z",-300);
        setup();
        create_door("south", "����", "north", DOOR_CLOSED);

}
