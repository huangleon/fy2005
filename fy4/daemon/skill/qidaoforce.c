// modified by mimicat@fy4
// qidaoforce.c

#include <ansi.h>
inherit SKILL;

void setup() {
	set("name","���");
	set("type","force");
	set("usage/force",1);
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("skill_class","legend");
	set("effective_level",150);
	set("damage_level",200);
	set("no_refund",({"diesword","shortsong-blade"}));
	set("difficulty",400);
	set("parry_msg",  ({
		"$n�ұۻ�ת��������ɽ�����ؽ�$N����ʽ�𿪡�\n",
		"$nһ����ȣ����������𵴣���ס��$N�Ĺ��ơ�\n",
		"$n�Ų��������ˣ����ָ����ֵͣ�$N�Ĺ�������ţ�뽭��ʧ���١�\n",
	}) );
	set("unarmed_parry_msg", ({
		"$n�ұۻ�ת��������ɽ�����ؽ�$N����ʽ�𿪡�\n",
		"$nһ����ȣ����������𵴣���ס��$N�Ĺ��ơ�\n",
		"$n�Ų��������ˣ����ָ����ֵͣ�$N�Ĺ�������ţ�뽭��ʧ���١�\n",
	}) );
	action = ({
        ([      "action":"$Nʹ��һ�С�����ͷ�������־۳�һ�����������϶��£�����$n��$l",
                "parry":		400,
                "dodge":		500,
                "damage":		200,
                "damage_type":  "����"
        ]),
        ([      "action":"$Nʹ��һ�С���б�������־۳�һ��������бб����$n��$l",
                "parry":		100,
                "dodge":		600,
                "damage":		250,
                "damage_type":  "����"
        ]),
	([ 	"action":"$Nʹ��һ�С�˫���ࡹ��˫�־۳�һ������������ͬʱ����$n��$l",
                "parry":		200,
                "dodge":		300,
                "damage":		300,
                "damage_type":  "����"
        ]),
	([	"action":"$Nʹ��һ�С�����������ȫ���ڿն�������ȫ�����������$n��$l",
                "parry":		400,
                "dodge":		400,
                "damage":		400,
                "damage_type":  "����"
        ]),
	});
}

int valid_enable(string usage) 
{ 
	return usage=="unarmed"||usage=="force"|| usage=="parry"; 
}

mixed hit_ob(object me,object victim)
{
	int extra, dream;
	string skill,message="";
	object weapon;
		
	extra = me->query_temp("pfm/qidaoforce_juqi");
	if ( extra <= 0 ) 	return;
	
	if (me->query_temp("pfm/legend_berserk"))	extra = extra*2;
			
	skill = objectp(weapon = me->query_temp("weapon")) ? weapon->query("skill_type") : "unarmed";
    if (skill == "unarmed")	extra = extra/2;
    
    skill = me->query_skill_mapped(skill);
    if (!skill || SKILL_D(skill)->skill_class()!="legend") {
		return;
    }
	
//	extra = COMBAT_D->magic_modifier(me, victim, "kee", extra);
	victim->receive_damage("kee",extra,me);
	
	if (me->query("family/master_id")=="master xuerui")
			message_vision(WHT"\n$N������ɫ��â��������ƬƬ����$n��$n"+WHT"ֻ��������һ����ʹ��\n"NOR,me, victim);
		else 
			message_vision(HIC"\n$N��������Ϊһ�ߣ�����$n"+HIC"�����ڡ�\n"NOR, me, victim);
	return;
}

int help(object me)
{
	write(@HELP
����Ѫ��(juxue)
���в���ʹ��exert juxue��������juxue����ֱ��ʹ�ã���������
æ�ҵ����ƣ���˲��ָ���������˵���Ѫֵ��ÿ��������һ�Ρ�
��Ѫ�ɣ��裶��������ķ����ظ�2000����Ѫ
��Ѫ�ɣɣ����ᣬ250��Ϣ��������150������ָ�6000����Ѫ
��Ѫ�ɣɣɣ����ᣬ290��Ϣ��������150������ָ�12000����Ѫ

�������������Ρ�(juqi)
�е���Ϊ������Ů����Ϊ���Σ�������ͬ����Ч��ͬ��
����ѩ�书�����Ӷ����˺������˺����ܶԷ����ס����������赲��
������I����100������ķ���������
������II����150������ķ���200��Ϣ��������������
������III������250��Ϣ��������������

���ۺ���(juhan)
Ϊ��ѩ�������ķ�����ˮԴ���������۳ɺ����������Դ��������ˣ�
ÿ15���Ӿۺ�һ�Σ��õ��ĺ�����ʹ�����Ρ����ۺ�I����150�������
ÿ������1000�㣬���ۺ�II����150�����220��Ϣ������������2000
�㣻���ۺ�III������270��Ϣ������������3000�㣬��ʹ�����Ρ�

�����ġ�(juxin)
��150�����150��Ϣ��������ÿ3����ʹ��һ�Σ�
��ѩս���е����ƣ��ָ�25%����Ѫ��50%���������ָ���Ѫ���ֵ
L200��Ϣ��������ÿ2��30����ʹ��һ��

������(jushen)
��150�����150�����鰵ʶ��ÿ5����ʹ��һ�Σ�ÿ�γ���60�룬
���������150��ѧϰABILILTY�������ٴ�ʹ��ʱ�䡣
L250�����鰵ʶ�����������200

��������(juwei)
��150�����230�����鰵ʶ
�������е��ˣ�����������غ����޷�ʹ����ͨ������
���в��������ޡ�����æ�ң��غϣ�ÿ3����ʹ��һ�Ρ�
�����޷��мܻ����ܡ�
L270�����鰵ʶ��ÿ2��30��ʹ��һ��
L300�����鰵ʶ��ÿ2����ʹ��һ��

��������(juli)
��150�����300��Ϣ��������ÿ5����ʹ��һ�Σ�ÿ�γ���60�룬
�ڼ��书ÿ���˺�����Ϊ���ֵ��ѧϰABILILTY�������ٴ�ʹ��
ʱ��
HELP
    );
    return 1;
}
