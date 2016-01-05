inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("С�����", ({ "walnut", "he tao", "hetao" }) );
        set_weight(100);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "����һ����ɫ�ĺ��ң�Ҳ��֪������û�С���Ҳ��������Уţţ̣�����������\n");
        set("unit", "��"); 
        set("value", 1);
    	set("peeled", 1);
    }
    ::init_item();
}

void init () {
	if( this_player() == environment()) {
		add_action("do_eat", "eat");
		add_action("do_peel", "peel");
	}
}

int do_eat(string arg)
{
    object walnut, me;
    
    me = this_player();    
    if (!arg || arg != "walnut" && arg != "С�����" && arg != "hetao") return 0; 	
   	if (query("peeled")) {
	   	message("vision", me->name() + "ץ��һ����Ƥ������Ҿ�ҧ���������˳�������ɬ��ֱ����ͷ��\n", 
   				environment(me), me);
   		write("�ۣ�ʲô��ζ����ɬ�ֿ࣡\n");
   		write("����æ���˳����������ﻹ��ɬ�����ܡ� \n");
   		remove_call_out("pig_mouth");
		call_out("pig_mouth", 20, me);
	} else {
		message("vision",me->name() + "�ó�һ�������ʷŵ����\n", environment(me), me);
   		write("����������ʳ��˳����������������Ǻü��ˣ� \n");
    	me->add("food", 2);
		destruct(this_object());
	}
    return 1;
}

void pig_mouth(object me)
{
	tell_object(me, "�����Ǵ�Ƥ�ĺ����ж��ɣ�������������ʹ������������\n");
	message("vison", "��֪��ʲôԭ��" + me->name() + "�������������������"
			+ "��һ����;��׵����С���졣\n", environment(me), me); 
}

int do_peel(string arg)
{
	object walnut, me, weapon, obj;
	
	if (!arg || arg != "walnut" && arg != "С�����" && arg != "hetao") {
		write("��Ҫ��ʲô��\n");
		return 1;
	}
	me = this_player();
	weapon = me->query_temp("weapon");
	if (query("peeled")) {
		if(!weapon) {
    		write("������û�к��ʵ������������ǰ���������ҵġ�\n");
   		} else {
			if(weapon->query("flag") & 4) {
				message_vision("$NС�ĵ�������ɫ�����Ƥ���п����ǣ�ȡ���˺����ʡ� \n", me);
				set("peeled", 0);
				set_name("������", ({"walnut", "peeled walnut"}) );
				set("long", "�װ����۵ĺ����ʡ�\n");
			} else {
				write("�������û�취������Ƥ�ģ���һ�����ԡ�\n");
			}
		}
	return 1;
	}
	return 0;
}