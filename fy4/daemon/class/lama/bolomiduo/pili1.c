// Silencer @ FY4 workgroup. Aug.2004
//	gin -40 DS

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
	object *team, *team1;
	int i, skill, iron, num;
	mapping buff;

	if (me->query("class")!= "lama")
		return notify_fail("ֻ�д��ѵ��Ӳ������á������ķ���\n");
		
	skill = me->query_skill("bolomiduo",1);
	if (skill < 160)
		return notify_fail("�������ķ�����Ҫ160�������۶��ľ���\n");
	
	iron = me->query_skill("jin-gang",1);
	if (iron < 180)
		return notify_fail("�������ķ�����Ҫ180����ղ����񹦡�\n");
		
	if (ANNIE_D->check_buff(me, "feat") || ANNIE_D->check_buff(me, "damageshield"))
		return notify_fail("���Ѿ���ʹ�����Ƶ��书�ˡ�\n");
	
	if( (int)me->query("force") < 200 )
		return notify_fail("�������ķ�����Ҫ200���������\n");
	
	if (userp(me))	me->add("force", -200);
	me->start_busy(2);
	
	message_vision(HIW "$N"HIW"���·����ƴ󺣰�Ĺ�����������Ծ�����ᣬ�ֳ��ۡ����䲻����
ȫ��Ĺǽڣ����������㡰žž���ر���������\n" NOR, me);
        
        team1 = me->query_team();
	
	skill = skill/4;
	
	if (!team1) {
		buff =
		([
			"caster":me,
			"who":	me,
			"type": "damageshield",
			"type2": "resistup",
			"att": "bless",
			"name": "�����۶��ľ��������ķ�",
			"time": 180,
			"shield_desc":HIW"$n"HIW"һ��$N"HIW"��������Ȼȫ�������������\n"NOR,
			"shield_amount":skill,
			"shield_type":"gin",
			"buff1": "resistance/gin",
			"buff1_c": 10,	
			"buff_msg":"",
		//	"warn_msg":WHT"��ġ������ķ����ܿ��Ҫ�����ˡ�\n"NOR,
		//	"disa_msg":YEL"��ġ������ķ���������ϣ�\n"NOR,
		]);
		ANNIE_D->buffup(buff);
	}else {	
		team = filter_array(team1,(: present($1,environment($2)) :),me);
		num = sizeof(team);	
		for (i=0; i<num; i++) {
			if (team[i]->query_temp("damage_shield")) continue;
			buff =
				([
					"caster":me,
					"who":	team[i],
					"type": "damageshield",
					"att": "bless",
					"name": "�����۶��ľ��������ķ�",
					"time": 180,
					"shield_desc":HIW"$n"HIW"һ��$N"HIW"��������Ȼȫ����𣬺�Ȼ��������\n"NOR,
					"shield_amount":skill,
					"shield_type":"gin",
					"buff_msg":"",
		//			"warn_msg":WHT"��ġ������ķ����ܿ��Ҫ�����ˡ�\n"NOR,
		//			"disa_msg":YEL"��ġ������ķ���������ϣ�\n"NOR,
				]);
			ANNIE_D->buffup(buff);
			tell_object(team[i],YEL""+me->name()+"��������ʩ���ˡ������ķ���\n"NOR);
		}
        }
        
	return 1;
}

