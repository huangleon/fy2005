// �� ˼· by Sinny/Silencer@fy4.
// ������������ 
// ʮ���������
// ���񳯷����� 
// �̺�������:  
// ����ˮ������
// ����ɢ


#include <ansi.h>
inherit SSERVER;

int conjure(object me, object target)
{
	string msg;
	object *weapon,*inv;
	int skill, your_exp, my_exp, damage, i;
	
	if (me->is_ghost())
		return notify_fail("�����ǹ�꣬�����뷨�Ȼ�����ɡ�\n");
	
	weapon = filter_array(all_inventory(me),(:$1->query("timbre"):));
		
	if (!sizeof(weapon))	
		return notify_fail("���ֱ����٣����Գ��֣� \n");
		
	if (me->is_busy())
		return notify_fail("��������æ���к���Ͼ���٣�\n");
	
	skill = me->query_skill("music",1);	
	if (!skill)
		return notify_fail("��������һ�ϲ�ͨ��Ϲ���˼��£��پ���Ȼ��ζ��\n");
	
	if (me->query("annie/music_choose") != 4 && userp(me))
		return notify_fail("���������ƺ�ûѧ������\n");

	if (skill < 150)
		return notify_fail("�㷢�ִ��׹��ڸ��������Ҫ150�����ٵ��������ࡣ\n");
        
    if (me->query_condition("qingxin"))
    	return notify_fail("��յ����������������\n");
    
    if( me->query("atman") < 200 )
		return notify_fail("���ࡺ��������������Ҫ200��������\n");
	me->add("atman",-200);
			        
	skill = skill + weapon[0]->query("timbre");
	
	message_vision(HIG"
$N�ָ����ң�����������ȴ�����֮��������һ������̾Ϣ�������ǳ�¶
���󻨰꣬����ͷ����ҡ��������� \n"NOR,me);


	me->apply_condition("qingxin", 10);
	me->set_temp("marks/music-qx", skill);
		
	return 1;	
}
