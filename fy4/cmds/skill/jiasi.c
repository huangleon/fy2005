// Silencer@fengyun	June.2005
// 5 mins per use.

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int main(object me, string arg)
{
	int skill, duration;
	object target;
	string msg;
	
 	seteuid(getuid());
	if(me->query("class") != "shenshui") 
		return	notify_fail("��������ˮ���ľ�����\n");
	
	if (me->is_ghost())
		return notify_fail("���Ѿ����ǻ����ˡ�\n");
		
	//  normally it's 900-600 = 300=5 min, 
	skill = me->query_skill("nine-moon-spirit",1);	
	duration = me->query("timer/jiasi") - time() + 900 - F_ABILITY->check_ability(me, "jiasi_add")*60;
	if (duration > 0)
	   	return notify_fail(WHT"��Ҫ�ȴ�" + duration + WHT"�����ң����ھɼ����ݻᱻ�����ģ�\n");
    	  	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("�㲻��ս���У�����Ҫ������\n");

	message_vision(WHT"\n$N"NOR+WHT"�ҽ�һ����һͷ�Ե��ڵ��¡���������\n"NOR,me);
        
    // Some attacks don't set this mark... mostly spells.    
    if (me->query_temp("last_damage_time") + 4 < time())
    {
		message_vision(HIR"$N"HIR"��Ц������û���������ˣ���������������\n"NOR, target);
		me->perform_busy(1);
		me->set("timer/jiasi",time());
		tell_object(me, RED"��������İ�Ϸ����ʶ���ˣ�������\n"NOR);
		return 1;
	}
	message_vision("\n$N���ˡ�\n",me);	
	
    me->set("disable_type",HIG "<������>" NOR);
    me->remove_all_killer();
	me->remove_all_enemy();
    me->start_call_out( (: call_other, __FILE__, "remove_dazuo", me :), 60);
    me->set_temp("disable_inputs",1);
    me->set_temp("block_msg/all",1);
	me->set_temp("is_unconcious",1);
	me->set_temp("in_jiasi",1);
	return 1;
}

void remove_dazuo(object me)
{
   	me->delete_temp("in_jiasi");
   	me->delete_temp("is_unconcious",1);
   	me->delete_temp("disable_inputs");
   	me->delete("disable_type");
   	me->delete_temp("block_msg/all");
   	message_vision("$N�ڵ������ĵط��˸���С��������������ۡ�\n",me);
	me->set("timer/jiasi",time());
}




int help(object me)
{
        write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	jiasi[0m
[0;1;37m����������������������������������������������������������������[0m   

��ˮ���������ھ����м�װ������ƭ���֣����������Ļ��ᡣ
ע�⣺��Ķ���Ҳ����ɵ�ӣ����ô˾�����ץ׼ʱ����Ψ��
�ڱ������˺����2�غ��ڲ�����Ч������Ī���������˿�ƭ
�����ˡ�

[0;1;37m����������������������������������������������������������������[0m   

HELP
        );
        return 1;
}
 
