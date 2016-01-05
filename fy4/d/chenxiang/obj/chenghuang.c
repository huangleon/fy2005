// medicine.c
inherit ITEM;
#include <ansi.h>

void create()
{
	set_name("������",({"guan yin"}));
        set_weight(6000);
	set("no_get",1);
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long",
     	        "һ������񣬾ݴ���ݣ�knee���Ժ������书��ͻ���ͽ���\n");
	    set("unit","��");
	    set("value", 200);
	}
}

void init()
{
	add_action("apply_effect","knee");
}

int apply_effect()
{
	int value = 20;
	int diff;

	if(this_player()->is_fighting())
	    return notify_fail("ս������ô�ܹ�ݹ�����\n");
	
	if (this_player()->is_busy())
		return notify_fail("��������æ��\n");
		
	if (this_player()->query("kee")<500)
		tell_object(this_player(),HIW"�ٿ���ȥҪ�����ˣ�����"NOR);
		
	message_vision("$N�����̣�һ�������ڹ�����ǰ�����������ؿ���������ͷ��\n",this_player());
	
	this_player()->receive_damage("kee",200);
	this_player()->start_busy(3);
	
	if (this_player()->query("class")=="shaolin")
	if (!random(100)) {
		this_player()->set("vendetta/shaolin",0);
		tell_object(this_player(),WHT"��������ԭ�����ˡ����������֪�ڸĵ����ְ��ࡣ������ӭ������\n"NOR);
	}
	
	return 1;
}


