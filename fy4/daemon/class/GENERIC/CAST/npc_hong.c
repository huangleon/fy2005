// void_sense.c

#include <ansi.h>

inherit SSERVER;
int bbqthem(object me, object obj);
int cast(object me, object target)
{
	int lvl,i,j,k;
	object env, *inv, *myteam;
	
	if(userp(me))
		return notify_fail("����ѡ�õ��书��û�����ֱ�ɱ������\n");
	
	if(me->query("class")!="lama")
		return notify_fail("ֻ�д����µĵ��Ӳſ���ʹ�����Է�����\n");
                
	lvl = (int) me->query_skill("spells");

	message_vision(HIW "$N��������ǰչ������֮״��������������������̨�����������£������ྲ��������ˡ� \n" NOR, me);
        message_vision(HIR "������ֻ��$N˫��һ˲�䷢����̫����Ҫҫ�۵Ĺ�â������\n" NOR, me);
        env = environment(me);

        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( me->is_fighting(inv[i])) 
                	bbqthem(me, inv[i]);
        }
        me->start_busy(2);
        return 1;

}


int bbqthem(object me, object obj) 
{
	int spells, busy_num;
	string id_enemy;
	spells = (int) me->query_skill("spells");
	spells = spells+ random(spells);
        if(obj->query("combat_exp")>random(me->query("combat_exp")/100*spells))
        {
        	message_vision(HIB"$N��æת��ͷȥ������$n��\n"NOR,obj,me);
        	obj->kill_ob(me);
        	me->kill_ob(obj);
        	return 1;
        }
	if(userp(obj) )
	{
	tell_object(obj,HIW"��ֻ������ǰ��ãã��һƬ��ʲô���������ˡ�����\n"NOR);
	obj->add_temp("block_msg/all",1);
	obj->start_busy(2);
	message_vision(CYN"$Nʹ�����ס�۾���ֱ�ڵ��ϴ����\n"NOR,obj);
	me->kill_ob(obj);
	obj->kill_ob(me);
	call_out ("recover",12, obj);
	}
	else
	{
	if (obj->query("no_busy")) {
		busy_num = obj->query("no_busy");
		obj->delete("no_busy");
		call_out ("busy_recover",10, busy_num, obj);
		}
	obj->start_busy(2+random(3));
	message_vision(CYN"$Nʹ�����ס�۾���ֱ�ڵ��ϴ����\n"NOR,obj);
	obj->kill_ob(me);
	me->kill_ob(obj);	
	}
	return 1;
}


int recover (object obj)
{
	if (obj->query_temp("block_msg/all")>=1)
	    	obj->add_temp("block_msg/all", -1);
	tell_object(obj, HIG"���������ģ�����۾���ʼ���Էֱ���Χ�������ˡ�\n" NOR);
	return 1;
}	

int busy_recover (int busy_num, object obj)
{
	obj->set("no_busy",busy_num);
	return 1;
}	
