// Room: qilin.c --- by MapMaker
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�����");

	set("long", @LONG
��ν�������ʵֻ��һ��ܿ��������ӣ��ı�ѩ���޳����ú�ľ�̳ɵĵ��棬
���˲��ʵ���ص��廨��̺��������ʲô��û�У�ֻ���������š�
LONG);

	//{{ --- by MapMaker
	set("type","indoors");
	set("exits",([
		"out":__DIR__"corridor2",
	]) );
	//}}
	set("indoors", "libie");
	set("coor/x",-10);
	set("coor/y",-20);
	set("coor/z",30);
        set("no_fly",1);

	setup();
}

void init(){	
	add_action("do_kill","kill");
}

int valid_enter(object me)
{
	object ying,yang,di;
	object room;
	
	room=this_object();
	room->reset();
	set("�������",me);

	if (objectp(di=present("di qinglin",room)))
			destruct(di);
	if(!objectp(di=present("di qinglin",room)))
	{
		di=new(__DIR__"npc/diqinglin");
		di->move(room);
	}
	if(!objectp(ying=present("ying wuwu",room)))
	{
		ying=new(__DIR__"npc/yingwuwu");
		ying->move(room);
	}
	ying->start_call_out( (: call_other, ying, "do_busy", me :), 1);	
	if(!objectp(yang=present("yang zheng",room)))
	{
		yang=new(__DIR__"npc/yangzheng");
		yang->move(room);
	}
	yang->start_call_out( (: call_other, yang, "do_rival", di :), 1);			
	return 1;
}

int do_kill(string arg)
{
	object me,yang,di,ying,room;
	
	room=this_object();
	me=this_player();
	if(!present(arg,room)) return 0;

	if(present("yang zheng",room)&&present("di qinglin",room))
	{
		write(HIW"�㱻�������˵�ɱ�����壬��Ȼһ��Ҳû������\n"NOR);
		return 1;
	}
	return 0;
}

int valid_leave(object me,string dir)
{
	object yangcorpse;
	
	if(dir!="out") return 1;
	if(query("�������")) delete("�������");
	if(present("di qinglin",this_object()))
		return notify_fail(HIR"������΢Ц�Ķ���˵��������ߣ��ò�����ô���ɣ���\n"NOR);
	if(me->query("libie/���_ɱ��������")==1)
	{	
		if(objectp(yangcorpse=present("yang's corpse",me)))	
			return 1;
		if(present("yang's corpse",this_object()))
			return notify_fail(HIY"�㿴����������Ŀ��ʬ�壬���÷�������δ�����Ĳ��̡�\n"NOR);
	}
	return 1;
}
