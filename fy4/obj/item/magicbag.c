#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIG"�������"NOR, ({ "hallucination" }) );
	set_weight(500);
	set_max_encumbrance(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("prep", "inside");
		set("unit", "��");
		set("long", "����һ����������ɵĻ��񣬿��ԷŽ�һЩ������\n��������ʱ���ܴ�������Ķ�����ʧ����˶������ǿ�һ��ɡ�\n");
	}
	call_out("dissolve",30);
}

int is_container() { return 1; }

int dissolve()
{
	object holder,room;
	
	if(!objectp(holder=environment())) {
		destruct(this_object());
		return 1;
	}
	
	if(userp(holder))
		room=environment(holder);
	else room=holder;
	message("vision",this_object()->query("name")+"��������ʧ�ڿ������ˡ�\n",room);
	destruct(this_object());
	return 1;
}