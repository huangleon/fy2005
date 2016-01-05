inherit DOOR_ROOM;
#include <ansi.h>
#include <room.h>

void create()

{
        set("short", "��Ѩ");
        set("long", @LONG
��Ѩ�ı��ϳ�������̦��ż������Ҷ��϶��͸�µ����ήή�����ز��ҽ��룬
�������һ�ţ�Խ�����ߣ���Խ���ŵ�һ��Ѫ�Ⱥ���ɧζ�����˻����Խ�������
��Ƥ��񡣿��Ըе����������ӲӲ�Ķ�����һ�������ǿеľ���Ķ����ͷ��
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"forest1",
	]));
        set("objects", ([
	]) );
        set("coor/x",-1620);
        set("coor/y",680);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	create_door("west","rock","��ʯ","east",DOOR_CLOSED);
}

void reset(){
	int i;
	object bear;	
	
	i = NATURE_D->get_season();	
	
	if (objectp(bear=present("bear",this_object())))
	{
		if (userp(bear) 
			|| bear->is_fighting() 
			|| !bear->is_character())	
		return;
	else
		destruct(bear);
	}
	if(i == 1 || i == 4 ) {
		bear=new(__DIR__"npc/bear_w");
		bear->move(this_object());
	} else {
		bear=new(__DIR__"npc/bear");
		bear->move(this_object());
	}
	::reset();
}

int valid_leave(object me, string dir) {
	object bear;
	if (dir == "west")
	if (bear = present("bear",this_object()) )
	if (bear->is_fighting(me))
		return notify_fail("Ұ���Ǿ޴��������ס�˶��ڡ�\n");
		
	return ::valid_leave(me,dir);
}