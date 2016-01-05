#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
  set("short","��������");
  set("long",@LONG
���Ǹ����ӵ����硣��Ŀ�����������Ƕ����������ֻ����춥���£��޴�����
������������ӯӯ���档��������������ӳ�����ھ��������ֻʵ�������ӣ�
���Ż�������Χ������Ϥ��������Ӱ��һ˿�־������������ͷ��
LONG
  );
  	set("exits",([
        	 "north":__DIR__"maze_ns",
        	 "south":__DIR__"maze_ns",
        ]));
	set("coor/x",99);
	set("coor/y",99);
	set("coor/z",0);
	set("no_fly",1);
		set("item_desc", ([
		"west":"�����������������ӰӰ�´µģ����������Ӱ�ӡ�\n",
		"north":"�����������������ӰӰ�´µģ����������Ӱ�ӡ�\n",
		"east":"�����������������ӰӰ�´µģ����������Ӱ�ӡ�\n",
		"south":"�����������������ӰӰ�´µģ����������Ӱ�ӡ�\n",
	]) );
	setup();
}

void init()
{
	if(userp(this_player()))
	{
		remove_call_out("attack");
		call_out("attack",3+random(3),this_player());
	}
	add_action("do_say","listen");
	add_action("do_push","push");
}


int do_push(string arg)
{
	object me = this_player(),room;
	mapping data;
	
	if (REWARD_D->riddle_check(me,"̽��׷Դ") != 10 
		&& !REWARD_D->check_m_success(me,"̽��׷Դ"))
		return 0;
	if (!arg)
		return 0;
	if (arg != "mirror" && arg != "����" && arg != "����")
		return 0;
	message_vision("$N���������ƾ��档\n",me);
	if (me->query_str() < 60)
		return notify_fail("���Ǿ����Ʒ粻�����������ǲ���̫�����ˣ�\n");
	message_vision("����ͻȻһת��$N⧲������������˵������С�\n",me);
	if (!room = find_object(__DIR__"maze_room"))
		room = load_object(__DIR__"maze_room");
	me->move(room);
	tell_room(this_object(),"����ɿ�ĺϻ�ԭλ���·�ʲôҲû�з�����\n"NOR);

	REWARD_D->riddle_done(me,"̽��׷Դ",100,1);
	
	    data = ([
			"name":		"̽��׷Դ",
			"target":	me,
			"att_1":	"int",
			"att_1c":	1,
			"mark":		1,
		]);
	
		REWARD_D->imbue_att(data);	
	
	return 1;

}

int do_say(string arg)
{
	object me = this_player(),room;
	if (REWARD_D->riddle_check(me,"̽��׷Դ") != 9 && !REWARD_D->check_m_success(me,"̽��׷Դ"))
		return 0;
	me->set_temp("annie/demon_feng",0);
	tell_object(me,CYN"�㽫�������������ϣ�����ԼԼ���������������˶Ի�֮����\n"NOR);
	me->start_busy(12);
	call_out("do_ggyy",1,this_object(),me,0);
	return 1;
}

void do_ggyy(object me,object target,int count)
{
	int i,j;
	object item;
	string msg;
	string *event_msg = ({
"\nһ����ǻ����������������������ֻ��������ʶ��һʱ��ȴ���벻��������������",
"ֻ����������������ˣ�ū���Ѿ�������ƭ���˵أ�����ʱ�䣬Ҳ������ƨ�ˡ�",
"��һ���º������˵�������ò�������ҽ�һͳ����֮�ʣ������ٵ�һ���谭��",
"��ǰ��������Ц������Ӧ�����ⶼ���������������㣬�ǣ������Ǹ�ʲô�ޱߡ�",
"��һ���Դ���ڽ�ĵ������÷ϻ�����ȥ�գ�ȥ����������ȡ����εı��꣬��Ϳ��Թ��ˡ�",
"һ��ϤϤ�����������������������ֹ��ڼž�������",
});
	if (!me || !target)
		return;
	if (me != environment(target) || target->is_fighting())
		return;
	msg = event_msg[count];
	message_vision(CYN+msg+"\n"NOR,target);
	if (count < sizeof(event_msg)-1)
		call_out("do_ggyy",2,me,target,count+1);
	else
	{

		if(REWARD_D->riddle_check(target,"̽��׷Դ") == 9)
			REWARD_D->riddle_set(target,"̽��׷Դ",10);

		tell_object(target,HIB"\n�����ľ����Ȼ΢΢һ��������һ����Ī���⾵�ڿ����ƿ���\n"NOR);
		return;
	}
	return;
}

int attack(object ob)
{
	int i;
	int damage;
	object room;
	if( environment(ob) == this_object() && REWARD_D->riddle_check(ob,"̽��׷Դ") == 8)
	{
		tell_object(ob,CYN"\n��ͻȻ����һ������˽��֮���Ӿ�������ﴫ��������\n"NOR);
		REWARD_D->riddle_set(ob,"̽��׷Դ",9);
		return 1;
	}
	else
		return 1;
}



/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/

