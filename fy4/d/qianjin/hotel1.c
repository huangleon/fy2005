inherit DOOR_ROOM;
#include <room.h>
void create()
{
        set("short", "�᷿");
        set("long", @LONG
��С���ţ�����һ��С�����������٣��������ҡ��Ա�һԲ�ʣ�����ԧ��档
�ݽ�ľ���������ϴ����壬�����һ��ԧ��Ϸˮ��ǽ�ǹ���һ��С׭������
		������״����У�ϧ�����񼸸�֪��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"corror2",
]));
        set("objects", ([
        __DIR__"npc/chick1" : 1,
                        ]) );


	set("coor/x",-85);
	set("coor/y",10);
	set("coor/z",0);
	setup();
        create_door("north", "door","ľ����", "south", DOOR_CLOSED);

}
