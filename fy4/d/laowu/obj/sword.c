//	�������ĶϽ�---��������������

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("�Ͻ�", ({ "guo sword","sword" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "
����һ���������۵�������������ǳǳ�ؿ��ż�����--���������ڣ�������������
�������ڽ�ͷ�Ѿ����ۣ�����͸��Щ����ɫ�Ĺ���\n");
		set("value", 400);
		set("guo_sword",1);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");
	}
	::init_sword(10);

}
