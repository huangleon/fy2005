// daimonsword.c	; annie 6.29.03
// demon - npc only.
// ����Ϭָ����������衢����Ʈ�㲽���̿ղ������㸡Ӱ���÷�Ʈ���衢���ɲ���
// desc: ESIIС������.��,��Ұ�����ʽ.��

#include <ansi.h>
inherit SKILL;
int check_skill(object victim) ;

void setup(){
	set("name","��̾����");
	set("usage/sword",1);
	// cant parry
	set("type","sword");
	set("practice_damage",100);
	set("effective_level",200);
	set("difficulty",250);
	set("skill_class","demon");

	action = ({
        ([      "action":               
"$N��ִ$w��ת��һ�С�Ҷ����硹�����㽣������ں���������$n",
                "parry":                50,
                "damage":               230,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$ŅüԶ����������Ȼ��$wһʽ���·�Զָ����бб�����Ƴ�",
                "parry":                120,
                "damage":               330,
                "damage_type":  "����"
        ]),
([      "action":               
"$Nʹ������ʱ���꡹һ��$w�������⻷��ˮ��������ɢ�������������$n��ȥ",
                "parry":                155,
                "damage":               450,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w����һ����ֻ�������㣬Ʈ�����������ơ�������䡹��ӳ����ɫ�԰׵�$n",
                "parry":                300,
                "damage":		320,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�������ģ�����$wһ��һת��ʩ������ʽ���Ϻޡ���һ����������ˮ�㻮��$n",
                "parry":                150,
                "damage":		600,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��ָ��ס$w����ƫ���еĻ�������$n������ƽ�����棬ʵ����ɲ�����������̾��������ʽ���γ���",
                "parry":                150,
                "damage":		600,
                "damage_type":  "����"
        ]),
	});
}
/*
int valid_learn(object me)
{
	object ob;
	seteuid(getuid());
	if(!::valid_learn(me))
		return 0;
	if (!me->query("marry") || me->query("divorced"))	// married,never divorce,and ... *grin
		return notify_fail("�������������ģ������޷�����ס��̾��������֮���ڡ�\n");
	ob = FINGER_D->acquire_login_ob(me->query("marry"));
	if (ob)
		return notify_fail("�������������ģ������޷�����ס��̾��������֮���ڡ�\n");
	return 1;
}*/


int practice_skill(object me)
{
	return notify_fail("��̾����ֻ����ѧ�ġ�\n");
}

mapping query_action(object me, object weapon) 
{
	int act;
	act=random(sizeof(action));
	return action[act];

}


mixed hit_ob(object me, object victim, int damage_bonus)
{
	int badint=0;
    	if( damage_bonus < 500 ) return 0; 
	if (victim->query_skill_mapped("dodge") == "stormdance"
		||victim->query_skill_mapped("dodge") == "fengyu-piaoxiang"
		||victim->query_skill_mapped("dodge") == "sky-steps"
		||victim->query_skill_mapped("dodge") == "cloud-dance"
		||victim->query_skill_mapped("dodge") == "anxiang-steps"
		||victim->query_skill_mapped("dodge") == "feixian-steps"
		)
		{
		badint=victim->query_skill("dodge");
		if(badint) {
			victim->receive_wound("kee",badint*2,me);
			switch(random(2)) {
        			case 0: return "$N�ϵл��ȣ�����׾ٵ�����$n�Ŀ�϶֮�䣡\n";
               			case 1: return "$N��֪$n����ȥ��$n��ʩչ�����ˣ�\n";
           			}
		}
	}
}


int help(object me)
{
	write(@HELP   
�ý�����������衢����Ʈ�㲽���̿ղ������㸡Ӱ���÷�Ʈ���衢
���ɲ��ж����˺�

����˼��ɱʽ����chousi��
���е�һ�У���ȥ��������ף�����˺���Ѫ=ף����*1000

����˼��ɱʽ��(chousix)
��ʱ�ģ�û��

���ϳ�����ʽ����duanchang��
���ϳ�����ʽ����duanchangx��
�����ŭʽ����libie��
�����ŭʽ����libie2��
���λÿջ�����menghuankonghua��
���������������֮�ǳ�����̬���ؼ���

HELP
    );
    return 1;
}
