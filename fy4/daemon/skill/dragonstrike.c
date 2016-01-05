inherit SKILL;
#include <ansi.h>


void setup() {
	set("name","����ʮ����");
	set("type","unarmed");
	set("usage/parry",1);
	set("usage/unarmed",1);
	set("effective_level",160);
	set("practice_limit",100);
	set("damage_level",250);
	set("difficulty",300);
	set("skill_class","beggar");

	set("parry_msg", ({
	        "$n˫��΢�֣�ʹ��һ�С�������β������ž����һ����$N��$w������\n",
	        "$n��һת��һ�С������������$N����$w���֡�\n",
	        "$nʹ����ճ���־���˫��һ������ƫ��$N��$w��\n",
	}) );

	set("unarmed_parry_msg", ({
	        "$n����������һ�С��𾪰������ĳ����ƣ��Ƶ�$N�����Ա���\n",
	        "$nʩչ����������β�������赭д�Ļ�����$N�Ĺ��ơ�\n",
	}) );	
	action = ({
([      "action": "$N˫��ƽƽ�ᵽ��ǰ����ɫ���صĻ���ʩ���������лڡ�����$n��$l",
        "dodge": 30,
        "parry": 10,
        "damage": 400,
        "damage_type": "����"
]),
([      "action": "$NͻȻ���η���˫�ƾӸ�����һ�С��������졹����$n��$l",
        "dodge": 15,
        "parry": 20,
        "damage": 800,
        "damage_type": "����"
]),
([	"action": "$N����һ�С����������Ѹ���ޱȵ�����$n��$l",
	"dodge": 10,
	"parry": 10,
	"damage": 720,
	"damage_type": "����"
]),
([	"action": "$N˫��ʩ��һ�С��轥��½�����������ŷ�������$n��$l",
        "dodge": 15,
	"parry": 10,
	"damage": 900,
	"damage_type": "����"
]),
([	"action": "$N���ƾ۳�ȭ״������һ�С�Ǳ�����á���������$n��$l",
	"dodge": 10,
	"parry": 10,
	"damage": 500,
	"damage_type": "����"
]),
([	"action": "$Nʩ��һ�С�����󴨡������Ʋ�������������$n��$l",
	"dodge": 10,
	"parry": 20,
	"damage": 500,
	"damage_type": "����"
]),
([	"action": "$Nʹ����ͻ�������������ƴӲ����ܵĽǶ���$n��$l�Ƴ�",
	"dodge": 0,
	"parry": 10,
	"damage": 500,
	"damage_type": "����"
]),
([	"action": "$N���һ����˫��ʹ�����𾪰��������һ�а����$n",
	"dodge": 25,
	"parry": 10,
	"damage": 700,
	"damage_type": "����"
]),
([	"action": "$Nʹ������Ծ��Ԩ������$n��$l��������",
	"dodge": 20,
	"parry": 20,
	"damage": 300,
	"damage_type": "����"
]),
([	"action": "$N���λ�����˫��ʹһ�С�˫��ȡˮ��һǰһ����$n��$l",
	"dodge": 10,
	"parry": 20,
	"damage": 460,
	"damage_type": "����"
]),
([	"action": "$Nʹ������Ծ��Ԩ�������η���˫�Ʋ���һ����$n��$l����",
	"dodge": 20,
	"parry": 30,
	"damage": 900,
	"damage_type": "����"
]),
([	"action": "$N˫������ʹ����ʱ����������$n��������",
	"dodge": 20,
	"parry": 20,
	"damage": 870,
	"damage_type": "����"
]),
([	"action": "$Nʹ�������Ʋ��꡹�����Ʒ�ס$n����·������бб������$l",
	"dodge": 15,
	"parry": 20,
	"damage": 220,
	"damage_type": "����"
]),
([	"action": "$Nʹ�����������ڡ���˫�������������$n��$l",
	"dodge": 25,
	"parry": 10,
	"damage": 350,
	"damage_type": "����"
]),
([	"action": "$N����һת��ͻȻ�۵�$n��ǰ��һ�С���ս��Ұ������$n��$l",
	"dodge": 20,
	"parry": 40,
	"damage": 630,
	"damage_type": "����"
]),
([	"action": "$N�Ż��󿪣�һ�С���˪��������$n��$l��ȥ",
	"dodge": 25,
	"parry": 1,
	"damage": 420,
	"damage_type": "����"
]),
([	"action": "$Nʹ��������ެ����˫���������ϻ���$n��$l",
	"dodge": 15,
	"parry": 40,
	"damage": 600,
	"damage_type": "����"
]),
([	"action": "$N���ƻ��أ�����ʹһ�С�������β�����»ζ��Ż���$n��$l",
	"dodge": 10,
	"parry": 40,
	"damage": 620,
	"damage_type": "����"
]),
});

}

int valid_learn(object me){
	
	if( me->query_skill("begging",1) <= (int)me->query_skill("dragonstrike",1)
		&& me->query_skill("begging",1) < 150) {
        	return notify_fail("�л��ӿ��ҵ�����֮��ûѧ�ã���ô�ͼ���ѧ����ʮ�������ء�\n");
	}
	return ::valid_learn(me);
}


//	����ʮ����ר���ڼ�Ӳ������
mixed hit_ob(object me, object victim, int damage_bonus)
{
	int badint=0;

    if( damage_bonus < 300 ) return 0; 
        badint = victim->query_skill("iron-cloth");
	if (stringp(victim->query_skill_mapped("iron-cloth"))) {
		if(badint) {
			badint = COMBAT_D->magic_modifier(me, victim, "kee", badint);
			victim->receive_wound("kee",badint,me);
			switch(random(3)) {
        			case 0: return CYN"$N��ɽ��ţ����������һ�����죬�����ǹ����������\n"NOR;
               			case 1: return CYN"$N�������£�$n��$l������������һ�����죡\n"NOR;
               			case 2: return CYN"ֻ����$n��$l��������һ�� ������\n"NOR;
           			}
		}
	}
}

int damage_level(object me)
{
	int skill, n;
	if (me) {
		skill=me->query_skill("dragonstrike",1);
				
		if (skill<=140) return 0;
		if (skill>=190) return 250;
		n= (skill-140)*5;
		return n;
	}
	return 250;
}
		
int help(object me)
{
	write(@HELP   
����ʮ������Ҫ��ͬ�ȼ�������֮��Ϊ���������������������޴����ơ�����
ʮ���ƣ����������ϣ�ÿ����һ���˺��ȼ���ߣ���ֱ����������������������

L20�������޻ڣɡ���xianglongwuhui��
L90��ʱ�������ɡ���shichengliulong��
L100���𾪰���ɡ���zhenjingbaili��	
	���𾪰���ɣɡ�	�����	
	���𾪰���ɣɣɡ�	�����
	���𾪰���ɣ֡�	�����
L150��ʱ�������ɣɡ�
L160�������޻ڣɣɡ��ɹ�����ͬ�����ĵڶ���

�������޻ڡ�ÿ���������������æ�ҵ�����Ч����ÿ�����������빥����
��ɱ�����ﵽһ�����ֵ������ʮ���Ƶȼ�Խ�ߣ�����ʱ��Խ�̣�����������
�ϣ�ÿ���ӣ�����������ʱ�����һ�룬ֱ������������
�������ʹ��ʱ�������̣��򲻻�������ϵ���Ч������æ�ң��غ�
�����⹥����������ʮ���Ƶȼ�����
�������˺���������ʮ���Ƶȼ�����

��ʱ��������������Ϊ���͵��˵ķ��������ٶۣ�
�������ʮ���Ƽ���Ϊ���������ϣ��ڳɹ�����ĸ��غ��ڣ�
���˿�����������ͬ�ķ�Ӧ���������ץסս��ʹ�ö�Ӧ���ؼ���
���������µĹ�Ч��
���˸������������־��ɹ��ʼӱ�������æ��ʱ��
���˿��ţ����������־����������˺����ӱ�
���˷��������������־��������ӱ�
�����мܣ����������־��ɹ��ʼӱ����������־�ʱ�ޣ�������û��������תΪ�ѻ�
�����򶨣���������и�ɻ���û��Ч��
���˽����������𾪰��������������Ѹ�����ٶȻ���
��ʱ���������ɹ�������æ�ң�ʧ������æ�ң��غ�

���𾪰���˺����ܴ󣬵���ͨʹ��ʱ��Ҫ�������У�����ܵ�����
��������������������ң��޷�ʹ����
���⹥����������ʮ���Ƶȼ��������޷�����
�����˺�����������������������������������������
�����˺�����Զȡ������ֵ
HELP
    );
    return 1;
}

