
#include <ansi.h>
inherit SSERVER;

int conjure(object me, object target)
{
	string msg;
	object weapon;
	int skill;
	object *stuff;
	int qin,i;
	
    	if (me->query("class") != "baiyun") 
    		return notify_fail("ֻ�а��Ƶ����ӿ������ࡺ���񳯷�����\n");

	if (me->is_ghost())
		return notify_fail("�����ǹ�꣬�����뷨�Ȼ�����ɡ�\n");
	
	stuff = all_inventory(me);
	qin=0;
	for (i=0;i<sizeof(stuff) ;i++){
		if(qin < stuff[i]->query("timbre")){
		  qin = stuff[i]->query("timbre");
		}
	}  
	if(!qin && userp(me)) return notify_fail("��������Ǵ����ˡ�\n");
		
	skill = me->query_skill("music",1);	
	if (!skill)
		return notify_fail("��������һ�ϲ�ͨ��Ϲ���˼��£��پ���Ȼ��ζ��\n");
	
	if (skill < 120)
		return notify_fail("�����ֲ����˼��£����ִ��׹��ڸ��������Ҫ100�����ٵ��������ࡣ\n");

	if (me->query_temp("shield_force"))
		return notify_fail(CYN"�����ֲ����˼��£�����������ƽ���кͣ�����������֮�⡣\n"NOR);	
	  
        if( me->query("atman") < 1 )
		return notify_fail("���ࡺ���񳯷�������Ҫ������\n");
	me->add("atman",-1);
	me->start_busy(2);

	skill = skill ;
	
	message_vision(CYN"
$N�Ღ���ң�����������ƽ���кͣ�����������֮�⣬�����ÿ�������֮��
���������������������񣬻�ֹЪ���ۣ������°��裬ë���ͷף�εΪ��ۡ�
δ�������׷׻�����$N���ϡ�\n\n"NOR,me);
 
	me->set_temp("shield_force/type","atman");
	me->set_temp("shield_force/ratio",skill);
	me->set_temp("shield_force/msg",
		CYN"����������������������$N����ס��$N�Ĺ��ơ�\n"NOR);
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), skill/2);     
	return 1;
}


void remove_effect(object me)
{
        me->delete_temp("shield_force");
        message_vision(CYN"$N���ϵ�����չ�᳤������ʧ���ƶ˲����ˡ�\n"NOR,me);
}

