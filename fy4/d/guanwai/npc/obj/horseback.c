#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("��", ({ "horseback" }) );
	set("short",WHT"�׿���ı���"NOR);
    set_weight(800);
    set_max_encumbrance(9999999);
			if( clonep() )
            set_default_object(__FILE__);
    else {
			set("no_fight",1);
			set("no_magic",1);
			set("no_spells",1);
            set("unit", "��");
            set("material", "cloth");
            set("long", "�����ڰ׿����ϣ�����������������ӹ�������Ѹ����������ر�ס����\n");
			set("value",0);
			set("closed", 1);
			set("is_horse",1);
		  }
    ::init_item();
}

int is_container() {return 1;}

void init()
{
	if (!wizardp(this_player()))
	{
	"/cmds/std/look"->look_room(this_player(),this_object());
	add_action("do_nothing", "");
	}
}	

int do_nothing()
{
	write("���ڲ����Ҷ������ĵ�����ˤ����\n");
	return 1;
}