
#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
    set_name("��β���ع�" , ({ "tiger staff", "staff" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "��");
       set("long", "����һ�������ع����ɵı��У��ϵ�ɻ���ͷ��ʾ���ϡ�\n");
        set("value", 5000);
		set("material", "wood");
        set("wield_msg", "$N���һ����$n�����������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}

    ::init_staff(10);
}
