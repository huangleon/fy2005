#include <ansi.h>

inherit SKILL;
void setup() {
	set("name","��÷�ķ�");
	set("type","force");
	set("effective_level",100);
	set("difficulty",200);
	set("usage/force",1);
	set("skill_class","huashan");
	
}

mapping ob_hit(object ob, object me, int damage) {
	
	mapping data = ([]);
	int num, x, dmg;
	
	if ((x=me->query_temp("pfm/hs_mthy_shield")>0)) {
		message_vision(WHT"$N"NOR WHT"���Ϻ��Ǻ���΢���������â������$n"NOR WHT"�����Ǳ��޿ɱܣ�\n"NOR, me, ob);
		COMBAT_D->report_status(ob);
		dmg = COMBAT_D->magic_modifier(me, ob, "kee", me->query_skill("tanzhi-shentong",1)); // 160 per hit
		ob->receive_damage("kee", dmg, me);
		if (me->query_temp("pfm/hs_mthy_shield")<2)
			me->delete_temp("pfm/hs_mthy_shield");
		else
			me->add_temp("pfm/hs_mthy_shield",-1);
	}
		
	if (damage <=0)	return 0;		
	if( me->query_temp("pfm/hs_yingyueliuhui")<=0
		|| me->query("class")!= "huashan"
		|| me->query_skill_mapped("iron-cloth")!= "spring-water")
		return 0;
	
	num = me->query_temp("pfm/hs_yingyueliuhui");
	
	if (!random(4)){
		me->add_temp("pfm/hs_yingyueliuhui",-1);
		data["msg"] = WHT"$Nһ�й�ȥ��ȴ�繥�벨���Ӱ��ʧȥ��$n�����٣�\n"NOR,
		data["damage"] = - damage;
		if (me->query_temp("pfm/hs_yingyueliuhui") <= 0) {
			ANNIE_D->debuff(me, "hs_yylh");
		}	
	} 	
	return data;	
}


int help(object me)
{
	write(@HELP   
����˪������chill��
�����������ж��֣��������溮÷�ķ���ߣ�ÿ�κķ�50��������
���⹥����=��÷�ķ��ȼ�

����˪������aoshuang��
�����ķ�������ս����ʹ�ã��������������ѣ�����æ��1�غ�
�����ٶȣ���Чʱ�䣩3�롣
�ɣ�	��20����÷�ķ����ָ�250����Ѫ���ķ�100������
�ɣɣ�	��50����÷�ķ����ָ�400����Ѫ���ķ�150������
�ɣɣɣ���100����÷�ķ����ָ�800����Ѫ���ķ�200������
�ɣ֣�	��150����÷�ķ����ָ�1200����Ѫ���ķ�250������
�֣�	��200����÷�ķ����ָ�1600����Ѫ���ķ�300������

����˪������remedy��
�����ķ�������ս����ʹ�ã��������������ѣ�����æ��1�غ�
��40�غ��ڳ�������10�Ρ�
�ɣ�	��150����÷�ķ���ÿ�λָ�200����Ѫ�����ķ�200������
�ɣɣ�	��170����÷�ķ���ÿ�λָ�250����Ѫ�����ķ�250������
�ɣɣɣ���200����÷�ķ���ÿ�λָ�300����Ѫ�����ķ�300������

����˪������elixir��
�����ķ�������ս����ʹ�ã�ͬʱ�������ڳ����ж��ѣ�����æ��1�غ�
��32�غ��ڳ�������8�Σ����롺��˪�������ӡ�
��200����÷�ķ���200���÷�Ʈ���裬ÿ�λָ�250����Ѫ
���ķ�400������

���ѩ��˪����divine��
�������ڳ������ж��ѣ�ƽ���ֲ������˵���Ѫֵ��������æ��
��200����÷�ķ���200���÷�Ʈ���衣ÿ15����ʹ��һ�Ρ�

HELP
    );
    return 1;
}
