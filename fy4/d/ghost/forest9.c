
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ɽ�±�");
	set("long", @LONG
��ǰ��Ȼһ�����������߳����ǿ��µ�ԭʼ���֣����ǣ�ǰ����[37mʯ[32m�������±���
һ������׵�������Ԩ������������ƣ�ʲô�����������������˵����鶼��������
�ѵ�������ɽׯ������������Ԩ֮�£�
LONG
	);
	set("exits", ([
                "west" : __DIR__"forest7",
                "south" : __DIR__"forest6",
	]));
	set("objects", ([
                __DIR__"obj/rock" : 1,
	]));
	set("outdoors", "ghost");
	set("coor/x",-90);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}

void init()
{
	object me;
	object          *inv;
        object          con, item;
        int             i;
        
        con = present("rock", this_object());
        if (!living(con)) 
	if (!present("pipe",con)) {
	         item = new(__DIR__"obj/pipe");
	         item->move(con);
	}
    	
	me = this_player();
	if(me->query_temp("marks/know_ghost")){
		tell_object(me, HIG"��ǰ��ɫ�ƺ���Щ��Ϥ������ϡ�ǵ��������ĵʹ��߿��Գ�ȥ��\n\n"NOR);
		add_action("do_northdown", "go");
	}
	if(this_object()->query("exits/east"))
		delete("exits/east");
}

void reset()
{
        object          *inv;
        object          con, item;
        int             i;
        ::reset();
        con = present("rock", this_object());
        if (!living(con)) 
		if (!present("pipe",con)) {
		         item = new(__DIR__"obj/pipe");
		         item->move(con);
		}
        if(query("exits/east"))	
        	delete("exits/east");
	
}

void pipe_notify()
{
        object ob;
        message("vision", WHT "\n����֮���Ȼ������һ���ˣ�ʲô�������վ�ڰ����\n"NOR, this_object() );
        message("vision", WHT "���ߵ��±߲ŷ��֣������������ֵܴĸ�������������Ե�ɽ�¡�\n"NOR, this_object() );
        set("exits/east", __DIR__"bridge" );
}


int do_northdown(string arg){
	object room;
	object me=this_player();
	
	if (arg == "northdown")
	if(me->query_temp("marks/know_ghost")) {
		message("vision", me->name()+"΢һ��������һ�·���������ɽ��֮�����˼��¾Ͳ����ˡ�\n", 
				environment(me), me);	
		room = find_object(__DIR__"lroad3");
		if(!objectp(room)){
			room = load_object(__DIR__"lroad3");
		}
		me->move(room);
		message("vision", me->name()+"�Ӵ���֮�����˳�����\n", environment(me), me);
		return 1;
	}
	return 0;
}
