#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name("����", ({ "durian", "liu lian" }) );
        set_weight(11000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "һ�ž޴����������������Ӳ�̣���˵�ж�ʮ��\n");
        set("unit", "��"); 
        set("value", 10);
        set("material", "wood");
        set("wield_msg", "$N�ó�һ�ž޴�ģ���������Ӳ�̵�$n���������С�\n");
        set("unequip_msg", "$N�������е�$n��\n");
    }    
        ::init_hammer(15);
}

void init () {
	if(this_player() == environment()) {
		add_action("do_eat", "eat");
		add_action("do_cut", "cut");
	}
}

int do_eat(string arg)
{
    object durian, me;
    
    me = this_player();    
    if (!arg || arg != "durian" && arg != "����" && arg != "liu lian") return 0; 	
   	tell_object(me, "�ⶫ������Ӳ�̣���ô���찡��\n");
   	message("vision", me->name() + "���Ŵ���������ҧ���������ĳ����̵�Ӳ�������޴����졣\n", 
   			environment(me), me);
    return 1;
}

int do_cut(string arg)
{
	object durian, me, weapon, obj;
	
	if (!arg || arg != "durian" && arg != "����" && arg != "liu lian") {
		write("��Ҫ����ʲô��\n");
		return 1;
	}
	me = this_player();
	weapon = me->query_temp("weapon");
	if(!weapon) {
    	write("������û�к��ʵ������������ǿ����������ġ�\n");
   	} else {
		if(weapon->query("flag") & 4) {
			message("vision", me->name() + "�����е�" + weapon->name() + 
					"�����˴�������\n", environment(me), me);
			message("vision", me->name() + "�Ծ����Ŵ����죡 �� \n",environment(me), me);
			message("vision", me->name() + "�����е�" + weapon->name() + 
					"�����˴��������Ծ��ط������������ֻ�пǣ�\n", me);
					tell_object(me,"�����ǿ��ģ�û��һ����⡣ \n", me);
			tell_object(me,"һ������Ĺ�ζ�˱Ƕ����������㱻Ѭ�á����� \n");
			me->unconcious();
			destruct(this_object());
		} else {
			write("�������û�취�������ģ���һ�����ԡ�\n");
		}
	}
	return 1;
}
