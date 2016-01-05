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
    	set("opened", 1);
    	set("durian_remain", 3);
    }    
        ::init_hammer(15);
}

void init () {
    if(this_player()==environment()) {
		add_action("do_eat", "eat");
		add_action("do_cut", "cut");
	}
}

int do_eat(string arg)
{
    object durian, me;
    
    me = this_player();    
    if (!arg || arg != "durian" && arg != "����" && arg != "liu lian") return 0; 	
   	if(query("opened")) {
   		tell_object(me, "�ⶫ������Ӳ�̣���ô���찡��\n");
   		message("vision", me->name() + "���Ŵ���������ҧ���������ĳ����̵�Ӳ�������޴����졣\n", 
   				environment(me), me);
    } else {
		message_vision("$N���ź���������һƬ��������ϸϸƷ��������\n", me);
    	tell_object(me, "����ģ����������ζ������������\n");
     	me->add("food", 2);
    	add("durian_remain", -1); 
    	if(query("durian_remain") == 0) {
    		destruct(this_object());
    	}
    }
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
			if(query("opened")) {
				message("vision", me->name() + "�Ӷ����е�" + weapon->name() + 
						"�����˴�������\n", environment(me), me);
				message_vision("һ������Ĺ�ζ�˱Ƕ������������� \n", me);
				set("long", "��������������¶�������ɫ��ȿ��ɢ����һ������Ĺ�ζ��\n");
				set_name("�򿪵�����", ({"durian", "opened durian"}));
				set("wield_msg", "$Nһ����������Ӳ�̵�$n���������С�\n");
        		set("unequip_msg", "$N�������е�$n��\n");
				set("opened", 0);
			} else {
				tell_object(me, "�����������Ѿ����ˡ�\n");
			}	
		} else {
			write("�������û�취�������ģ���һ�����ԡ�\n");
		}
	}
	return 1;
}
