inherit DOOR_ROOM;
#include <room.h>
void create()
{
        set("short", "����");
        set("long", @LONG
ÿ���岽�����Ҹ�һ�š��������мǺţ��ź�����������ÿ��ʮ�������һյ��
��������������ϸ�������ƺ�ÿ���տա�����������������ǰ��չ��һ����������
ͷ��ÿ�������沨ҡ�ڣ��������εĸо���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"corror2",
  "north" : __DIR__"hotel2",
]));

	set("coor/x",-90);
	set("coor/y",15);
	set("coor/z",0);
	setup();
        create_door("north", "door","ľ����", "south", DOOR_CLOSED);

}
