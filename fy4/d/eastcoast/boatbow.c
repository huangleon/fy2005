#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", "��ͷ");
        set("long", @LONG
�˴��������󣬽��ú�ɼľ��ɣ����߶��㣬����Χ���ƾ��洬����ͬ�ն��
��βһ������ڷ����������죬��������һ��������צ�İ��������Ž��գ�������
�����������Ц������ͷվ�������ֳֵָ������º��ӣ������������⣬��Ȼ����
���ࡣ������һ�����׳�������ͨ�򰶱ߡ�
LONG
        );
        set("exits", ([ 
		"enter" : __DIR__"boatcabin",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
		    "����" : "ľ��ܽ�ʵ��˳�������Իص�(walkto)����(bank)��\n",
		    "plank" : "ľ��ܽ�ʵ��˳�������Իص�(walkto)����(bank)��\n",	
	]));
        set("objects", ([
        	AREA_TAIPING"npc/blueman" : 2,
                       ]) );

	set("coor/x",1030);
	set("coor/y",20);
	set("coor/z",10);
	setup();
}


void init()
{
    add_action("do_walk", "walkto");
    add_action("do_listen","listen");
}


int do_listen(string arg) {
	
	if (!arg || arg== "����" || arg == "����") {
		tell_object(this_player(),MAG"\n~~~~~~~~��~~~~��~~~~~~��~~��~~~~~~~~~\n\n"NOR);
	}
	return 1;
}
	
int do_walk( string arg )
{
	 object me,room;
	 me = this_player();
	 if(!arg || (arg != "bank" && arg != "����"))	  	return notify_fail("��Ҫ���Ķ��ߣ�\n");
	 
	 if (me->query_temp("taiping/walk_plunk_2"))	 	return notify_fail("���Ѿ����������ˡ�\n");
	 if (this_player()->is_busy())	 	return notify_fail("��������æ��\n");
	 message_vision("$N�����������򰶱ߣ�ľ��ܽ�ʵ����������ƽ·�ϡ�\n",me);
	 me->set_temp("taiping/walk_plunk_2",1);
	 me->start_busy(3);
	 call_out("do_arrive",6,me);
	 return 1;
}

int do_arrive(object me) {
	object room;
	
	 if (!objectp(me) || me->is_ghost()) return 1;	
	 room = find_object(__DIR__"cape");
         if(!objectp(room))
                 room = load_object(__DIR__"cape");
         message("vision",me->name()+"�����������˹�����\n",room);
         tell_object(me,"�������˰��ߡ�\n");
         me->move(room);
         me->delete_temp("taiping/walk_plunk_2");
         return 1;
}

int valid_leave(object me,string dir)
{
	object ob;
	if(userp(me) && dir == "enter" && ob=present("blue cloth man",this_object())) {
		if (!me->query_temp("taiping/boat_enter"))	{
			message_vision(ob->name()+"˵��������δ�������ڲ����͡�\n",me);
			return notify_fail("");
		} 
	}
	return 1;
}