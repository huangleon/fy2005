#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���Ϲ�������");

	set("long", @LONG
����������Ϲ�������꣬��Ȼ�Ĵ����ǻ���δȥ���͹����ա����Ƕ��е���
Ѽ��ζ���㼸������������ȴһ�У������߻��м������Ҳ�����Ϲ�˯���ĵط���
��䷿�����ǹ��ŵģ���Ϊ���Ϲ������±ζҲ�ǡ������ط��������Ǳ�����͵͵
ѧȥ�ˣ����ķ���Ҳ�������ˡ�
LONG);

	set("type","house");
	set("exits",([
		"east":__DIR__"xiaojie3",
		"west":__DIR__"neishi",
	]) );
	set("objects",([
     		__DIR__"npc/mai":1,
    	]) );

	set("coor/x",10);
	set("coor/y",90);
	set("coor/z",0);
	setup();
}

void init()
{
	add_action("do_look", "look");
}


int valid_leave(object me, string dir)
{
        object room,ob;
        if( userp(me) && dir=="west")	{
        	if (present("mai laoguang", this_object())) 
				return notify_fail("���Ϲ�����Ц��������������ϵ����ϵ�ͣ�����ϵ��ȥ�ġ���\n");
			room = find_object(__DIR__"neishi");
			if (room->usr_in())
				return notify_fail("������С�������Ѿ��������ˡ�\n");
			if (ob= present("feng qiwu",room))
				destruct(ob);
			if (me->query_temp("fugui_mai_showyaopai")) {
				ob = new(__DIR__"npc/feng");
				ob->move(room);
			}
		}
		return 1;
}

int show_notify(object obj, int i)
{
		object me;
		object room, mai;
		object feng;
		me = this_player();
		mai = present("mai laoguang", environment(me));
		
		if (!mai)	return 0;
			
		if (mai->is_fighting())
		{
			tell_object(me,"���Ϲ����ڴ�ܣ�û�������㣡\n");
			return 1;
		}
		else
		{
			if (!me->query_temp("yaopai")) {
				message_vision("���Ϲ�պ�Ц����������$N������ҡ��ҡͷ��\n",me);
				return 1;
			}
			if (!(room=find_object(__DIR__"neishi")))
	      		room=load_object(__DIR__"neishi");
	      	write(YEL"\n���Ϲ���ɫͻȻ��úܽ��š�\n"NOR);
	      	write(YEL"���Ϲ���㲻ע�⣬͵͵Ų�����ݡ�\n"NOR);
			destruct(mai);
			me->set_temp("fugui_mai_showyaopai",1);
			return 1;
		}
}


int do_look(string arg)
{
        object 	me;
		me = this_player();
		if( arg == "west") 
		{
			tell_object(me,"��ߺ�����ģ�ʲô����������\n"); 
			return 1;
		}
		return 0;
}