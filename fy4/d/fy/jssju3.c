#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "��¥");
    set("long", @LONG

	[45m[1;33m��	ѧ	��	��	��	��	Ī	��[2;37;0m

��������һ�Ÿ�ʾ��[37m�����[32m��

LONG
    );
    
	set("no_fight",1);
	set("no_fly",1);
	set("exits", ([
	"down" : __DIR__"jssju2",
      ]));

     set("item_desc", ([
		"sign": @TEXT
[0;1;37m��������������������������������������������������������������������[0m

Ϊ����������������ѧ���ա��������ԣ������ṩҵ��ɽ���ѧ������ѧ
�����������ѵ�Ǳ�ܵ��ڻ��ͨ�����ɽ�����

���������������������������Ը������£�
������check��������������ܷ��ض���Ǳ�ܣ���ʽΪ��check ����Ӣ����
������pay����������ѣ����ѵĻƽ������ȼ������Ѻ��뿪��������
    �����߶��ߣ�ǰ��������ʹ��refund��������һ�����ѡ�
�������Ѻ󣬿�ʹ��refund�����ʽΪ��refund ����Ӣ����

ע�����1���뿪�Ժ���Ҫ���½��ѡ�
          2�����ػ�����ڵ�ǰ������ѧϰ���о�������Ǳ����ȫ����


[0;1;37m��������������������������������������������������������������������[0m
TEXT
      ]) );

    set("objects", ([
	
    ]) );
	
    set("coor/x",-40);
    set("coor/y",80);
    set("coor/z",30);
    set("map","fynorth");
    setup();
}

void init(){
	
	add_action("do_pay","pay");
	add_action("do_check","check");
	add_action("do_refund","refund");
	add_action("do_answer","answer");
}


int do_check(string arg){
	object me;
	int pot, level,i;
	string *limit;
	
	me = this_player();
		
	if (!arg)	return notify_fail("��Ҫ��ѯ��ѧ������һ��ܣ�\n");
	
	if (me->query_skill(arg,1)<1)
		return notify_fail("����ܲ����ڻ�����û��ѧ������ܡ�\n");
	
	pot = me->query("annie/skill_cost/"+arg);
	level = me->query_skill(arg,1);
	
	tell_object(me,WHT"���Ѿ�������"+level+"��"+ SKILL_D(arg)->name()+"��"+arg+"��\n"NOR);	
	tell_object(me,HIR"���ڸü����Ϲ�������"+pot+"��Ǳ�ܣ�\n"NOR);
	
	if (SKILL_D(arg)->refundable()!="none"){ 
		if (SKILL_D(arg)->refundable()=="attr")
			return notify_fail("�ü����漰���������Ա仯���޷��ظ���Ǳ�ܡ�\n");
		limit = SKILL_D(arg)->refundable();	
		for (i=0;i<sizeof(limit);i++){
			level = me->query_skill(limit[i],1);
			tell_object(me,"�ü���Ϊ"+SKILL_D(limit[i])->name()+"��"+limit[i]+"���Ļ�������ӵ��"+level+"����\n");
		}
		tell_object(me,HIW"Ψ�н����й����书����ϴȥ�����ϴȥ�˼��ܡ�\n"NOR);
	}
	else
		tell_object(me,HIR"�����ѡ�� refund ���⽫�������ܹ��ûص�Ǳ�ܵ�����\n"NOR);
		
	return 1;
		
}


int do_pay(){
	
	object me;
	int level;
	
	me = this_player();
	
	if (me->query_temp("marks/refund_enable"))
		return notify_fail("���Ѿ������������ˣ���ʹ��refund����ı似�ܡ�\n");
		
	level = F_LEVEL->get_level(me->query("combat_exp"));
	tell_object(me,"refund ��Ҫ�ƽ�" + level + "�����Զ���Ǯׯת�ˣ����Ƿ�Ը�⣿��answer yes/no��\n");
	
	me->set_temp("marks/jssju3_pay",1);
	
	return 1;
}


int do_answer(string arg){
	
	object me;
	int level;
	
	me= this_player();
	
	level = F_LEVEL->get_level(me->query("combat_exp"));
	
	if (!me->query_temp("marks/jssju3_pay"))
		return notify_fail("ʲô��\n");
	
	if (arg == "no") {
		me->delete_temp("marks/jssju3_pay");
		return notify_fail("�������ִ�� refund �ˡ�\n");
		}
	
	if (arg !="yes" )
		return notify_fail("��ص�answer yes ���� answer no\n");
	
	me->delete_temp("marks/jssju3_pay");
			
	if (me->query("deposit")< level*10000)
		return notify_fail("refund ��Ҫ�ƽ�"+ level +"�������Ǯׯ���������Ŀ��\n");

	me->add("deposit",-level*10000);
	tell_object(me,HIR"������ϣ�Ǯׯת��"+ level + "���ƽ������ʹ�� refund �����ˡ�
"NOR YEL"ע�����ֻҪ���뿪������䣬����Զ��ִ�� refund ����ı������ܣ�
��һ�����뿪�˵أ��򱾴ν��׽�������һ�� refund ��Ҫ���½��\n"NOR);	
	me->set_temp("marks/refund_enable",1);
	return 1;
}

int do_refund(string arg){
	
	object me;
	int pot, level, mark, i;
	string *limit;
	
	me = this_player();
	
	if (!me->query_temp("marks/refund_enable"))
		return notify_fail("��������pay����������ѡ�\n");
		
	if (me->query_temp("timer/refund")+2 > time())
		return notify_fail("ִ�и������������롣\n");
				
	if (!arg)	return notify_fail("��Ҫ������ѧ������һ��ܣ�\n");
	
	if (me->query_skill(arg,1)<1)
		return notify_fail("����ܲ����ڻ�����û��ѧ������ܡ�\n");
	
	if (!SKILL_D(arg)->refundable()) 
		return notify_fail(HIW"ϵͳ�涨��������޷��ظ���Ǳ�ܡ�\n"NOR);

	mark = 0;
	if (SKILL_D(arg)->refundable()!="none"){ 
		if (SKILL_D(arg)->refundable()=="attr")
			return notify_fail("�ü����漰���������Ա仯���޷��ظ���Ǳ�ܡ�\n");
		limit = SKILL_D(arg)->refundable();	
		for (i=0;i<sizeof(limit);i++){
			level = me->query_skill(limit[i],1);
			if (level >=1) mark = 1;
			tell_object(me,"�ü���Ϊ"+SKILL_D(limit[i])->name()+"��"+limit[i]+"���Ļ�������ӵ��"+level+"����\n");
		}
		if (mark)
			return notify_fail(HIW"Ψ�н����й����书����ϴȥ�����ϴȥ�˼��ܡ�\n"NOR);
	}

	pot = me->query("annie/skill_cost/"+arg);
	level = me->query_skill(arg,1);
	
	tell_object(me,WHT"������������"+level+"��"+ SKILL_D(arg)->name()+"��"+arg+"�����������㡣\n"NOR);	
	tell_object(me,HIR"���ڸü����Ϲ�������"+pot+"��Ǳ�ܣ�����ȫ�����ء�\n"NOR);
	tell_object(me,"����Լ��� refund �������ܣ���������κη�ʽ�뿪�˵أ���ôι��̽�����\n");
	
	me->add("learned_points", -pot);
	
	me->delete("annie/skill_cost/"+arg);
	me->delete_skill(arg);
	me->reset_action();
	
	log_file("REFUND_LOG", 
					sprintf("(%s)%s refund %d��%s��Ǳ�ָܻ�%d��\n",
   					ctime(time()), 
   					me->name(1)+"("+ me->query("id")+")", 
					level,
					arg,
					pot,
				));
	me->save();			
	me->set_temp("timer/refund",time());				
	return 1;	
	
}


int valid_leave(object me, string dir)
{
	me->delete_temp("marks/jssju3_pay");
	me->delete_temp("marks/refund_enable");
	return ::valid_leave(me, dir);
}

