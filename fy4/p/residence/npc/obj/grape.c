#include <ansi.h>
#include <weapon.h>

inherit THROWING;

void create()
{
	set_name(CYN"��������"NOR, ({ "grape"}) );
	set_weight(35);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һЩ���������������ѡ�\n");
		set("unit", "��");
		set("desc_txt","���Ŷ���");
		set("base_unit","��");
		set("wield_msg", "$N��$n�������е�������\n");
		set("material", "bone");
		set("level_required",60);
		set("volumn",1);
	}
	set_amount(1);
	::init_throwing(60);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	string tmp1;
	mapping buff;
	
	if (victim->query_temp("annie/grape"))	return 0;
	if (!victim->query("can_speak"))	return 0;	// ����Ų������ʲô��

	tmp1 = CYN"$N����һ�����֣������ȵ�������ǧ����Ҷ��ˣ������а������������ѣ�\n�˽�����������������ʮһ������������һ�Ķ��Ű����������������ߣ���\n��Ѫ�У�һ�����ģ���ҩ�ɾȣ���\n"NOR;
	victim->add_temp("annie/grape", 1);	
	if (random(me->query_int()*2) > random(victim->query_int()))
	{
		tmp1 += CYN"$nһ�����������˰�ء����������������ٶ�ȡʤ������ι�����ˣ���Խ��
���������ģ�Խ��ϲ����һ���������޵���Ŀ��ֻ���������������֣����
�����Ƕ���֮ǿ�����ųƿɱܶ�֮��Ҳ�ɷ��顣
$nԽ��Խ�£�������ʱ����������\n"NOR;
		buff = 
		([
			"caster": me,
			"who":  victim,
			"type":  "slow",
			"att":	"curse",
			"name":	"�������ѡ�����",
			"buff1": "apply/slow",
			"buff1_c":50+random(50),
			"time":  30,
			"buff_msg": "",
		]);
		ANNIE_D->buffup(buff);
	}
	else
	{
		tmp1 += WHT"$n��ߵ���ʲô�������ѣ��˵��Ǻ�˵�˵���\n"NOR;
	}
	me->perform_busy(1);
	return tmp1;
}
/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/
