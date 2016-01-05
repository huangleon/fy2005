// TIE@FY3
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	int wimpy;
	int attr, max_attr;
	object room;
    seteuid(getuid());
    
    if( me->is_fighting() )
    	return notify_fail("ս���в��ܴ��������߻���ħ�ġ�\n");
    if( me->is_busy() )
        return notify_fail("����һ��������û����ɣ����ܴ�����\n");
	room = environment(me);
	if(room->query("NONPC") || room->query("no_fight") || room->query("no_pk")
		|| room->query("no_magic") || room->query("no_preach")
      	|| room->query("no_beg") || room->query("no_dazuo") || room->query("no_death_penalty")
		|| room->query("no_steal") || room->query("no_spells"))
		return notify_fail("�㲻���������������\n");
	if(me->is_ghost())
		return notify_fail("��겻�ܴ�����\n");
	
	if (me->query("death_revive")+ 180 > time())
		return notify_fail("�����ڵ�����״���޷�����������\n");
	
	if (me->query("food") <= 0 || me->query("water") <=0)
		return notify_fail("���ʳ�����ˮΪ�㣬�����ǲ�����Ч���ġ�\n");
	
	wimpy = (int)me->query("env/wimpy");
	message_vision("$N���ȵ����ڵ��ϣ������۾���ʼ��Ϣ������\n",me);
    me->set_temp("disable_inputs",1);

   	me->add_temp("block_msg/all", 1);
	me->set_temp("is_unconcious",1);
    me->set("disable_type",HIG "<������>" NOR);
	me->set_temp("in_dazuo",1);
    me->start_call_out( (: call_other, __FILE__, "remove_dazuo", me:), 4+ random(6));
	return 1;
}

void remove_dazuo(object me)
{
   	int attr, max_attr;
   	
   	me->delete_temp("disable_inputs");
   	me->delete("disable_type");


	if (me->query_temp("block_msg/all")>=1)
	    	me->add_temp("block_msg/all", -1);


	me->delete_temp("in_dazuo");
   	me->delete_temp("is_unconcious");
   if(!me->is_ghost() && (int) me->query("food") > 0 && (int)me->query("water") > 0)
  {
	attr = (int) me->query("food");
	attr = attr  /10 * 5;
	me->set("food",attr);

        attr = (int) me->query("water");
        attr = attr  /10 * 5;
        me->set("water",attr);

	attr = (int)me->query("kee");
	max_attr = (int)me->query("eff_kee");
	if( 2*attr > max_attr) attr = max_attr;
	else attr *=2;
	me->set("kee",attr);
        attr = (int)me->query("gin");
        max_attr = (int)me->query("eff_gin");
        if( 2*attr > max_attr) attr = max_attr;
        else attr *=2;
        me->set("gin",attr);
        attr = (int)me->query("sen");
        max_attr = (int)me->query("eff_sen");
        if( 2*attr > max_attr) attr = max_attr;
        else attr *=2;
        me->set("sen",attr);

        attr = (int)me->query("mana");
        max_attr = (int)me->query("max_mana");
	if(attr < max_attr)
        {
	        if( 2*attr > max_attr) attr = max_attr;
	        else attr *=2;
        	me->set("mana",attr);
        }
        attr = (int)me->query("force");
        max_attr = (int)me->query("max_force");
        if(attr < max_attr)
        {
                if( 2*attr > max_attr) attr = max_attr;
                else attr *=2;
                me->set("force",attr);
        }
        attr = (int)me->query("atman");
        max_attr = (int)me->query("max_atman");
        if(attr < max_attr)
        {
                if( 2*attr > max_attr) attr = max_attr;
                else attr *=2;
                me->set("atman",attr);
        }
	me->status_msg("all");
	me->force_status_msg("all");
 	message_vision("$N�����ҵľ����л����������������۾���\n",me);
  }

}

int help(object me)
{
        write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	dazuo[0m
[0;1;37m����������������������������������������������������������������[0m   

ʹ��������ҵĴ���״̬�У��������쾫������Ѫ������������
�����������Ļָ��ٶȡ�

[0;1;37m����������������������������������������������������������������[0m   

HELP
        );
        return 1;
}
 
