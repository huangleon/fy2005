// Copyright C apstone, inc.
#include <ansi.h>
#include <weapon.h>
inherit DAGGER;
void create()
{
	set_name(HIC "Ӣ��ɳ�쵶" NOR, ({ "sharp dagger","dagger" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 500);
		set("material", "iron");
	        set("long", @LONG
Ӣ��ɳС������ԭ����Ӣ��ɳ�ض������ģ����½���������Ĵ�ͳ�ֹ���
��Ʒ֮һ��ÿһ�������϶���һ�ѣ���ľ����Ҳһ��ӵ��һ�ѷ�����Ӣ��
ɳС����Ӣ��ɳС��������â�������ɴ壬��˵�ܾ���ǰâ�������ɴ���
��һ����������������������ĵ��ӣ��ܶ��˴Ӳ�ͬ�ط�ǰ����������
Ӣ��ɳС���ͳ�������ľ������â�������ɴ���������游�����Ǹ���
��Ӣ��ɳС���������������ϵ�Ӣ��ɳ�쵶�������游�������ġ�һ��С
С�ĵ���������ľ�����游�ĳɹ���
LONG);
		set("wield_msg", "$N���һ�����λε�$n�������С�\n");
		set("unequip_msg", "$N�����е�$n����ѥ���\n");
	}
	::init_dagger(20);
}
