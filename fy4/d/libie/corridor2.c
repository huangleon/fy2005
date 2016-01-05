// Room: qilin.c --- by MapMaker
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");

	set("long", @LONG
����������һ�����ȡ���������������С���ϣ���ջҲûʲôǮ��������
����ҡҡ�λΣ���֨��֨�����ľͷ���ȣ�����Ϊ��Ϯһ�Ⱥ������ĵ�����һ��
��ʡ�Լ��õ��ϰ�ݺ���Ӳ�Ǽ������������еļҵ��������������˺��̺������
����Ҳ�߸߹����˴�������
LONG);

	//{{ --- by MapMaker
	set("type","indoors");
	set("exits",([
		"down":__DIR__"corridor",
		"enter":__DIR__"qilin",
	]) );
	//}}

	set("no_fight",1);
	set("objects", ([
        	__DIR__"npc/tongzi": 2,
        ]) );
        set("indoors", "libie");
	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",20);
	setup();	
}


int valid_leave(object me,string dir)
{
	object menfang;
	object room,ob;
	
	if(dir!="enter") return ::valid_leave();
	
	if (!objectp(ob = present("jinyi tongzi", this_object())))
		return notify_fail("���Ž��գ����޷����롣\n");
			
	if(REWARD_D->riddle_check(me,"���")==3)
	{
		room = find_object(__DIR__"qilin");
		if (!room)	room = load_object(__DIR__"qilin");
		if (room->usr_in())
			return notify_fail(CYN"����ͯ��΢Ц˵���������ڼ��ͣ����Ժ�\n"NOR);
		
		if (me->query_temp("libie/libie_enter"))	{
			me->delete_temp("libie/libie_enter");
			room->reset();
			return 1;
		}
		
		message_vision(CYN"����ͯ��΢Ц�Ķ�$N˵��������λ"
 			+RANK_D->query_respect(me)+"һ������"
 			+ me->query("name")+"�����ɣ������Ѿ��Ⱥ���¶�ʱ�ˡ���\n"NOR,me);
		me->set_temp("libie/libie_enter",1);
		return notify_fail("");
	}
	
	if (!me->query_temp("libie/libie_enter"))
	{
		message_vision(CYN"����ͯ��б�ۿ���$N��ƤЦ�ⲻЦ�غ���һ����������ʣ�
����֪��֪��������ʲô�ط�����"WHT" answer(yes/no)\n"NOR, me);
		add_action("do_answer","answer");
		return notify_fail("");
	}
	return 1;
}

int do_answer(string arg)
{
	object ob, me;
	object room;
	
	room=this_object();
	ob=present("jinyi tongzi",room);
	me = this_player();
	
	if(!objectp(ob)) return 0;
	
	if (arg=="no")
	{
		message_vision(CYN"
����ͯ��ͦ��ͦ��˵�������������Ϯһ�Ⱥ�������µ�һ�������ٵ�С��ү��
��ջ����������������С�����ǿ�����°ɡ�\n"NOR,me);
		remove_action("do_answer","answer");
		return 1;
	}
	if (arg=="yes")
	{
		remove_action("do_answer","answer");
		message_vision(CYN"����ͯ��˵��������Ȼ֪��������������¡���\n"NOR,me);
		return 1;
	}
	
	return 0;
}
