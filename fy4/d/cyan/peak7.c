// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "������");
    set("long", @LONG
�����ȵ���������ӫӫ��ʯ����һ������Ϫ��������������С����Ϫˮ��
������������������м�����ণ���Ҳ���һ�����顣�������Ѿ�����������
������һЩǰ����ˮ��С����һ���Ҳ��������������ԲԲ�Ĵ��۾�����ش�
�����㡣
LONG
NOR
        );
	set("objects", ([
	__DIR__"npc/cat":1,
	__DIR__"npc/turtle":1,
		__DIR__"obj/river" : 1,

	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"westup" : __DIR__"path8",
  		"southup" : __DIR__"peak11",
  		"northup" : __DIR__"peak10",
  		"eastdown" : __DIR__"patha",
	]) );

	set("outdoors", "cyan");

	set("coor/x",-20);
	set("coor/y",50);
	set("coor/z",70);
	setup();
}

void reset()
{
	object river,stone,*inv;
	
	::reset();

	river = present("Ϫˮ", this_object());
	if (!river)
		return;
	inv = all_inventory(river);
	if (sizeof(inv) < 1)
	{
		stone = new(__DIR__"obj/stone");
		if(stone)
			stone->move(river);
		stone = new(__DIR__"obj/stone");
		if(stone)
			stone->move(river);
	}
	return;
}

int	valid_leave(object who, string dir)
{
	object me,npc;
	me = who;
	if (me->query_temp("annie/no_leave"))
		return notify_fail("���ȥ·����ס��Ү������\n");

	if (dir != "southup")
		return ::valid_leave(who,dir);

	if (REWARD_D->riddle_check(me,"̽��׷Դ") != 3 && REWARD_D->riddle_check(me,"̽��׷Դ") != 4)
		return ::valid_leave(who,dir);

	me->set_temp("annie/no_leave",1);
	REWARD_D->riddle_set(me,"̽��׷Դ",4);
	npc=new(__DIR__"npc/stormeye");
	npc->move(this_object());
	message_vision(CYN"\n�����ͻ���½����֮����һ���ߴ����Ӱ����ӵ�������$N��ǰ��\n\n",me,npc);
	message_vision(CYN"$n��ɫ���࣬��������վס��\n",me,npc);
	tell_object(me,RED"��Ϊ�������������𣬽���ס��ס�Ų���\n");
	who->start_busy(9);
	call_out("do_ggyy",2,me,npc,0);
	return notify_fail(" ");
}

void do_ggyy(object me,object target,int count)
{
	string msg;
	string *event_msg = ({
"$n����ؽ�$N��ͷ���Ŵ���һ�飬���ְ���������佣֮�ϡ�\n$n�����Ϸ������˵ħ����Թ˵���ʹ�¶��֣������ȥ������\n$n����û�뵽��������������Ⱥ����С�˵ĵ���",
"$N�����ɻ���ʣ����˵����ѵ�����ħ�����ˣ�",
"$n�������˵���˵���һ����Ϊ������������������ħ�����ˣ�\n\n$n��ɫͻȻһ�䣬������ף�˭������˵�����ħ��צ����",
"$N���üͷ��������ʼĩԭԭ���������г���",
"$nԽ��Խ���������ֱ��ŭ�����ţ���ȵ������ģ����ģ�������������",
HIR"$n���û�������ָ��$N�ı��ӵ�����������ȥ���˼ҵ�"YEL"����"HIR"���µ���񻹲�����ô��"NOR,
"$N��Ȼ���򣬳��ɵ����ǣ�����",
"$n̾��������ľ����ľ����\n$n�����Ϸ������������ʳ��̿����䣬����Ǳ����ã������ѳ���Ӱ��\n$n����Ƭ�̵�������������������Ļ��ᡣ",
"$n�����Ϸ�����������Ҫ����ͼ�������֣�Ϊ����һ�����Ǳ�����·��\n$n��������Ϸ�ǰȥ���ϸ��������ϣ�����ֱ��ǰȥ�ػ��̿͡�",
"$N�ʵ�����֪�Ǵ̿���˭��",
"$nһ��һ�ֵ��������ǹ������������ְ��࣬�˹����µ�"HIR"������ʦ"NOR CYN"��",
"$n������ȥ��֮��ֻ����ѯ����ͼ���ѧʿ�����֣��������¶ԭ�Ρ�",
});
	if (!me || !target)
	{
		if (me)
			me->set_temp("annie/no_leave",0);
		if (target)
			destruct(target);
		return;
	}
	if (environment(me) != environment(target) || me->is_fighting() || target->is_fighting())
	{
		if (me)
			me->set_temp("annie/no_leave",0);
		if (target)
			destruct(target);
		return;
	}
	msg = event_msg[count];

	if (count == 1)
		tell_object(me,RED"ħ�̣����ǣ�����\n"NOR);

	message_vision(CYN+msg+"\n"NOR,me,target);

	if (count == 5)
		tell_object(me,RED"�������ת�������һ�����µ���ͷ�ܽ��Ժ������ͻ����\nԭ����ʼ�����㶼���˱��˵ĵ�����ν��ɽ����·��������ħ�����µ�һ��ƭ�֡�\n"NOR);


	if (count < sizeof(event_msg)-1)
		call_out("do_ggyy",2,me,target,count+1);
	else
	{
		set("ggyying",0);
		me->set_temp("annie/no_leave",0);
		REWARD_D->riddle_set(me,"̽��׷Դ",5);
		message_vision(CYN"����էͣ������������������ʧ��Ӱ��\n"NOR, me);
		destruct(target);
		return;
	}
	return;
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


