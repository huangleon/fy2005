// TIE@FY3
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIG  "ǧ������" NOR, ({ "old jade" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ����ɫ����ʯ��ӯӯ���������˳���
��������С�֣���ɽ�ɡ����ƺ��������������ˣ������壩��\n");
		set("value", 10000);
		set("max_cure",5);
		set("max_amount",1500);
		set("material", "stone");
	}
	::init_item();
}
void init()
{
	if(environment()==this_player())
	add_action("do_cure","cure");

}

int do_cure(string arg)
{
	object target, me;
	int amount;
	
	me = this_player();
	if(query("max_cure") <=0){
        set("name", "ǧ������");
        set("long", "һ����ɫ����ʯ��Ȼ����ɫ����������һ�ɺ�����\n");
        set("value", 1);
        return notify_fail("���������Ч�Ѿ����ù��ˣ�\n");	    
    }
    if(!arg) {
        target = me;
    } else if(!objectp(target=present(arg, environment(me))) && !objectp(target=present(arg, me))){
        return notify_fail("����û������ˡ�\n");
    } else if(!target->is_character() || target->is_corpse()){
        return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
    }
	if(target->query("eff_kee") == target->query("max_kee"))
	return notify_fail("������ֻ�������������ˣ�������û�ã�\n");

	amount = target->query("max_kee") - target->query("eff_kee");
	amount = amount/1500 ? amount/1500: 1;
	if (amount < 0 ) amount = 1;	
		
	target->set("eff_kee",(int)target->query("max_kee"));
	add("max_cure",-amount);
	
	
	if(target == this_player()){
    	message_vision("$N��һ��ǧ����������˿��������ද��Ѫ���ܵ��˿�
��Ȼ�漣��������ˣ���\n", me);
    } else {
    	message_vision("$N��һ��ǧ���������" + target->name() + "���˿��������ද��Ѫ���ܵ��˿�
��Ȼ�漣��������ˣ���\n", me);        
	}
    target->Cured(me);
	return 1;
}
