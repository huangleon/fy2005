//By clone        6/2001

#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("�಼��", ({ "dirty cloth","cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else{
		set("unit", "��");
		set("long", "������ɽ��ƽʱ���ʱ���Ĳ��£����浽���Ǻں��������գ�ɢ��
��һ�����̣��ռ��ͳ��������һ��Ĺ����ζ����\n");
		set("value", 0);
		set("material", "cloth");
		set("armor_prop/armor", 5);
	}
	::init_cloth();
}
