#include <ansi.h>
inherit __DIR__"annieitem";

void create()
{
	set_name("С��", ({ "artificial lake"}) );	// �����id�б���������������ʹ�õ���id!
	set_weight(30000);
	set("unit", "Ƭ");
	set("desc", "һƬ�˹��������С������������ϰϰ��\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_stack",1);
	set("no_reset",1);
	set("item_type","k");
	set("lore_item",1);
	set("outdoors",1);
	set("size",1);
	set("tax",30);
	set("score_tax",1);
	set("value", 500000);

	set("liq",([
            "name":"�峺��ˮ",
            "container":"С��"]));

	seteuid(getuid());
}

void init()
{
	::init();
	if (environment() != this_player())
	   	add_action("do_swim","swim");
}


int do_swim(string arg)
{
   	int	s, amount, da;
 	object me = this_player(),env=environment(me),ob=this_object();
	if (!env->is_owner(me->query("id")))
		return notify_fail("����������ֻ�����˲���ʹ�á�\n");
	
	if (me->is_fighting() || me->is_busy()){
		tell_object(me,"��������æ��\n"); 
		return 1;
	}
   	 	
   	me->perform_busy(1);
   	s = me->query_skill("swimming", 1);
	if(random(me->query("kar")) && me->query("kar")>11 && s>=40 ) 
	{
		if(s >= 80)
		{
			message_vision("\n$N��С��������һȦ����̬������⡣\n", me);
			tell_object(me, "�����Ӿ����֮������û��ʲô������\n");
			return 1;
		} 
		if(random(s) >= 30) 
			message_vision("\n$N��С��������һȦ����̬������⡣\n", me);
		else 
			message_vision("\n$Nսս��������С��������һȦ��\n", me);
	  
		tell_object(me, "�����Ӿ����֮�����󳤽���һЩ��\n");
		     amount = me->query("agi") + me->query("int") + me->query_skill("swimming",1)*25;
		if(amount < 1) amount = 1;
		me->improve_skill("swimming", amount);
		da = 50;
		me->set_temp("last_damage_from","��С������ˮ����С�������ˡ�");
		me->receive_damage("kee", da);
   	} else {
      	message_vision("\n$N��С��������һȦ����̬������⡣\n", me);
      	message_vision("\n$Nһ��С�ģ���Ǻ�˼���ˮ��\n", me);
		da = 150;
		me->set_temp("last_damage_from","��С������ˮ����С�������ˡ�");
		me->receive_damage("kee", da);
    }
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
