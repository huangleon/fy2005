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
	object *stuff, weapon;
	int skill,i , damage;
	int qin;
	
    if (me->query("class") != "baiyun") 
    	return notify_fail("ֻ�а��Ƶ����ӿ������ࡺ����ɢ��\n");

	if (me->is_ghost())
		return notify_fail("�����ǹ�꣬�����뷨�Ȼ�����ɡ�\n");
	
	skill = me->query_skill("music",1);	
	if (!skill)
		return notify_fail("��������һ�ϲ�ͨ��Ϲ���˼��£��پ���Ȼ��ζ��\n");
	if (skill < 200)
		return notify_fail("�����ֲ����˼��£����ִ��׹��ڸ��������Ҫ200�����ٵ��������ࡣ\n");

	stuff = all_inventory(me);
	qin=0;
	for (i=0;i<sizeof(stuff) ;i++){
		if(qin < stuff[i]->query("timbre")){
		  qin = stuff[i]->query("timbre");
		}
	}  
	if(!qin && userp(me)) return notify_fail("��������Ǵ����ˡ�\n");

	if( !target ) target = offensive_target(me);        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("������ɢ��ֻ����ս�����������Ч��\n");
        
    if(me->query_temp("max_bird") || me->query_temp("pfm/summoning_crane"))
       	return notify_fail(CYN"�������˼��£�������ɱ������������Ȼ���¡�\n"NOR);	
        	
    if( me->query("atman") < skill*2 )
		return notify_fail("���ࡺ����ɢ����Ҫ"+chinese_number(skill*2)+"��������\n");
	if (userp(me))	me->add("atman",-skill*2);
	
	me->perform_busy(2);
		        
	message_vision(YEL"
$N��Хһ����ָȡ�ž�����ǧ�����գ�����һ����������ͬ�����Ӳ�֮�䣬
һ����ɱ����֮��ֱ�������������������޲�ʼ���ߣ����������ն�����֮��
�ӣ�������˹������Ϊ֮���������Ϊ֮���ݣ� \n\n\n"NOR,me);
	me->set_temp("pfm/summoning_crane",1);
	call_out("summoning",3,me);
	return 1;
 		
}

int summoning(object me) {
	
	object bird;
	int skill;
	
	skill = me->query_skill("magic");
	if (!me || me->is_ghost()) return 1;
	
	if (random(me->query_skill("music",1))> 5 ) {
		message_vision(RED"
������ɢ�����ϣ����֮���Ȼ�������ƺ����ѳ������У�ļȻ����ؽ���֮
�������쳪�㴫����Хһ����������Ʒ·����һ�㣬�ʺ���Ѫ��һֻ˶����
�ȵĻ�״��������\n\n"NOR,me);
			seteuid(getuid());
	        bird = new("/obj/npc/fire_crane");
	        bird->move(environment(me));
	        // 475 500
	        bird->invocation(me, skill);
			bird->set("possessed", me);
			me->add_temp("max_bird",1);
	}
 	else {
 		message_vision(WHT"
ļȻ���������������Ҿ��ϣ��㵫����ƽ�������֮�£�������Ŀ����
������ס����֮�飬���ٴ�ޣ����ۡ���һ����������Ѫ��\n\n"NOR,me);
		me->receive_damage("kee",skill);
		me->receive_damage("gin",skill);
		me->receive_damage("sen",skill);
		me->set_temp("last_damage_from","һ��������ɢ���ϣ�ŻѪ����������\n");
	}
	me->delete_temp("pfm/summoning_crane");
	return 1;
}