inherit DOOR_ROOM;
#include <ansi.h>
#include <room.h>

void create()

{
        set("short", "�鷿");
        set("long", @LONG
�鷿���ϲ��Ľ��أ�����������˵ʲô�������±����������������ǲ����ϲ�
�����ѣ��������ô�¿�������ֻҪ�㵽�˾ջ�԰���ϲ��������������������
����˵������⡣��ϲ����ȫ���ˣ�ϲ������������һ�в��������£�����������
���յ�ũ�ˣ�����ȳ漱�ڳ���һ����
LONG
        );
        set("exits", ([ 
		"west" :   __DIR__"garden4",
		"north":	__DIR__"groom2",
	]));
        set("objects", ([
	]) );
        set("coor/x",-1260);
        set("coor/y",970);
        set("coor/z",-50);
	set("map","zbeast");
	setup();
	create_door("north","door","ɴ��","south",DOOR_CLOSED);
}


int valid_leave(object me, string dir){
	
	object room, lu, laobo;
	mapping doors;
	
	room = find_object(__DIR__"groom2");
	if (!room) room = load_object(__DIR__"groom2");
	
	if ( dir == "north") {
		if ( !me->query_temp("marks/kuaihuo/lv_cook"))
			return notify_fail("û���ϲ���׼���κ��˲��ý������ҡ�\n");
		
		if (room->usr_in())
			return notify_fail("�ϲ��Ѿ��ڼ������ˣ����Ժ�Ƭ�̡�\n");
		doors = this_object()->query_doors();
		if (doors["north"]["status"]==1)
			return notify_fail("ɴ�Ź��š�\n");
		me->delete_temp("kuaihuo/lv_cook");
		if (lu=present("lv xiangchuan",room))
			destruct(lu);
		if (laobo = present("sun yubo",room))
			laobo->remove_all_killer();
		return ::valid_leave(me,dir);
	}
	return ::valid_leave(me, dir);
}