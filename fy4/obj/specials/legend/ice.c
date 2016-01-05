// Silencer @ FY4 workgroup. Feb.2005

#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIW  "����" NOR, ({ "ice" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "Ƭ");
		set("long", "СС��һƬ�������䱡��ֽ��ȴ�������ơ�\n");
		set("desc_ext","cure wound");
		set("value", 0);
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
	
	me = this_player();
	
	if (arg!= "wound")
		return 0;
	
	if (query("juhan_owner")!=me)	
		return notify_fail("�㽫���������˿��������ද��������̫̫̫���ˣ�\n");
	
	if (me->is_fighting())
		return notify_fail("ս�������п��������\n");
		
	target = me;		
    	if(target->query("eff_kee") == target->query("max_kee"))
		return notify_fail("�˺���ֻ�������������ˣ�������û�ã�\n");

	if(me->query("marks/legend_juhan")<=0)
	{
		tell_object(me,"�������̻��������Ѿ���������ˮ���޷����������ˡ�\n");
		destruct(this_object());
		return 1;
	}
	
	target->receive_curing("kee",query("amount"));		
	
	message_vision("$N��һ�麮�������˿��������ද��Ѫ���ܵ��˿�
��Ȼ�漣�����������࣡��\n", me);
    me->add("marks/legend_juhan",-1);
    	
    if(me->query("marks/legend_juhan")<=0)
	{
		tell_object(me,"���������۵�����ɢ������������ˮ��\n");
		destruct(this_object());
		return 1;
	}
	
	return 1;
}
