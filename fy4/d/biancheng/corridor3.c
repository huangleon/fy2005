#include <room.h>
#include <ansi.h>
inherit DOOR_ROOM;
void create()

{
        set("short", "¥��");
        set("long", @LONG
�߹�¥����ǰ�������Ⱥ�����ң������ϸ���һ�䣬���һ��������ʮ���죬
һ���ʮ��Сʱ���˵�ֵ��������������ģ��������Ⱥ�ĵմ����ӣ����Ǹ�����
������������������������ܹܹ���ϣ�����������������ҲҪͨ���˲�����¥��
LONG
        );
        set("exits", ([ 
	"down": __DIR__"pianting2",
	"north": __DIR__"uproom1",
	"east": __DIR__"uproom2",
	]));
        set("objects", ([
        	__DIR__"npc/vguard4":	1,
	]) );
        set("coor/x",-15);
        set("coor/y",130);
        set("coor/z",10);
	set("map","zbwest");
	setup();
	create_door("north","door","ľ��","south",DOOR_CLOSED);
}
