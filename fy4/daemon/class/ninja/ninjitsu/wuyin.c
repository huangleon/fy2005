/* // Silencer @ FY4 workgroup. Aug.2004
	����������wuyin�����������жݼ�����һ�����֣���Ũ�������
����Ұ����������֮�����ܿ����˵�׷������Զ������ˮ���ļ���������
ɽ��ˮ��֮ʱȴҲ������Ψһ������������200�����ɹ���60%��
*/


#include <ansi.h>

inherit SSERVER;
int conjure(object me, object target)
{
	int skill, n,duration,i;
	string msg;
	object *inv;
	
	skill = me->query_skill("ninjitsu",1);
	if ( skill < 200)
                return notify_fail("������Ҫ200����������\n");
                        
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("�㲻��ս���У�����Ҫ������\n");

	duration = me->query("timer/pfm/wuyin")+ 1200 - time();
	if (duration >0)
		return notify_fail("��Ҫ�ȴ�"+ duration/60 + "���Ӳ����ٴ�������\n");
	
	message_vision(BMAG HIM"
$N"NOR BMAG HIM"���֣�����һ����ɫ���ţ��������ԣ�������ԣ������ͷף�ϼ��
���档�����ߵ���ɫ�ָ������ڲ��ƣ����ɲʷ����һ�㣬���·��衣
"NOR BMAG HIM"$N"NOR BMAG HIM"������λ�Ӱ����������֮�С�\n"NOR,me);			
	    
	me->set("disable_type",HIG "<������>" NOR);
    me->set_temp("disable_inputs",1);
    me->set_temp("is_unconcious",1);
	me->set_temp("in_jiasi",1);
	me->add_temp("block_msg/all",1);
	
	n = random(100);
//	message_vision(" random(100) is " + n + "\n",me);
		
	if (n >50)	{
		message_vision( HIB"\n$N��Ϊ֮�ң���Ϊ֮�ԣ��޲���Ͷ���ǻ�����ɫ���\n"NOR,target);		
		me->remove_all_killer();
		me->remove_all_enemy();

		inv = all_inventory(environment(me));
		for (i=0;i<sizeof(inv);i++){
			if (inv[i]->query("possessed")==me)		// My pet	
			{
				inv[i]->remove_all_killer();
				inv[i]->remove_all_enemy();
			}
		}
    } else
	{
		message_vision(WHT"\n$Nһ�ƻ������ǵ�â��ǧѰ���������Ĳʺ���ʧ������\n"NOR, target);			
	}
	me->set("timer/pfm/wuyin",time());
	me->start_call_out( (: call_other, __FILE__, "remove_dazuo", me :), 40 + random(50));
	return 1;
}

void remove_dazuo(object me)
{
   	me->delete_temp("in_jiasi");
   	me->delete_temp("is_unconcious");
   	me->delete_temp("disable_inputs");
   	me->delete_temp("disable_type");
   	if (me->query_temp("block_msg/all")>0)	me->add_temp("block_msg/all",-1);
   	message_vision("$N���������������������\n",me);
//	me->set("timer/jiasi",time());
}

