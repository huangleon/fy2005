// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
    	string msg,id;
    	int lvl, ap, dp;
		object ob,*inv;
      	
    	if (me->query("class") != "moon")
        	return notify_fail("ֻ����¹����˲���ʹ�á����������\n");
        	
    	if((int)me->query_skill("heart-listening",1) < 40 )
        	return notify_fail("�����������Ҫ����40���Ļ���������\n");

    	if((int)me->query("mana") < 300 )
        	return notify_fail("�����������Ҫ300�㷨����\n");

		id = me->query("marry");
		if (!id || !(target = find_player(id)))
        	return notify_fail("û��������������ͨ���޷�ʹ�á��������(set telepathy_to ���ID)��\n");

		if (!target->query("env/telepathy"))
        	return notify_fail("���˲�Ը��������ԡ������������Ʒ(set telepathy 1)��\n");

    	me->add("mana", -300);  
    	msg = HIG "$N"HIG"˫��ƽ�У��̷��о���һ��ǳ��ɫ�Ĺ�â��$N"HIG"���г��֡�\n\n" ;
		inv = all_inventory(me);
		
		if (sizeof(inv) >= 14)
		{
	    	msg += HIG "��â������һ�¾���ʧ�ˣ������ϵĶ���̫���ˣ���\n\n" ;
			message_vision(msg+NOR,me);
		}
		message_vision(msg+NOR,me);

		tell_object(target,HIG"�����к�Ȼһ�����ƺ��������ܵ�����ʲô����Ҫ���㡣\n"NOR);
		
		seteuid(getuid());
		ob = new("/obj/item/magicbag");
		ob->set_max_encumbrance(me->query_skill("heart-listening",1)
			*me->query_skill("heart-listening",1));	// 1600 - 40000,bag 1000,basket 8000,mugui 80000.
		ob->move(me);
		call_out("do_trans",10,me,target,ob);
        return 1;
}

void do_trans(object me,object target,object ob)
{
	object *inv;
	if (!ob || !me)
		return;
	if (!target)
	{
		tell_object(me,"��ͻȻ�о�����������ͨ�������ˣ����ǿ�Щ��ֹ��������ɡ�\n");
		return ;
	}
	inv = all_inventory(target);
	if (environment(ob) != me || sizeof(inv) >= 14)
	{
		tell_object(me,"������һ�󲻰����ƺ���������˲���Է����ϵĶ���̫���ˣ���\n");
		return ;
	}
	message_vision(HIG"������ͻ��һ�󲨶���$N"HIG"����ǳ��ɫ�Ĺ�â������ʧ������\n"NOR,me);
	ob->move(target);
	message_vision(HIG"������Ȼ��ʼˮ�����񶯣�ֻ����žણ�һ������ʲô����$N"HIG"���\n"NOR,target);
	return ;
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
