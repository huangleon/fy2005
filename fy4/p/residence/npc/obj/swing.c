#include <ansi.h>
inherit __DIR__"annieitem";

void create()
{
	set_name("��ǧ", ({ "swing"}) );	// �����id�б���������������ʹ�õ���id!
	set_weight(30000);
	set("unit", "��");
	set("desc", "��ǧ�ù�����ͣ���Ȼ��ª��ȴ������Ȥ��\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_stack",1);
	set("no_reset",1);
	set("item_type","l");
	set("outdoors",1);
	set("size",1);
	set("value", 200000);
set("tax",20);
set("score_tax",1);
	seteuid(getuid());
}

void init()
{
	::init();
	if (environment() != this_player())
	   	add_action("do_swing","swing");
}

int do_swing(string arg)
{
   	int	s, amount, da;
 	object me = this_player(),env=environment(me),ob=this_object();
	if (!env->is_owner(me->query("id")))
		return notify_fail("����������ֻ�����˲���ʹ�á�\n");
	if (!arg)
		return 0;
	if (present(arg,env) != ob)
		return 0;
	if (me->is_fighting() || me->is_busy()) return 1;
   	me->perform_busy(1);
   	s = me->query_skill("move", 1);
	if(random(me->query("kar")) && me->query("kar")>11 && s>=55 )
	{
		if(s >= 60)
		{
			message_vision("\n$N������ǧ�ϣ������ؿ�ʼ������ǧ��Խ��Խ�ߡ�\n", me);
			tell_object(me, "��Ļ����Ṧ����û��ʲô������\n");
			return 1;
		} 
		message_vision("\n��ǧԽ��Խ�ߣ�$N���ɵý���ץס���١�\n", me);
        tell_object(me, "��ֻ���÷�ӽŵ��ӹ������ƺ�Ҫ�˷��ȥ��\n");
	  
		amount = me->query("agi") + me->query("int") + me->query_skill("move",1)*5;
		if(amount < 1) amount = 1;
		me->improve_skill("move", amount);
		da = 30*20/(me->query_dur()+me->query_fle());
		me->set_temp("last_damage_from","����ǧˤ���ˡ�");
		me->receive_damage("kee", da);
   	} else {
      		message_vision("\n��ǧԽ��Խ�ߣ�$Nһ���������ǧ�ϵ���������\n", me);
		    tell_object(me, "���飡�������ص�ˤ�������ϣ�ƨƨ��ʹŶ��\n");
			da = 30*20/(me->query_dur()+me->query_fle());
			me->set_temp("last_damage_from","����ǧˤ���ˡ�");
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
