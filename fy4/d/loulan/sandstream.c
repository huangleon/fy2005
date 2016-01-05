#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ɳ��");
	set("long", @LONG
���Ѿ�������ɳ֮�У�����û��һ�������ĵط������˻�ɳ����ʲô����������
LONG
	);

        set("NONPC",1);
		set("no_fly", 1);
		set("coor/x",-90);
		set("coor/y",-210);
		set("coor/z",90);
		setup();
}

void init(){	
	object me;
	
	me = this_player();
	if(interactive(me)) {
		call_out("entering", 4, me);
	}
}

int entering(object me)
{
	int i;
	object room;
	i = random(4);
	if( !me || environment(me) != this_object()){
		return 1;
	}
	switch (i)
		{
			case 0:
				if(!objectp(room = find_object(__DIR__"northtower")))
				room = load_object(__DIR__"northtower");
				break;
			case 1:
				if(!objectp(room = find_object(__DIR__"westtower")))
				room = load_object(__DIR__"westtower");
				break;
			case 2:
				if(!objectp(room = find_object(__DIR__"easttower")))
				room = load_object(__DIR__"easttower");
				break;
			case 3:
				if(!objectp(room = find_object(__DIR__"southtower")))
				room = load_object(__DIR__"southtower");
				break; 
			default: 
				message_vision("$Nһ���£�ʹ�����̵ľ������ķ�����ȥ��\n",me);
				me ->move("/d/loulan/kongquehe");
				return 1;
		}
	if( me &&  environment(me) == this_object())
	{
		message_vision(YEL"��Ȼ��һ�������ױȵ�����ǣ����$N����ﾣ�С�ȣ�����......ɳʯ����
û��ͷ������ֻ���û�������ը......\n\n"NOR, me);
//		me->unconcious(); ---- really no need to let players faint left and right.
		me->move(room);
	}
	return 1;
}
