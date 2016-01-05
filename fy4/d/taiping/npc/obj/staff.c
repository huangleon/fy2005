#include <weapon.h>
inherit STAFF;

void create() {
	set_name("�ִֵĵ����", ({ "fishpole" }) );
	set_weight(2000);
	set_max_encumbrance(1);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���ִֵĵ���͡�\n");
		set("value", 300);
		set("material", "wood");
		set("wield_msg", "$N��$n�������������С�\n");
		set("unwield_msg", "$N�ɿ������е�$n��\n");
	}
    ::init_staff(10);
}


void init()
{
        add_action("do_use", ({ "fishing","fish" }));
}

int do_use(string arg)
{
        tell_object(this_player(),"���ͳ�һ��" + this_object()->name() + "��\n");
        environment(this_player())->fish_notify(this_object(), 0);

        return 1;
}

int is_container() { return 1; }