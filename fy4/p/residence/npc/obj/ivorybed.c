#include <ansi.h>
inherit __DIR__"annieitem";

void create()
{
	set_name("�������", ({ "ivory bed"}) );	// �����id�б���������������ʹ�õ���id!
	set_weight(30000);
	set("unit", "��");
	set("desc", "һ�Ű����������������ɵ���齣���ϱ��������˯��ȥһ��������ˡ�\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_stack",1);
	set("no_reset",1);
	set("item_type","o");
	set("size",2);
set("tax",80);
set("score_tax",10);
	set("value", 800000);
	seteuid(getuid());
}

void init()
{
	::init();
	if (environment() != this_player())
	   	add_action("do_sleep","sleep");
}


int do_sleep(string arg)
{
   object me, obj, girl;
   int gin, kee, sen;
	mapping buff;
	function f;

   me = this_player();
   obj = this_object();
	if (!environment(me)->is_owner(me->query("id")))
		return notify_fail("����������ֻ�����˲���ʹ�á�\n");
   if (me->is_fighting() || me->is_busy()) return 1;
   if (query_temp("marks/taken")) {
      tell_object(me, "��������Ү��������\n");
      return 1;
   }
  message_vision("$N�����ۡ������Ƿ���ɵ��˴��ϣ�", me);
  tell_object(me, "�ܿ���;���˯�����ʡ�\n");
  obj->set_temp("marks/taken", 1);
  gin =  me->query("eff_gin");
  kee =  me->query("eff_kee");
  sen =  me->query("eff_sen");
  me->set("gin", gin);
  me->set("kee", kee);
  me->set("sen", sen);
	f = (: call_other, __FILE__, "fullnpc",obj :);

		buff =
		([
			"caster":me,
			"who":me,
			"type":"freeze",
			"att":"bless",
			"name":"���žӼҡ��������",
			"buff1":"disable_inputs",
			"buff1_c":1,
			"buff2":"is_unconcious",
			"buff2_c":1,
			"buff3":"block_msg/all",
			"buff3_c":1,
			"disable_type":HIG " <˯����>"NOR,
			"time":10+random(10),
			"buff_msg":"$N���˼������ҵ������ʵ����ƣ��ܿ�ͽ��������硣\n"NOR,
			"disa_msg":CYN"\n$N�������۾���һ�������ͦ�Ӵ�������������\n"NOR,
			"disa_type":1,
				"finish_function":bind(f, this_object()),
		]);
		ANNIE_D->buffup(buff);

      return 1;
}


void fullnpc(object target,int i)
{
	if (!target)
		return;
	target->delete_temp("marks/taken");
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
