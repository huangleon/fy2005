
#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("��ʯ", ({ "pebble","cobble","stone" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"һ�Ѱ�ɫ��Сʯͷ��\n");
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 100);
	}
	set_amount(1);
	::init_throwing(10);
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
	string tmp1;
	victim->add_temp("annie/pebble", 1);
	if (victim->query_temp("annie/pebble") < 4)
		victim->set_temp("body_print", "����ͷ��������"+chinese_number(victim->query_temp("annie/pebble"),tmp1)+"��С����");
	else
		victim->set_temp("body_print", "����ͷ����������������һƬ����Ҳ�Ƶ�С����");
	return "ֻ��ž�һ������ʯ��$n�����ҳ���һ��С�İ���\n";
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
