inherit DOOR_ROOM;
#include <room.h>

void create()
{
        set("short", "��̲");
        set("long", @LONG
�����ƺ��Ѿ����˺�̲�ľ�ͷ��ԭ��Ҳ������壬��ȴ��ͻȻ���Ÿ��ش��
��ʣ����Դ�ʱ���ѻķϣ�ֻ����̲�Ͼ����ѽ�������ƴ�����ʣ��ʮ���ľ��Ҳ
�Ƕ������ᣬ����ģ��������һ������ľ�ݣ�ľ���������ã��ں��������ص��죬
��ʱ�����ܵ�����
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"house",
		"north" : __DIR__"village3",
		"east" : __DIR__"village",
	]));
        set("outdoors", "tieflag");
	set("item_desc", ([
	 ]));
	set("coor/x",900);
	set("coor/y",20);
	set("coor/z",0);
	setup();
	create_door("west","door","ľ��","east",DOOR_CLOSED);
}

