// seaside2.c

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
ת��һ���䣬����ǰ��Ȼһ���ޱ��޼ʵĴ󺣾�����ǰ�ˡ�������棬һϴ
�����ÿ͵�һ·�Ͷ١��������������е���ζ������΢΢���Ų��ˡ������ĺ�ˮ��
��ӿ����׵��˻�������Ʈ������ı���·����һƬ�Ĺ�ľ�ԣ���ľ����ȴ���ܣ�
������ؿ����屳����û��·��
LONG
        );
        set("exits", ([ 
  		"north" : __DIR__"seaside",
  		"south" : __DIR__"lin1",

	]));
        set("outdoors", "tieflag");
	set("coor/x",1000);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
}

int valid_enter(object me)
{
	if(me->query("lovestory1/epilogue")) return 1;
	if(this_object()->query("lovestory1_epilogue")) return 1;
	
//	if(random(10)) 
	this_object()->set("lovestory1_epilogue",1);
	me->set("lovestory1/epilogue",2);
	me->set_temp("lovestory1_epilogue",1);
	remove_call_out("lovestory1_epilogue");
	call_out("lovestory1_epilogue",5+random(5),me,1);
	return 1;
}

void pipe_notify()
{
        object ob;

        message("vision","һ������������԰��ߣ���������ؼ�ľ��ţ����ﵽԶ����\n" , this_object() );
		call_out("boat_come",5);
}
void boat_come()
{
	object boat;
	object woman;
	object *inv;
	object who, oob;
	int i;
	
	if (query("exits/down")) return;
	if (!objectp(boat=find_object(AREA_CHANGCHUN"boat")))
		boat=load_object(AREA_CHANGCHUN"boat");
	inv=all_inventory(boat);
	if (!(oob=present("old boater",boat)) || boat->query("exits/up") || !living(oob))
	{              
			message("vision","�����ã�������ʲôҲû�г��֡�\n",this_object());
			return;
	}
	for (i=0;i<sizeof(inv);i++)
	    if (userp(inv[i]))
		{
			message("vision","�����ã�������ʲôҲû�г��֡�\n",this_object());
			return;
		}
	message("vision","���˰��Σ�һ���洬�����е���������׿����һ���׷��ԲԵ��ϸ��ˣ����ҡ�֡�\n",this_object());
	message("vision","������˵�������ϴ��ɣ���\n",this_object());
	boat->set("exits/up",__DIR__"seaside2");
	set("exits/down",AREA_CHANGCHUN"boat");
	call_out("boat_leave",10,boat);
}
void boat_leave(object boat)
{
	if (query("exits/down")) delete("exits/down");
	if (boat->query("exits/up")) boat->delete("exits/up");
	message("vision","�����ӳ���һ�㣬���۾��뿪�˺�����\n",this_object()); 
	boat->set_temp("mark/dest","island");
	message("vision","�����ӳ���һ�㣬���۾��뿪�˺�����\n",boat);
	boat->boat_run(0);
}

int lovestory1_epilogue(object me,int count)
{
	object girl;
	
	if((!me)||(!living(me))||(!present(me,this_object())))
		return 0;
	
	switch(count){
	case 1:
		message_vision(WHT"�����ĺ�̲��������ˮ��������һƬ���������������ǰ��\n"NOR,me);
		break;
	case 2:
		tell_object(me,"������ԼԼ������֮�У���·𿴼���һλ"HIW"����"NOR"Ů�ӡ�\n");
		girl=new("/questnpc/lovestory1/whitegirl");
		girl->move(this_object());
		set("lovestory1_char",girl);
		break;
	case 3:
		girl=query("lovestory1_char");
		girl->ccommand("emote �����̾��һ�����ƺ������޾������ˡ�");
		girl->leave_room(me);
		break;
	case 4:
		this_object()->delete("lovestory1_epilogue");
		me->delete_temp("lovestory1_epilogue");
		me->set("lovestory1/epilogue",1);
		return 1;
	}
	call_out("lovestory1_epilogue",5+random(5),me,count+1);
	return 1;
}
		
		
