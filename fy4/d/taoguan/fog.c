// ; annie 07.2003
// dancing_faery@hotmail.com
// 

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����֮��");
        set("long", @LONG
���������һƬ�ڰ���ã�������������Լ���ż����������ƺ���
Ѫ��ζ��������ӰӰ�´µ��ƺ���ʲô�ڻ��ֻ���������ֲ�����ָ��
��������Ļ�������������������
LONG
        );
	set("item_desc", ([
		"out" : "��Ӱ���أ���ʲôҲ���������\n",
	]) );

	set("no_fly",1);
	setup();
}

// ���������Ҫ������˽������⡢��call֮ǰ�뿪����

int	valid_leave(object who, string dir)
{
	int i;
	object me,here=environment(who),*inv=all_inventory(here),room=load_object(__DIR__"dimroom");
	me = who;

	if (dir == "out")
	{
		if (present("lesser demon",here))
		{
			return notify_fail("�׺���ס��Ψһ�ĳ�·������\n");
		}

		// now out.
		// 
		message_vision(CYN"\n������һ��Ц���������������Ĺ��ơ�\n"NOR,me);
		message_vision(CYN"һ��������������������Ȼ���ʡ�\n"NOR,me);
		message_vision(CYN"����ǰ�ĺ����Ȼɢ����ԭ���㻹��С��֮�У���������վ������ǰ�ĳ�֮�⡣\n\n"NOR,me);
		for (i=0;i<sizeof(inv) ; i++)
			inv[i]->move(room);
		return notify_fail(" ");
	}
	return ::valid_leave(who,dir);
}


void init()
{
	object room,me;
	object *olist;
	int i;
	me = this_player();
	delete("exits");
	if (userp(me))
	{
		room = this_object();
		olist = all_inventory(room);
/*		for(i=0; i<sizeof(olist); i++)
			if (!userp(olist[i]))
				destruct(olist[i]);*/
		if (me->query_temp("annie/demon_xin_1",1))
			call_out("do_pil",2,me,room);
	}
	return;
}

void do_pil(object me,object room)
{
	if (!me || room != environment(me))
		return;
	message_vision(MAG"\n�ڰ�֮�д���һ������ë���Ȼ�ĵ�Ц���š�������\n���м�����ڤ�й���������������������ǰɣ�\n"NOR,me);
	message_vision(YEL"\n����ȼ���ŵĻ�ֽ�Ӱ����ƮƮ���Ƶ����¡�\n"NOR,me);
	call_out("do_next",2,me,room);
	return;
}

void do_next(object me,object room)
{
	object zombie;
	int i,j;
	if (!me || room != environment(me))
		return;
	message_vision(YEL"\n����������֮��������������ڶ���\n����ɢȥ��һȺ��֫�ϱ۵���ʬ�������г��֣���\n"NOR,me);
	j = 3+random(3);	// 3 - 5 zombies
	for(i=0; i<j; i++)
	{
		zombie = new(__DIR__"npc/lessdemon");
		zombie->move(room);
		zombie->kill_ob(me);
		me->kill_ob(zombie);
	}
	set("exits/out",__DIR__"dimroom");
	return;
}


/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/

