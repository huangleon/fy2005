inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "��Ѩ��");
        set("long", @LONG
����͸���������˽�����Ȼ����Ŀ���ܼ���ֻ�ж������ܣ���Բһ�����ڵľ�
������һ�н�������һƬ�ޱߵĺڰ�֮�С�û�������Ķ���������ǰ�ߣ�ֻ��
���׶༪�١���ʱ�����ôϣ����ʲô�������������ǡ�     
LONG
        );
        set("exits", ([ 
		"enter" : __DIR__"darkhole",
		"out" : __DIR__"whiterock",
	]));
	set("outdoors","fengyun");
	set("coor/x",-50);
	set("coor/y",70);
	set("coor/z",30);
	setup();
}


int 	light_notify(object lighter, int num)
{
		object me, room;
		
		me = this_player();
		
		write(WHT"�����" + lighter->name()+ NOR WHT"�����Ĺ⣬��ϸ�۲�����ĵ��Ρ�\n"NOR);	
		
		me->add_temp("block_msg/all",1);
		if (!room = find_object(__DIR__"lighthole"))
			room = load_object(__DIR__"lighthole");
		me->move(room);
		me->add_temp("block_msg/all",-1);
		
		return 1;
}

/*
	
	


int valid_leave(object me, string dir)
{
        object *inv, ob;
        int i;

	if( userp(me) && dir == "enter" ) {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			if(inv[i]->name() == "ҹ����") {
				me->move(__DIR__"lighthole");
				return notify_fail(HIY"\n��ӻ����ͳ�ҹ���飬����ҹ���鷢���Ĺ⣬����˶���\n"NOR);
			}
                }
        }
	return 1;
}

*/
