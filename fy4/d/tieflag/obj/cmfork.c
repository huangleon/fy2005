
#include <ansi.h>
#include <weapon.h>

inherit FORK; 

void create()
{
        set_name(  "��" , ({ "fork" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",

"����һ������ͨͨ�Ĳ棬���ϵ���û���κ�����֮����\n"
);
                set("material", "steel");
                set("rigidity", 100000);
                set("weapon_prop/agility", 2);
                set("weapon_prop/intelligence", 1);
                set("weapon_prop/courage", 1);
                set("weapon_prop/composure", 1);
        }

        ::init_fork(20);
}
 
void init()
{
	add_action("do_make","remake");
}


int do_make()
{
	object me;
	object obj;
	me=this_player();
	obj=new(__DIR__"commcase");
	obj->move(me);
        if(query("equipped")) unequip();
        tell_object(me,"�㽫���е�"+query("name")+"�ֲ𿪣���ɸ����ӡ�\n");
        destruct(this_object());
	return 1;
}          
  
