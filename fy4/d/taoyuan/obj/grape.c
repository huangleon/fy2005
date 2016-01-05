inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("һ��С����", ({ "grape", "pu tao" }) );
        set_weight(200);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "СС������ɫ��Ө�������ñ����ɡ�\n");
        set("unit", "��"); 
        set("value", 1);
        set("grape_remaining", 4);
    }
    ::init_item();
}

void init () {
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
    object grape, me;
    
    me = this_player();
    grape = present("grape", this_player());
    
    if (!arg || arg != "grape" && arg != "һ��С����" && arg != "pu tao") return 0; 	
	if ((int)query("grape_remaining") >= 0) {
	   	message_vision("$N�����ض���һ�����ѵ����\n", me);
    	write("�ۡ��������������㱻���˵����������\n");
 		me->add("food", -3);
 		me -> set_temp("marks/��Դ_������", 1);
 		if ((string)me->query("gender") == "����" ) {
	 		message("vision",me->name() + "����ý�������üͷ�����ӣ��۾�����ͣ����۵���һ������һ�����ӡ�\n", environment(me), me);
    	} else {
    		message("vision",me->name() + "������ס��ͣ�üͷ����������\n", environment(me), me);
    	}
		if ((int)query("grape_remaining") == 1) {
			destruct (grape);
		} else {
			add ("grape_remaining", -1);
		}
	}
    return 1;
}