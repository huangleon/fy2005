// hat.c
#include <armor.h>

inherit HEAD;

void create()
{
    set_name("һ����Ⱦ��������", ({ "rain hat" ,"hat"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("value", 0);
		set("material", "wood");
        set("armor_prop/armor", 1);
       set("long", "һ������ͨ����ҳ��������Ķ���,�ƺ��ܳ¾���,��ȴһ����Ⱦ,�ɸɾ���.\n");
	}
	::init_head();
}
